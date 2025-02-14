//1992 퀴드트리
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> video; // 비디오
void compressVideo(int x, int y, int size) { // 비디오를 압축하는 재귀 함수
	int color = video[x][y]; // 비디오의 색
	bool all_same = true; // 모든 비디오가 같은 색인지 확인하는 변수

    // 비디오의 색이 모두 같은지 확인
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			if (video[i][j] != color) {
				all_same = false; // 모든 비디오가 같은 색이 아니면면
				break; // 반복문 종료
			}
		}
		if (!all_same) break; // 모든 비디오가 같은 색이 아니면 반복문 종료
	}

	if (all_same) // 모든 비디오가 같은 색이면
		cout << color; // 색 출력
	else { // 모든 비디오가 같은 색이 아니면
		int new_size = size / 2; // 비디오의 크기를 반으로 줄임
		cout << "("; // 괄호 열기
		compressVideo(x, y, new_size); // 비디오를 압축하는 재귀 함수 호출(1사분면)
		compressVideo(x, y + new_size, new_size); // 비디오를 압축하는 재귀 함수 호출(2사분면)
		compressVideo(x + new_size, y, new_size); // 비디오를 압축하는 재귀 함수 호출(3사분면)
		compressVideo(x + new_size, y + new_size, new_size); // 비디오를 압축하는 재귀 함수 호출(4사분면)
		cout << ")"; // 괄호 닫기
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; // 비디오의 한 변의 길이
	cin >> N; // 비디오의 한 변의 길이 입력
	video.resize(N, vector<int>(N)); // 비디오의 크기만큼 벡터 생성
	for (int i = 0; i < N; i++) { // 비디오의 색 입력
		string line; // 0과 1이 공백 없이 입력되므로 문자열로 입력
		cin >> line; // 한 줄 입력
		for (int j = 0; j < N; j++) { // 한 줄 반복
			video[i][j] = line[j] - '0'; // 정수로 변환
		}
	}
	compressVideo(0, 0, N); // 비디오를 압축하는 재귀 함수 호출
	return 0; // 프로그램 종료
}

/*
    https://www.acmicpc.net/problem/1992

    흑백 영상을 압축하여 표현하는 데이터 구조로 쿼드 트리(Quad Tree)라는 방법이 있다. 흰 점을 나타내는 0과 검은 점을 나타내는 1로만 이루어진 영상(2차원 배열)에서
    같은 숫자의 점들이 한 곳에 많이 몰려있으면, 쿼드 트리에서는 이를 압축하여 간단히 표현할 수 있다.
    주어진 영상이 모두 0으로만 되어 있으면 압축 결과는 "0"이 되고, 모두 1로만 되어 있으면 압축 결과는 "1"이 된다. 만약 0과 1이 섞여 있으면 전체를 한 번에
    나타내지를 못하고, 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래, 이렇게 4개의 영상으로 나누어 압축하게 되며, 이 4개의 영역을 압축한 결과를 차례대로 괄호
    안에 묶어서 표현한다.
    위 그림에서 왼쪽의 영상은 오른쪽의 배열과 같이 숫자로 주어지며, 이 영상을 쿼드 트리 구조를 이용하여 압축하면 "(0(0011)(0(0111)01)1)"로 표현된다.
    N ×N 크기의 영상이 주어질 때, 이 영상을 압축한 결과를 출력하는 프로그램을 작성하시오.

    입력: 첫째 줄에는 영상의 크기를 나타내는 숫자 N 이 주어진다. N 은 언제나 2의 제곱수로 주어지며, 1 ≤ N ≤ 64의 범위를 가진다. 두 번째 줄부터는 길이 N의 문자열이
    N개 들어온다. 각 문자열은 0 또는 1의 숫자로 이루어져 있으며, 영상의 각 점들을 나타낸다.

    출력: 영상을 압축한 결과를 출력한다.

    풀이: 2630 색종이 만들기 문제와 비슷한 방식으로 쿼드 트리를 구현하였다. 색종이 만들기 문제와 다른 점은 색이 0 또는 1로만 이루어져 있어서 색이 다르면
    색종이를 나누는 것이 아니라 색이 같은지 확인하고, 색이 다르면 색종이를 나누는 것이다. 색이 같으면 색을 출력하고, 색이 다르면 색종이를 나누어 재귀적으로
    호출한다.
*/