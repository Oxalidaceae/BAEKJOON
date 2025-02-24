//1300 K번째 수
#include <iostream>
using namespace std;

long long countLessOrEqual(long long n, long long x) { // x보다 작거나 같은 수의 개수
    long long count = 0; // 개수
    for (long long i = 1; i <= n; i++) { // 1부터 n까지 반복
        count += min(x / i, n); // x/i와 n 중 작은 값 더하기
    }
    return count; // 개수 반환
}

int main() {
    long long n, k; // n, k 정의
    cin >> n >> k; // 입력

    long long left = 1, right = n * n, answer = 0; // 이분 탐색 범위 설정 및 결과 초기화
    while (left <= right) { // 이분 탐색 반복
        long long mid = (left + right) / 2; // 중간값 설정
        if (countLessOrEqual(n, mid) >= k) { // x보다 작거나 같은 수의 개수가 k보다 크거나 같을 경우
            answer = mid; // 결과 갱신
            right = mid - 1; // 오른쪽 이동
        }
        else { // x보다 작거나 같은 수의 개수가 k보다 작을 경우
            left = mid + 1; // 왼쪽 이동
        }
    }

    cout << answer; // 결과 출력
    return 0; // 프로그램 종료
}

/*
    https://www.acmicpc.net/problem/1300

    문제 설명: 1300 K번째 수
    세준이는 크기가 N×N인 배열 A를 만들었다. 배열에 들어있는 수 A[i][j] = i×j 이다. 이 수를 일차원 배열 B에 넣으면 B의 크기는 N×N이 된다.
    B를 오름차순 정렬했을 때, B[k]를 구해보자. 배열 A와 B의 인덱스는 1부터 시작한다.

    입력: 첫째 줄에 배열의 크기 N이 주어진다. N은 105보다 작거나 같은 자연수이다. 둘째 줄에 k가 주어진다. k는 min(109, N2)보다 작거나 같은 자연수이다.

    출력: B[k]를 출력한다.

    풀이: 이분 탐색을 이용하여 풀이하였다.
*/