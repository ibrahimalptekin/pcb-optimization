

// Kişi 3: Queue, Stack ve Union-Find / Min-Heap sınıfları buraya yazılacak.
// std kütüphanelerinden sadece vector veya iostream gibi yardımcılar kullanılabilir.

#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include <iostream>

// --- UNION-FIND (DISJOINT SET UNION) ---
// Kruskal algoritmasının döngü kontrolü için kritik yapı.
class UnionFind {
private:
    int* parent;
    int* rank;
    int count;

public:
    UnionFind(int n) {
        count = n;
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Her düğüm başlangıçta kendi kendinin ebeveyni
            rank[i] = 0;   // Ağaç derinliğini optimize etmek için
        }
    }

    // Path Compression (Yol Sıkıştırma) ile Find işlemi
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]); // Kökü direkt bağla (Hızlandırır)
    }

    // Union by Rank ile birleştirme işlemi
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);

        if (root_i != root_j) {
            if (rank[root_i] < rank[root_j])
                parent[root_i] = root_j;
            else if (rank[root_i] > rank[root_j])
                parent[root_j] = root_i;
            else {
                parent[root_i] = root_j;
                rank[root_j]++;
            }
        }
    }

    ~UnionFind() {
        delete[] parent;
        delete[] rank;
    }
};

// --- STACK (YIĞIT) ---
// DFS (Derinlik Öncelikli Arama) için kullanılacak.
template <typename T>
class MyStack {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* topNode;

public:
    MyStack() : topNode(nullptr) {}

    void push(T val) {
        Node* newNode = new Node{val, topNode};
        topNode = newNode;
    }

    void pop() {
        if (topNode) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    T top() { return topNode->data; }
    bool isEmpty() { return topNode == nullptr; }
};

// --- QUEUE (KUYRUK) ---
// BFS (Genişlik Öncelikli Arama) için kullanılacak.
template <typename T>
class MyQueue {
private:
    struct Node {
        T data;
        Node* next;
    };
    Node* frontNode;
    Node* rearNode;

public:
    MyQueue() : frontNode(nullptr), rearNode(nullptr) {}

    void enqueue(T val) {
        Node* newNode = new Node{val, nullptr};
        if (!rearNode) {
            frontNode = rearNode = newNode;
            return;
        }
        rearNode->next = newNode;
        rearNode = newNode;
    }

    void dequeue() {
        if (frontNode) {
            Node* temp = frontNode;
            frontNode = frontNode->next;
            if (!frontNode) rearNode = nullptr;
            delete temp;
        }
    }

    T front() { return frontNode->data; }
    bool isEmpty() { return frontNode == nullptr; }
};

#endif