#include <stdio.h>
#include <stdlib.h>

int visited[100];
int path[100];

// Ham in ra lo trinh
void inLoTrinh(int pathLength) {
    printf("Cau 6:\n");

    for (int i = 0; i < pathLength; i++) {
        // Chuyen so thanh ky tu A, B, C, D ...
        printf("%c ", 'A' + path[i]);
        if (i < pathLength - 1)
        {
            printf("-> ");
        }
    }
    printf("\n");
}

// thuat toan tim chu trinh hamilton
int chuTrinhHamilton(int maTranKe[100][100], int pos, int start, int MAX) {
    
    if (pos == MAX) {
        if (maTranKe[path[pos - 1]][start] != 0) { 
            path[pos] = start; 
            return 2; 
        }
        else {
            return 1; 
        }
    }

    
    for (int v = 0; v < MAX; v++) {
        
        if (!visited[v] && maTranKe[path[pos - 1]][v] != 0) {
            path[pos] = v;
            visited[v] = 1;

            int result = chuTrinhHamilton(maTranKe, pos + 1, start, MAX);
            if (result == 2) return 2; 

            visited[v] = 0; 
        }
    }

    return 0; 
}

// chay thuat toan tim ra chu trinh hamilton va in ra ket qua
int chayHamilton(int maTranKe[100][100], int MAX, int dinhXuatPhat) {
    // Dinh D la diem xuat phat (voi dinhXuatPhat = 3)
    int start = dinhXuatPhat;

    for (int i = 0; i < MAX; i++)
    {
        visited[i] = 0;
    }
    path[0] = start;
    visited[start] = 1;

    int result = chuTrinhHamilton(maTranKe, 1, start, MAX);

    // In ra ket qua
    if (result == 2) {
        printf("Cau 5: \nKet qua: 2 (Ton tai chu trinh Hamilton quay lai dinh xuat phat)\n");
        inLoTrinh(MAX + 1);
    }
    else if (result == 1) {
        printf("Cau 5: \nKet qua: 1 (Ton tai duong di Hamilton khong quay lai dinh xuat phat)\n");
        inLoTrinh(MAX);
    }
    else {
        printf("Cau 5: \nKet qua: 0 (Khong ton tai lo trinh Hamilton nao)\n");
    }

    return 0;
}
