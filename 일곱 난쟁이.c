#include <stdio.h>
#include <stdlib.h>

#define TOTAL_DWARFS 9

// ������ ���ϴ� �Լ�
int total_sum(int dwarfs[TOTAL_DWARFS]) {
	int total_sum = 0;
	for (int i = 0; i < TOTAL_DWARFS; i++) {
		total_sum += dwarfs[i];
	}
	return total_sum;
}

// �� �Լ� (qsort��)
int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}

int main() {
	int dwarfs[TOTAL_DWARFS];
	int selected_dwarfs[7];
	
	// ������ Ű �Է¹ޱ�
	for (int i = 0; i < TOTAL_DWARFS; i++) {
		scanf("%d", &dwarfs[i]);
	}

	// ��ü �� ���ϱ�
	int dwarfs_sum = total_sum(dwarfs);

	// �� ���� ������ ���� 100�� �Ǵ��� Ȯ��
	for (int i = 0; i < TOTAL_DWARFS - 1; i++) {
		for (int j = i + 1; j < TOTAL_DWARFS; j++) {
			if (dwarfs_sum - (dwarfs[i] + dwarfs[j]) == 100) {
				int index = 0;
				for (int k = 0; k < TOTAL_DWARFS; k++) {
					if (k != i && k != j) {
						selected_dwarfs[index++] = dwarfs[k];
					}
				}

				// ���õ� 7���� Ű�� ����
				qsort(selected_dwarfs, 7, sizeof(int), compare);
				
				// ���ĵ� ��� ���
				for (int l = 0; l < 7; l++) {
					printf("%d\n", selected_dwarfs[l]);
				}
				return 0;
			}
		}
	}
	return 0;
}