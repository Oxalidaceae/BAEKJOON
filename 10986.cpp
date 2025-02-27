//10986 나머지 합
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; // n, m 정의
	cin >> n >> m; // 입력
	vector<int> arr(n); // n개의 수를 저장할 벡터 arr 정의
	vector<int> prefix(m, 0); // m개의 수를 저장할 벡터 prefix 정의
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; // n개의 수 입력
	}

	int sum = 0; // sum 정의
	for (int i = 0; i < n; i++) { // i가 0부터 n-1까지 반복
		sum += arr[i]; // sum에 arr[i] 더하기
		sum %= m; // sum을 m으로 나눈 나머지를 sum에 저장
		prefix[sum]++; // prefix[sum]에 1 더하기
	}

	long long ans = prefix[0]; // ans에 prefix[0] 저장
	for (int i = 0; i < m; i++) { // i가 0부터 m-1까지 반복
		ans += (long long)prefix[i] * (prefix[i] - 1) / 2; // ans에 prefix[i] * (prefix[i] - 1) / 2 더하기
        // prefix[i] * (prefix[i] - 1) / 2는 prefix[i]개 중 2개를 뽑는 조합의 수이다.
	}

	cout << ans; // ans 출력
	return 0; // 프로그램 종료
}

/*
    https://www.acmicpc.net/problem/10986

    문제 설명: 10986 나머지 합
    수 N개 A1, A2, ..., AN이 주어진다. 이때, 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 구하는 프로그램을 작성하시오.
    즉, Ai + ... + Aj (i ≤ j) 의 합이 M으로 나누어 떨어지는 (i, j) 쌍의 개수를 구해야 한다.

    입력: 첫째 줄에 N과 M이 주어진다. (1 ≤ N ≤ 10^6, 2 ≤ M ≤ 10^3)
    둘째 줄에 N개의 수 A1, A2, ..., AN이 주어진다. (0 ≤ Ai ≤ 10^9)

    출력: 첫째 줄에 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 출력한다.

    풀이: 누적 합을 이용하여 풀이하였다.
    누적 합을 구하면서 M으로 나눈 나머지를 저장하는 배열을 만들어준다.
    이후, 나머지가 같은 부분 구간의 개수를 구해주면 된다.
*/