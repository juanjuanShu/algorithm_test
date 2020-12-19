#include <iostream>
#include <vector>
#include <queue>


using namespace std;

/*
* ���źϲ�����
* ȷ��ʹ��2·�ϲ������������ϲ��Ĵ����Ѿ�ȷ�����������������ȨֵԽС������Խ�̵ģ��Ⱥϲ���������С��
* ʹ�ö�ʵ��Ч�ʱȽϸ�
*/
template<typename T>
int combine(T q) {
	int res = 0;

	while ((int)q.size() >= 2) {
		int sum = 0;
		//��������Ԫ��
		for (int i = 0; i < 2; i++) {
			sum += q.top();
			q.pop();
		}
		
		//���ǲ����´κϲ��ĳ����� m + n;
		q.push(sum);
		//ÿ�κϲ��Ĵ����� m + n -1
		res = res + sum - 1;
	}

	return  res;
}
int main() {
	int sequence_num;
	int tmp;
	priority_queue<int, vector<int>, greater<int> > p;// С���ѣ���С���� Min
	priority_queue<int, vector<int>, less<int> > q;// �󶥶ѣ��Ӵ�С Max

	cout << "������Ҫ�ϲ������и�����" << endl;
	cin >> sequence_num;


	cout << "����ÿ�����еĳ���"<<endl;
	for (int i = 0; i < sequence_num; i++) {
		cin >> tmp;
		p.push(tmp);
		q.push(tmp);
	}
	
	int minTimes = combine(p);
	cout << "�ϲ��������С�����ǣ�"<<minTimes << endl;
	int maxTimes = combine(q);
	cout << "�ϲ�������������ǣ�" << maxTimes << endl;
	return 0;
}