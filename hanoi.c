#include <stdio.h>

// n: 이동할 원반의 수, from: 원반을 옮길 출발지, tmp: 옮기는 과정의 임시 장소, to: 원반 옮길 목적ㅈ;
void hanoi_tower(int n, char from, char tmp, char to) {
	//원반 1개일 때
	if (n == 1)
		printf("원반 1을 % c에서 % c로 이동. \n", from, to);
	else {
		// n-1개 원반을 from에서 tmp로 이동
		hanoi_tower(n - 1, from, to, tmp);
		//원반 n을 from에서 to로 이동
		printf("원반 %d을 %c에서 %c로 이동. \n", n, from, to);
		//n-1개의 원반을 tmp에서 to로 이동
		hanoi_tower(n - 1, tmp, from, to);
	}
}

int main() {
	//원반 5개를 A에서 C로 이동하는 하노이 타워 문제
	hanoi_tower(5, 'A', 'B', 'C');
	return 0;
}
