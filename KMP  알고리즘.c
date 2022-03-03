#include<stdio.h>
int lentxt, lenpat;

// 일치하는 경우는 j,i 둘 다 증가 시켜주고 일치하지 않으면 i만 증가
// abacaaba 에서 처음 j는 a를 가리키고, i는 b를 가리킨다.
void getFailFunc(char* pattern) {

	for (int i = 1,j = 0; i < lenpat; i++) {
		while (j > 0 && pattern[i] != pattern[j]) j = p[j - 1];
		if (pattern[i] == pattern[j]) {
			p[i] = ++j;
		}
		else p[i] = 0;
	}
} 

void KMP(char* text, char* pattern) {
	getFailFunc();

	for (int i = 0, j = 0; i < lentxt; i++) {
		while (j > 0 && text[i] != pattern[j]) j = p[j - 1];

		if (text[i] == pattern[j]) {
			if (j == lenpat - 1) { // 전체 문자열이 매칭됨.
				printf("%d번째에서 찾았습니다.\n", i - lenpat + 2);
				j = p[j]; // 점프
			}
			else j++; // 계속해서 매칭 확인
		}
		else j = 0;
	}
}
