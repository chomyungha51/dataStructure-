#include <stdio.h>
#define QueueMax 100

int MyQueue[QueueMax];
int current = 0;

void Insert() {
	int new;
	if (current <= QueueMax-1) {
		printf("�߰��ϰ� ���� ���� �Է��Ͻÿ�: ");
		scanf("%d", &new);
		MyQueue[current + 1] = new;
		current++;
	}
	else {
		printf("Queue�� �ִ� ������ �ʰ��Ͽ� ���ο� ���� �߰��� �� �����ϴ�.");
	}
}

void Delete() {
	int result; int i;
	if (current == 0)
		printf("���� Queue�� ��� �־� ������ ���� �����ϴ�.");
	else {
		result = MyQueue[1];
		for (i = 1; i <= current; i++) {
			MyQueue[i] = MyQueue[i + 1];
		}MyQueue[current] = 0;
		current--;
		printf("%d�� ������ϴ�.", result);
	}
}

void SearchInQueue() {
	int value; int i; int found = 0;
	printf("ã�� ���� ���ڸ� �Է��ϼ���: ");
	scanf("%d", &value);
	for (i = 1; i < current + 1; i++) {
		if (MyQueue[i] == value) {
			found = 1;
			printf("ã���� �ϴ� ���ڴ� %d��°�� �ֽ��ϴ�.", i);
		}
	}
	if (found == 0)
		printf("MyQueue�� ���ϴ� ���� �����ϴ�.");
}

void main() {
	Delete();
	Insert();
	Delete();
	SearchInQueue();
}