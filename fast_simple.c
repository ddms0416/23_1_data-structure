#include <stdio.h>
#include <time.h>

#define MAX_TERMS 501 // �ִ� ���� ��
#define MAX_COL 501 // �ִ� ���� ��

// ��� ����� ���� ��Ÿ���� ����ü ����
// term ����ü�� ��� ����� �� ���� ��Ÿ����, ��, ��, ���� ����
typedef struct {
	int col; // �� �ε���
	int row; // �� �ε���
	int value; // ��
} term;

//��� ����� ��� �迭 ����, a: ���� �࿭, b: ��ġ ���
term a[MAX_TERMS];
term b[MAX_TERMS];

// ��� ����� ������ ��ġ�ϴ� �Լ�
void FAST_TRANS(term a[], term b[]) {
	int row_terms[MAX_COL]; // �� ���� �ִ� 0�� �ƴ� ���� ��
	int starting_pos[MAX_COL]; // �� ���� ���� ��ġ
	int i, j;
	int num_cols = b[0].row = a[0].col; // ��ġ ����� �� ���� ���� ����� �� ��
	int num_terms = b[0].value = a[0].value; // ��ġ ����� ���� ���� ���� ����� ���� ��
	b[0].col = a[0].row; // ��ġ ����� �� ���� ���� ����� �� ��

	if (num_terms > 0) { // ���� ���� 0���� ū ���

		//�� ���� �ִ� ���� ���� �ʱ�ȭ
		for (i = 0; i < num_cols; i++)
			row_terms[i] = 0;

		// �� ���� �ִ� ���� ���� ���
		for (i = 1; i <= num_terms; i++)
			row_terms[a[i].col]++;
		starting_pos[0] = 1;

		// �� ���� ���� ��ġ ���
		for (i = 1; i < num_cols; i++)
			starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];

		// ��ġ ��� ����
		for (i = 1; i <= num_terms; i++) {
			j = starting_pos[a[i].col]++;
			b[j].row = a[i].col; b[j].col = a[i].row;
			b[j].value = a[i].value;

		}
	}
}

//�ܼ� ��ġ �Լ�
void SIMPLE_TRANS(term a[], term b[]) {
	int i, j, currentb;
	b[0].row = a[0].col;
	b[0].col = a[0].row;
	b[0].value = a[0].value;

	if (a[0].value > 0) { //���� ���� 0���� ū ���

		currentb = 1;

		// ��ġ ��� ����
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

	// �׽�Ʈ�� ��� �ʱ�ȭ
	for (i = 0; i < MAX_COL; i++)
	{
		a[0].row = MAX_TERMS - 1;
		a[0].col = MAX_TERMS - 1;
		a[0].value = MAX_TERMS - 1;
	}

	//FAST_TRANS �Լ� ���� �ð� ����
	clock_t start = clock();
	for (i = 0; i < 1000; i++) {
		FAST_TRANS(a, b);
	}
	clock_t end = clock();

	// SIMPLE_TRANS �Լ� ���� �ð� ����
	clock_t start2 = clock();
	for (i = 0; i < 1000; i++) {
		SIMPLE_TRANS(a, b);
	}
	clock_t end2 = clock();

	//���� �ð� ���
	printf("FAST_TRANS: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
	printf("SIMPLE_TRANS: %lf\n", (double)(end2 - start2) / CLOCKS_PER_SEC);

	return 0;
}