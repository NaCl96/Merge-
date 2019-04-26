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