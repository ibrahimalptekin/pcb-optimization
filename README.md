# PCB Optimizasyonu - Graph Modülü

Bu modül, PCB bağlantı ağı optimizasyonu projesi kapsamında graf veri yapısının oluşturulmasından sorumludur.

## Amaç
PCB üzerindeki bileşenleri düğüm (node), bağlantıları ise ağırlıklı kenar (edge) olarak modellemek ve Minimum Spanning Tree (MST) algoritmaları için uygun veri yapısını sağlamaktır.

## Kullanılan Veri Yapıları
- Komşuluk Listesi (Adjacency List)
- Kenar Listesi (Edge List)

## Özellikler
- Düğüm ekleme (`addNode`)
- Kenar ekleme (`addEdge`)
- Grafın bağlılık kontrolü (`isConnected`)
- BFS (Breadth-First Search)
- DFS (Depth-First Search)

## Tasarım Kararları
Graf yapısı komşuluk listesi ile implemente edilmiştir. Bu yapı, bellek kullanımı açısından O(V + E) karmaşıklığı sağladığı için tercih edilmiştir.

Kruskal algoritmasının tüm kenarları sıralayabilmesi için ayrıca ayrı bir kenar listesi tutulmuştur.

## Notlar
- Graf yönsüz (undirected) olarak modellenmiştir.
- Kenar ağırlıkları bağlantı maliyetini temsil eder.# pcb-optimization