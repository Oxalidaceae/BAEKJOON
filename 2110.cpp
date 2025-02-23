//2110 공유기 설치
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, c; // 집 개수, 공유기 개수
	cin >> n >> c; // 입력
	vector<int> house(n); // 집 좌표 저장하는 벡터
	for (int i = 0; i < n; i++) {
		cin >> house[i]; // 집 좌표 입력
	}
	sort(house.begin(), house.end()); // 집 좌표 정렬

	int left = 1, right = house[n - 1] - house[0]; // 이분 탐색 범위 설정(집 사이의 좌표 차이 기준)
	int result = 0; // 결과
	while (left <= right) { // 이분 탐색 반복
		int mid = (left + right) / 2; // 중간값
		int cnt = 1; // 공유기 개수
		int prev = house[0]; // 이전 집 좌표(첫 집으로 시작)
		for (int i = 1; i < n; i++) { // 집 개수만큼 반복
			if (house[i] - prev >= mid) { // 집 사이의 좌표 차이가 중간값보다 크거나 같을 경우
				cnt++; // 공유기 개수 증가
				prev = house[i]; // 이전 집 좌표 갱신
			}
		}
		if (cnt >= c) { // 공유기 개수가 필요한 공유기 개수보다 크거나 같을 경우
			result = mid; // 결과 갱신
			left = mid + 1; // 왼쪽 이동
		}
		else { // 공유기 개수가 필요한 공유기 개수보다 작을 경우
			right = mid - 1; // 오른쪽 이동
		}
	}
	cout << result; // 결과 출력
	return 0; // 프로그램 종료
}

/*
    https://www.acmicpc.net/problem/2110

    문제 설명: 2110 공유기 설치
    도현이의 집 N개가 수직선 위에 있다. 각각의 집의 좌표는 x1, ..., xN이고, 집 여러개가 같은 좌표를 가지는 일은 없다.
    도현이는 언제 어디서나 와이파이를 즐기기 위해서 집에 공유기 C개를 설치하려고 한다. 최대한 많은 곳에서 와이파이를 사용하려고 하기 때문에,
    한 집에는 공유기를 하나만 설치할 수 있고, 가장 인접한 두 공유기 사이의 거리를 가능한 크게 하여 설치하려고 한다.
    C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 공유기 사이의 거리를 최대로 하는 프로그램을 작성하시오.

    입력: 첫째 줄에 집의 개수 N (2 ≤ N ≤ 200,000)과 공유기의 개수 C (2 ≤ C ≤ N)이 하나 이상의 빈 칸을 사이에 두고 주어진다. 둘째 줄부터 N개의 줄에는
    집의 좌표를 나타내는 xi (0 ≤ xi ≤ 1,000,000,000)가 한 줄에 하나씩 주어진다.

    출력: 첫째 줄에 가장 인접한 두 공유기 사이의 최대 거리를 출력한다.

    풀이: 이분 탐색을 이용하여 풀이하였다.
*/