#include <iostream>
#include <fstream>
const int N = 210;
using namespace std;

/*
* ��ͧ����
* �������ݣ�3
*	        5 15  => r[1][2] = 5    r[1][3] = 15
*			7     => r[2][3] = 7    
*		    
* ���Žⶨ��Ϊm[1][n],�������ӽṹ��m[i][j],��iվ��jվ�����Ű취�ǣ���i��k ,�ٴ�k��j
* �ݹ��ϵ��m[i][j] 
*			if   i = j ,m[i][i] = 0
*			else i < j ,m[i][j] = m[i][k] + m[k][j]
* �ӳ���Ϊ2�Ŀ�ʼ�ҽ��Ž� ��ֱ���ҵ�����Ϊn��
*/


int main() {
	ifstream input("boat_input.txt");
	ofstream output("boat_output.txt");
	int m[N][N];
	int n;

	//�洢r[i][j]�Ĵ���
	input >> n;
	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			input >> m[i][j];
		}
	}

	//m[i][i] = 0
	for (int i = 1; i <= n; i++) m[i][i] = 0;
	//�ӳ���Ϊ2�Ŀ�ʼ�ҽ��Ž� ��ֱ���ҵ�����Ϊn��
	for (int r = 2; r <= n; r++) {//r������������
		for (int i = 1; i <= n - r + 1; i++) {//���ѭ���������г���Ϊr��·��
			int j = i + r - 1;//r(i,j)�ĳ���Ϊr
			//��i �� j ��ĳһվ k ,ʹ��r(i,k) + r(k,j)��С
			for (int k = i; k < j; k++) {
				int min_cost = m[i][k] + m[k][j];
				if (min_cost < m[i][j]) {
					//�ý��Ž��滻ԭ���Ľ�
					m[i][j] = min_cost;
				}
			}
		}
	}
	
	output << m[1][n] << endl;
	input.close();
	output.close();
}