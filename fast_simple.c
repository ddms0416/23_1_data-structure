#include <stdio.h>
#include <time.h>

#define MAX_TERMS 501 // 최대 항의 수
#define MAX_COL 501 // 최대 열의 수

// 희소 행렬의 항을 나타내는 구조체 정의
// term 구조체는 희소 행렬의 한 항을 나타내며, 행, 열, 값을 가짐
typedef struct {
	int col; // 열 인덱스
	int row; // 행 인덱스
	int value; // 값
} term;

//희소 행렬을 담는 배열 정의, a: 원래 행열, b: 전치 행렬
term a[MAX_TERMS];
term b[MAX_TERMS];

// 희소 행렬을 빠르게 전치하는 함수
void FAST_TRANS(term a[], term b[]) {
	int row_terms[MAX_COL]; // 각 열에 있는 0이 아닌 값의 수
	int starting_pos[MAX_COL]; // 각 열의 시작 위치
	int i, j;
	int num_cols = b[0].row = a[0].col; // 전치 행렬의 행 수는 원래 행렬의 열 수
	int num_terms = b[0].value = a[0].value; // 전치 행렬의 항의 수는 원래 행렬의 항의 수
	b[0].col = a[0].row; // 전치 행렬의 열 수는 원래 행렬의 행 수

	if (num_terms > 0) { // 항의 수가 0보다 큰 경우

		//각 열에 있는 항의 수를 초기화
		for (i = 0; i < num_cols; i++)
			row_terms[i] = 0;

		// 각 열에 있는 항의 수를 계산
		for (i = 1; i <= num_terms; i++)
			row_terms[a[i].col]++;
		starting_pos[0] = 1;

		// 각 열의 시작 위치 계산
		for (i = 1; i < num_cols; i++)
			starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];

		// 전치 행렬 구성
		for (i = 1; i <= num_terms; i++) {
			j = starting_pos[a[i].col]++;
			b[j].row = a[i].col; b[j].col = a[i].row;
			b[j].value = a[i].value;

		}
	}
}

//단순 전치 함수
void SIMPLE_TRANS(term a[], term b[]) {
	int i, j, currentb;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;

	if (a[0].value > 0) { //항의 수가 0보다 큰 경우

		currentb = 1;

		// 전치 행렬 구성
		for (i = 0; i < a[0].col; i++) {
			
			for (j = 1; j <= a[0].value; j++) {
				
				if (a[j].col == i) {
					b[currentb].row = a[j].col;
					b[currentb].col = a[j].row;
					b[currentb].value = a[j].value;
					currentb++;

				}
			}
		}
	}
}

int main() {

	int i;

	// 테스트용 행렬 초기화
	for (i = 0; i < MAX_COL; i++)
	{
		a[0].row = MAX_TERMS - 1;
		a[0].col = MAX_TERMS - 1;
		a[0].value = MAX_TERMS - 1;
	}

	//FAST_TRANS 함수 실행 시간 측정
	clock_t start = clock();
	for (i = 0; i < 1000; i++) {
		FAST_TRANS(a, b);
	}
	clock_t end = clock();

	// SIMPLE_TRANS 함수 실행 시간 측정
	clock_t start2 = clock();
	for (i = 0; i < 1000; i++) {
		SIMPLE_TRANS(a, b);
	}
	clock_t end2 = clock();

	//실행 시간 출력
	printf("FAST_TRANS: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("SIMPLE_TRANS: %lf\n", (double)(end2 - start2) / CLOCKS_PER_SEC);

	return 0;
}