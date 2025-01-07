#include <stdio.h>
#include <stdlib.h>

#define TOTAL_DWARFS 9

// 총합을 구하는 함수
int total_sum(int dwarfs[TOTAL_DWARFS]) {
	int total_sum = 0;
	for (int i = 0; i < TOTAL_DWARFS; i++) {
		total_sum += dwarfs[i];
	}
	return total_sum;
}

// 비교 함수 (qsort용)
int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	int dwarfs[TOTAL_DWARFS];
	int selected_dwarfs[7];
	
	// 난쟁이 키 입력받기
	for (int i = 0; i < TOTAL_DWARFS; i++) {
		scanf("%d", &dwarfs[i]);
	}

	// 전체 합 구하기
	int dwarfs_sum = total_sum(dwarfs);

	// 두 명을 제외한 합이 100이 되는지 확인
	for (int i = 0; i < TOTAL_DWARFS - 1; i++) {
		for (int j = i + 1; j < TOTAL_DWARFS; j++) {
			if (dwarfs_sum - (dwarfs[i] + dwarfs[j]) == 100) {
				int index = 0;
				for (int k = 0; k < TOTAL_DWARFS; k++) {
					if (k != i && k != j) {
						selected_dwarfs[index++] = dwarfs[k];
					}
				}

				// 선택된 7명의 키를 정렬
				qsort(selected_dwarfs, 7, sizeof(int), compare);
				
				// 정렬된 결과 출력
				for (int l = 0; l < 7; l++) {
					printf("%d\n", selected_dwarfs[l]);
				}
				return 0;
			}
		}
	}
	return 0;
}