//9663 N-Queen
#include <iostream>
#include <vector>
using namespace std;

int col[15]; // 열
int N, cnt = 0; // N, 경우의 수

bool isPossible(int row) { // 가능한지 확인
	for (int i = 0; i < row; i++) { // 행 확인
		if (col[i] == col[row] || abs(col[row] - col[i]) == row - i) { // 같은 열 또는 대각선에 위치할 경우
			return false; // 불가능 반환
		}
	}
	return true; // 그 외의 경우 가능 반환
}

void backtrack(int row) { // 백트래킹
	if (row == N) { // 행이 N일 경우
		cnt++; // 경우의 수 증가
	}
	else { // 그 외의 경우
		for (int i = 0; i < N; i++) { // 열 확인
			col[row] = i; // 열 설정
			if (isPossible(row)) { // 가능한지 확인
				backtrack(row + 1); // 다음 행으로 이동
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N; // N 입력
	backtrack(0); // 백트래킹
	cout << cnt; // 경우의 수 출력
	return 0; // 프로그램 종료
}

/*
    https://www.acmicpc.net/problem/9663

    문제 설명: 9663 N-Queen
    N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.
    N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

    입력: 첫째 줄에 N이 주어진다. (1 ≤ N < 15)

    출력: 첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

    풀이: 백트래킹을 이용하여 N-Queen 문제를 해결하였다.
*/