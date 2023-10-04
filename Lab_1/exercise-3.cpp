#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int n, m;

    cout << "¬ведите размер массива A: ";
    cin >> n;
    cout << "¬ведите размер массива B: ";
    cin >> m;

    int* A = new int[n];
    int* B = new int[m];

    cout << "¬ведите элементы массива A:" << endl;
    for (int i = 0; i < n; i++) {
        std::cin >> A[i];
    }

    cout << "¬ведите элементы массива B:" << endl;
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
            bool Dubl = false;
            for (int m = 0; m < k; m++) {
                if (C[m] == A[i]) {
                    Dubl = true;
                    break;
                }
            }
            if (!Dubl) {
                C[k++] = A[i];
            }
        }
    }


    for (int i = 0; i < m; i++) {
        bool noDub2 = false;
        for (int j = 0; j < n; j++) {
            if (B[i] == A[j]) {
                noDub2 = true;
                break;
            }
        }
        if (!noDub2) {
            bool Dubl = false;
            for (int m = 0; m < k; m++) {
                if (C[m] == B[i]) {
                    Dubl = true;
                    break;
                }
            }
            if (!Dubl) {
                C[k++] = B[i];
            }
        }
    }

    cout << "Ёлементы массивов A и B, которые не €вл€ютс€ общими, без повторений:" << endl;
    for (int i = 0; i < k; i++) {
        cout << C[i] << " ";
    }
    cout << endl;


    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}