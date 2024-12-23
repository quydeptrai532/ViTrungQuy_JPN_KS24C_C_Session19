#include <stdio.h>

struct sinhvien {
    int id;
    char name[50];
    int age;
    char phoneNumber[50];
};

struct sinhvien sinhvienkhachsan[5] = {
    {1, "Vi Trung Quy", 4, "033999555"},
    {2, "Vi Trung Hieu", 5, "033999556"},
    {3, "Vi Trung Chien", 6, "033999557"},
    {4, "Vi Trung Lam", 7, "033999558"},
    {5, "Vi Trung Day", 8, "033999559"}
};

int n = 5; 

void xoaSinhvien(int id, struct sinhvien sinhvien[]) {
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (sinhvien[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf("Khong tim thay sinh vien voi id = %d\n", id);
        return;
    }

   
    for (int i = pos; i < n - 1; i++) {
        sinhvien[i] = sinhvien[i + 1];
    }

    n--; 
    printf("Da xoa sinh vien voi id = %d\n", id);
}

int main() {
    int id;
    printf("Nhap id sinh vien muon xoa: ");
    scanf("%d", &id);

    xoaSinhvien(id, sinhvienkhachsan);

    printf("Danh sach sinh vien sau khi xoa:\n");
    for (int i = 0; i < n; i++) {
        printf("Sinh vien %d:\n", sinhvienkhachsan[i].id);
        printf("  Ten: %s\n", sinhvienkhachsan[i].name);
        printf("  Tuoi: %d\n", sinhvienkhachsan[i].age);
        printf("  So dien thoai: %s\n\n", sinhvienkhachsan[i].phoneNumber);
    }

    return 0;
}

