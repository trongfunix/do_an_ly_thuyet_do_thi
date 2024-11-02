#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "thuat_toan_hamilton.h"
#include "read_file.h"
#include <ctype.h>

int main() {

    // file .txt can xet
    char filename[] = "playground_example.txt";
    int n;
    int maTranKe[100][100];

    // doc file danh sach ke va chuyen doi thanh ma tran ke
    docFileVaChuyenMaTranKe(filename, maTranKe, &n);

    // In ma tran ke
    inMaTranKe(maTranKe, n);

    /*
    * doan code chay cau 5 va 6 (tim lo trinh hamilton)
    */ 
    printf("---Cau 5 va 6 la bai toan tim lo trinh Hamilton---\n");
    printf("---------Chay giai thuat Hamilton-----------\n");

    //Khoi tao va cho nguoi dung nhap dinh xuat phat. Vd: A = 0, B = 1 ... 

    char kyTuDinhXuatPhat;
    int dinhXuatPhat;

    printf("Nhap vao dinh xuat phat: ");
    scanf("%c", &kyTuDinhXuatPhat);

    // chuyen chu thuong thanh chu hoa 
    kyTuDinhXuatPhat = toupper(kyTuDinhXuatPhat);

    dinhXuatPhat = kyTuDinhXuatPhat - 'A';
    // Chay giai thuat hamilton
    chayHamilton(maTranKe, n, dinhXuatPhat);

    return 0;
}
