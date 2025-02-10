//2580 스도쿠
#include <iostream>
#include <vector>
using namespace std;

// 스도쿠 판의 유효성 검사
bool isValid(vector<vector<int>>& board, int row, int col, int num) {
    for (int i = 0; i < 9; i++) { // 가로, 세로 검사
        if (board[row][i] == num || board[i][col] == num) { // 가로, 세로에 num이 있는지 검사
            return false; // num이 있으면 유효하지 않음
        }
    }

    int startRow = (row / 3) * 3; // 3x3 정사각형의 시작 행
    int startCol = (col / 3) * 3; // 3x3 정사각형의 시작 열
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num) { // 3x3 정사각형에 num이 있는지 검사
                return false; // num이 있으면 유효하지 않음
            }
        }
    }
    return true; // num이 없으면 유효함
}

// 스도쿠 풀이
bool solveSudoku(vector<vector<int>>& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) { // 빈 칸이면
                for (int num = 1; num <= 9; num++) { // 1부터 9까지 시도
                    if (isValid(board, row, col, num)) { // 유효하면
                        board[row][col] = num; // 숫자 채우기
                        if (solveSudoku(board)) { // 재귀적으로 스도쿠 풀이
                            return true; // 풀이 성공
                        }
                        board[row][col] = 0; // 풀이 실패하면 다시 빈 칸으로
                    }
                }
                return false; // 1부터 9까지 시도해도 풀이 실패하면 false 반환
            }
        }
    }
    return true; // 모든 칸이 채워지면 true 반환
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    vector<vector<int>> board(9, vector<int>(9)); // 스도쿠 판

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j]; // 스도쿠 판 입력
        }
    }

	solveSudoku(board); // 스도쿠 풀이
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << board[i][j] << " "; // 스도쿠 판 출력
		}
		cout << endl; // 줄바꿈
	}
    return 0; // 프로그램 종료
}

/*
    문제설명: 2580 스도쿠
    스도쿠는 18세기 스위스 수학자가 만든 '라틴 사각형'이랑 퍼즐에서 유래한 것으로 현재 많은 인기를 누리고 있다. 이 게임은 아래 그림과 같이 가로, 세로
    각각 9개씩 총 81개의 작은 칸으로 이루어진 정사각형 판 위에서 이뤄지는데, 게임 시작 전 일부 칸에는 1부터 9까지의 숫자 중 하나가 쓰여 있다.
    나머지 빈 칸을 채우는 방식은 다음과 같다.
    1. 각각의 가로줄과 세로줄에는 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
    2. 굵은 선으로 구분되어 있는 3x3 정사각형 안에도 1부터 9까지의 숫자가 한 번씩만 나타나야 한다.
    위의 예의 경우, 첫째 줄에는 1을 제외한 나머지 2부터 9까지의 숫자들이 이미 나타나 있으므로 첫째 줄 빈칸에는 1이 들어가야 한다.
    또한 위쪽 가운데 위치한 3x3 정사각형의 경우에는 3을 제외한 나머지 숫자들이 이미 쓰여있으므로 가운데 빈 칸에는 3이 들어가야 한다.
    이와 같이 빈 칸을 차례로 채워 가면 다음과 같은 최종 결과를 얻을 수 있다.
    게임 시작 전 스도쿠 판에 쓰여 있는 숫자들의 정보가 주어질 때 모든 빈 칸이 채워진 최종 모습을 출력하는 프로그램을 작성하시오.

    입력: 아홉 줄에 걸쳐 한 줄에 9개씩 게임 시작 전 스도쿠판 각 줄에 쓰여 있는 숫자가 한 칸씩 띄워서 차례로 주어진다.
    스도쿠 판의 빈 칸의 경우에는 0이 주어진다. 스도쿠 판을 규칙대로 채울 수 없는 경우의 입력은 주어지지 않는다.

    출력: 모든 빈 칸이 채워진 스도쿠 판의 최종 모습을 아홉 줄에 걸쳐 한 줄에 9개씩 한 칸씩 띄워서 출력한다.
    스도쿠 판을 채우는 방법이 여럿인 경우는 그 중 하나만을 출력한다.

    풀이: 백트래킹을 이용하여 스도쿠를 풀이한다.
*/