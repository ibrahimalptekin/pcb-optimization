# Veri Yapıları Proje Ara Raporu: PCB Bağlantı Ağı Optimizasyonu

## Proje Ekibi ve Görev Dağılımı
* **İbrahim Alptekin]** - *[Arayüz Tasarımı ve Entegrasyon]* (Branch: `feat/arayuz`)
* **[Ahmet Şeref Gölcük]** - *[Veri Yapıları Geliştiricisi]* (Branch: `ahmetgolcuq`)
* **[Sadettin Şahin]** - *[Graf Mimarı]* (Branch: `sadettinsahin`)
* **[Seymen Yiğit Ceylan]** - *[Algoritma Geliştiricisi]* (Branch: ``)

## Ortak Tartışma ve Kararlar
Proje başlangıcında ekip üyeleriyle yapılan toplantılarda aşağıdaki kararlar alınmıştır:
* PCB üzerindeki bileşenler arası rotaları optimize etmek için Minimum Spanning Tree (MST) algoritmalarından Kruskal Algoritması'nın kullanılmasına karar verilmiştir.
* Kruskal algoritmasında döngü oluşumunu engellemek için Union-Find veri yapısı sıfırdan implemente edilecektir.
* Projenin kodlama dili C++ olarak belirlenmiş olup, modüler bir Header (.h) yapısı kurulmuştur.

## Şu Ana Kadar Yapılan Çalışmalar (Branch Bazlı Durum)
* **`main`:** Proje iskeleti oluşturuldu, boş header dosyaları eklendi ve tüm ekip üyeleri kendi dallarına ayrıldı.
