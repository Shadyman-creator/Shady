#include <iostream>
#include <cmath>

// Функция для проверки, является ли число простым
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

// Функция для удаления простых чисел из динамического массива
int* removePrimes(int* array, int& size) {
    int* newArray = new int[size];
    int newSize = 0;

    // Копирование элементов из исходного массива в новый массив, исключая простые числа
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
    std::cout << "Введите размер динамического массива: ";
    std::cin >> size;


    int* dynamicArray = new int[size];
    std::cout << "Введите элементы массива:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> dynamicArray[i];
    }

    // Вызов функции
    dynamicArray = removePrimes(dynamicArray, size);


    std::cout << "Массив после удаления простых чисел:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;


    delete[] dynamicArray;

    return 0;
}