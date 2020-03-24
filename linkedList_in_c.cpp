#include <stdio.h>
#include <stdlib.h> //malloc ��� 

typedef int element; //giving a particular type a special name, int->element
typedef struct ListNode{
	element data;
	struct ListNode *link;
} ListNode;
void insertNode(ListNode **phead, ListNode *p, ListNode *new_node){
	//�� ���� ���-1)no elements, 2)one element, 3)general case
	//�ش� ��� �տ� �ֱ� 
	if (*phead==NULL){
		new_node->link=NULL;
		*phead=new_node;
	}
	else if (p==NULL){
		new_node->link=*phead;
		*phead=new_node;
	}
	else {
		new_node->link=p->link;
		p->link=new_node;}
}
void insert_node_after_value(ListNode *head, int value, ListNode *new_node){
	ListNode *p=head;
	int found=0;
	while (p!=NULL && found==0){
		if (p->data==value){
			found=1;
			break;
		}
		else{
			p=p->link;
		}
	}
	if (found==0){
		printf("ã���� �ϴ� value ����");
	}
	else{
		//���� p ������ value ��� �־�
		new_node->link=p->link;
		p->link=new_node;	 
	} 	
}
void remove_node_by_value(ListNode **phead, ListNode *head, int value){
	ListNode *p=head;
	int found=0;
	
	ListNode *prev;
	while (p!=NULL && found==0){
		if (p->data == value){
			found=1;
			break;
		}
		else{
		    prev=p;
			p=p->link;
		}
	}
	if (found==0){
		printf("ã���� �ϴ� value ����");
		printf("\n");
	}
	else{
		prev->link=p->link;
	} 
	free(p);
}
void display(ListNode *head){
	ListNode *p= head;
	while (p!=NULL){
		printf("%d ",p->data);
		p=p->link;
	}
	printf("\n");
}
void count(ListNode *head){
	int cnt=0;
	ListNode *p=head;
	while (p!=NULL){
		cnt++;
		p=p->link;
	}
	printf("%d ",cnt);
	printf("\n");
}
int main(int argc, const char *argv[]){
	//head ��� �ʱ�ȭ��Ű��
    struct ListNode *head1 = malloc(sizeof(struct ListNode));
	head1=NULL;
	int i;
	//1���� 5������ ���� ������ ���Ḯ��Ʈ �����
	//1)����� ����, 2)insertNode function�� ���� ��忬��(���Ḯ��Ʈ �����)
	for (i=1;i<=5;i++){
		struct ListNode *newNode=malloc(sizeof(struct ListNode));
		newNode->link=NULL;
		newNode->data=i;
		insertNode(&head1,NULL,newNode);//head1 as a pointer of the head pointer
		//only working with single nodes, no predecessor assumed 
	}
	printf("���Ḯ��Ʈ ���\n");
	display(head1);
	printf("���Ḯ��Ʈ count ���\n");
    count(head1);
    
    printf("���ο� ��� 11�� 4 �ڿ� �ֱ�\n");
	struct ListNode *new_node = malloc(sizeof(struct ListNode));
    new_node->link = NULL;
    new_node->data = 11;
    insert_node_after_value(head1, 4, new_node);
    display(head1);
    
    printf("���ο� ��� 11�� 0 (���� ��) �ڿ� �ֱ�\n");
    struct ListNode *new_node2 = malloc(sizeof(struct ListNode));
    new_node2->link = NULL;
    new_node2->data = 11;
    insert_node_after_value(head1, 0, new_node);
    display(head1);

 	printf("��� 11�� �����ϱ�\n");
    remove_node_by_value(&head1, head1, 11);
    display(head1);
    printf("��� 1�� �����ϱ�\n");
    remove_node_by_value(&head1, head1, 1);
    display(head1);
    printf("��� 10�� �����ϱ�\n");
    remove_node_by_value(&head1, head1, 10);
    display(head1);
    printf("��� 1�� �����ϱ�\n");
    remove_node_by_value(&head1, head1, 1);
    display(head1);


}
