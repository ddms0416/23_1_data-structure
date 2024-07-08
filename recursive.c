#include <stdio.h>

int FIB(int n) {
	if (n <= 1)
		return n;
	else
		return FIB(n - 1) + FIB(n - 2);
}

int main() {
	int n ;

	//1부터 10까지 피보나치 수를 계산, 출력
	for (n = 1; n <= 10; n++) {
		printf("%d번째 피보나치 수의 값: %d\n", n, FIB(n));
	}
		
	return 0;
}