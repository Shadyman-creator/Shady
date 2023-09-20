
/*№1
1.	Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры).
 Необходимо создать третий массив минимально возможного раз-мера,
 в котором нужно собрать общие элементы двух массивов без повторений.
*/

#include <iostream>

int main() {
    setlocale(LC_ALL, "rus");
    int M, N;

    // Ввод размеров массивов
    std::cout << "Введите размер массива А: ";
    std::cin >> M;
    std::cout << "Введите размер массива B: ";
    std::cin >> N;

    // Создание массивов А и B
    int* A = new int[M];
    int* B = new int[N];

    // Ввод элементов массива A
    std::cout << "Введите элементы массива A:" << std::endl;
    for (int i = 0; i < M; i++) {
        std::cin >> A[i];
    }

    // Ввод элементов массива B
    std::cout << "Введите элементы массива B:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    // Создание массива C для общих элементов
    int* C = new int[M > N ? M : N];  // Максимальный размер массива C равен максимальному из M и N

    int k = 0; // Индекс для массива C

    // Поиск общих элементов и их добавление в массив C без повторений
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                bool isDuplicate = false;
                // Проверка на дубликаты в массиве C
                for (int m = 0; m < k; m++) {
                    if (C[m] == A[i]) {
                        isDuplicate = true;
                        break;
                    }
                }
                if (!isDuplicate) {
                    C[k] = A[i];
                    k++;
                }
                break;
            }
        }
    }

    // Вывод общих элементов
    std::cout << "Общие элементы массивов A и B без повторений:" << std::endl;
    for (int i = 0; i < k; i++) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    // Освобождение выделенной памяти
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}



/*№2

2.	Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры).
 Необходимо создать третий массив минимально возможного раз-мера, в котором нужно собрать элементы массива A,
 которые не включаются в массив B, без повторений.
*/
#include <iostream>

int main() {
    setlocale(LC_ALL, "rus");
    int M, N;

    // Ввод размеров массивов
    std::cout << "Введите размер массива A: ";
    std::cin >> M;
    std::cout << "Введите размер массива B: ";
    std::cin >> N;

    // Создание массивов A и B
    int* A = new int[M];
    int* B = new int[N];

    // Ввод элементов массива A
    std::cout << "Введите элементы массива A:" << std::endl;
    for (int i = 0; i < M; i++) {
        std::cin >> A[i];
    }

    // Ввод элементов массива B
    std::cout << "Введите элементы массива B:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    // Создание массива C для элементов из A, которые не включаются в B
    int* C = new int[M];  // Максимальный размер массива C равен размеру массива A

    int k = 0; // Индекс для массива C

    // Поиск элементов из A, которые не включаются в B
    for (int i = 0; i < M; i++) {
        bool isNotInB = true;
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                isNotInB = false;
                break;
            }
        }
        if (isNotInB) {
            bool isDuplicate = false;
            // Проверка на дубликаты в массиве C
            for (int m = 0; m < k; m++) {
                if (C[m] == A[i]) {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate) {
                C[k] = A[i];
                k++;
            }
        }
    }

    // Вывод элементов из A, которые не включаются в B
    std::cout << "Элементы массива A, которые не включаются в B без повторений:" << std::endl;
    for (int i = 0; i < k; i++) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    // Освобождение выделенной памяти
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}



/*№3

3.	Даны два массива: А[M] и B[N] (M и N вводятся с клавиатуры).
 Необходимо создать третий массив минимально возможного раз-мера, в котором нужно собрать элементы массивов A и B,
 которые не являются общими для них, без повторений.
*/
#include <iostream>

int main() {
    setlocale(LC_ALL, "rus");
    int M, N;

    std::cout << "Введите размер массива A: ";
    std::cin >> M;
    std::cout << "Введите размер массива B: ";
    std::cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    std::cout << "Введите элементы массива A:" << std::endl;
    for (int i = 0; i < M; i++) {
        std::cin >> A[i];
    }

    std::cout << "Введите элементы массива B:" << std::endl;
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    int sizeC = (M > N) ? M : N;
    int* C = new int[sizeC];

    int k = 0;

    // Заполнение массива C элементами из массива A, которые не включаются в B
    for (int i = 0; i < M; i++) {
        bool isCommon = false;
        for (int j = 0; j < N; j++) {
            if (A[i] == B[j]) {
                isCommon = true;
                break;
            }
        }
        if (!isCommon) {
            bool isDuplicate = false;
            for (int m = 0; m < k; m++) {
                if (C[m] == A[i]) {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate) {
                C[k++] = A[i];
            }
        }
    }

    // Заполнение массива C элементами из массива B, которые не включаются в A
    for (int i = 0; i < N; i++) {
        bool isCommon = false;
        for (int j = 0; j < M; j++) {
            if (B[i] == A[j]) {
                isCommon = true;
                break;
            }
        }
        if (!isCommon) {
            bool isDuplicate = false;
            for (int m = 0; m < k; m++) {
                if (C[m] == B[i]) {
                    isDuplicate = true;
                    break;
                }
            }
            if (!isDuplicate) {
                C[k++] = B[i];
            }
        }
    }

    std::cout << "Элементы массивов A и B, которые не являются общими, без повторений:" << std::endl;
    for (int i = 0; i < k; i++) {
        std::cout << C[i] << " ";
    }
    std::cout << std::endl;

    // Освобождение выделенной памяти
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}


/*
№8

8.	Написать функцию, которая получает указатель на статический массив и его размер. Функция распределяет положительные, от-рицательные и нулевые элементы в отдельные динамические мас-сивы.
*/
#include <iostream>

#include <iostream>

void distributeElements(const int* staticArray, int size, int*& positiveArray, int& positiveSize, int*& negativeArray, int& negativeSize, int*& zeroArray, int& zeroSize) {
    positiveSize = negativeSize = zeroSize = 0; // Инициализируем размеры массивов

    // Первый проход: определяем размеры массивов
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

    // Выделяем память для динамических массивов
    positiveArray = new int[positiveSize];
    negativeArray = new int[negativeSize];
    zeroArray = new int[zeroSize];

    // Второй проход: заполняем динамические массивы
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
    int staticArray[] = { 3, -1, 0, 5, -2, 7, 0 };
    int size = sizeof(staticArray) / sizeof(staticArray[0]);

    int* positiveArray = nullptr;
    int positiveSize = 0;
    int* negativeArray = nullptr;
    int negativeSize = 0;
    int* zeroArray = nullptr;
    int zeroSize = 0;

    distributeElements(staticArray, size, positiveArray, positiveSize, negativeArray, negativeSize, zeroArray, zeroSize);

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

    // Освобождаем память для динамических массивов
    delete[] positiveArray;
    delete[] negativeArray;
    delete[] zeroArray;

    return 0;
}

/*№7

7.	Написать функцию, которая получает указатель на динамический массив и его размер.
Функция должна удалить из массива все простые числа и вернуть указатель на новый динамический мас-сив.
*/
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
    // Создание нового динамического массива без простых чисел
    int* newArray = new int[size];
    int newSize = 0;

    // Копирование элементов из исходного массива в новый массив, исключая простые числа
    for (int i = 0; i < size; i++) {
        if (!isPrime(array[i])) {
            newArray[newSize++] = array[i];
        }
    }

    // Освобождение памяти, занимаемой исходным массивом
    delete[] array;

    // Обновление размера исходного массива и возврат нового массива
    size = newSize;
    return newArray;
}

int main() {
    setlocale(LC_ALL, "rus");
    int size;
    std::cout << "Введите размер динамического массива: ";
    std::cin >> size;

    // Создание и ввод элементов динамического массива
    int* dynamicArray = new int[size];
    std::cout << "Введите элементы массива:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cin >> dynamicArray[i];
    }

    // Вызов функции для удаления простых чисел из массива
    dynamicArray = removePrimes(dynamicArray, size);

    // Вывод элементов массива после удаления простых чисел
    std::cout << "Массив после удаления простых чисел:" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << dynamicArray[i] << " ";
    }
    std::cout << std::endl;

    // Освобождение памяти, занимаемой динамическим массивом
    delete[] dynamicArray;

    return 0;
}

