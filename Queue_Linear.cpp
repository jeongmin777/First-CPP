#include <iostream>
#include <string>
using namespace std;

// 선형 큐 클래스
class LinearQueue {
private:
    int* arr;           // 큐를 저장할 배열
    int front;          // 큐의 앞 위치
    int rear;           // 큐의 뒤 위치
    int size;           // 배열의 크기
    int count;          // 큐에 저장된 원소의 개수

public:
    // 생성자: 크기가 size인 큐 생성
    LinearQueue(int size = 10) {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = -1;
        count = 0;
    }

    // 소멸자
    ~LinearQueue() {
        delete[] arr;
    }

    // 큐가 비어있는지 확인
    bool isEmpty() {
        return count == 0;
    }

    // 큐가 가득 찼는지 확인
    bool isFull() {
        return count == size;
    }

    // 큐에 원소 추가 (enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear = (rear + 1) % size;  // 원형 큐처럼 동작하도록 수정
        arr[rear] = value;
        count++;
    }

    // 큐에서 원소 제거 (dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int value = arr[front];
        front = (front + 1) % size;  // 원형 큐처럼 동작하도록 수정
        count--;
        return value;
    }

    // 큐의 앞 원소 확인 (peek)
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // 큐의 크기
    int getSize() {
        return count;
    }
};

// ===== 백준 스타일 문제: 큐 명령 처리 =====
// 문제: N개의 명령을 처리하는 큐 시뮬레이션
// 명령: push X, pop, size, empty, front

void solveQueueProblem() {
    int n;
    cin >> n;

    LinearQueue q(n + 1);

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "push") {
            int x;
            cin >> x;
            q.enqueue(x);
        }
        else if (command == "pop") {
            int value = q.dequeue();
            if (value != -1) {
                cout << value << "\n";
            }
        }
        else if (command == "size") {
            cout << q.getSize() << "\n";
        }
        else if (command == "empty") {
            cout << (q.isEmpty() ? 1 : 0) << "\n";
        }
        else if (command == "front") {
            int value = q.peek();
            if (value != -1) {
                cout << value << "\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 테스트 코드 1: 기본 선형 큐 동작
    cout << "=== Linear Queue Test ===" << endl;
    LinearQueue q(5);

    cout << "Push: 10, 20, 30, 40" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Current size: " << q.getSize() << endl;
    cout << "Front element: " << q.peek() << endl;

    cout << "Pop order: ";
    while (!q.isEmpty()) {
        cout << q.dequeue() << " ";
    }
    cout << endl;

    cout << "\nIs empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    // 테스트 코드 2: 백준 스타일 문제 풀기
    // 아래 주석을 풀고 실행하면 됩니다.
    // cout << "\n=== Baekjoon Style Queue Problem ===" << endl;
    // solveQueueProblem();

    return 0;
}
