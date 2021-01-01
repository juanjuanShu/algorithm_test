#include <iostream>

using namespace std;

/*
* ��һ����n��2���������������ࡣ�����������Ϊ0��֤��������������i�������������ӡ�
* ��ô���Ƕ� n/i���еݹ飬ֱ�� n/i ��Ϊ 1 ֹͣ�ݹ顣
*/

void solve(int n, int &total) {
	if (n == 1) total++;
	else{
		for (int i = 2; i <= n; i++) {
			if (n % i == 0)
				solve(n/i,total);
		}
	}
}

int main() {
	int n,total;
	while (cin>>n)
	{
		total = 0;
		solve(n,total);
		cout << total << endl;
	}

}