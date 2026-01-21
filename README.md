*This project has been created as part of the 42 curriculum by ykpgunduz.*

# push_swap

## Açıklama

**push_swap**, iki stack kullanarak verilen sayı dizisini en az hamle ile sıralayan bir algoritmik projedir. Proje, belirli operasyonlar kullanarak Stack A'daki elemanları sıralamayı hedefler.

Bu proje kapsamında şu konular ele alınmıştır:
- Veri yapıları (stack list ve node implementasyonu)
- Sıralama algoritmaları (radix sort ve optimize edilmiş küçük sayı sıralamaları)
- Algoritma optimizasyonu ve hamle sayısı minimizasyonu
- C dilinde bellek yönetimi ve hata kontrolü

Projede kullanılan **libft** kütüphanesi daha önceki 42 projelerinde tarafımdan geliştirilmiştir.

## Kullanım Talimatları

### Derleme

```bash
make
```

### Çalıştırma

```bash
./push_swap 2 1 3
./push_swap "5 4 3 2 1"
./push_swap 42 8 15 16 23 4
```

Program, verilen sayıları sıralamak için gerekli operasyonları standart çıktıya yazdırır.

### İzin Verilen Operasyonlar

- **sa/sb/ss**: İlk iki elemanın yerini değiştir (swap)
- **pa/pb**: Bir stack'ten diğerine eleman taşı (push)
- **ra/rb/rr**: Stack'i yukarı doğru kaydır (rotate)
- **rra/rrb/rrr**: Stack'i aşağı doğru kaydır (reverse rotate)

### Proje Yapısı

```
push_swap/
├── push_swap.h          # Ana header dosyası
├── src/
│   ├── core/            # Temel veri yapısı işlemleri (deque)
│   ├── ops/             # Stack operasyonları
│   ├── algorithm/       # Sıralama algoritmaları
│   ├── parser/          # Girdi işleme ve doğrulama
│   └── main.c
└── libft/               # Libft kütüphanesi
```

### Temizleme

```bash
make clean   # Nesne dosyalarını kaldırır
make fclean  # Tüm derleme çıktılarını kaldırır
make re      # Yeniden derler
```

## Kaynaklar

### Dokümantasyon
- [push_swap Proje Konusu (42 İntra)](https://cdn.intra.42.fr/pdf/pdf/192991/en.subject.pdf)
- [Radix Sort Algoritması](https://en.wikipedia.org/wiki/Radix_sort)
- [Stack Veri Yapısı](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))
- [Algorithm Visualizer - Push Swap](https://push-swap-visualizer.vercel.app/)

### AI Kullanımı

Proje geliştirilirken AI araçları aşağıdaki alanlarda yardımcı araç olarak kullanılmıştır:
- Hata ayıklama ve bellek sızıntısı tespiti
- Kod optimizasyonu önerileri
- README dosyasının hazırlanması

Tüm temel mantık, algoritmalar ve sıralama mekanikleri tamamen tarafımdan geliştirilmiştir.
