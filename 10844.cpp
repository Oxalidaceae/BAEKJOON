//10844 쉬운 계단 수
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; // n 정의
	int res = 0; // 결과 정의
	cin >> n; // 입력
	int** dp = new int* [n]; // 이중 포인터 dp 배열 동적 할당
	for (int i = 0; i < n; i++) {
		dp[i] = new int[10];
	}

	for (int i = 0; i < 10; i++) { // 0부터 9까지 반복
		dp[0][i] = 1; // 0번째 행은 1로 초기화
	}
	for (int i = 1; i < n; i++) { // 1부터 n까지 반복
		dp[i][0] = dp[i - 1][1]; // 0번째 열은 1번째 열 값으로 초기화
		dp[i][9] = dp[i - 1][8]; // 9번째 열은 8번째 열 값으로 초기화
		for (int j = 1; j < 9; j++) { // 1부터 8까지 반복
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000; // 계단 수 계산
		}
	}
	for (int i = 1; i < 10; i++) { // 1부터 9까지 반복
		res = (res + dp[n - 1][i]) % 1000000000; // 결과 계산
	}
	cout << res; // 결과 출력

	for (int i = 0; i < n; i++) { // 동적 할당 해제
		delete[] dp[i];
	}
	delete[] dp;
	return 0; // 프로그램 종료
}

/*
    https://www.acmicpc.net/problem/10844

    문제 설명: 10844 쉬운 계단 수
    45656이란 수를 보자.
    이 수는 인접한 모든 자리의 차이가 1이다. 이런 수를 계단 수라고 한다.
    N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구해보자. 0으로 시작하는 수는 계단수가 아니다.

    입력: 첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

    출력: 첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

    풀이: 다이나믹 프로그래밍을 이용하여 풀이하였다.
*/