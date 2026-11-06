#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20

struct employee {
    char name[20];
    int code;
    char job[20];
    int exp;
    int age;
};

struct employee emp[MAX];
int num = 0;

void build() {
    int i;
    printf("\nMaksimum calisan kapasitesi: %d\n", MAX);
    printf("Lutfen olusturulacak calisan sayisini giriniz: ");
    
    if (scanf("%d", &num) != 1) {
        printf("Gecersiz giris yapildi!\n");
        while (getchar() != '\n');
        num = 0;
        return;
    }

    if (num > MAX) {
        printf("Maksimum calisan sayisini astiniz. Calisan sayisi %d olarak ayarlandi.\n", MAX);
        num = MAX;
    } else if (num < 0) {
        printf("Calisan sayisi negatif olamaz!\n");
        num = 0;
        return;
    }

    printf("\n--- Calisan Bilgilerini Giriniz ---\n");
    for (i = 0; i < num; i++) {
        printf("\n%d. Calisan:\n", i + 1);
        printf("Ad: ");
        scanf("%19s", emp[i].name);
        printf("Calisan ID: ");
        scanf("%d", &emp[i].code);
        printf("Meslek / Pozisyon: ");
        scanf("%19s", emp[i].job);
        printf("Tecrube (Yil): ");
        scanf("%d", &emp[i].exp);
        printf("Yas: ");
        scanf("%d", &emp[i].age);
    }
    printf("\nTablo basariyla olusturuldu. Toplam %d calisan kaydedildi.\n", num);
}

void insert() {
    if (num < MAX) {
        printf("\n--- Yeni Calisan Ekle ---\n");
        printf("Ad: ");
        scanf("%19s", emp[num].name);
        printf("Calisan ID: ");
        scanf("%d", &emp[num].code);
        printf("Meslek / Pozisyon: ");
        scanf("%19s", emp[num].job);
        printf("Tecrube (Yil): ");
        scanf("%d", &emp[num].exp);
        printf("Yas: ");
        scanf("%d", &emp[num].age);
        num++;
        printf("\nCalisan basariyla eklendi! Toplam calisan: %d\n", num);
    } else {
        printf("\nMaksimum calisan sayisini astiniz! Daha fazla kayit eklenemez.\n");
    }
}

void deleteEmployee() {
    int code, i, j;
    int found = 0;

    if (num == 0) {
        printf("\nSistemde silinecek calisan kaydi bulunmamaktadir.\n");
        return;
    }

    printf("\nSilmek istediginiz calisanin ID numarasini giriniz: ");
    scanf("%d", &code);

    for (i = 0; i < num; i++) {
        if (emp[i].code == code) {
            found = 1;
            for (j = i; j < num - 1; j++) {
                emp[j] = emp[j + 1];
            }
            num--;
            printf("\nID: %d olan calisan basariyla silindi.\n", code);
            break;
        }
    }

    if (!found) {
        printf("\nID: %d ile eslesen calisan bulunamadi!\n", code);
    }
}

void searchEmployee() {
    int code, i;
    int found = 0;

    if (num == 0) {
        printf("\nSistemde kayitli calisan bulunmamaktadir.\n");
        return;
    }

    printf("\nBilgilerini gormek istediginiz calisanin ID numarasini giriniz: ");
    scanf("%d", &code);

    for (i = 0; i < num; i++) {
        if (emp[i].code == code) {
            found = 1;
            printf("\n========================================\n");
            printf(" Calisan ID : %d\n", emp[i].code);
            printf(" Ad         : %s\n", emp[i].name);
            printf(" Meslek     : %s\n", emp[i].job);
            printf(" Deneyim    : %d yil\n", emp[i].exp);
            printf(" Yas        : %d\n", emp[i].age);
            printf("========================================\n");
            break;
        }
    }

    if (!found) {
        printf("\nID: %d ile eslesen calisan bulunamadi!\n", code);
    }
}

void listAllEmployees() {
    int i;
    if (num == 0) {
        printf("\nSistemde gosterilecek kayitli calisan yok.\n");
        return;
    }

    printf("\n----------------------- CALISAN LISTESI -----------------------\n");
    printf("%-5s | %-15s | %-15s | %-8s | %-5s\n", "ID", "AD", "MESLEK", "TECRUBE", "YAS");
    printf("---------------------------------------------------------------\n");
    for (i = 0; i < num; i++) {
        printf("%-5d | %-15s | %-15s | %-8d | %-5d\n", 
               emp[i].code, emp[i].name, emp[i].job, emp[i].exp, emp[i].age);
    }
    printf("---------------------------------------------------------------\n");
}

int main() {
    int option;

    do {
        printf("\n==================================================\n");
        printf("           CALISAN YONETIM SISTEMI                \n");
        printf("==================================================\n");
        printf("1. Calisan tablosu olustur (Sifirlar ve Doldurur)\n");
        printf("2. Yeni calisan ekle\n");
        printf("3. Calisan sil (ID ile)\n");
        printf("4. Calisan bilgilerini getir (ID ile Ara)\n");
        printf("5. Tum calisanlari listele\n");
        printf("6. Cikis\n");
        printf("Seciminizi giriniz (1-6): ");

        if (scanf("%d", &option) != 1) {
            printf("\nGecersiz giris! Lutfen bir sayi giriniz.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (option) {
            case 1:
                build();
                break;
            case 2:
                insert();
                break;
            case 3:
                deleteEmployee();
                break;
            case 4:
                searchEmployee();
                break;
            case 5:
                listAllEmployees();
                break;
            case 6:
                printf("\nSistemden cikis yapiliyor... Iyi gunler!\n");
                break;
            default:
                printf("\nYanlis bir secim yaptiniz. Lutfen 1-6 arasinda bir deger giriniz.\n");
        }
    } while (option != 6);

    return 0;
}
