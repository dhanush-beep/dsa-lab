#include <iostream>
using namespace std;

class PriorityQueue {
    int *heap;
    int capacity;
    int size;

public:
    PriorityQueue(int cap) {
        capacity = cap;
        heap = new int[capacity];
        size = 0;
    }

    ~PriorityQueue() {
        delete[] heap;
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void swap(int &x, int &y) {
        int temp = x;
        x = y;
        y = temp;
    }

    void insert(int key) {
        if (size == capacity) {
            cout << "Priority Queue is full\n";
            return;
        }

        heap[size] = key;
        int i = size;
        size++;

        // Heapify Up
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void deleteMax() {
        if (size <= 0) {
            cout << "Priority Queue is empty\n";
            return;
        }

        cout << "Deleted Max: " << heap[0] << endl;
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }

    void heapifyDown(int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && heap[l] > heap[largest])
            largest = l;
        if (r < size && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void display() {
        if (size == 0) {
            cout << "Priority Queue is empty\n";
            return;
        }

        cout << "Priority Queue (Heap): ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }

    void heapSort() {
        int* temp = new int[size];
        int tempSize = size;

        for (int i = 0; i < tempSize; i++) {
            temp[i] = heap[0];
            heap[0] = heap[size - 1];
            size--;
            heapifyDown(0);
        }

        cout << "Heap Sorted Order (Descending): ";
        for (int i = 0; i < tempSize; i++)
            cout << temp[i] << " ";
        cout << endl;

        // Restore original heap
        delete[] heap;
        heap = new int[capacity];
        size = 0;
        for (int i = 0; i < tempSize; i++)
            insert(temp[i]);

        delete[] temp;
    }
};

// Driver code
int main() {
    PriorityQueue pq(100);

    pq.insert(40);
    pq.insert(20);
    pq.insert(60);
    pq.insert(30);
    pq.insert(10);

    pq.display();

    pq.deleteMax();
    pq.display();

    pq.insert(70);
    pq.display();

    pq.heapSort();
    pq.display();

    return 0;
}
