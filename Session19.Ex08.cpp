#include <stdio.h>
#include <string.h>

struct sinhvien {
    int id;
    char name[50];
    int age;
    char phoneNumber[50];
};

void sapXepSinhVien(struct sinhvien arr[], int n) {
    struct sinhvien temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].name, arr[j + 1].name) > 0) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void inDanhSachSinhVien(struct sinhvien arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Sinh vien %d:\n", arr[i].id);
        printf("  Ten: %s\n", arr[i].name);
        printf("  Tuoi: %d\n", arr[i].age);
        printf("  So dien thoai: %s\n\n", arr[i].phoneNumber);
    }
}

int main() {
    struct sinhvien sinhvienkhachsan[5] = {
        {1, "Vi Trung Quy", 21, "033999555"},
        {2, "Nguyen Van An", 20, "033999556"},
        {3, "Tran Thi Hoa", 22, "033999557"},
        {4, "Le Hoang Nam", 19, "033999558"},
        {5, "Pham Minh Tuan", 23, "033999559"}
    };

    printf("Danh sach sinh vien truoc khi sap xep:\n");
    inDanhSachSinhVien(sinhvienkhachsan, 5);

    sapXepSinhVien(sinhvienkhachsan, 5);

    printf("Danh sach sinh vien sau khi sap xep theo ten:\n");
    inDanhSachSinhVien(sinhvienkhachsan, 5);

    return 0;
}

