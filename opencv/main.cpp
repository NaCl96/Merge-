#include <iostream>
//#include <algorithm>
#include <vector>
#include<string>

using namespace std;

void merge(int *data, int start, int end, int *result);
//class Student {
//private:
//	string m_name;
//	int m_age;
//	float m_score;
//public:
//	Student(string name = "", int age = 0, float score = 0.0f);
//	Student(const Student &stu);
//public:
//	void display();
//	Student &operator=(const Student &stu);
//};
//Student::Student(string name,int age,float score):m_name(name),m_age(age),m_score(score){
//	cout << "调用构造函数" << endl;
//}
//Student::Student(const Student &stu) {
//	this->m_name = stu.m_name;
//	this->m_age = stu.m_age;
//	this->m_score = stu.m_score;
//	cout << "Copy constructor was called." << endl;
//}
//
//Student &Student::operator=(const Student &stu) {
//	this->m_name = stu.m_name;
//	this->m_age = stu.m_age;
//	this->m_score = stu.m_score;
//	cout << "operator=() was called." << endl;
//	return *this;
//}
//
//void Student::display(){
//	cout<<m_name << "的年龄是" << m_age << "，成绩是" << m_score << endl;
//}
//
//void fibonaccl(int n) {
//	if (n < 0) {
//		cout << "输入错误：" << endl;
//		return;
//	}
//
//	int f = 1;
//	int k = k;
//	int temp;
//	cout << "Fibonaccl is:" << endl;
//	for (int i = 1; i < n; i++) {
//		if (i < 2) {
//			cout << k << " ";
//		}
//		else {
//			cout << k << " ";
//			temp = k + f;
//			f = k;
//			k = temp;
//		}
//	}
//}
//
//int Partition1(vector<int> &a, int i, int j) {
//	int start = i;
//	int end = j;
//	int x = a[i];
//	while (start < end) {
//		while (a[end] >= x&&end>start)
//			end--;
//		swap(a[start], a[end]);
//		while (a[start] <= x&&end > start)
//			start++;
//		swap(a[start],a[end]);
//	}
//	cout << "center address:" << start << endl;
//	/*for (int i = 0; i < j; j++) {
//		cout << a[i];
//	}*/
//	return start;
//}
//
//void quickSort1(vector<int> &a, int p, int r) {
//	if (p < r) {
//		int x = Partition1(a, p, r);
//		quickSort1(a, p, x - 1);
//		quickSort1(a, x + 1, r);
//	}
//}
//
//double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
//	
//	int m = nums1.size();
//	int n = nums2.size();
//	if (m > n) {
//		return findMedianSortedArrays(nums2, nums1);
//	}
//
//	int iMin = 0, iMax = m;
//	int halfLen = (m + n + 1) / 2;
//	while (iMin <= iMax) {
//		int i = (iMin + iMax) / 2;
//		int j = halfLen - i;
//		if (i<iMax&&nums2[j - 1]>nums1[i]) {
//			iMin = i + 1;
//		}else if (i > iMin&&nums1[i - 1] > nums2[j]) {
//			iMax = i - 1;
//		}else {
//			int maxLeft = 0;
//			if (i == 0) { maxLeft = nums2[j - 1]; }
//			else if (j == 0) { maxLeft = nums1[i - 1]; }
//			else {
//				maxLeft = max(nums1[i - 1], nums2[j - 1]);
//			}
//			if ((m + n) % 2 == 1) { return maxLeft; }
//			
//			int minRight = 0;
//			if (i == m) { minRight = nums2[j]; }
//			else if (j == n) { minRight = nums1[i]; }
//			else { minRight = min(nums1[i], nums2[j]); }
//
//			return (maxLeft + minRight) / 2.0;
//
//
//		}
//	}
//}

//int  BisectionFind(vector<int> &res, int l,int r, int target) {
//	int index = -1;
//	if (l < r) {
//		int mid = (r + l) / 2;
//		if (target < res[mid]) {
//			r = mid - 1;
//			BisectionFind(res, l, r, target);
//		}
//		else if (target>res[mid]) {
//			l = mid + 1;
//			BisectionFind(res, l, r, target);
//		}
//		else {
//			index= mid;
//			return index;
//		}
//		return -1;
//	}
//}

//

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