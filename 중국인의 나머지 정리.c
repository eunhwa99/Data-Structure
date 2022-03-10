#include<stdio.h>
#define MAX 11
int T, N;
int number[MAX], remainder[MAX];

long computeInverse(long a, long b) {
    long m = b, t, q;
    long x = 0, y = 1;

    if (b == 1) return 0;

    // 확장된 유클리드 알고리즘 적용
    while (a > 1) {
        q = a / b;
        t = b;

        b = (int)(a % b);
        a = t;

        t = x;
        x = y - q * x;
        y = t;
    }

    // 음수이면 양수로 만들기
    if (y < 0) y += m;

    return y;
}


long chineseRemainder() {
    long product = 1;
    for (int i = 0; i < N; i++) {
        product *= number[i];
    }

    long result = 0;
    for (int i = 0; i < N; i++) {
        long partialProduct = product / number[i];
        result += remainder[i] * computeInverse(partialProduct, number[i]) * partialProduct;
    }

    return result % product;

}


int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%d %d", &remainder[i], &number[i]);
		}
		
		printf("#%d %ld\n",t,chineseRemainder());
		
	}
}
