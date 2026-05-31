# YZM104 (Programlama II) Dersi Dönem Projesi

![C++ 17](https://img.shields.io/badge/Language-C++17-D6A2E8)
![SFML 2.6.1](https://img.shields.io/badge/Libraries-SFML--2.6.1-B19FFB)
![CMake](https://img.shields.io/badge/Build-CMake-C3B1E1)

# Oyun Projesi: Tetris

Bu projede, Programlama II dersi kapsamında dönem projesi olarak klasik tetris oyunu C++ programlama dili ve SFML kütüphanesi kullanılarak geliştirilmiştir. Proje, temelde 20 satır 15 sütundan oluşan bir oyun alanı üzerinde, 7 adet tetrominonun 4 farklı rotasyonda oluşturulması ile tasarlanmıştır. Rastgele oluşturulan blokların ızgara yüzeyindeki izdüşümlerini gösteren hayalet parça (ghost piece), sıradaki blok önizlemesi, satır silme efekti, dinamik rekor sistemi, skor ve level modülleri  gibi özellikler de ilave olarak dahil edilmiştir. Proje, işitsel ve görsel efektler ile desteklenmiş olup oyunu duraklatma ve yeniden başlatma seçenekleriyle zenginleştirilmiştir.

---

## 🎮 Kontroller 

Oyunu oynamak ve kontrol etmek için aşağıdaki klavye kısayolları tanımlanmıştır:

* **Sol Yön Tuşu:** Bloğu yatay eksende sola bir birim hareket ettirir.
* **Sağ Yön Tuşu:** Bloğu yatay eksende sağa bir birim hareket ettirir.
* **Yukarı Yön Tuşu:** Bloğu 90 derece saat yönünde döndürür (Rotasyon Özelliği).
* **Aşağı Yön Tuşu:** Bloğu dikey eksende bir birim aşağı hareket ettirir.
* **Boşluk (Space):** Bloğu anında en alta düşürür ve kilitler.
* **P Tuşu:** Oyunu anlık olarak duraklatır / devam ettirir.
* **R Tuşu:** Oyunu tamamen sıfırlayıp yeniden başlatır.
* **ESC Tuşu:** Oyunu kapatır.

---

## 🛠️ Kurulum ve Derleme

### Gereksinimler

*   C++17 destekleyen bir derleyici (GCC/MinGW)
*   CMake (Sürüm 3.14 veya üzeri)
*   Git (FetchContent için gereklidir.)
(SFML kütüphanesi CMake FetchContent aracılığıyla projeyi çalıştırdığınızda cihazınıza otomatik indirilecektir.)


### Derleme Adımları

1. Projeyi bilgisayarınıza indirin veya klonlayın.
2. Klonladığınız dosyayı terminalde açın ve sırasıyla aşağıdaki komutları girin:
```bash
mkdir build
cd build
cmake ..
cmake --build .
```
3. Program derlendikten sonra terminalden çıkın ve klonladığınız dosyaya dönün.
4. Oluşturulan build dosyasına girin ve "tetris.exe" dosyasını çalıştırın.
5. Oyununuz oynanmaya hazır. İyi eğlenceler!

---

## 📂 Proje Dosya Yapısı

```
TetrisProjesi/
├── assets/                        — Yazı tipleri ve ses dosyaları
├── src/
│   ├── main.cpp                   — Ana oyun döngüsü ve pencere yönetimi
│   ├── OyunAlani.hpp/.cpp         — Oyun alanı sınıfı
│   ├── TetrisBlokları.hpp/.cpp    — Tetromino sınıfı
│   └── BilgiAlani.hpp/.cpp        — Bilgi paneli sınıfı
├── CMakeLists.txt                 — Yapılandırma dosyası
└── README.md                      — Açıklama dosyası
```

---

