// Kişi 3: Queue, Stack ve Union-Find / Min-Heap sınıfları buraya yazılacak.
// std kütüphanelerinden sadece vector veya iostream gibi yardımcılar kullanılabilir.

#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <iostream>
#include <vector> // Sadece yardımcı olarak izin verilmiş

// --- UNION-FIND (DISJOINT SET UNION) ---
class UnionFind {
private:
    int* parent;
    int* rank;
public:
    UnionFind(int n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j]) parent[root_i] = root_j;
            else if (rank[root_i] > rank[root_j]) parent[root_j] = root_i;
            else { parent[root_i] = root_j; rank[root_j]++; }
        }
    }
    ~UnionFind() { delete[] parent; delete[] rank; }
};

// --- MIN-HEAP (PRIORITY QUEUE) ---
// Kruskal'da kenarları ağırlığına göre sıralı tutmak için.
template <typename T>
class MinHeap {
private:
    std::vector<T> heap; // Yardımcı olarak vector kullanımına izin var denmiş
    void heapifyUp(int index) {
        while (index > 0 && heap[(index - 1) / 2] > heap[index]) {
            std::swap(heap[index], heap[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }
    void heapifyDown(int index) {
        int minIndex = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if (left < heap.size() && heap[left] < heap[minIndex]) minIndex = left;
        if (right < heap.size() && heap[right] < heap[minIndex]) minIndex = right;
        if (index != minIndex) {
            std::swap(heap[index], heap[minIndex]);
            heapifyDown(minIndex);
        }
    }
public:
    void push(T val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }
    T pop() {
        T root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }
    bool isEmpty() { return heap.empty(); }
};

// --- STACK (YIĞIT) ---
template <typename T>
class MyStack {
private:
    struct Node { T data; Node* next; };
    Node* topNode = nullptr;
public:
    void push(T val) { topNode = new Node{val, topNode}; }
    void pop() { if (topNode) { Node* t = topNode; topNode = topNode->next; delete t; } }
    T top() { return topNode->data; }
    bool isEmpty() { return topNode == nullptr; }
};

// --- QUEUE (KUYRUK) ---
template <typename T>
class MyQueue {
private:
    struct Node { T data; Node* next; };
    Node *frontNode = nullptr, *rearNode = nullptr;
public:
    void enqueue(T val) {
        Node* n = new Node{val, nullptr};
        if (!rearNode) frontNode = rearNode = n;
        else { rearNode->next = n; rearNode = n; }
    }
    void dequeue() {
        if (frontNode) {
            Node* t = frontNode; frontNode = frontNode->next;
            if (!frontNode) rearNode = nullptr;
            delete t;
        }
    }
    T front() { return frontNode->data; }
    bool isEmpty() { return frontNode == nullptr; }
};

#endif