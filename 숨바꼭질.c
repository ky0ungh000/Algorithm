#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100001  // 가능한 최대 위치

typedef struct {
    int pos;
    int time;
} Node;

int bfs(int N, int K) {
    if (N == K) return 0;  // 이미 같은 위치에 있으면 0초
    
    bool visited[MAX] = { false };  // 방문 여부 체크 배열
    Node queue[MAX];  // 큐를 위한 배열
    int front = 0, rear = 0;  // 큐의 앞과 뒤 인덱스
    
    queue[rear++] = (Node){N, 0};  // 초기 위치 삽입
    visited[N] = true;
    
    while (front < rear) {
        Node current = queue[front++];
        
        int next_positions[3] = {current.pos - 1, current.pos + 1, current.pos * 2};  // 이동할 위치들
        
        for (int i = 0; i < 3; i++) {
            int next_pos = next_positions[i];

            // 유효한 범위 내에서 방문하지 않은 경우
            if (next_pos >= 0 && next_pos < MAX && !visited[next_pos]) {
                if (next_pos == K)  // 목적지 도착 시 즉시 반환
                    return current.time + 1;
                
                queue[rear++] = (Node){next_pos, current.time + 1};  // 큐에 삽입
                visited[next_pos] = true;  // 방문 처리
            }
        }
    }
    return -1;  // 이론적으로 도달할 수 없는 경우는 없음
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    printf("%d\n", bfs(N, K));
    return 0;
}
