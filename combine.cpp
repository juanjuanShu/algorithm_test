#include <iostream>
#include <vector>
#include <queue>


using namespace std;

/*
* 最优合并问题
* 确定使用2路合并，并且两两合并的次数已经确定。联想哈夫曼树，权值越小（长度越短的）先合并，代价最小。
* 使用堆实现效率比较高
*/
template<typename T>
int combine(T q) {
	int res = 0;

	while ((int)q.size() >= 2) {
		int sum = 0;
		//弹出两个元素
		for (int i = 0; i < 2; i++) {
			sum += q.top();
			q.pop();
		}
		
		//但是参与下次合并的长度是 m + n;
		q.push(sum);
		//每次合并的次数是 m + n -1
		res = res + sum - 1;
	}

	return  res;
}
int main() {
	int sequence_num;
	int tmp;
	priority_queue<int, vector<int>, greater<int> > p;// 小顶堆，从小到大 Min
	priority_queue<int, vector<int>, less<int> > q;// 大顶堆，从大到小 Max

	cout << "输入需要合并的序列个数：" << endl;
	cin >> sequence_num;


	cout << "输入每个序列的长度"<<endl;
	for (int i = 0; i < sequence_num; i++) {
		cin >> tmp;
		p.push(tmp);
		q.push(tmp);
	}
	
	int minTimes = combine(p);
	cout << "合并所需的最小次数是："<<minTimes << endl;
	int maxTimes = combine(q);
	cout << "合并所需的最大次数是：" << maxTimes << endl;
	return 0;
}