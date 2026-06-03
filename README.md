


# Veri Yapıları Proje Raporu: PCB Bağlantı Ağı Optimizasyonu
Bu proje, C++ programlama dili ve Raylib grafik kütüphanesi kullanılarak, Graf Teorisi prensipleri çerçevesinde minimum maliyetli PCB optimizasyonu problemini çözmek ve görselleştirmek amacıyla geliştirilmiş bir masaüstü uygulamasıdır.

## Proje Ekibi ve Görev Dağılımı
* **İbrahim Alptekin]** - *[Arayüz Tasarımı ve Entegrasyon]* (Branch: `feat/arayuz`)
* **[Ahmet Şeref Gölcük]** - *[Veri Yapıları Geliştiricisi]* (Branch: `ahmetgolcuq`)
* **[Sadettin Şahin]** - *[Graf Mimarı]* (Branch: `sadettinsahin`)
* **[Seymen Yiğit Ceylan]** - *[Algoritma Geliştiricisi]* (Branch: `Algoritma/Kruskal`)

## Ortak Tartışma ve Kararlar
Proje başlangıcında ekip üyeleriyle yapılan toplantılarda aşağıdaki kararlar alınmıştır:
* PCB üzerindeki bileşenler arası rotaları optimize etmek için Minimum Spanning Tree (MST) algoritmalarından Kruskal Algoritması'nın kullanılmasına karar verilmiştir.
* Kruskal algoritmasında döngü oluşumunu engellemek için Union-Find veri yapısı sıfırdan implemente edilecektir.
* Projenin kodlama dili C++ olarak belirlenmiş olup, modüler bir Header (.h) yapısı kurulmuştur.

## 30/04/26 Tarihine Kadar Yapılan Çalışmalar (Branch Bazlı Durum)
* **`main`:** Proje iskeleti oluşturuldu, boş header dosyaları eklendi ve tüm ekip üyeleri kendi dallarına ayrıldı.

## Pull Request Öncesi Tamamlananlar

# Graph Modülü

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
