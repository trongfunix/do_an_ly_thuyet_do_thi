#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// Ham doc file va chuyen thanh ma tran ke 
void docFileVaChuyenMaTranKe(const char* filename, int maTranKe[100][100], int* n) {
    
    FILE* file = fopen(filename, "r");

    // Kiem tra co mo duoc file hay khong
    if (file == NULL) {
        printf("Khong the mo file, hay kiem tra lai ten file!\n");
        exit(1);
    }

    // Doc so dinh
    fscanf(file, "%d", n);

    // Khoi tao ma tran ke rong
    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *n; j++) {
            maTranKe[i][j] = 0;
        }
    }

    // Doc nhung dong con lai và chuyen doi thanh ma tran ke
    for (int i = 0; i < *n; i++) {
        int num_neighbors;

        // Doc so luong canh ke cua dinh i
        fscanf(file, "%d", &num_neighbors); 

        for (int j = 0; j < num_neighbors; j++) {
            int neighbor;
            // doc cac so còn lai (bieu thi chi muc cua dinh ke)
            fscanf(file, "%d", &neighbor); 

            // tang gia tri tai vi tri (i, neighbor) de bieu thi so canh
            maTranKe[i][neighbor]++;
        }
    }

    fclose(file);
}

// ham hien thi ma tran ke
void inMaTranKe(int maTranKe[100][100], int n) {
    printf("Ma tran ke:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", maTranKe[i][j]);
        }
        printf("\n");
    }
}


