//1149 RGB 거리
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	int** arr = new int* [n]; // n개의 집을 저장할 배열
	int** dp = new int* [n]; // n개의 집을 칠하는 비용을 저장할 배열
	for (int i = 0; i < n; i++) { // n개의 집을 저장할 배열과 n개의 집을 칠하는 비용을 저장할 배열을 동적할당
		arr[i] = new int[3]; // 각 집의 RGB값을 저장할 배열을 동적할당
		dp[i] = new int[3]; // 각 집을 칠하는 비용을 저장할 배열을 동적할당
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2]; // 각 집의 RGB값 입력
	}
	dp[0][0] = arr[0][0]; // 첫 번째 집을 빨간색으로 칠하는 비용
	dp[0][1] = arr[0][1]; // 첫 번째 집을 초록색으로 칠하는 비용
	dp[0][2] = arr[0][2]; // 첫 번째 집을 파란색으로 칠하는 비용
	for (int i = 1; i < n; i++) { // 두 번째 집부터 n번째 집까지 반복
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0]; // i번째 집을 빨간색으로 칠하는 비용
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1]; // i번째 집을 초록색으로 칠하는 비용
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2]; // i번째 집을 파란색으로 칠하는 비용
	}
	int res = min({ dp[n - 1][0], dp[n - 1][1], dp[n - 1][2] }); // n번째 집을 빨간색, 초록색, 파란색으로 칠하는 비용 중 가장 작은 비용
	cout << res; // 가장 작은 비용 출력
	return 0; // 프로그램 종료
}