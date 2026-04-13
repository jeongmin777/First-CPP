#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode* next;
} listNode;

typedef struct {
    listNode* head;
} linkedList_h;

void init(linkedList_h* L) {
    L->head = (listNode*)malloc(sizeof(listNode));
    L->head->next = NULL;
    L->head->data = 0;
}

listNode* appendTerm(listNode* k, int c) {
    listNode* t = (listNode*)malloc(sizeof(listNode));
    t->data = c;
    t->next = NULL;
    k->next = t;
    return t;
}

// 합집합: 두 리스트를 비교하며 작은 쪽을 새 리스트에 추가
linkedList_h* uni(linkedList_h* A, linkedList_h* B) {
    linkedList_h* U = (linkedList_h*)malloc(sizeof(linkedList_h));
    init(U);
    listNode* p = A->head->next;
    listNode* q = B->head->next;
    listNode* k = U->head;

    while (p != NULL || q != NULL) {
        if (p != NULL && (q == NULL || p->data < q->data)) {
            // p만 남았거나 p의 데이터가 더 작을 때
            k = appendTerm(k, p->data);
            p = p->next;
        }
        else if (q != NULL && (p == NULL || q->data < p->data)) {
            // q만 남았거나 q의 데이터가 더 작을 때
            k = appendTerm(k, q->data);
            q = q->next;
        }
        else { // p->data == q->data (중복인 경우 하나만 추가)
            k = appendTerm(k, p->data);
            p = p->next;
            q = q->next;
        }
    }
    return U;
}

// 교집합: 두 데이터가 같을 때만 새 리스트에 추가
linkedList_h* inter(linkedList_h* A, linkedList_h* B) {
    linkedList_h* I = (linkedList_h*)malloc(sizeof(linkedList_h));
    init(I);
    listNode* p = A->head->next;
    listNode* q = B->head->next;
    listNode* k = I->head;

    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            p = p->next;
        }
        else if (p->data > q->data) {
            q = q->next;
        }
        else { // 같은 값을 찾았을 때
            k = appendTerm(k, p->data);
            p = p->next;
            q = q->next;
        }
    }
    return I;
}

int main() {
    int a, b, t;

    linkedList_h* p = (linkedList_h*)malloc(sizeof(linkedList_h));
    init(p);
    scanf("%d", &a);
    listNode* curP = p->head;
    for (int i = 0; i < a; i++) {
        scanf("%d", &t);
        curP = appendTerm(curP, t);
    }

    linkedList_h* q = (linkedList_h*)malloc(sizeof(linkedList_h));
    init(q);
    scanf("%d", &b);
    listNode* curQ = q->head;
    for (int i = 0; i < b; i++) {
        scanf("%d", &t);
        curQ = appendTerm(curQ, t);
    }

    linkedList_h* u = uni(p, q);
    linkedList_h* i_list = inter(p, q); // 'i'는 예약어와 겹칠 수 있어 변수명 변경

    // 결과 출력
    listNode* fir = u->head->next;
    if (fir == NULL) printf(" 0");
    else {
        while (fir != NULL) {
            printf(" %d", fir->data);
            fir = fir->next;
        }
    }
    printf("\n");

    listNode* sec = i_list->head->next;
    if (sec == NULL) printf(" 0");
    else {
        while (sec != NULL) {
            printf(" %d", sec->data);
            sec = sec->next;
        }
    }
    printf("\n");

    return 0;
}
// A - B
linkedList_h* diff(linkedList_h* A, linkedList_h* B) {
    linkedList_h* D = (linkedList_h*)malloc(sizeof(linkedList_h));
    init(D);

    listNode* p = A->head->next;
    listNode* q = B->head->next;
    listNode* k = D->head; // tail 역할

    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            // p 값은 B에 없음 -> 결과에 포함
            k = appendTerm(k, p->data);
            p = p->next;
        }
        else if (p->data > q->data) {
            // B를 따라잡기
            q = q->next;
        }
        else {
            // 같은 값이면 제거 (A-B에 포함 X)
            p = p->next;
            q = q->next;
        }
    }

    // B가 끝났으면 A 나머지는 전부 포함
    while (p != NULL) {
        k = appendTerm(k, p->data);
        p = p->next;
    }

    return D;
}

// 대칭차 A △ B = (A - B) ∪ (B - A) 와 동일하지만 한 번에 구할 수 있음
linkedList_h* symDiff(linkedList_h* A, linkedList_h* B) {
    linkedList_h* S = (linkedList_h*)malloc(sizeof(linkedList_h));
    init(S);

    listNode* p = A->head->next;
    listNode* q = B->head->next;
    listNode* k = S->head; // tail

    while (p != NULL && q != NULL) {
        if (p->data < q->data) {
            k = appendTerm(k, p->data);
            p = p->next;
        }
        else if (p->data > q->data) {
            k = appendTerm(k, q->data);
            q = q->next;
        }
        else {
            // 같으면 대칭차에서 제외
            p = p->next;
            q = q->next;
        }
    }
    while (p != NULL) {
        k = appendTerm(k, p->data);
        p = p->next;
    }
    while (q != NULL) {
        k = appendTerm(k, q->data);
        q = q->next;
    }

    return S;
}

void printSet(linkedList_h* L) {
    listNode* cur = L->head->next;
    if (cur == NULL) {
        printf(" 0");
        return;
    }
    while (cur != NULL) {
        printf(" %d", cur->data);
        cur = cur->next;
    }
}