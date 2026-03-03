#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;
    
    void siftUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] > heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }
    
    void siftDown(int index) {
        int size = heap.size();
        while (true) {
            int smallest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            
            if (left < size && heap[left] < heap[smallest]) {
                smallest = left;
            }
            if (right < size && heap[right] < heap[smallest]) {
                smallest = right;
            }
            
            if (smallest == index) {
                break;
            }
            
            swap(heap[index], heap[smallest]);
            index = smallest;
        }
    }
    
public:
    void insert(int value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }
    
    int deleteMin() {
        if (heap.empty()) {
            return -1;
        }
        
        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        
        if (!heap.empty()) {
            siftDown(0);
        }
        
        return minValue;
    }
    
    int size() {
        return heap.size();
    }
};

int main() {
    int n;
    cin >> n;
    
    MinHeap heap;
    
    for (int i = 0; i < n; i++) {
        int operation;
        cin >> operation;
        
        if (operation == 0) {
            int value;
            cin >> value;
            heap.insert(value);
        } 
        else if (operation == 1) {
            cout << heap.deleteMin() << endl;
        }
        else if (operation == 2) {
            cout << heap.size() << endl;
        }
    }
    
    return 0;
}