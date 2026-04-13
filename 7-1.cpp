#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)


typedef struct ListNode {
	int data;
	struct ListNode* next;
} listNode;



listNode* add(listNode* k, int c) {
	listNode* t = (listNode*)malloc(sizeof(listNode));

	t->data = c;
	t->next = NULL;

	k->next = t;

	return t;
}
int main() {

	int a, b;
	int t;


    listNode* p;
	p = (listNode*)malloc(sizeof(listNode));
	p->next = NULL;
	scanf("%d", &a);

	if (a == 0) {
		printf("0");
		return 0;
	}
	else {
		scanf("%d", &t);
		p->data = t;

		listNode* curr = p;

		for (int i = 0; i < a - 1; i++) {
			int k;
			scanf("%d", &k);
			add(curr, k);
			curr = curr->next;
		}
	}

	
	scanf("%d", &b);
	if (b == 0) {
		printf("%d", p->data);
		return 0;
	}


	listNode* q;
	q = (listNode*)malloc(sizeof(listNode));
	q->next = NULL;
	scanf("%d", &t);
	q->data = t;


	listNode* curr2 = q;
	for (int i = 0; i < b- 1; i++) {
		int k;
		scanf("%d", &k);
		add(curr2, k);
		curr2 = curr2->next;
	}

	listNode* fir = p;
	listNode* sec = q;

	
	while(fir!=NULL && sec!= NULL) {
		if (fir->data > sec->data)sec = sec->next;
		else if (fir->data == sec->data) {
			fir = fir->next;
			sec = sec->next;
		}
		else {
			printf("%d", fir->data);
			return 0;
			}
		}
	 if (fir != NULL) {
	printf("%d", fir->data);
	return 0;
}
	 printf("0");
	 return 0;
	}


	