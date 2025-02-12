//1931 회의실 배정
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, int>> meetings(N); // 회의의 시작시간과 끝나는 시간을 저장할 벡터

	for (int i = 0; i < N; ++i) { // N개의 회의 정보 입력
		cin >> meetings[i].second >> meetings[i].first;
	}

	sort(meetings.begin(), meetings.end()); // 회의의 끝나는 시간을 기준으로 오름차순 정렬

	int answer = 0; // 회의의 최대 개수를 저장할 변수
	int end_time = 0; // 회의의 끝나는 시간을 저장할 변수
	for (int i = 0; i < N; ++i) { // N개의 회의 정보 반복
		if (meetings[i].second >= end_time) { // 회의의 시작시간이 회의의 끝나는 시간보다 크거나 같으면
			++answer; // 회의의 최대 개수 증가
			end_time = meetings[i].first; // 회의의 끝나는 시간을 변경
		}
	}

	cout << answer; // 회의의 최대 개수 출력
	return 0; // 프로그램 종료
}

/*
    문제 설명: 1931 회의실 배정
    한 개의 회의실이 있는데 이를 사용하고자 하는 N개의 회의에 대하여 회의실 사용표를 만들려고 한다. 각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고,
    각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수를 찾아보자. 단, 회의는 한번 시작하면 중간에 중단될 수 없으며 한 회의가
    끝나는 것과 동시에 다음 회의가 시작될 수 있다. 회의의 시작시간과 끝나는 시간이 같을 수도 있다. 이 경우에는 시작하자마자 끝나는 것으로 생각하면 된다.

    입력: 첫째 줄에 회의의 수 N(1 ≤ N ≤ 100,000)이 주어진다. 둘째 줄부터 N+1 줄까지 각 회의의 정보가 주어지는데 이것은 공백을 사이에 두고 회의의
    시작시간과 끝나는 시간이 주어진다. 시작 시간과 끝나는 시간은 231-1보다 작거나 같은 자연수 또는 0이다.

    출력: 첫째 줄에 최대 사용할 수 있는 회의의 최대 개수를 출력한다.

    풀이: 회의의 시작시간과 끝나는 시간을 pair로 묶어 vector에 저장한 후, 회의의 끝나는 시간을 기준으로 오름차순 정렬한다.
*/