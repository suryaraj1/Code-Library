#include <iostream>
#include <cstdio>

#define int long long
using namespace std;

// binary heap
// Min-Heap

class MinHeap {
	int *cur; // points to the array that stores elements
	int capacity, size;

public:
	MinHeap(int n) {
		// constructor
		capacity = n;
		size = 0;
		cur = new int[n];
	}

	~MinHeap() {
		// destructor
		delete cur;
	}

	int length() {
		return size;
	}

	int parent(int node) {
		return (node - 1) >> 1;
	}

	int leftChild(int node) {
		return 2 * node + 1;
	}

	int rightChild(int node) {
		return 2 * node + 2;
	}

	int top() {
		// peek into MinHeap
		// root is minimum 
		return cur[0];
	}

	void insert(int node) {
		if (size == capacity) {
			cout << "Could not insert key into heap" << endl;
			exit(0);
		}
		size++;
		int i = size - 1;
		cur[i] = node;
		while (i != 0 && cur[parent(i)] > cur[i]) {
			swap(cur[parent(i)], cur[i]);
			i = parent(i);
		}		
	}

	int extractMin() {
		if (size <= 0)
			return 1e18;
		if (size == 1) {
			size--;
			return cur[0];
		}
		int root = cur[0];
		// last node of complete binary tree 
		// takes the position of the root
		cur[0] = cur[size - 1];
		size--;
		MinHeapify(0);
		return root;
	}

	void MinHeapify(int i) {
		// min heapifies a subtree rooted at current index
		int l = leftChild(i);
		int r = rightChild(i);
		int min = i;
		if (l < size && cur[l] < cur[i])
			min = l;
		if (r < size && cur[r] < cur[min])
			min = r;
		if (min != i) {
			swap(cur[i], cur[min]);
			MinHeapify(min);
		}
	}
};


int32_t main() {
	MinHeap pq(11);
	pq.insert(100);
	pq.insert(2);
	pq.insert(3);
	pq.insert(15);
	pq.insert(11);
	pq.insert(4);
	cout << pq.extractMin() << endl;
	cout << pq.top() << endl;
}