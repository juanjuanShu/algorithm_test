#include <iostream>
#include <vector>


using namespace std;

/*
* 汽车加油问题
* 输入数据：n k  汽车加满油后可行驶 n km;途中有 k 个加油站。
* k+1个整数      第 k 个加油站与第 k - 1个加油站之间的距离
* 一开始不理解 k 个加油站怎么会有 k + 1个数据
* 距离     1   2   3   4  5  1  6  6
* 加油站 $   1   2   3  4  5  6  7   ^
* 
* 先逐个扫描各个加油站的距离，若发现其中有一个距离大于汽车加满油能跑的距离，则输出 “无解”
* 否则尽可能的跑远（贪心策略）
* 
* 每停一次，则加满油，num++
*/

int oil(vector<double> arr_distance, int distance_after_oil) {
	int num = 0;

	for (int i = 0,s = 0; i < arr_distance.size(); i++) {
		//无解
		if (distance_after_oil < arr_distance[i]) {
			cout << "No solution" << endl;
			return num;
		}

		s += arr_distance[i];
		if (s > distance_after_oil) {
			num++;
			s = arr_distance[i];
		}
	}

	return num;
}


int main() {
	int distance_after_oil, oil_station_nums;
	double tmp;
	vector<double> arr_distance;

	cout << "输入加满油后最多能行驶的距离：" << endl;
	cin >> distance_after_oil ;
	cout << "输入加油站的个数:" << endl;
	cin >> oil_station_nums;
	

	cout << "输入第 k 个加油站与第 k - 1个加油站之间的距离"<<endl;
	for (int i = 0; i <= oil_station_nums; i++) {
		cin >> tmp;
		arr_distance.push_back(tmp);
	}

	int num = oil(arr_distance,distance_after_oil);
	cout << "最少加油次数" << num << endl;
	return 0;
}