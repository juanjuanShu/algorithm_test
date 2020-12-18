#include <iostream>

using namespace std;

template <typename T>
void BinarySearch_Changed(const T a[], T seekValue, int length, int& i, int& j) {
	//i :小于seekValue的最大位置i
	//j :大于seekValue的最小位置j
	int  lleft, left, rright, right, middle;
	left = lleft = 0;
	right = rright = length - 1;

	while (left <= right) {
		middle = left + (right - left) / 2;

		if (seekValue == a[middle]) {
			i = j = middle;
			return;
		}

		if (seekValue > a[middle]) {
			left = middle + 1;
		}
		else {
			right = middle - 1;
		}
	}

	i = left - 1; j = left;
	if (left > rright) {
		i = rright, j = -1;
	}
	if (right < 0) {
		i = -1, j = 0;
	}

	return;
}
/*
* 1 2 3 4 5 6 7   8   9
* 1 3 5 6 7 9 12 13  14
* 10
* [1,9]  mid = 5  7 < 10
* [6,9]  mid = 7  12>10
* [6,6]  9 < 10   left = 7       i = 6    j = 7
* 8
* [1,9]  mid = 5  7 < 8
* [6,9]  mid = 7  12>8
* [6,6]  8 < 9  right = 5  left = 6    i = 5   j = 6
* 15
* [1,9]  mid = 5  14 <15
* [6,9]  mid = 7  12 <15
* [8,9]  mid = 8
* [9,9]  mid = 9  14 <15 i = 9 j = -1
*/

int main() {

	double arr[] = { 1 ,3 ,5 ,6, 7 ,9 ,12 ,13 , 14 };
	double seekValue;
	int i, j;

	cout << "输入要查找的数" << endl;
	while (cin >> seekValue) {
		cout << seekValue << endl;
		int length = sizeof(arr) / sizeof(arr[0]);
		BinarySearch_Changed(arr, seekValue, length, i, j);
		cout << i << " " << j << endl;
	}
	
	return 0;
}




