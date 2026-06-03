📄 **[Projenin Kapsamlı Mimari ve Zaman/Alan Karmaşıklığı Raporunu (PDF) Görüntülemek/İndirmek İçin Tıklayınız](VeriYapilariProje_Grup1.pdf)**


# Veri Yapıları Proje Raporu: PCB Bağlantı Ağı Optimizasyonu
Bu proje, C++ programlama dili ve Raylib grafik kütüphanesi kullanılarak, Graf Teorisi prensipleri çerçevesinde minimum maliyetli PCB optimizasyonu problemini çözmek ve görselleştirmek amacıyla geliştirilmiş bir masaüstü uygulamasıdır.

## Proje Ekibi ve Görev Dağılımı
* **[İbrahim Alptekin - 032090138]** - *[Arayüz Tasarımı ve Entegrasyon]* (Branch: `feat/arayuz`)
* **[Ahmet Şeref Gölcük - 031890087]** - *[Veri Yapıları Geliştiricisi]* (Branch: `ahmetgolcuq`)
* **[Sadettin Şahin - 032190020]** - *[Graf Mimarı]* (Branch: `sadettinsahin`)
* **[Seymen Yiğit Ceylan - 032090022]** - *[Algoritma Geliştiricisi]* (Branch: `Algoritma/Kruskal`)

## Ortak Tartışma ve Kararlar
Proje başlangıcında ekip üyeleriyle yapılan toplantılarda aşağıdaki kararlar alınmıştır:
* PCB üzerindeki bileşenler arası rotaları optimize etmek için Minimum Spanning Tree (MST) algoritmalarından Kruskal Algoritması'nın kullanılmasına karar verilmiştir.
* Kruskal algoritmasında döngü oluşumunu engellemek için Union-Find veri yapısı sıfırdan implemente edilecektir.
* Projenin kodlama dili C++ olarak belirlenmiş olup, modüler bir Header (.h) yapısı kurulmuştur.

## 30/04/26 Tarihine Kadar Yapılan Çalışmalar (Branch Bazlı Durum)
* **`main`:** Proje iskeleti oluşturuldu, boş header dosyaları eklendi ve tüm ekip üyeleri kendi dallarına ayrıldı.

## Pull Request Öncesi Tamamlananlar

# Graph Modülü (Graph.h)

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


# Veri Yapıları Modülü (DataStructures.h)

Projenin temel yapı taşlarını oluşturan, algoritmaların ve graf modelinin ihtiyaç duyduğu özel veri yapılarının tanımlandığı ve optimize edildiği modüldür. Bellek yönetimini minimumda tutmak ve arama/birleştirme işlemlerini en yüksek hızda gerçekleştirmek amacıyla, C++ standart kütüphanelerine ek olarak projeye özgü performans odaklı yapılar tasarlanmıştır. Özellikle graf üzerinde döngü kontrolünün anlık olarak yapılabilmesi bu modüldeki yapı sayesindedir.

## Yapılan Çalışmalar
- Kruskal algoritmasının çevrim kontrolünü asgari zaman karmaşıklığıyla çözebilmesi için Union Find veri yapısı sıfırdan kodlanmıştır.
- Küme birleştirme ve temsilci bulma işlemlerini optimize etmek adına Path Compression ve Union by Rank teknikleri entegre edilmiştir.
- Graf üzerindeki kenarların maliyetlerine veya mesafelerine göre hızlıca sıralanabilmesi için uygun veri yapıları ve veri modelleri tanımlanmıştır.


# Algoritma Modülü (Algorithms.h)

Projenin mantıksal işleyişini ve problem çözme yeteneğini barındıran çekirdek modüldür. Graf üzerindeki tüm düğümlerin en düşük maliyetle ve en kısa hat uzunluğuyla birbirine bağlanması problemi bu katmanda çözülür. Arayüzden bağımsız çalışan bu modül, tamamen matematiksel doğruluğa ve optimizasyona odaklanır.

## Yapılan Çalışmalar
- Graf üzerindeki Minimum Yayılan Ağacı (MST) hesaplayarak en optimize dağıtım ağını bulmayı sağlayan Kruskal Algoritması başarılı bir şekilde implemente edilmiştir.
- Graf matrisinden veya komşuluk listesinden gelen verilerin algoritma tarafından doğru okunabilmesi için veri dönüştürme mantığı kurulmuştur.
- Kenarların ağırlıklarına göre (küçükten büyüğe) sıralanması algoritmanın giriş aşamasına entegre edilmiştir.
- Algoritmanın zaman karmaşıklığı O(ElogE) seviyesinde tutularak, ekrana çok sayıda düğüm eklendiğinde bile uygulamanın donmadan, gerçek zamanlı hesaplama yapması garanti altına alınmıştır.


# Ana Kontrol ve Arayüz Modülü (main.cpp)

Kullanıcının grafı görsel olarak görebildiği, dinamik olarak yeni düğümler ekleyip silebildiği ve arka plandaki algoritmaların sonuçlarını canlı olarak izleyebildiği arayüz ve yönetim merkezidir. Projenin yaşam döngüsünü kontrol eder. Graph.h, DataStructures.h ve Algorithms.h modüllerini bir araya getirerek aralarındaki senkronizasyonu ve kullanıcı etkileşimini yönetir.

## Yapılan Çalışmalar
- Raylib grafik kütüphanesi entegrasyonu gerçekleştirilerek projenin pencere yönetimi, yenilenme hızı (FPS) ve grafik motoru ayarları yapılmıştır.
- Kullanıcının ekrana fare ile tıklayarak dinamik olarak düğüm yerleştirmesi, düğümleri seçmesi ve aralarında kenar oluşturması için etkileşim mekanizması kodlanmıştır.
- Arka plandaki Algorithms.h modülünden dönen Minimum Yayılan Ağaç (MST) sonuçlarının, ekranda gerçek zamanlı ve estetik bir şekilde (belirlenen renk ve kalınlıkta çizgilerle) çizilmesi sağlanmıştır.
