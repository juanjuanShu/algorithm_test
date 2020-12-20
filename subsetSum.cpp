#include <iostream>
#include <vector>

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

void show(int t) {
	for (int i = 0; i <= t; i++) {
		if (res[i] == 1)
			cout << itemSet[i] << ' ';
	}
	cout << endl;
}


int backTrack(int t) {
	if (times > 0 || t > set_num - 1 || sum + suffix_sum[t] < given_num) {//到达叶节点
		return times;
	}
	
	//子集树两种情况
	for (int i = 0; i <= 1; i++) {
		res[t] = i;
		if (i == 1) {
			sum += itemSet[t];
			if (sum == given_num) {
				show(t);
				times++;
				return times;
			}
			//限定函数和边界条件均满足
			if (sum < given_num && sum + suffix_sum[t] >= given_num) {
				backTrack(t + 1);
			}

			//如果选了这个分支有问题 则回退
			if (sum > given_num) 
			{
				res[t] = 0;
				sum -= itemSet[t];
				backTrack(t + 1);
			}
		}
		else {
			backTrack(t + 1);
		}
	}

	return times;
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

	times = backTrack(0);
	if (times == 0) {
		cout << "No solution" << endl;
	}
	return 0;
}