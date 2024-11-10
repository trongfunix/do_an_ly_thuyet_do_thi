#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "thuat_toan_hamilton.h"
#include "read_file.h"
#include <ctype.h>

/*

int main() {

    // file .txt can xet
    char filename[] = "playground_example.txt";
    int n;
    int maTranKe[100][100];

    // doc file danh sach ke va chuyen doi thanh ma tran ke
    docFileVaChuyenMaTranKe(filename, maTranKe, &n);

    // In ma tran ke
    inMaTranKe(maTranKe, n);

    // doan code chay cau 5 va 6 (tim lo trinh hamilton)

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
*/

/*
* Phần code giải thuật euler - câu 3, 4
*/
#define NUM_OF_ROOMS 4
#define MAX_VERTICES 25
int check_euler_circuit(int adj_list[][NUM_OF_ROOMS], int n) {
    for (int i = 0; i < n; i++) {
        int row_sum = 0;
        for (int j = 0; j < n; j++) {
            row_sum += adj_list[i][j];
        }
        if (row_sum % 2 != 0) {
            return 0;
        }
    }
    return 2;
}


int check_euler_path_from_garden(int adj_list[][NUM_OF_ROOMS], int n) {
    int odd_count = 0;

    int first_row_sum = 0;
    for (int j = 0; j < n; j++) {
        first_row_sum += adj_list[0][j];
    }

    if (first_row_sum % 2 != 1) {
        return 0;
    }

    for (int i = 1; i < n; i++) {
        int row_sum = 0;
        for (int j = 0; j < n; j++) {
            row_sum += adj_list[i][j];
        }
        if (row_sum % 2 != 0) {
            odd_count++;
        }
    }

    return (odd_count == 1) ? 1 : 0;
}

void traverse_rooms(int adj_list[][NUM_OF_ROOMS]) {
    printf("%c -> ", 'A' - 1 + NUM_OF_ROOMS);


    int current_line = 0;

    while (1) {
        int found = 0;


        for (int j = 0; j < NUM_OF_ROOMS; j++) {
            if (adj_list[current_line][j] > 0) {
                // Nếu tìm thấy kết nối
                if (j != 0) {
                    printf("%c -> ", j + 'A' - 1);
                }
                else {
                    printf("%c -> ", j + 'A' - 1 + NUM_OF_ROOMS);
                }
                adj_list[current_line][j]--;
                adj_list[j][current_line]--;

                current_line = j;
                found = 1;
                break;
            }
        }


        if (!found) {
            printf("end\n");
            break;
        }
    }
}

//node is sum of nodes. For example, if there are A, B, C, D nodes, then node = 4
//start node is count from 0, with above example, start_node = 3 which is D
void convert_list_to_matrix(int adj[][NUM_OF_ROOMS], int adj_list[][MAX_VERTICES], int node, int start_node) {
    if (start_node >= node || start_node < 0) {
        //woah, we cannot convert if start node is greater than node
        return;
    }

    // Khởi tạo ma trận kề với 0
    for (int i = 0; i < node; i++) {
        for (int j = 0; j < node; j++) {
            adj[i][j] = 0;
        }
    }

    // start with start node in adj[0], i==0
    for (int j = 0; adj_list[start_node][j] != 0; j++) {
        int vertex = adj_list[start_node][j];
        adj[0][vertex - 1]++; // Tăng số lần kết nối
        if (adj_list[start_node][j + 1] < 0) {
            break;
        }
    }

    // Chuyển đổi danh sách kề thành ma trận kề
    int index = 1; //index for adj[][] 
    for (int i = 0; i < node; i++) {
        //start at i == 1 
        if (i == start_node) {
            //skip start node
            continue;
        }
        else {
            for (int j = 0; adj_list[i][j] != 0; j++) {
                int vertex = adj_list[i][j];
                adj[index][vertex - 1]++; // Tăng số lần kết nối
                if (adj_list[i][j + 1] < 0) {
                    break;
                }
            }
            index++;
        }
    }
}
void read_graph_from_file(const char* filename, int* n, int adj_list[MAX_VERTICES][MAX_VERTICES]) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Không thể mở tệp %s\n", filename);
        return;
    }

    // Đọc số lượng đỉnh
    fscanf(file, "%d", n);

    // Đọc danh sách kề
    for (int i = 0; i < *n; i++) {
        int m; // Số lượng đỉnh kề
        fscanf(file, "%d", &m); // Đọc số lượng đỉnh kề

        for (int j = 0; j < m; j++) {
            int temp;
            fscanf(file, "%d", &temp); // Đọc số vào tạm
            adj_list[i][j] = temp + 1; // Cộng 1 vào số và gán vào đỉnh kề
        }
        adj_list[i][m] = -1; // Đánh dấu kết thúc danh sách kề bằng -1
    }
    // for (int i = 0; i < *n; i++) {
    //     printf("Đỉnh %d kết nối với: ", i);
    //     for (int j = 0; adj_list[i][j] != -1; j++) {
    //         printf("%d ", adj_list[i][j]);
    //     }
    //     printf("\n");
    // }

    fclose(file);
}

int main() {

    /*
    * Phần chạy giải thuật Euler - câu 3, 4
    * Code sẽ mặc định chạy với đỉnh D là đỉnh sân vườn
    */
    printf("---Cau 3 va 4 la bai toan tim lo trinh Euler---\n");
    printf("---------Chay giai thuat Euler-----------\n");

    char fileNameEuler[] = "input_euler.txt";
    char kyTuDinhXuatPhatEuler;
    int dinhXuatPhatEuler;

    printf("Nhap vao dinh xuat phat Euler: ");
    scanf("%c", &kyTuDinhXuatPhatEuler);

    // chuyen ky tu thuong thanh ky tu in hoa
    kyTuDinhXuatPhatEuler = toupper(kyTuDinhXuatPhatEuler);

    dinhXuatPhatEuler = kyTuDinhXuatPhatEuler - 'A';

    int start_node = dinhXuatPhatEuler; // D has index 3
    int node; // Số lượng đỉnh
    int adj_list[MAX_VERTICES][MAX_VERTICES]; // Danh sách kề
    int adj_matrix[NUM_OF_ROOMS][NUM_OF_ROOMS]; // Ma trận kề
    read_graph_from_file(fileNameEuler, &node, adj_list);

    convert_list_to_matrix(adj_matrix, adj_list, node, start_node);

    int result = check_euler_circuit(adj_matrix, NUM_OF_ROOMS);
    if (result == 0) {
        result = check_euler_path_from_garden(adj_matrix, NUM_OF_ROOMS);
    }
    printf("Result for 3) :%d\n", result);
    if (result != 0) {
        printf("Result for 4): ");
        traverse_rooms(adj_matrix);
    }
    else {
        printf("No Euler path/cycle\n");
    }

    /*
    * Phần chạy giải thuật Hamilton - câu 5, 6
    * Code sẽ cần nhập đỉnh vào để chạy, (nhập đỉnh D là đỉnh sân vườn)
    */

    int n;
    int maTranKe[100][100];
    char fileNameHamilton[] = "input_hamilton.txt";

    // doc file danh sach ke va chuyen doi thanh ma tran ke
    docFileVaChuyenMaTranKe(fileNameHamilton, maTranKe, &n);

    // doan code chay cau 5 va 6 (tim lo trinh hamilton)
    printf("\n");
    printf("---Cau 5 va 6 la bai toan tim lo trinh Hamilton---\n");
    printf("---------Chay giai thuat Hamilton-----------\n");
    
    char kyTuDinhXuatPhatHamilton;
    int dinhXuatPhatHamilton;

    printf("Nhap vao dinh xuat phat: ");
    scanf(" %c", &kyTuDinhXuatPhatHamilton);

    // chuyen ky tu thuong thanh ky tu in hoa
    kyTuDinhXuatPhatHamilton = toupper(kyTuDinhXuatPhatHamilton);

    dinhXuatPhatHamilton = kyTuDinhXuatPhatHamilton - 'A';
    printf("Chi so dinhXuatPhat : %d\n", dinhXuatPhatHamilton);

    // Chay giai thuat hamilton
    chayHamilton(maTranKe, n, dinhXuatPhatHamilton);

    return 0;
}

