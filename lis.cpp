#include <iostream>
#include <vector>


using namespace std;

/*
* ���������������
* ���⣺����һ�����飬�ҳ�һ����ĵ������������У����Բ�����������˳�����ң���
* ���磺{5�� 6�� 7�� 1�� 2�� 8}������ĵ�������������Ϊ{5,6,7,8}
* �賤��ΪN������{a0,a1,a2,a3...a(n-1)}
* L[j]:�� a[j]��β���������е�����������еĳ���
* L[j] = {max(L[i]) + 1 }    i < j ���� a[i] < a[j]
* ���������е�L[j] �ҳ����ֵ��Ϊ������������
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