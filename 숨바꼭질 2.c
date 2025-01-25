#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100001

// 큐 구조체 정의
typedef struct {
    int pos;
    int time;
} Node;

typedef struct {
    Node data[MAX];
    int front, rear;
} Queue;

// 큐 초기화
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

// 큐가 비었는지 확인
int isEmpty(Queue *q) {
    return q->front == q->rear;
}

// 큐에 삽입
void enqueue(Queue *q, int pos, int time) {
    q->data[q->rear].pos = pos;
    q->data[q->rear].time = time;
    q->rear++;
}

// 큐에서 제거 후 반환
Node dequeue(Queue *q) {
    return q->data[q->front++];
}

int N, K;
int visited[MAX];  // 방문 시간을 저장
int ways[MAX];     // 해당 시간에 도달하는 방법의 수 저장

void bfs() {
    Queue q;
    initQueue(&q);
    enqueue(&q, N, 0);
    visited[N] = 0;
    ways[N] = 1;

    while (!isEmpty(&q)) {
        Node cur = dequeue(&q);
        int curPos = cur.pos;
        int curTime = cur.time;

        // 세 가지 이동 방식 적용
        int next_positions[3] = {curPos - 1, curPos + 1, curPos * 2};

        for (int i = 0; i < 3; i++) {
            int next = next_positions[i];

            if (next < 0 || next >= MAX) continue;  // 범위를 벗어나면 무시

            // 첫 방문이면 시간 갱신 후 큐에 삽입
            if (visited[next] == -1) {
                visited[next] = curTime + 1;
                ways[next] = ways[curPos];  // 경우의 수 갱신
                enqueue(&q, next, curTime + 1);
            } 
            // 이미 방문한 경우, 최단 시간으로 방문했다면 경우의 수 증가
            else if (visited[next] == curTime + 1) {
                ways[next] += ways[curPos];
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);

    if (N == K) {
        printf("0\n1\n");
        return 0;
    }

    // 초기화
    memset(visited, -1, sizeof(visited));
    memset(ways, 0, sizeof(ways));

    bfs();

    // 결과 출력
    printf("%d\n%d\n", visited[K], ways[K]);
    
    return 0;
}
