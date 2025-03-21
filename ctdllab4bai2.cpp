#include <iostream>
using namespace std;

// Struct để biểu diễn phân số
struct Fraction {
    int numerator, denominator;
};

// Stack sử dụng mảng động
class ArrayStack {
private:
    Fraction* arr;
    int top;
    int capacity;
public:
    ArrayStack(int size = 100) {
        capacity = size;
        arr = new Fraction[capacity];
        top = -1;
    }
    ~ArrayStack() { delete[] arr; }

    void push(Fraction f) {
        if (top == capacity - 1) {
            cout << "Stack day!\n";
            return;
        }
        arr[++top] = f;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return;
        }
        top--;
    }

    bool isEmpty() { return top == -1; }

    int size() { return top + 1; }

    void clear() { top = -1; }
};

// Stack sử dụng danh sách liên kết
struct Node {
    Fraction data;
    Node* next;
};

class LinkedListStack {
private:
    Node* head;
    int count;
public:
    LinkedListStack() {
        head = nullptr;
        count = 0;
    }

    ~LinkedListStack() { clear(); }

    void push(Fraction f) {
        Node* newNode = new Node{ f, head };
        head = newNode;
        count++;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
    }

    bool isEmpty() { return head == nullptr; }

    int size() { return count; }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Hàm nhập phân số
Fraction inputFraction() {
    Fraction f;
    cout << "Nhap tu so : ";
    cin >> f.numerator;
    cout << "Nhap mau so: ";
    cin >> f.denominator;
    return f;
}

int main() {
    int choice, stackType;
    cout << "Chon kieu  stack:\n1. Mang\n2. DSLK\nlua chon\n: ";
    cin >> stackType;

    ArrayStack* arrayStack = nullptr;
    LinkedListStack* linkedStack = nullptr;

    if (stackType == 1) arrayStack = new ArrayStack();
    else linkedStack = new LinkedListStack();

    do {
        cout << "\nMenu:\n";
        cout << "1. Push\n2. Pop\n3. Kiem tra rong\n4. dem phan tu\n5. Xoa tat ca\n0. Thoat\nLua chon: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (stackType == 1) arrayStack->push(inputFraction());
            else linkedStack->push(inputFraction());
            break;
        case 2:
            if (stackType == 1) arrayStack->pop();
            else linkedStack->pop();
            break;
        case 3:
         cout << ((stackType == 1 ? arrayStack->isEmpty() : linkedStack->isEmpty()) ? "Stack rong!" : "Stack kh!") << "ong rong \n";


            break;
        case 4:
            cout << "So phan tu: " << (stackType == 1 ? arrayStack->size() : linkedStack->size()) << "\n";
            break;
        case 5:
            if (stackType == 1) arrayStack->clear();
            else linkedStack->clear();
            cout << "da xoa toan bo  stack!\n";
            break;
        }
    } while (choice != 0);

    delete arrayStack;
    delete linkedStack;
    return 0;
}
