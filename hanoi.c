#include <stdio.h>

// n: �̵��� ������ ��, from: ������ �ű� �����, tmp: �ű�� ������ �ӽ� ���, to: ���� �ű� ������;
void hanoi_tower(int n, char from, char tmp, char to) {
	//���� 1���� ��
	if (n == 1)
		printf("���� 1�� % c���� % c�� �̵�. \n", from, to);
	else {
		// n-1�� ������ from���� tmp�� �̵�
		hanoi_tower(n - 1, from, to, tmp);
		//���� n�� from���� to�� �̵�
		printf("���� %d�� %c���� %c�� �̵�. \n", n, from, to);
		//n-1���� ������ tmp���� to�� �̵�
		hanoi_tower(n - 1, tmp, from, to);
	}
}

int main() {
	//���� 5���� A���� C�� �̵��ϴ� �ϳ��� Ÿ�� ����
	hanoi_tower(5, 'A', 'B', 'C');
	return 0;
}
