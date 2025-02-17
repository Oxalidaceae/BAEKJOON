//9184 신나는 함수 실행
#include <iostream>
using namespace std;

int dp[21][21][21]; // dp[a][b][c]는 w(a, b, c)의 값을 의미한다.

int f(int a, int b, int c) { // 재귀함수 w(a, b, c)를 구하는 함수
	if (a <= 0 || b <= 0 || c <= 0) // a, b, c 중 하나라도 0보다 작거나 같으면
		return 1; // 1 반환
	else if (a > 20 || b > 20 || c > 20) // a, b, c 중 하나라도 20보다 크면
		return f(20, 20, 20); // w(20, 20, 20) 반환
	else if (dp[a][b][c] != 0) // dp[a][b][c]가 0이 아니면
		return dp[a][b][c]; // dp[a][b][c] 반환
	else if (a < b && b < c) // a < b < c이면
		dp[a][b][c] = f(a, b, c - 1) + f(a, b - 1, c - 1) - f(a, b - 1, c); // w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c) 반환
	else // 그 외의 경우
		dp[a][b][c] = f(a - 1, b, c) + f(a - 1, b - 1, c) + f(a - 1, b, c - 1) - f(a - 1, b - 1, c - 1);
        // w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1) 반환
	return dp[a][b][c];
}

int main() {
	int a, b, c; // a, b, c
	while (true) { // 무한 루프
		cin >> a >> b >> c; // a, b, c 입력
		if (a == -1 && b == -1 && c == -1) break; // a, b, c가 -1이면 루프 종료
		cout << "w(" << a << ", " << b << ", " << c << ") = " << f(a, b, c) << endl; // w(a, b, c) 출력
	}
	return 0; // 프로그램 종료
}

/*
    https://www.acmicpc.net/problem/9184

    문제 설명: 9184 신나는 함수 실행
    재귀 호출만 생각하면 신이 난다! 아닌가요?
    다음과 같은 재귀함수 w(a, b, c)가 있다.
    if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
        1
    if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
        w(20, 20, 20)
    if a < b and b < c, then w(a, b, c) returns:
        w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
    otherwise it returns:
        w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
    위의 함수를 구현하는 것은 매우 쉽다. 하지만, 그대로 구현하면 값을 구하는데 매우 오랜 시간이 걸린다. (예를 들면, a=15, b=15, c=15)
    a, b, c가 주어졌을 때, w(a, b, c)를 출력하는 프로그램을 작성하시오.

    입력: 입력은 세 정수 a, b, c로 이루어져 있으며, 한 줄에 하나씩 주어진다. 입력의 마지막은 -1 -1 -1로 나타내며,
    세 정수가 모두 -1인 경우는 입력의 마지막을 제외하면 없다.

    출력: 입력으로 주어진 각각의 a, b, c에 대해서, w(a, b, c)를 출력한다.

    풀이: dp를 이용하여 재귀함수를 구현하였다.
*/