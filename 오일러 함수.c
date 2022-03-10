// 파이의 합 문제
#include<stdio.h>
#define MAX 1000005
int T, a, b, N;
int isCompositeNumber[MAX];
int arr[MAX];
long sum[MAX], rslt;

int main() {
    scanf("%d", &T);

    // 에라토스테네스의 체를 이용해 소수 판별(= 합성수 여부)
    N = 1000000;
    isCompositeNumber[1] = 1; // 합성수도 소수도 아니지만 true
    for (int i = 2; i * i <= N; i++) {
        // 에라토스테넷스의 체
        if (!isCompositeNumber[i]) {
            // 배수들을 제외 처리.
            for (int j = 2; i * j <= N; j++) {
                isCompositeNumber[i * j] = 1;
            }
        }
    }

    // 오일러 함수 결과 구하기
    for (int i = 1; i <= N; i++) {
        arr[i] = i;
    }

    for (int i = 2; i <= N; i++) {
        // 소수이면
        if (!isCompositeNumber[i]) {
            // 배수들에 대한 처리
            for (int j = 1; i * j <= N; j++) {
                arr[i * j] = (i - 1) * (arr[i * j] / i);
            }
        }
    }

    sum[0] = 0; sum[1] = 1;
    for (int i = 2; i <= N; i++) {
        sum[i] = sum[i - 1] + arr[i];
    }

    for (int t = 1; t <= T; t++) {
        scanf("%d %d", &a, &b);
        rslt = sum[b] - sum[a - 1];
        printf("#%d %ld\n", t, rslt);
    }
}
