#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include<string>
#include<map>

using namespace std;

void combination(vector<vector<int>> &res,vector<int> &candidates,int start,int target,vector<int> &result) {
	if (target < 0) {
		return;
	}
	if (target == 0) {
		res.push_back(result);
		return;
	}
	else{
		for (int i = start; i < candidates.size(); i++) {
			result.push_back(candidates[i]);
			combination(res, candidates, i, target - candidates[i], result);
			result.pop_back();
		}
	}
}

//快速排序方法一
void quick_sort1(vector<int> &nums, int left, int right) {
	if (left < right) {
		int i = left, j = left;
		int pivot = nums[right];

		for (j=left; j < right;j++) {
			if (nums[j] < pivot) {
				int tmp = nums[j];
				nums[j] = nums[i];
				nums[i] = tmp;
				i++;
			}
		}
		nums[j] = nums[i];
		nums[i] = pivot;
		quick_sort1(nums, left, i - 1);
		quick_sort1(nums, i + 1, right);
	}
}

//快速排序方法二
void quick_sort2(vector<int> &nums, int left, int right) {
	if (left < right) {
		int i = left, j = right;
		int pivot = nums[right];
		while (i < j&&nums[i] <= pivot) {
			i++;
		}
		while (i < j) {
			nums[j--] = nums[i];
		}
		while (i < j&&nums[j] >= pivot) {
			j--;
		}
		while (i < j) {
			nums[i++] = nums[j];
		}
		nums[i] = pivot;
		quick_sort2(nums, left, i - 1);
		quick_sort2(nums, i + 1, right);
	}
	
}


int main() {
	vector<int> candidates = { 2,3,6,7 };
	int target = 7;
	vector<vector<int>> res;
	vector<int> result;
	combination(res, candidates, 0, target, result);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j];
		}
		cout << endl;
	}
	
 	system("pause");
	return 0;
}