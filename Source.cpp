#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "thuat_toan_hamilton.h"
#include "playground.h"

int main() {

    // file .txt can xet
    char filename[] = "playground_example.txt";

    // test chuyen tu danh sach ke sang ma tran ke
    int n = soLuongDinhTuFile(filename);
    int maTranKe[26][26];
    printf("So dinh trong do thi: %d\n", n);

    // khoi tao ma tran ke
    khoiTaoMaTranKe(maTranKe, n);

    // doc file danh sach ke va chuyen doi thanh ma tran ke
    docFile(filename, maTranKe, n);

    // In ma tran ke
    printf("Ma tran ke cua do thi:\n");
    inRaMaTranKe(maTranKe, n);

    /*
    * doan code chay cau 5 va 6 (tim lo trinh hamilton)
    */ 
    printf("---Cau 5 va 6 la bai toan tim lo trinh Hamilton---\n");
    printf("---------Chay giai thuat Hamilton-----------\n");

    //Khoi tao va cho nguoi dung nhap dinh xuat phat. Vd: A = 0, B = 1 ... 
    int dinhXuatPhat;
    printf("Nhap vao dinh xuat phat: ");
    scanf("%d", &dinhXuatPhat);
    chayHamilton(maTranKe, n, dinhXuatPhat);

    return 0;
}
