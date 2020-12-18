#include <iostream>
#include <vector>


using namespace std;

/*
* 最长单调递增子序列
* 问题：给定一个数组，找出一个最长的单调自增子序列（可以不连续，但是顺序不能乱）。
* 例如：{5， 6， 7， 1， 2， 8}，则最长的单调递增子序列为{5,6,7,8}
* 设长度为N的数组{a0,a1,a2,a3...a(n-1)}
* L[j]:以 a[j]结尾的数组序列的最长递增子序列的长度
* L[j] = {max(L[i]) + 1 }    i < j 并且 a[i] < a[j]
* 最后遍历所有的L[j] 找出最大值即为最大递增子序列
*/

void lis(int arr[], int len) {
	vector<int> longest(len,1);

	for (int j = 0; j < len; j++) {
		for (int i = 0; i < j; i++) {
			if (arr[i] < arr[j] && (longest[j] < longest[i] + 1)) {
				longest[j] = longest[i] + 1;
			}
		}
	}

	int max_longest = longest[0];
	for (int j = 1; j < longest.size(); j++) {
		if (longest[j] > max_longest) {
			max_longest = longest[j];
		}
	}

	cout << max_longest << endl;
}

int main() {
	int arr[] = { 1,4,5,7,6,2,3,8,9 };
	int length = sizeof(arr) / sizeof(arr[0]);
	lis(arr, length);

	return 0;
}