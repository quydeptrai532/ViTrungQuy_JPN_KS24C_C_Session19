#include <stdio.h>
#include <string.h>

#define MAX 100

struct sinhvien {
    int id;
    char name[50];
    int age;
    char phoneNumber[50];
};

int soLuongSinhVien = 0;
struct sinhvien danhSach[MAX];

void hienThiDanhSach();
void themSinhVien();
void suaSinhVien();
void xoaSinhVien();
void timKiemSinhVien();
void sapXepSinhVien();

int main() {
    int luaChon;
    do {
        printf("\nMENU\n");
        printf("1. Hien thi danh sach sinh vien\n");
        printf("2. Them sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Xoa sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach sinh vien\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                hienThiDanhSach();
                break;
            case 2:
                themSinhVien();
                break;
            case 3:
                suaSinhVien();
                break;
            case 4:
                xoaSinhVien();
                break;
            case 5:
                timKiemSinhVien();
                break;
            case 6:
                sapXepSinhVien();
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 7);

    return 0;
}

void hienThiDanhSach() {
    if (soLuongSinhVien == 0) {
        printf("Danh sach sinh vien rong.\n");
        return;
    }
    for (int i = 0; i < soLuongSinhVien; i++) {
        printf("Sinh vien %d:\n", danhSach[i].id);
        printf("  Ten: %s\n", danhSach[i].name);
        printf("  Tuoi: %d\n", danhSach[i].age);
        printf("  So dien thoai: %s\n\n", danhSach[i].phoneNumber);
    }
}

void themSinhVien() {
    if (soLuongSinhVien >= MAX) {
        printf("Khong the them sinh vien vi danh sach day.\n");
        return;
    }
    struct sinhvien sv;
    printf("Nhap id: ");
    scanf("%d", &sv.id);
    getchar();
    printf("Nhap ten: ");
    fgets(sv.name, sizeof(sv.name), stdin);
    sv.name[strcspn(sv.name, "\n")] = 0;
    printf("Nhap tuoi: ");
    scanf("%d", &sv.age);
    getchar();
    printf("Nhap so dien thoai: ");
    fgets(sv.phoneNumber, sizeof(sv.phoneNumber), stdin);
    sv.phoneNumber[strcspn(sv.phoneNumber, "\n")] = 0;

    danhSach[soLuongSinhVien++] = sv;
    printf("Da them sinh vien thanh cong!\n");
}

void suaSinhVien() {
    int id, found = 0;
    printf("Nhap id sinh vien muon sua: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < soLuongSinhVien; i++) {
        if (danhSach[i].id == id) {
            found = 1;
            printf("Sua thong tin sinh vien co id = %d:\n", id);
            printf("Nhap ten moi: ");
            fgets(danhSach[i].name, sizeof(danhSach[i].name), stdin);
            danhSach[i].name[strcspn(danhSach[i].name, "\n")] = 0;
            printf("Nhap tuoi moi: ");
            scanf("%d", &danhSach[i].age);
            getchar();
            printf("Nhap so dien thoai moi: ");
            fgets(danhSach[i].phoneNumber, sizeof(danhSach[i].phoneNumber), stdin);
            danhSach[i].phoneNumber[strcspn(danhSach[i].phoneNumber, "\n")] = 0;
            printf("Da sua thong tin thanh cong!\n");
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien voi id = %d\n", id);
    }
}

void xoaSinhVien() {
    int id, found = 0;
    printf("Nhap id sinh vien muon xoa: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < soLuongSinhVien; i++) {
        if (danhSach[i].id == id) {
            found = 1;
            for (int j = i; j < soLuongSinhVien - 1; j++) {
                danhSach[j] = danhSach[j + 1];
            }
            soLuongSinhVien--;
            printf("Da xoa sinh vien thanh cong!\n");
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien voi id = %d\n", id);
    }
}

void timKiemSinhVien() {
    char ten[50];
    int found = 0;
    printf("Nhap ten sinh vien can tim: ");
    getchar();
    fgets(ten, sizeof(ten), stdin);
    ten[strcspn(ten, "\n")] = 0;

    for (int i = 0; i < soLuongSinhVien; i++) {
        if (strstr(danhSach[i].name, ten) != NULL) {
            found = 1;
            printf("Sinh vien %d:\n", danhSach[i].id);
            printf("  Ten: %s\n", danhSach[i].name);
            printf("  Tuoi: %d\n", danhSach[i].age);
            printf("  So dien thoai: %s\n\n", danhSach[i].phoneNumber);
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien voi ten \"%s\"\n", ten);
    }
}

void sapXepSinhVien() {
    struct sinhvien temp;
    for (int i = 0; i < soLuongSinhVien - 1; i++) {
        for (int j = 0; j < soLuongSinhVien - i - 1; j++) {
            if (strcmp(danhSach[j].name, danhSach[j + 1].name) > 0) {
                temp = danhSach[j];
                danhSach[j] = danhSach[j + 1];
                danhSach[j + 1] = temp;
            }
        }
    }
    printf("Da sap xep danh sach sinh vien theo ten!\n");
}

