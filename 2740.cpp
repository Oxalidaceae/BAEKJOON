//2740 행렬 곱셈
#include <iostream>
#include <vector>
using namespace std;

void matrix_multiplication(vector<vector<int>> arr1, vector<vector<int>> arr2) { // 행렬 곱셈 함수
	int n = arr1.size(); // 행렬 A의 행의 개수
	int m = arr1[0].size(); // 행렬 A 및 B의 열의 개수
	int k = arr2[0].size(); // 행렬 B의 열의 개수
	vector<vector<int>> result(n, vector<int>(k, 0)); // 결과 행렬
	for (int i = 0; i < n; i++) { // 행렬 곱셈
		for (int j = 0; j < k; j++) {
			for (int l = 0; l < m; l++) {
				result[i][j] += arr1[i][l] * arr2[l][j]; // 결과 저장
			}
		}
	}
	for (int i = 0; i < n; i++) { // 결과 출력
		for (int j = 0; j < k; j++) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k; // 행렬 A의 행의 개수, 행렬 A 및 B의 열의 개수, 행렬 B의 열의 개수
	cin >> n >> m; // 행렬 A의 행, 열 입력
	vector<vector<int>> arr1(n, vector<int>(m)); // 행렬 A
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr1[i][j]; // 행렬 A 입력
		}
	}
	cin >> m >> k; // 행렬 B의 행, 열 입력
	vector<vector<int>> arr2(m, vector<int>(k)); // 행렬 B
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> arr2[i][j]; // 행렬 B 입력
		}
	}
	matrix_multiplication(arr1, arr2); // 행렬 곱셈 함수 호출
	return 0; // 프로그램 종료
}

/*
    https://www.acmicpc.net/problem/2740
    
    문제 설명: 2740 행렬 곱셈
    N*M크기의 행렬 A와 M*K크기의 행렬 B가 주어졌을 때, 두 행렬을 곱하는 프로그램을 작성하시오.

    입력: 첫째 줄에 행렬 A의 크기 N 과 M이 주어진다. 둘째 줄부터 N개의 줄에 행렬 A의 원소 M개가 순서대로 주어진다. 그 다음 줄에는 행렬 B의 크기 M과 K가 주어진다.
    이어서 M개의 줄에 행렬 B의 원소 K개가 차례대로 주어진다. N과 M, 그리고 K는 100보다 작거나 같고, 행렬의 원소는 절댓값이 100보다 작거나 같은 정수이다.

    출력: 첫째 줄부터 N개의 줄에 행렬 A와 B를 곱한 행렬을 출력한다. 행렬의 각 원소는 공백으로 구분한다.

    풀이: 행렬 곱셈을 구현하였다.
*/
