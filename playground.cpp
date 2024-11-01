#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 26

/* Ma tran ke de doi chieu voi ham doc file co ra ket qua dung hay khong
int adjacencyMatrix[MAX][MAX] = {
	{0, 1, 1, 1}, // A
	{1, 0, 1, 2}, // B
	{1, 1, 0, 2}, // C
	{1, 2, 2, 0}  // D
};
*/

// khoi tao ma tran ke
void khoiTaoMaTranKe(int maTranKe[MAX_NODES][MAX_NODES], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			maTranKe[i][j] = 0;
		}
	}
}

// Ham tim so luong dinh bang cach lay dinh lon nhat trong file
int soLuongDinhTuFile(const char* filename) {
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		printf("Khong the mo file.\n");
		return -1;
	}

	int maxNode = 0;
	char line[256];

	while (fgets(line, sizeof(line), file)) {
		printf("doc file test: %s\n", line);
		char* token = strtok(line, ": ");

		if (token != NULL) {
			int node = atoi(token);
			if (node > maxNode) maxNode = node;
		}

		token = strtok(NULL, " ");
		while (token != NULL) {
			int neighbor = atoi(token);
			if (neighbor > maxNode) maxNode = neighbor;
			token = strtok(NULL, " ");
		}
	}

	fclose(file);
	return maxNode;
}

// doc file de chuyen doi danh sach ke thanh ma tran ke
void docFile(const char* filename, int maTranKe[MAX_NODES][MAX_NODES], int n) {
	printf("--- doc file ----\n");
	
	// khoi tao bien doc file
	FILE* file;
  	
	// Mo file o che do doc
	file = fopen(filename, "r");

	// kiem tra co mo dc file hay khong
	if (file == NULL) {
		printf("Khong the mo file.\n"); 
	}

	// chuyen doi sang ma tran ke
	char line[256];
	while (fgets(line, sizeof(line), file)) {
		int node;
		char* token = strtok(line, ": ");

		if (token != NULL) {
			node = atoi(token) - 1;
		}

		token = strtok(NULL, " ");
		while (token != NULL) {
			int neighbor = atoi(token) - 1;
			maTranKe[node][neighbor]++;
			token = strtok(NULL, " ");
		}
	}

	// Close the file
	fclose(file);
	
}

void inRaMaTranKe(int maTranKe[MAX_NODES][MAX_NODES], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", maTranKe[i][j]);
		}
		printf("\n");
	}
}
