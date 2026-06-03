#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <cmath>

// Arayüz için koordinat tutan düğüm yapısı
struct Node {
    int id;
    float x, y;
};

struct Edge {
    int src, dest;
    double weight;
};

class PCBGraph {
public:
    std::vector<Node> nodes;
    std::vector<Edge> edges;

    // Arayüzden fareyle tıklanan yere yeni bileşen ekler
    void addNode(float x, float y) {
        int newId = nodes.size();
        nodes.push_back({newId, x, y});
        
        // Yeni eklenen bileşeni, tahtadaki diğer tüm bileşenlere bağla (Olası yollar)
        // Ağırlık (Maliyet) = İki nokta arasındaki piksel mesafesi
        for (int i = 0; i < newId; i++) {
            double dist = std::sqrt(std::pow(nodes[i].x - x, 2) + std::pow(nodes[i].y - y, 2));
            edges.push_back({i, newId, dist});
        }
    }

    // Tahtayı temizler
    void clear() {
        nodes.clear();
        edges.clear();
    }
};

#endif