#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int n, m;

    cout << "������� ������ ������� A: ";
    cin >> n;
    cout << "������� ������ ������� B: ";
    cin >> m;

    int* A = new int[n];
    int* B = new int[m];

    cout << "������� �������� ������� A:" << endl;
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    cout << "������� �������� ������� B:" << endl;
    for (int i = 0; i < m; i++) {
        cin >> B[i];
    }


    int* C = new int[n > m ? n : m];

    int k = 0;

    for (int i = 0; i < n; i++) {
        bool nodub = false;
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                nodub = true;
                break;
            }
        }
        if (!nodub) {
            bool Duplicate = false;
            for (int m = 0; m < k; m++) {
                if (C[m] == A[i]) {
                    Duplicate = true;
                    break;
                }
            }
            if (!Duplicate) {
                C[k++] = A[i];
            }
        }
    }


    for (int i = 0; i < m; i++) {
        bool isCommon = false;
        for (int j = 0; j < n; j++) {
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

    cout << "�������� �������� A � B, ������� �� �������� ������, ��� ����������:" << endl;
    for (int i = 0; i < k; i++) {
        cout << C[i] << " ";
    }
    cout << endl;


    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}