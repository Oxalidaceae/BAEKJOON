//9251 LCS
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string a, b; // 문자열 a, b
	cin >> a >> b; // 문자열 a, b 입력
	int** dp = new int* [a.length() + 1]; // dp 배열 동적 할당
	for (int i = 0; i <= a.length(); i++) {
		dp[i] = new int[b.length() + 1];
	}
	for (int i = 0; i <= a.length(); i++) {
		for (int j = 0; j <= b.length(); j++) {
			dp[i][j] = 0; // dp 배열 초기화
		}
	}

	for (int i = 1; i <= a.length(); i++) {
		for (int j = 1; j <= b.length(); j++) {
			if (a[i - 1] == b[j - 1]) { // 문자열 a, b의 문자가 같을 경우
				dp[i][j] = dp[i - 1][j - 1] + 1; // dp 배열 갱신
			}
			else { // 문자열 a, b의 문자가 다를 경우
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // dp 배열 갱신
			}
		}
	}
	cout << dp[a.length()][b.length()]; // LCS 출력

	for (int i = 0; i <= a.length(); i++) { // dp 배열 동적 할당 해제
		delete[] dp[i]; 
	}
	delete[] dp;
	return 0; // 프로그램 종료
}

/*
    https://www.acmicpc.net/problem/9251

    문제 설명: 9251 LCS
    LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.
    예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

    입력: 첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

    출력: 첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.

    풀이: dp를 이용하여 LCS를 구현하였다.
*/