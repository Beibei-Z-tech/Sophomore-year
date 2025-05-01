#include <iostream>
#include <vector>

void QuickSort(int *a, int low, int high);
int Partition(int *a, int low, int high);
void PrintArray(int *a, int size);

int main() {
    int a[] = {7, 29, 33, 12, 89, 25, 26, 77, 15, 55};
    int n = sizeof(a) / sizeof(a[0]);
    std::cout << "Original array: ";
    PrintArray(a, n);
    QuickSort(a, 0, n - 1);
    std::cout << "Sorted array:   ";
    PrintArray(a, n);
    
    return 0;
}
void QuickSort(int *a, int low, int high) {
    if (low < high) {
        int pivotIndex = Partition(a, low, high); 
        QuickSort(a, low, pivotIndex - 1);   
        QuickSort(a, pivotIndex + 1, high); 
    }
}
int Partition(int *a, int low, int high) {
    int pivot = a[low];
    int i = low;
    for (int j = low + 1; j <= high; j++) {
        if (a[j] < pivot) {
            i++;
            std::swap(a[i], a[j]); 
        }
    }
    std::swap(a[low], a[i]);
    return i; 
}
void PrintArray(int *a, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
