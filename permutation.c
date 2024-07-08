#include <stdio.h>

// ����Ʈ�� ������ �����ϰ� ����ϴ� �Լ�
void perm(char* list, int i, int k) {
	int j, temp;

	//���� �ε��� i�� ������ �ε��� k�� ���� ��
	if (i == k) {
		//���� ������ ���
		for (j = 0; j <= k; j++)
			printf("%c", list[j]);
		printf("	");
	}
	else {
		// ���, �� ��Ҹ� ���� �ε����� ��ȯ�Ͽ� ���� ����
		for (j = i; j <= k; j++) {
			//�ε��� i�� j�� ��Ҹ� ��ȯ��
			temp = list[i];
			list[i] = list[j];
			list[j] = temp;

			//���� �ε����� ���� ������ �����ϱ� ���� perm �Լ� ��� ȣ��
			perm(list, i + 1, k);

			//���� ��ȸ�� ���� ����Ʈ�� ���� ���·� ����
			temp = list[i];
			list[i] = list[j];
			list[j] = temp;
		}
	}
}

int main() {
	//���� �迭 �ʱ�ȭ
	char permu[] = { 'a', 'b', 'c', 'd' };
	//�ε��� 0���� 3������ ��� ���� �����ϱ� ���� perm �Լ� ȣ��
	perm(permu, 0, 3);
	return 0;
}