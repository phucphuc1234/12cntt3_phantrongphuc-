#include <iostream>
using namespace std;

class QueueArray {
private:
    int* queue;
    int front, rear, size, capacity;

public:
    QueueArray(int cap) {
        capacity = cap;
        queue = new int[capacity];
        front = rear = -1;
        size = 0;
    }

    ~QueueArray() {
        delete[] queue;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        queue[rear] = value;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1; // Hoặc một giá trị đặc biệt
        }
        int value = queue[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    int count() {
        return size;
    }

    void clear() {
        front = rear = -1;
        size = 0;
    }
};

// Hàm chính cho Queue sử dụng mảng
int main() {
    QueueArray queue(5);
    int choice;

    do {
        cout << "\nMenu:\n1. Enqueue\n2. Dequeue\n3. Kiem tra rong \n4. dem so luong\n5. Xoa tat ca\n0. Thhoat\n";
        cout << "Chon thao tac: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Nhap gia tri: ";
                cin >> value;
                queue.enqueue(value);
                break;
            }
            case 2:
                cout << "Gia tri dequeue: " << queue.dequeue() << endl;
                break;
            case 3:
                cout << (queue.isEmpty() ? "Queue rong" : "Queue khong rong") << endl;
                break;
            case 4:
                cout << "So luong phan tu: " << queue.count() << endl;
                break;
            case 5:
                queue.clear();
                cout << "da xoa tat ca phan tu trong queue." << endl;
                break;
            case 0:
                break;
            default:
                cout << "Lua chon khong hop le." << endl;
        }
    } while (choice != 0);

    return 0;
}