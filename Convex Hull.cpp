#include<stdio.h>
#include<algorithm>
#define MAX 100005
using namespace std;
int N;
int T;
typedef long long int lld;
typedef struct point {
	int x;
	int y;
}Point;
Point p[MAX], stack[MAX];
int pivot, rslt, top;


int CCW(Point a, Point b, Point c) {
	lld ccw= ((lld)a.x * b.y + (lld)b.x * c.y + (lld)c.x * a.y) - ((lld)a.y * b.x + (lld)b.y * c.x + (lld)c.y * a.x);

	if (ccw < 0) return -1; // 반시계
	else if (ccw > 0) return 1; // 시계
	else return 0;
}

// 각도정렬 함수
int cmp(Point a, Point b) {
	lld ccw = CCW(p[0], a, b); // 원점에 대하여 
	if (ccw == 0) { // 일직선 위에 있을 때
		if (a.x == b.x) return a.y < b.y; // 더 가까운 점
		else return a.x < b.x;
	}
	return ccw > 0; // 시계
}

// CCW를 이용하여 오목한 점을 제거하는 함수
void count() {
	for (int i = 0; i < N; i++) {
		// 최종 선택에 포함 되는 점들을 stack에 담고 제거해야하는 점들은 pop을 해줌
		// 3점이 right turn
		while (top > 1 && CCW(stack[top - 1], stack[top], p[i]) <= 0) {
			top--;
		}
		stack[++top] = p[i];
	}
}

int main() {
	scanf("%d", &T);

	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d", &p[i].x, &p[i].y);
			// 최하점 기준점
			if (p[i].x < p[pivot].x || (p[i].x == p[pivot].x && p[i].y < p[pivot].y)) {
				pivot = i;
			}
		}

		// 기준점을 0번으로
		Point tmp = p[0];
		p[0] = p[pivot];
		p[pivot] = tmp;
	
		sort(p + 1, p + N, cmp);
		count();
		printf("#%d %d\n", t, top);
		top = pivot = 0;
		
	}
}
