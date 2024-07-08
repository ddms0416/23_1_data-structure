#include <stdio.h>

int FIB(int n) {
	int a = 0, b = 1, temp;
	if (n <= 1)
		return n;
	else {
		for (int i = 0; i < n; i++) {
			temp = a + b;
			a = b;
			b = temp;
		}
		return a;
	}
}

int main() {
	int n;
	for (n = 1; n <= 10; n++) {
		printf("%d��° �Ǻ���ġ ���� ��: %d\n", n, FIB(n));
	}
	return 0;
}