#include <stdio.h>
#include <math.h>

int main(void) {
    float urun_tutari, odenen_para;

    // 1. Ürün tutarýný ve ödenen parayý float olarak al
    printf("Urun tutarini giriniz (TL): ");
    scanf("%f", &urun_tutari);

    printf("Odenen parayi giriniz (TL): ");
    scanf("%f", &odenen_para);

    // 2. Rapor bölümü: Yuvarlama yapmadan kuruþa çevir
    int yuvarlamasiz_kurus = (int)((odenen_para - urun_tutari) * 100);

    printf("\n--- RAPOR / YUVARLAMASIZ HESAPLAMA ---\n");
    printf("Yuvarlamasiz hesaplanan para ustu: %d kurus\n", yuvarlamasiz_kurus);
    printf("Aciklama: Float veri tipinin ikili (binary) kayan nokta hassasiyeti (IEEE 754)\n");
    printf("nedeniyle bazi sayilar bellekte tam tutulamadigi icin sonuc hatali cikabilmektedir.\n");

    // 3. Doðru yöntem: round() fonksiyonu ile en yakýn tam kuruþa yuvarla
    int toplam_kurus = (int)round((odenen_para - urun_tutari) * 100.0);

    printf("\n--- DOGRU PARA USTU HESAPLAMASI ---\n");
    printf("Toplam para ustu: %d TL %d kurus (Toplam %d kurus)\n\n",
           toplam_kurus / 100, toplam_kurus % 100, toplam_kurus);

    // 4. Küpürleri sýrayla, koþulsuz ve döngüsüz hesapla
    int adet200 = toplam_kurus / 20000; toplam_kurus %= 20000;
    int adet100 = toplam_kurus / 10000; toplam_kurus %= 10000;
    int adet50  = toplam_kurus / 5000;  toplam_kurus %= 5000;
    int adet20  = toplam_kurus / 2000;  toplam_kurus %= 2000;
    int adet10  = toplam_kurus / 1000;  toplam_kurus %= 1000;
    int adet5   = toplam_kurus / 500;   toplam_kurus %= 500;
    int adet1   = toplam_kurus / 100;   toplam_kurus %= 100;

    int adet50k = toplam_kurus / 50;    toplam_kurus %= 50;
    int adet25k = toplam_kurus / 25;    toplam_kurus %= 25;
    int adet10k = toplam_kurus / 10;    toplam_kurus %= 10;
    int adet5k  = toplam_kurus / 5;     toplam_kurus %= 5;
    int adet1k  = toplam_kurus / 1;     // Son kalan doðrudan 1 kuruþtur

    // 5. Sonuçlarý ekrana bas (Koþul olmadýðý için "0 adet" olanlar da yazdýrýlýr)
    printf("%d adet 200 TL\n", adet200);
    printf("%d adet 100 TL\n", adet100);
    printf("%d adet 50 TL\n", adet50);
    printf("%d adet 20 TL\n", adet20);
    printf("%d adet 10 TL\n", adet10);
    printf("%d adet 5 TL\n", adet5);
    printf("%d adet 1 TL\n", adet1);
    printf("%d adet 50 kurus\n", adet50k);
    printf("%d adet 25 kurus\n", adet25k);
    printf("%d adet 10 kurus\n", adet10k);
    printf("%d adet 5 kurus\n", adet5k);
    printf("%d adet 1 kurus\n", adet1k);

    // 6. Toplam küpür adedini hesapla ve yazdýr
    int toplam_kupur_adedi = adet200 + adet100 + adet50 + adet20 + adet10 + adet5 + adet1 +
                             adet50k + adet25k + adet10k + adet5k + adet1k;

    printf("\nMusteriye verilen toplam kupur adedi: %d\n", toplam_kupur_adedi);

    return 0;
}
