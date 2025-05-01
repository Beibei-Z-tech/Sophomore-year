#include <iostream>
using namespace std;
void QuickSort(int *a, int low, int high){
    if (low < high){
        int pivot = a[low]; 
        int left = low;
        int right = high;
        while (left < right){
            while (left < right && a[right] >= pivot){
                right--;
            }
            a[left] = a[right]; 
            while (left < right && a[left] < pivot) {
                left++;
            }
            a[right] = a[left];
        }
        a[left] = pivot; 
        QuickSort(a, low, left - 1); 
        QuickSort(a, left + 1, high); 
    }
}
void printArray(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main() {
    int a[] = {7, 29, 33, 12, 89, 25, 26, 77, 15, 55};
    int n = sizeof(a) / sizeof(a[0]);
    QuickSort(a, 0, n - 1); 
    printArray(a, n); 
    return 0;
}
