#include <stdio.h>

int FIB(int n) {
	if (n <= 1)
		return n;
	else
		return FIB(n - 1) + FIB(n - 2);
}

int main() {
	int n ;

	//1���� 10���� �Ǻ���ġ ���� ���, ���
	for (n = 1; n <= 10; n++) {
		printf("%d��° �Ǻ���ġ ���� ��: %d\n", n, FIB(n));
	}
		
	return 0;
}