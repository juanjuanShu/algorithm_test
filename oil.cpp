#include <iostream>
#include <vector>


using namespace std;

/*
* ������������
* �������ݣ�n k  ���������ͺ����ʻ n km;;���� k ������վ��
* k+1������      �� k ������վ��� k - 1������վ֮��ľ���
* һ��ʼ����� k ������վ��ô���� k + 1������
* ����     1   2   3   4  5  1  6  6
* ����վ $   1   2   3  4  5  6  7   ^
* 
* �����ɨ���������վ�ľ��룬������������һ����������������������ܵľ��룬����� ���޽⡱
* ���򾡿��ܵ���Զ��̰�Ĳ��ԣ�
* 
* ÿͣһ�Σ�������ͣ�num++
*/

int oil(vector<double> arr_distance, int distance_after_oil) {
	int num = 0;

	for (int i = 0,s = 0; i < arr_distance.size(); i++) {
		//�޽�
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

	cout << "��������ͺ��������ʻ�ľ��룺" << endl;
	cin >> distance_after_oil ;
	cout << "�������վ�ĸ���:" << endl;
	cin >> oil_station_nums;
	

	cout << "����� k ������վ��� k - 1������վ֮��ľ���"<<endl;
	for (int i = 0; i <= oil_station_nums; i++) {
		cin >> tmp;
		arr_distance.push_back(tmp);
	}

	int num = oil(arr_distance,distance_after_oil);
	cout << "���ټ��ʹ���" << num << endl;
	return 0;
}