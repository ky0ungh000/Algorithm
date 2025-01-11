#include <stdio.h>

int N, M;
int arr[50][50];

int main() {
    // 입력 받기
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &arr[i][j]);  // 한 자리 숫자 입력
        }
    }

    int maxSize = 1;  // 최소 정사각형 크기

    // (i, j)를 정사각형의 좌상단으로 탐색
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 가능한 최대 크기의 정사각형 탐색
            for (int side = 1; side + i < N && side + j < M; side++) {
                // 꼭짓점 확인
                if (arr[i][j] == arr[i][j + side] &&
                    arr[i][j] == arr[i + side][j] &&
                    arr[i][j] == arr[i + side][j + side]) {
                    int size = (side + 1) * (side + 1);  // 정사각형 크기
                    if (size > maxSize) {
                        maxSize = size;
                    }
                }
            }
        }
    }

    printf("%d\n", maxSize);  // 가장 큰 정사각형의 크기 출력
    return 0;
}
