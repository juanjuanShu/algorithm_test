#include <iostream>

using namespace std;

/*
* 将一个数n从2到它本身依次求余。如果发现余数为0，证明这个被求余的数i是它的整数因子。
* 那么我们对 n/i进行递归，直到 n/i 变为 1 停止递归。
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