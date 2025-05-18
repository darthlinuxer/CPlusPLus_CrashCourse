#include <iostream>
#include <vector>
#include <algorithm>

class NoobPriorityQueue {
private:
    std::vector<int> heap;

    void heapify_up(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                std::swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapify_down(int index) {
        int size = heap.size();
        while (index < size) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }
            if (largest != index) {
                std::swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    void push(int value) {
        heap.push_back(value);
        heapify_up(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        std::swap(heap[0], heap.back());
        heap.pop_back();
        heapify_down(0);
    }

    int top() const {
        return heap.empty() ? -1 : heap[0];
    }

    bool empty() const {
        return heap.empty();
    }
};

int main() {
    NoobPriorityQueue pq;

    // Push elements
    pq.push(10);
    pq.push(5);
    pq.push(20);

    // Process the priority queue
    std::cout << "Priority queue elements: ";
    while (!pq.empty()) {
        std::cout << pq.top() << " ";
        pq.pop();
    }
    std::cout << "\n";

    return 0;
}

/*
Expected Output:
Priority queue elements: 20 10 5
*/