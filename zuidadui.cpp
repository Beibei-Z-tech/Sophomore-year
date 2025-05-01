#include <iostream>
#include <vector>
#include <algorithm> 
void printHeap(const std::vector<int>& heap) {
    for (int i = 0; i < heap.size(); ++i) {
        std::cout << heap[i] << " ";
        if (((i + 1) & (i + 1 - 1)) == 0) std::cout << std::endl;
    }
}
void heapify(std::vector<int>& heap, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
    if (left < n && heap[left] > heap[largest])
        largest = left;
    if (right < n && heap[right] > heap[largest])
        largest = right;
    if (largest != i) {
        std::swap(heap[i], heap[largest]);
        heapify(heap, n, largest);
    }
}
void buildMaxHeap(std::vector<int>& heap) {
    int n = heap.size();
    int startIdx = (n / 2) - 1;
    for (int i = startIdx; i >= 0; --i)
        heapify(heap, n, i);
}
void heapSort(std::vector<int>& heap) {
    int n = heap.size();
    for (int i = n - 1; i >= 0; --i) {
        std::swap(heap[0], heap[i]);
        heapify(heap, i, 0);
    }
}

int main() {
    std::vector<int> data;
    data.push_back(53);
    data.push_back(78);
    data.push_back(65);
    data.push_back(17);
    data.push_back(1);
    data.push_back(87);
    data.push_back(9);
    data.push_back(81);
    data.push_back(15);
    buildMaxHeap(data);
    std::cout << "Max Heap:" << std::endl;
    printHeap(data);
    heapSort(data);
    int nums[] = {53, 78, 65, 17, 1, 87, 9, 81, 15};
    int length = sizeof(nums) / sizeof(nums[0]);
    std::cout << "Sorted array:" << std::endl;
    for (int i = 0; i < length; ++i) {
        data.push_back(nums[i]);
    }
    std::cout << std::endl;
    return 0;
}
