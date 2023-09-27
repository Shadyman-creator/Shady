#include <iostream>
#include <cmath>

// ������� ��� ��������, �������� �� ����� �������
bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    if (number <= 3) {
        return true;
    }
    if (number % 2 == 0 || number % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

// ������� ��� �������� ������� ����� �� ������������� �������
int* removePrimes(int* array, int& size) {
    int* newArray = new int[size];
    int newSize = 0;

    // ����������� ��������� �� ��������� ������� � ����� ������, �������� ������� �����
    for (int i = 0; i < size; i++) {
        if (!isPrime(array[i])) {
            newArray[newSize++] = array[i];
        }
    }


    delete[] array;


    size = newSize;
    return newArray;
}

int main() {
    setlocale(LC_ALL, "rus");
    int size;
    std::cout << "������� ������ ������������� �������: ";
    std::cin >> size;


    int* dynamicArray = new int[size];
    std::cout << "������� �������� �������:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> dynamicArray[i];
    }

    // ����� �������
    dynamicArray = removePrimes(dynamicArray, size);


    std::cout << "������ ����� �������� ������� �����:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;


    delete[] dynamicArray;

    return 0;
}