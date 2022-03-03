#include<stdio.h>
#include<algorithm>
using namespace std;

#define MAX 200005
int T;
int L; // 문자열 길이
char S[MAX];
int SA[MAX], lcp[MAX], rank_[MAX]; // SA: suffix array
int g[MAX], tg[MAX]; // 그룹, 팀그룹
int t = 1; // 단어의 위치를 보는 변수

bool cmp(int x, int y) {
	// 그룹 번호가 같으면
	if (g[x] == g[y]) return g[x + t] < g[y + t];

	// 그룹 번호가 다르면
	return g[x] < g[y];
}

void LCP() {
	
	// rank_ 배열에 접미사 배열 순서가 들어간다.
	for (int i = 0; i < L; i++)
		rank_[SA[i]] = i;

	int len = 0;
	
	for (int i = 0; i < L; i++) {
		int k = rank_[i];
		if (k) {
			int j = SA[k - 1];
			while(S[j + len] == S[i + len]) len++;

			lcp[k] = len;

			if (len) len--;
		}
	}

}

void suffixArray() {
	// 초기 인덱스
	//각 접미사의 첫 글자에 맞는 사전순에 맞는 그룹 지정
	for (int i = 0; i < L; i++) {
		SA[i] = i;
		g[i] = S[i] - 'a';
	}

	// 1,2,4,8... 씩 단어의 길이보다 작은 경우를 탐색
	while (t <= L) {
		g[L] = -1;
		sort(SA, SA + L, cmp); // 그룹에 의한 정렬
		tg[SA[0]] = 0; // 다음 그룹을 할당하기 위하여 tempgroup의 첫번째 번호 배정

		//다음 그룹 배정 
		for (int i = 1; i < L; i++)
		{
			//그룹이 다를 경우 다음 그룹 번호 할당
			if (cmp(SA[i - 1], SA[i]))
				tg[SA[i]] = tg[SA[i - 1]] + 1;

			//그룹이 같을 경우 같은 그룹 번호 할당
			else
				tg[SA[i]] = tg[SA[i - 1]];
		}

		//새로운 그룹 할당
		for (int i = 0; i < L; i++)
			g[i] = tg[i];

		t <<= 1; // t *= 2;

	}
}
