#include <stdio.h>

// 리스트의 순열을 생성하고 출력하는 함수
void perm(char* list, int i, int k) {
	int j, temp;

	//현재 인덱스 i가 마지막 인덱스 k와 같을 때
	if (i == k) {
		//현재 순열을 출력
		for (j = 0; j <= k; j++)
			printf("%c", list[j]);
		printf("	");
	}
	else {
		// 재귀, 각 요소를 현재 인덱스와 교환하여 순열 생성
		for (j = i; j <= k; j++) {
			//인덱스 i와 j의 요소를 교환ㄴ
			temp = list[i];
			list[i] = list[j];
			list[j] = temp;

			//다음 인덱스에 대한 순열을 생성하기 위해 perm 함수 재귀 호출
			perm(list, i + 1, k);

			//다음 순회를 위해 리스트를 원래 상태로 복원
			temp = list[i];
			list[i] = list[j];
			list[j] = temp;
		}
	}
}

int main() {
	//문자 배열 초기화
	char permu[] = { 'a', 'b', 'c', 'd' };
	//인덱스 0부터 3까지의 모든 순열 생성하기 위해 perm 함수 호출
	perm(permu, 0, 3);
	return 0;
}