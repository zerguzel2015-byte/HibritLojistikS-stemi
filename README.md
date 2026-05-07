# 🚚 Lojistik Hibrit Veri Yapıları Sistemi

Bu proje, Veri Yapıları ve Algoritmalar dersi kapsamında geliştirilmiş, bir lojistik/kargo firmasının şehirler arası bağlantılarını ve paket indeksleme işlemlerini aynı anda yöneten **hibrit bir sistemdir**. Projede C programlama dili (C89 standartları) kullanılmış olup, modüler dosya mimarisi uygulanmıştır.

## 🎯 Proje Özellikleri

- **Hızlı Paket Sorgulama (Hash Tablosu):** Kargo paketlerinin ID bazlı anlık sorgulanması için O(1) maliyetine yaklaşan indeksleme sistemi.
- **Rota Yönetimi (Graf):** Şehirler (düğümler) ve aralarındaki teslimat rotalarının (kenarlar) Adjacency List (Komşuluk Listesi) ile modellenmesi.
- **Dinamik Bellek İzleme (Memory Monitor):** Sistemin çalışma zamanında (runtime) aldığı RAM adreslerini (0x...) ve işaretçi (pointer) bağlantılarını konsol üzerinde gösteren entegre raporlama aracı.

## ⚙️ Teknik Parametreler ve Algoritmalar

Bu proje, spesifik gereksinimlere göre (Öğrenci ID kısıtlamaları) aşağıdaki algoritmalar kullanılarak inşa edilmiştir:

* **Hash Fonksiyonu:** Tip A (Division Method / Modüler Aritmetik)
* **Çakışma (Collision) Yönetimi:** Açık Adresleme (Linear Probing)
* **Graf Gezinme Algoritması:** DFS (Depth-First Search / Derinlemesine Arama)

## 📁 Dosya Mimarisi

Proje, mantıksal katmanlarına göre ayrılmış çoklu dosya (multi-file) yapısındadır:

```text
📦 LojistikProjesi
 ┣ 📜 types.h    # Graf ve Hash tablolarının ortak struct tanımları
 ┣ 📜 hash.h     # Hash tablosu fonksiyon prototipleri
 ┣ 📜 hash.c     # Hash algoritmaları ve çakışma yönetimi
 ┣ 📜 graph.h    # Graf yapısı fonksiyon prototipleri
 ┣ 📜 graph.c    # Düğüm, kenar ekleme ve DFS gezinme işlemleri
 ┗ 📜 main.c     # Test senaryoları ve bellek izleme raporu motoru
