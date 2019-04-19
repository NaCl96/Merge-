#include <iostream>
//#include <algorithm>
#include <vector>
#include<string>

using namespace std;

void merge(int *data, int start, int end, int *result);


void Merge(int *data, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	int i, j, k;
	int *L = new int[n1 + 1];
	int *R = new int[n2 + 1];
	for (i = 0; i < n1; i++) {
		L[i] = data[p + i];
	}
	for (j = 0; j < n2; j++) {
		R[j] = data[q + 1 + j];
	}

	L[n1] = 11111111;
	R[n2] = 11111111;
	for (i = 0, j = 0, k = p; k <=r; k++) {
		if (L[i] < R[j]) {
			data[k] = L[i++];
		}
		else {
			data[k] = R[j++];
		}
	}

	delete []L;
	delete[]R;

}

void merge_Sort(int *data, int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		merge_Sort(data, l, m);
		merge_Sort(data, m + 1, r);
		Merge(data, l, m, r);
	}
}

int main() {
	int data[6] = { 3,42,1,5,2,8 };
	for (int i = 0; i < 6; i++) {
		cout << data[i] << " ";
	}
	cout << endl;

	merge_Sort(data, 0, 5);
	for (int i = 0; i < 6; i++) {
		cout << data[i] << " ";
	}
	cout << endl;	
	

	system("pause");
	return 0;
}