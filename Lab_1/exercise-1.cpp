#include <iostream>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	int n, m;
	cout << "¬ведите размер 1 массива: \n";
	cin >> n;
	cout << "¬ведите размер 2 массива: \n";
	cin >> m;

	int* A = new int[n];
	int* B = new int[m];

	for (int i = 0; i < n; i++) {
		cout << "¬ведите " << i << " элемент массива A: \n";
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cout << "¬ведите " << i << " элемент массива B: \n";
		cin >> B[i];
	}

	int* C = new int[n < m ? n : m];
	int k = 0;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {

			if (A[i] == B[j]) {
				bool dubl = false;

				for (int m = 0; m < k; m++) {

					if (C[k] == A[i]) {
						dubl = true;
						break;
					}
				}
				if (!dubl) {
					C[k] = A[i];
					k++;
				}
				break;
			}
		}
	}
	cout << "ќбщие элементы массивов A и B без повторений:" << std::endl;
	for (int i = 0; i < k; i++) {
		cout << C[i] << " ";
	}
	cout << "\n";

	delete[] A;
	delete[] B;
	delete[] C;

	return 0;
}