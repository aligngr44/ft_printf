*This project has been created as part of the 42 curriculum by algungor.*
## Description
ft_printf, C dilindeki standart printf fonksiyonunun yeniden implementasyonudur.
Bu proje, variadic fonksiyonlar, format specifier mantığı, hexadecimal dönüşüm, pointer gösterimi ve output kontrolü gibi düşük seviye C konularını derinlemesine anlamayı amaçlar.

Proje kapsamında aşağıdaki formatlar desteklenmektedir:
```
%c → karakter

%s → string

%p → pointer adresi

%d / %i → decimal integer

%u → unsigned integer

%x / %X → hexadecimal integer

%% → yüzde karakteri
```
Fonksiyon, yazdırılan toplam karakter sayısını int olarak döndürür.
## Instructions
#### Compilation
```
make
```
Bu komut libftprintf.a statik kütüphanesini oluşturur.
#### Clean
```
make clean
```
Object dosyalarını siler.
```
make fclean
```
Object dosyaları ve kütüphaneyi siler.
### 🛠 Usage Example
```
#include "ft_printf.h"

int main()
{
    ft_printf("Merhaba %s\n", "Dünya");
    return (0);
}
```
Derlemek için:
```
cc main.c libftprintf.a
```
## Resources
man printf ve man stdarg

C dilinde variadic fonksiyonlar üzerine teknik dokümanlar

Hexadecimal sayı sistemi hakkında akademik ve teknik kaynaklar

Pointer ve bellek yapısı üzerine makaleler

YouTube üzerinde C programlama ve printf implementasyonu üzerine eğitim videoları
## AI Usage

Proje geliştirme sürecinde yapay zekâ araçlarından kod üretimi yapılmadan yararlanılmıştır.

Yapay zekâ şu amaçlarla kullanılmıştır:

Kavramsal konuları daha iyi anlamak

Hata mesajlarını yorumlamak

Dokümantasyon ve README hazırlamak

Öğrenme sürecini destekleyici açıklamalar almak

Tüm kod yazımı ve algoritma tasarımı manuel olarak gerçekleştirilmiştir.