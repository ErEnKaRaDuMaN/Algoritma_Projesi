    #include <stdio.h>
    #include <string.h>



    struct Dosya {
        FILE *kaynak;   // Okunacak kaynak dosya pointer'ı
        FILE *yedek;    // Oluşturulacak yedek dosya pointer'ı
        char kaynakAd[100];
        char yedekAd[120];
    };

    int main() {
        struct Dosya d;
        char satir[256];

        // Dosya adını alma
        printf("Yedegi alinacak C dosyasinin adini giriniz: ");
        scanf("%s", d.kaynakAd);

        // Yedek dosya oluşturma (.YED ekle)
        strcpy(d.yedekAd, d.kaynakAd);
        strcat(d.yedekAd, ".YED");

        // Kaynak dosyayı açma
        d.kaynak = fopen(d.kaynakAd, "r");
        if (d.kaynak == NULL) {
            printf("Kaynak dosya acilamadi!\n");
            return 1;
        }

        // yedekleme
        d.yedek = fopen(d.yedekAd, "w");
        if (d.yedek == NULL) {
            printf("Yedek dosya olusturulamadi!\n");
            fclose(d.kaynak);
            return 1;
        }

        // kopyalayan kısım
        while (fgets(satir, sizeof(satir), d.kaynak) != NULL) {
            fputs(satir, d.yedek);
        }

        // kapatan ksım
        fclose(d.kaynak);
        fclose(d.yedek);

        printf("Yedekleme basariyla tamamlandi: %s\n", d.yedekAd);

        return 0;
    }
