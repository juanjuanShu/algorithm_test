#include <vector>
#include <iostream>


using namespace std;

/*
* 子集和问题 s c
* 排列树问题
* 约束函数 sum（子集）<= c;限界函数：加上剩余的 > c 非法
*
*/
const int N = 1000;
int set_num;
int given_num;
int  itemSet[N];
int  res[N];//存储结果的数组
int  suffix_sum[N];//存储后缀和
int sum = 0; //当前和
int times = 0;//成功的次数

void show() {
	for (int i = 0; i < set_num; i++) {
		if (res[i] == 1)
			cout << itemSet[i] << ' ';
	}
	cout << endl;
}


void backTrack(int t, int sum) {
	if (t > set_num || sum + suffix_sum[t] < given_num) {
		return;
	}

	if (sum == given_num) {
		show();
		return;
	}

	//子集树两种情况
	res[t] = 1;
	//约束函数和限界函数
	if (sum + itemSet[t] <= given_num && sum + suffix_sum[t] >= given_num)
		backTrack(t + 1, sum + itemSet[t]);

	res[t] = 0;
	backTrack(t + 1, sum);
}
int main() {
	int tmp;

	cout << "输入集合的个数：" << endl;
	cin >> set_num;
	cout << "输入c：" << endl;
	cin >> given_num;

	cout << "输入集合中的元素" << endl;
	for (int i = 0; i < set_num; i++) {
		cin >> itemSet[i];
		res[i] = 0;
	}

	suffix_sum[set_num - 1] = itemSet[set_num - 1];
	for (int i = set_num - 2; i >= 0; i--) {
		suffix_sum[i] = itemSet[i] + suffix_sum[i + 1];
	}

	backTrack(0, 0);

	return 0;
}