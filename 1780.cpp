//1780 종이의 개수
#include <iostream>
#include <vector>
using namespace std;

int minus_count = 0, zero_count = 0, one_count = 0; // -1, 0, 1로만 채워진 종이의 개수
vector<vector<int>> paper; // 종이

void countPapers(int x, int y, int size) { // 종이의 개수를 세는 재귀 함수
    int check = paper[x][y]; // 종이의 색
    bool all_same = true; // 모든 종이가 같은 숫자인지 확인하는 변수

    for (int i = x; i < x + size; i++) { // 종이의 숫자가 모두 같은지 확인
        for (int j = y; j < y + size; j++) { 
            if (paper[i][j] != check) { // 종이의 숫자가 다르면
                all_same = false; // 모든 종이가 같은 숫자가 아님
                break; // 반복문 종료
            }
        }
        if (!all_same) break; // 모든 종이가 같은 숫자가 아니면 반복문 종료
    }

    if (all_same) { // 모든 종이가 같은 숫자이면
		if (check == -1) minus_count++; // -1이면 -1로만 채워진 종이의 개수 증가
		else if (check == 0) zero_count++; // 0이면 0으로만 채워진 종이의 개수 증가
		else one_count++; // 1이면 1로만 채워진 종이의 개수 증가
    }
    else {
        int new_size = size / 3; // 종이의 크기를 3으로 나눔
        countPapers(x, y, new_size);
		countPapers(x, y + new_size, new_size);
		countPapers(x, y + 2 * new_size, new_size);
		countPapers(x + new_size, y, new_size);
		countPapers(x + new_size, y + new_size, new_size);
		countPapers(x + new_size, y + 2 * new_size, new_size);
		countPapers(x + 2 * new_size, y, new_size);
		countPapers(x + 2 * new_size, y + new_size, new_size);
		countPapers(x + 2 * new_size, y + 2 * new_size, new_size);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 종이의 크기
    cin >> N; // 종이의 크기 입력
    paper.resize(N, vector<int>(N)); // 종이의 크기만큼 벡터 생성
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> paper[i][j]; // 종이의 숫자 입력
        }
    }
    countPapers(0, 0, N); // 종이의 개수를 세는 재귀 함수 호출
    cout << minus_count << "\n" << zero_count << "\n" << one_count; // -1, 0, 1로만 채워진 종이의 개수 출력
    return 0; // 프로그램 종료
}

/*
    https://www.acmicpc.net/problem/1780

    문제 설명: 1780 종이의 개수
    N×N크기의 행렬로 표현되는 종이가 있다. 종이의 각 칸에는 -1, 0, 1 중 하나가 저장되어 있다. 우리는 이 행렬을 다음과 같은 규칙에 따라 적절한 크기로 자르려고 한다.
    1. 만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
    2. (1)이 아닌 경우에는 종이를 같은 크기의 종이 9개로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.
    이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.

    입력: 첫째 줄에 N(1 ≤ N ≤ 3^7, N은 3^k 꼴)이 주어진다. 다음 N개의 줄에는 N개의 정수로 행렬이 주어진다.

    출력: 첫째 줄에 -1로만 채워진 종이의 개수를, 둘째 줄에 0으로만 채워진 종이의 개수를, 셋째 줄에 1로만 채워진 종이의 개수를 출력한다.

    풀이: 분할 정복을 이용하여 종이의 개수를 세는 재귀 함수를 작성한다. 모든 종이가 같은 수로 되어 있으면 해당 종이의 개수를 증가시키고, 그렇지 않으면
    종이를 9개로 나누어 재귀 함수를 호출한다. 모든 종이의 개수를 센 후, -1, 0, 1로만 채워진 종이의 개수를 출력한다.
*/