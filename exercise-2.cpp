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

	cout << "��������� ������ A: ";
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	cout << "��������� ������ B: ";
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}

	int* C = new int[n];
	int k = 0;

	for (int i = 0; i < n; i++) {
		bool NotB = true;
		for (int j = 0; j < m; j++) {
			if (A[i] == B[j]) {
				NotB = false;
				break;
			}
		}
		if (!NotB) {
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
		}
	}
	cout << "�������� ������� A, ������� �� ���������� � B ��� ����������:\n";
	for (int i = 0; i < k; i++) {
		cout << C[i] << " ";
	}
	cout << "\n";

	delete[] A;
	delete[] B;
	delete[] C;

	return 0;
}