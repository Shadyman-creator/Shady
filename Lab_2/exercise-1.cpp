#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};


class MyLinkedList {
public:
    MyLinkedList() : head(nullptr), size(0) {}

    size_t get_size() { return size; } // Получить размер списка
    void add_at_tail(int val);         // Добавить элемент в конец списка
    void add_at_index(size_t index, int val); // Добавить элемент по индексу

    // Добавление элемента в начало списка
    void addAtHead(int val);

    // Вывести все значения элементов списка через пробел
    void print();

    // Изменить порядок элементов списка на обратный
    void reverse();

    // Удалить элемент по индексу
    void delete_at_index(size_t index);
private:
    ListNode* head;
    size_t size;
};

void MyLinkedList::add_at_tail(int val) {
    // Создать новый экземляр ListNode или новый элемент списка
    ListNode* newNode = new ListNode(val, nullptr);

    if (head == nullptr) {
        head = newNode;
        return;
    }
    // Двигаем указатель it до достижения последнего элемента списка
    ListNode* it = head;
    while (it->next != nullptr)
        it = it->next;

    // Присваиеваем указателю на следующий элемент (next) текущего последнего элемента
    // адрес нового последнего элемента
    it->next = newNode;

    ++size;
}

void MyLinkedList::add_at_index(size_t index, int val) {
    ListNode* prev = head;
    ListNode* curr = head->next;
    size_t pos = 0;

    while (prev != nullptr && pos < index - 1) {
        prev = prev->next;
        curr = curr->next;
        ++pos;
    }
    ListNode* newNode = new ListNode(val, curr);
    prev->next = newNode;

    ++size;
}

void MyLinkedList::addAtHead(int val) {

    ListNode* newNode = new ListNode(val);
    newNode->next = head;
    head = newNode;

    ++size;
}

void MyLinkedList::print() {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

void MyLinkedList::reverse() {
    ListNode* prev = nullptr;
    ListNode* current = head;
    ListNode* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;


        prev = current;
        current = next;
    }
    head = prev;
}

void MyLinkedList::delete_at_index(size_t index) {
    if (index >= size) {
        cout << "Index is larger than or equal to the size=" << size << "\n";
        return;
    }

    if (index == 0) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
    else {
        ListNode* prev = head;
        ListNode* curr = head->next;
        size_t pos = 0;

        while (prev != nullptr && pos < index - 1) {
            prev = prev->next;
            curr = curr->next;
            ++pos;
        }
        prev->next = curr->next;
        delete curr;
    }
    --size;
}

int main() {

    int arr[5] = { 1, 2, 3, 4, 5 };

    MyLinkedList* obj = new MyLinkedList();
    for (int val : arr) {
        obj->add_at_tail(val);
    }

    cout << "Original List: ";
    obj->print();

    // obj->print_list();
    cout << "Deleting the last element...\n";
    obj->delete_at_index(4);
    obj->print();
    // obj->print_list();

    cout << "Add at index 3\n";
    obj->add_at_index((size_t)2, 10);
    obj->print();
    // obj->print_list();

    cout << "Add at head: 5\n";
    obj->addAtHead(5);
    obj->print();

    cout << "Reversing the list...\n";
    obj->reverse();
    obj->print();

    cout << "Deleting at index 1...\n";
    obj->delete_at_index(1);
    obj->print();

    delete obj;

    return 0;
}
