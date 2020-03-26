#include <stdio.h>
#define QueueMax 100

int MyQueue[QueueMax];
int current = 0;

void Insert() {
	int new;
	if (current <= QueueMax-1) {
		printf("추가하고 싶은 수를 입력하시오: ");
		scanf("%d", &new);
		MyQueue[current + 1] = new;
		current++;
	}
	else {
		printf("Queue의 최대 범위를 초과하여 새로운 값을 추가할 수 없습니다.");
	}
}

void Delete() {
	int result; int i;
	if (current == 0)
		printf("현재 Queue가 비어 있어 삭제할 값이 없습니다.");
	else {
		result = MyQueue[1];
		for (i = 1; i <= current; i++) {
			MyQueue[i] = MyQueue[i + 1];
		}MyQueue[current] = 0;
		current--;
		printf("%d를 얻었습니다.", result);
	}
}

void SearchInQueue() {
	int value; int i; int found = 0;
	printf("찾고 싶은 숫자를 입력하세요: ");
	scanf("%d", &value);
	for (i = 1; i < current + 1; i++) {
		if (MyQueue[i] == value) {
			found = 1;
			printf("찾고자 하는 숫자는 %d번째에 있습니다.", i);
		}
	}
	if (found == 0)
		printf("MyQueue에 원하는 값이 없습니다.");
}

void main() {
	Delete();
	Insert();
	Delete();
	SearchInQueue();
}