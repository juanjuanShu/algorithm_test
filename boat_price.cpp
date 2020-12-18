#include <iostream>
#include <fstream>
const int N = 210;
using namespace std;

/*
* 游艇问题
* 输入数据：3
*	        5 15  => r[1][2] = 5    r[1][3] = 15
*			7     => r[2][3] = 7    
*		    
* 最优解定义为m[1][n],则最优子结构是m[i][j],从i站到j站的最优办法是：从i到k ,再从k到j
* 递归关系：m[i][j] 
*			if   i = j ,m[i][i] = 0
*			else i < j ,m[i][j] = m[i][k] + m[k][j]
* 从长度为2的开始找较优解 ，直到找到长度为n的
*/


int main() {
	ifstream input("boat_input.txt");
	ofstream output("boat_output.txt");
	int m[N][N];
	int n;

	//存储r[i][j]的代价
	input >> n;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			input >> m[i][j];
		}
	}

	//m[i][i] = 0
	for (int i = 1; i <= n; i++) m[i][i] = 0;
	//从长度为2的开始找较优解 ，直到找到长度为n的
	for (int r = 2; r <= n; r++) {//r是子问题的深度
		for (int i = 1; i <= n - r + 1; i++) {//这个循环计算所有长度为r的路径
			int j = i + r - 1;//r(i,j)的长度为r
			//在i 到 j 找某一站 k ,使得r(i,k) + r(k,j)最小
			for (int k = i; k < j; k++) {
				int min_cost = m[i][k] + m[k][j];
				if (min_cost < m[i][j]) {
					//用较优解替换原来的解
					m[i][j] = min_cost;
				}
			}
		}
	}
	
	output << m[1][n] << endl;
	input.close();
	output.close();
}