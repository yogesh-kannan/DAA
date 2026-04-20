//KnapSack problem using branch and bound technique
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Item { int profit, weight; };

bool compareItems(const Item& a, const Item& b) {
    return ((double)a.profit / a.weight) > ((double)b.profit / b.weight);
}

struct Node { int level, profit, weight; double bound; };
double calculateBound(Node u, int n, int W, const vector<Item>& items) {
    if (u.weight >= W) return 0;
    double profit_bound = (double)u.profit;
    int j = u.level + 1, totweight = u.weight;
    while (j < n && totweight + items[j].weight <= W) {
        totweight += items[j].weight;
        profit_bound += items[j].profit;
        j++;
    }
    if (j < n) profit_bound += (W - totweight) * ((double)items[j].profit / items[j].weight);
    return profit_bound;
}

struct CompareNodes {
    bool operator()(const Node& n1, const Node& n2) { return n1.bound < n2.bound; }
};

int knapsack(int W, vector<Item>& items, int n) {
    sort(items.begin(), items.end(), compareItems);
    priority_queue<Node, vector<Node>, CompareNodes> pq;
    Node u, v;
    v.level = -1; v.profit = 0; v.weight = 0;
    v.bound = calculateBound(v, n, W, items);
    pq.push(v);
    int maxProfit = 0;
    while (!pq.empty()) {
        v = pq.top(); pq.pop();
        if (v.bound <= (double)maxProfit) continue;
        u.level = v.level + 1;

        u.weight = v.weight + items[u.level].weight;
        u.profit = v.profit + items[u.level].profit;
        if (u.weight <= W && u.profit > maxProfit) maxProfit = u.profit;
        u.bound = calculateBound(u, n, W, items);
        if (u.bound > (double)maxProfit) pq.push(u);

        u.weight = v.weight; u.profit = v.profit;
        u.bound = calculateBound(u, n, W, items);
        if (u.bound > (double)maxProfit) pq.push(u);
    }
    return maxProfit;
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> W;

    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter profit for item " << i + 1 << ": ";
        cin >> items[i].profit;
        cout<<"Enter weight for item "<<i+1<<": ";
        cin >> items[i].weight;
    }

    int result = knapsack(W, items, n);
    cout << "\nThe maximum profit is: " << result << endl;

    return 0;
}
