#include <iostream>
//#include <algorithm>
#include <vector>
#include<string>
#include<map>

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


//Leetcode两数之和
vector<int> twoSum(vector<int> &nums, int target) {
	vector<int> res;
	map<int, int> tmp;
	for (int i = 0; i < nums.size(); i++) {
		tmp[nums[i]] = i;
	}
	for (int i = 0; i < nums.size(); i++) {
		if (tmp.count(target - nums[i]) != 0 && tmp[target - nums[i]] != i) {
			res.push_back(i);
			res.push_back(tmp[target - nums[i]]);
			break;
		}
	}
	return res;
}

int main() {

	//Map<>的使用

	//int data[6] = { 3,42,1,5,2,8 };
	//for (int i = 0; i < 6; i++) {
	//	cout << data[i] << " ";
	//}
	//cout << endl;

	//merge_Sort(data, 0, 5);
	//for (int i = 0; i < 6; i++) {
	//	cout << data[i] << " ";
	//}
	//cout << endl;	
	//

	vector<int> nums = { 2,4,5,7,9 };
	int target = 12;
	vector<int> res = twoSum(nums, target);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}