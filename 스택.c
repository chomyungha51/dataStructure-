#include <stdio.h>
#include <math.h>

/*Stack 구현하기*/

#define StackMax 100

int MyStack[StackMax];
int Top = 0;

/*push 함수 구현하기*/

void push() {
	if (Top < StackMax-1) {
		printf("MyStack에 push할 값을 입력해주세요: ");
		scanf("%d", &MyStack[Top + 1]);
		Top++;
	}
	/*스택이 꽉 찬 경우*/
	else
		printf("스택이 꽉 차서 더 이상 push 할 수 없습니다.");
}
/*pop 함수 구현하기*/
void pop() {
	int result;
	if (Top == 0)
		printf("스택이 비어 있어 pop 할 수 없습니다.");
	else {
		result = MyStack[Top + 1];
		MyStack[Top + 1] = 0;
		Top--;
		printf("pop 실행 결과 %d를 얻었습니다.", result);
	}
}


int StackInfo() {
	printf("MyStack size: %d", StackMax);
	printf("Current Top: %d ", Top);
}

void SearchInStack() {
	int i; int found = 0; int value;
	printf("찾고 싶은 값을 입력하시오: ");
	scanf("%d", &value);
	for (i = 1; i <= StackMax; i++) {
		if (MyStack[i] == value) {
			printf("%d는 %d번째에 있습니다.", value, i);
			found = 1;
		}
		else
			i++;
	}
	printf("찾는 값이 스택에 존재하지 않습니다.");
}
void main() {
	int random;
	StackInfo();
	push();
	pop();
	printf("랜덤으로 MyStack을 채우시겠습니까? (예:1/ 아니오: 2)");
	Scanf("%d", &random);
	if (random == 1)
		while (Top != StackMax) {
			MyStack[Top + 1] = rand() % 100;
			Top++;
		}printf("스택이 꽉 찼습니다. *더 이상 push할 수 없습니다*");
	SearchInStack();
}