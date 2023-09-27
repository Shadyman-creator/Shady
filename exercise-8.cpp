#include <iostream>

void distributeElements(const int* staticArray, int size, int*& positiveArray, int& positiveSize, int*& negativeArray, int& negativeSize, int*& zeroArray, int& zeroSize) {
    positiveSize = negativeSize = zeroSize = 0;


    for (int i = 0; i < size; ++i) {
        if (staticArray[i] > 0) {
            positiveSize++;
        }
        else if (staticArray[i] < 0) {
            negativeSize++;
        }
        else {
            zeroSize++;
        }
    }


    positiveArray = new int[positiveSize];
    negativeArray = new int[negativeSize];
    zeroArray = new int[zeroSize];


    int posIdx = 0, negIdx = 0, zeroIdx = 0;
    for (int i = 0; i < size; ++i) {
        if (staticArray[i] > 0) {
            positiveArray[posIdx++] = staticArray[i];
        }
        else if (staticArray[i] < 0) {
            negativeArray[negIdx++] = staticArray[i];
        }
        else {
            zeroArray[zeroIdx++] = staticArray[i];
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int staticArray[] = { 3, -1, 0, 5, -2, 7, 0 };
    int size = sizeof(staticArray) / sizeof(staticArray[0]);

    int* positiveArray = nullptr;
    int positiveSize = 0;
    int* negativeArray = nullptr;
    int negativeSize = 0;
    int* zeroArray = nullptr;
    int zeroSize = 0;

    distributeElements(staticArray, size, positiveArray, positiveSize, negativeArray, negativeSize, zeroArray, zeroSize);

    std::cout << "Статистический массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << staticArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Положительные элементы: ";
    for (int i = 0; i < positiveSize; ++i) {
        std::cout << positiveArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Отрицательные элементы: ";
    for (int i = 0; i < negativeSize; ++i) {
        std::cout << negativeArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Нулевые элементы: ";
    for (int i = 0; i < zeroSize; ++i) {
        std::cout << zeroArray[i] << " ";
    }
    std::cout << std::endl;

    delete[] positiveArray;
    delete[] negativeArray;
    delete[] zeroArray;

    return 0;
}