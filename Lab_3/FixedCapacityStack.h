#ifndef FIXEDCAPACITYSTACK_H
#define FIXEDCAPACITYSTACK_H

#include <iostream>

template <typename T>
class FixedCapacityStack {
private:
    T* a;        // ������, ���������� �������� �����
    int n;       // ���������� ��������� � �����
    int capacity; // ������������ ������ �����

public:
    FixedCapacityStack(int capacity);
    ~FixedCapacityStack();

    bool empty() const;
    bool full() const;

    void push(T item);
    T pop();
    T top() const;

    friend std::ostream& operator<<(std::ostream& os, const FixedCapacityStack& st);
};

#endif // FIXEDCAPACITYSTACK_H
