#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

struct Node {
    char data;
    float freq;
    Node *left, *right;

    Node(char d, float f) {
        data = d;
        freq = f;
        left = NULL;
        right = NULL;
    }
};

struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Global variable to store total bits used by Huffman
float total_huffman_bits = 0;

void printCodes(Node* root, string code) {
    if (!root) return;

    if (!root->left && !root->right) {
        cout << root->data << ": " << code << endl;
        // Frequency * length of bits for this character
        total_huffman_bits += (root->freq * code.length());
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    float total_freq = 0;
    cout << "Enter number of characters: ";
    if (!(cin >> n)) return 0;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++) {
        char ch;
        float freq;
        cout << "Enter character with frequency: ";
        cin >> ch >> freq;
        total_freq += freq;
        pq.push(new Node(ch, freq));
    }

    // Fixed-length bit size (e.g., if we have 5 chars, we need 3 bits each: 2^3=8)
    float fixed_bit_size = ceil(log2(n));
    float total_fixed_bits = total_freq * fixed_bit_size;

    cout << "\nBuilding Huffman Tree using greedy technique ...\n";

    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    if (!pq.empty()) {
        Node* root = pq.top();
        cout << "\nHuffman Codes:\n";
        printCodes(root, "");

        cout << fixed << setprecision(2);
        cout << "\n****Compression Analysis ****" << endl;
        cout << " Fixed-length " << (int)fixed_bit_size  << total_fixed_bits << endl;
        cout << "Huffman-length: " << total_huffman_bits << endl;

        // Ratio = (Original Size / Compressed Size)
        float ratio = total_fixed_bits / total_huffman_bits;

        // Savings % = (1 - Compressed/Original) * 100
        float savings = (1 - (total_huffman_bits / total_fixed_bits)) * 100;
        cout << "Compression Ratio " << savings << "%" << endl;
    }

    return 0;
}
