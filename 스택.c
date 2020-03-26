#include <stdio.h>
#include <math.h>

/*Stack �����ϱ�*/

#define StackMax 100

int MyStack[StackMax];
int Top = 0;

/*push �Լ� �����ϱ�*/

void push() {
	if (Top < StackMax-1) {
		printf("MyStack�� push�� ���� �Է����ּ���: ");
		scanf("%d", &MyStack[Top + 1]);
		Top++;
	}
	/*������ �� �� ���*/
	else
		printf("������ �� ���� �� �̻� push �� �� �����ϴ�.");
}
/*pop �Լ� �����ϱ�*/
void pop() {
	int result;
	if (Top == 0)
		printf("������ ��� �־� pop �� �� �����ϴ�.");
	else {
		result = MyStack[Top + 1];
		MyStack[Top + 1] = 0;
		Top--;
		printf("pop ���� ��� %d�� ������ϴ�.", result);
	}
}


int StackInfo() {
	printf("MyStack size: %d", StackMax);
	printf("Current Top: %d ", Top);
}

void SearchInStack() {
	int i; int found = 0; int value;
	printf("ã�� ���� ���� �Է��Ͻÿ�: ");
	scanf("%d", &value);
	for (i = 1; i <= StackMax; i++) {
		if (MyStack[i] == value) {
			printf("%d�� %d��°�� �ֽ��ϴ�.", value, i);
			found = 1;
		}
		else
			i++;
	}
	printf("ã�� ���� ���ÿ� �������� �ʽ��ϴ�.");
}
void main() {
	int random;
	StackInfo();
	push();
	pop();
	printf("�������� MyStack�� ä��ðڽ��ϱ�? (��:1/ �ƴϿ�: 2)");
	Scanf("%d", &random);
	if (random == 1)
		while (Top != StackMax) {
			MyStack[Top + 1] = rand() % 100;
			Top++;
		}printf("������ �� á���ϴ�. *�� �̻� push�� �� �����ϴ�*");
	SearchInStack();
}