#include "FixedCapacityStack.h"

// Определение конструктора
template <typename T>
FixedCapacityStack<T>::FixedCapacityStack(int capacity) : capacity(capacity), n(0) {
    a = new T[capacity];
}

template <typename T>
FixedCapacityStack<T>::~FixedCapacityStack() {
    delete[] a;
}

// Остальные методы класса тоже должны иметь указание на тип T


// Определение метода empty()
template <typename T>
bool FixedCapacityStack<T>::empty() const {
    return n == 0;
}

// Определение метода full()
template <typename T>
bool FixedCapacityStack<T>::full() const {
    return n == capacity;
}

// Определение метода push()
template <typename T>
void FixedCapacityStack<T>::push(T item) {
    if (!full()) {
        a[n++] = item;
    }
}

// Определение метода pop()
template <typename T>
T FixedCapacityStack<T>::pop() {
    if (!empty()) {
        return a[--n];
    }
    throw std::runtime_error("Stack is empty");
}

// Определение метода top()
template <typename T>
T FixedCapacityStack<T>::top() const {
    if (!empty()) {
        return a[n - 1];
    }
    throw std::runtime_error("Stack is empty");
}

// Определение оператора << для вывода стека
template <typename T>
std::ostream& operator<<(std::ostream& os, const FixedCapacityStack<T>& st) {
    for (int i = st.n - 1; i >= 0; --i) {
        os << st.a[i] << "\n";
    }
    return os;
}
