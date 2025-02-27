//1912 연속합
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; // 수열의 크기
	cin >> n; // 수열의 크기 입력
	int* arr = new int[n]; // 수열을 저장할 배열 동적할당
	int* dp = new int[n]; // 연속합을 저장할 배열 동적할당
	for (int i = 0; i < n; i++) { 
		cin >> arr[i]; // 수열 입력
	}
	dp[0] = arr[0]; // 첫 번째 수열의 연속합은 첫 번째 수열과 같음
	int mx = dp[0]; // 최대 연속합은 첫 번째 수열과 같음
	for (int i = 1; i < n; i++) { // 두 번째 수열부터 n번째 수열까지 반복
		dp[i] = max(dp[i - 1] + arr[i], arr[i]); // i번째 수열의 연속합은 i-1번째 수열의 연속합과 i번째 수열 중 큰 값
		if (dp[i] > mx) mx = dp[i]; // i번째 수열의 연속합이 최대 연속합보다 크면 최대 연속합을 i번째 수열의 연속합으로 변경
	}
	cout << mx; // 최대 연속합 출력
	return 0; // 프로그램 종료
}

/*
    문제 설명: 1912 연속합
    n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다.
    단, 수는 한 개 이상 선택해야 한다. 예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자.
    여기서 정답은 12+21인 33이 정답이 된다.

    입력: 첫째 줄에 정수 n(1 ≤ n ≤ 100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다.
    수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

    출력: 첫째 줄에 답을 출력한다.

    풀이: 각 수열의 연속합을 저장할 배열을 동적할당한 후, 각 수열의 연속합을 구하였다.
*/