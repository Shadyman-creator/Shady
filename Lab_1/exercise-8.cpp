#include <iostream>

void distributeElements(const int* staticArray, int size, int* positive, int& positiveSize, int*& negative, int& negativeSize, int*& zero, int& zeroSize) {

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


    positive = new int[positiveSize];
    negative = new int[negativeSize];
    zero = new int[zeroSize];


    int posIdx = 0, negIdx = 0, zeroIdx = 0;
    for (int i = 0; i < size; ++i) {
        if (staticArray[i] > 0) {
            positive[posIdx++] = staticArray[i];
        }
        else if (staticArray[i] < 0) {
            negative[negIdx++] = staticArray[i];
        }
        else {
            zero[zeroIdx++] = staticArray[i];
        }
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    int staticArray[] = { 3, -1, 0, 5, -2, 7, 0 };
    int size = sizeof(staticArray) / sizeof(staticArray[0]);

    int* positive = nullptr;
    int positiveSize = 0;
    int* negative = nullptr;
    int negativeSize = 0;
    int* zero = nullptr;
    int zeroSize = 0;

    distributeElements(staticArray, size, positive, positiveSize, negative, negativeSize, zero, zeroSize);

    std::cout << "Статистический массив: ";
    for (int i = 0; i < size; ++i) {
        std::cout << staticArray[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Положительные элементы: ";
    for (int i = 0; i < positiveSize; ++i) {
        std::cout << positive[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Отрицательные элементы: ";
    for (int i = 0; i < negativeSize; ++i) {
        std::cout << negative[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Нулевые элементы: ";
    for (int i = 0; i < zeroSize; ++i) {
        std::cout << zero[i] << " ";
    }
    std::cout << std::endl;

    delete[] positive;
    delete[] negative;
    delete[] zero;

    return 0;
}