#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)


typedef struct ListNode {
	int coef;
	int exp;
	struct ListNode* next;
} listNode;

typedef struct {
	listNode* head;
}linkedList_h;

void init(linkedList_h* L) {
	L->head = (listNode*)malloc(sizeof(listNode));
	L->head->next = NULL;
	L->head->coef = 0;
	L->head->exp = 0;
}

listNode* appendTerm(listNode* k, int c, int e) {
	listNode* t = (listNode*)malloc(sizeof(listNode));

	t->coef = c;
	t->exp = e;
	t->next = NULL;

	k->next = t;
	

	return t;
}
linkedList_h addPoly(linkedList_h* x, linkedList_h* y) {
	linkedList_h result;

	result.head = (listNode*)malloc(sizeof(listNode));
	result.head->next = NULL;

	listNode* i = x->head->next;
	listNode* j = y->head->next;
	listNode* k = result.head;

	while (i != NULL && j != NULL) {
		if (i->exp > j->exp) {
			k = appendTerm(k, i->coef, i->exp);
			i = i->next;
		}
		else if (i->exp < j->exp) {
			k = appendTerm(k, j->coef, j->exp);
			j = j->next;
		}
		else {
			int sum = i->coef + j->coef;
			if (sum != 0) {
				k = appendTerm(k, sum, i->exp);
			}
			i = i->next;
			j = j->next;

		}
	}

	while (i != NULL) {
		k = appendTerm(k, i->coef, i->exp);
		i = i->next;
	}

	while (j != NULL) {
		k = appendTerm(k, j->coef, j->exp);
		j = j->next;
	}
	return result;

}

void print(linkedList_h* L) {
	listNode* p = L->head->next;

	while (p != NULL) {
		printf(" %d %d", p->coef, p->exp);
		p = p->next;
	}
}

int main() {
	int a;
	scanf("%d", &a);

	linkedList_h F, S;
	init(&F);
	listNode* k = F.head;

	for (int i = 0; i < a; i++) {
		int c, e;
		scanf("%d %d", &c, &e);
		k = appendTerm(k, c, e);
	}

	int b;
	scanf("%d", &b);
	init(&S);

	listNode* p = S.head;
	for (int i = 0; i < b; i++) {
		int c, e;
		scanf("%d %d", &c, &e);
		p = appendTerm(p, c, e);
	}

	linkedList_h R = addPoly(&F, &S);

	print(&R);


	return 0;

}