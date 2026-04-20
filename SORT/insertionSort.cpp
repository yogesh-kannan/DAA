#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout<<"Enter number of element :";
    cin>>n;
    int arr1[n];
    for (int i = 0; i < n; i++){
       cout<<"Enter element"<<i+1<<":";
       cin>>arr1[i];
    }
    cout << "Original array: ";
    printArray(arr1, n);

    insertionSort(arr1, n);
    cout << "Sorted by Insertion Sort: ";
    printArray(arr1, n);
    return 0;
}
