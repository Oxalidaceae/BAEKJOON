//1629 곱셈
#include <iostream>
#include <cmath>
using namespace std;

long long power(long long A, long long B, long long C) { // 거듭제곱을 구하는 함수
	if (B == 1) return A % C; // B가 1이면 A를 C로 나눈 나머지 반환
	long long temp = power(A, B / 2, C); // 거듭제곱을 구하는 함수를 재귀적으로 호출
	if (B % 2 == 0) return (temp * temp) % C; // B가 짝수이면 거듭제곱의 제곱을 C로 나눈 나머지 반환
	else return (((temp * temp) % C) * A) % C; // B가 홀수이면 거듭제곱의 제곱에 A를 곱한 값을 C로 나눈 나머지 반환
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A, B, C; // 자연수 A, B, C
	cin >> A >> B >> C; // 자연수 A, B, C 입력
	cout << power(A, B, C); // 거듭제곱을 구하는 함수 호출
	return 0; // 프로그램 종료
}

/*
    https://www.acmicpc.net/problem/1629
    
    문제 설명: 1629 곱셈
    자연수 A를 B번 곱한 수를 알고 싶다. 단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.

    입력: 첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다. A, B, C는 모두 2,147,483,647 이하의 자연수이다.

    출력: 첫째 줄에 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.

    풀이: 분할 정복을 이용하여 거듭제곱을 구하는 문제. 거듭제곱을 구하는 함수 power를 재귀적으로 구현함.
*/