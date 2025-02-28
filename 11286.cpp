//11286 절댓값 힙
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct cmp { // cmp 구조체 정의
	bool operator()(int a, int b) { // bool operator() 함수 정의
		if (abs(a) == abs(b)) { // a의 절댓값이 b의 절댓값과 같으면
			return a > b; // a가 b보다 크면 true, 아니면 false 반환
		}
		return abs(a) > abs(b); // a의 절댓값이 b의 절댓값보다 크면 true, 아니면 false 반환
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; // n 정의
	cin >> n; // n 입력
	priority_queue<int, vector<int>, cmp> pq; // 절댓값 힙 pq 정의

	while (n--) { // n이 0이 될 때까지 반복
		int x; // x 정의
		cin >> x; // x 입력

		if (x == 0) { // x가 0이면
			if (pq.empty()) { // pq가 비어있으면
				cout << 0 << '\n'; // 0 출력
			}
			else { // pq가 비어있지 않으면
				cout << pq.top() << '\n'; // pq의 top 출력
				pq.pop(); // pq의 top 제거
			}
		}
		else { // x가 0이 아니면
			pq.push(x); // pq에 x 추가
		}
	}
	return 0; // 프로그램 종료
}

/*
    https://www.acmicpc.net/problem/11286

    문제 설명: 11286 절댓값 힙
    절댓값 힙은 다음과 같은 연산을 지원하는 자료구조이다.
    1. 배열에 정수 x (x ≠ 0)를 넣는다.
    2. 배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다.
    절댓값이 가장 작은 값이 여러개일 때는, 가장 작은 수를 출력하고, 그 값을 배열에서 제거한다.
    프로그램은 처음에 비어있는 배열에서 시작하게 된다.

    입력: 첫째 줄에 연산의 개수 N(1≤N≤100,000)이 주어진다. 다음 N개의 줄에는 연산에 대한 정보를 나타내는 정수 x가 주어진다.
    만약 x가 0이 아니라면 배열에 x라는 값을 넣는(추가하는) 연산이고, x가 0이라면 배열에서 절댓값이 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 경우이다.
    입력되는 정수는 -2^31보다 크고, 2^31보다 작다.

    출력: 입력에서 0이 주어진 회수만큼 답을 출력한다. 만약 배열이 비어 있는 경우인데 절댓값이 가장 작은 값을 출력하라고 한 경우에는 0을 출력하면 된다.

    풀이: 1927 최소 힙과 비슷한 문제이다.
    절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거하는 문제이다.
    절댓값이 같은 경우에는 작은 수를 출력하고, 그 값을 배열에서 제거한다.
    이를 위해 cmp 구조체를 만들어주었다.
*/