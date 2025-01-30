//2447 별 찍기 - 10
#include <iostream>
using namespace std;

void star(int i, int j, int num) { // 재귀함수
    if ((i / num) % 3 == 1 && (j / num) % 3 == 1) { // i, j가 num으로 나누어 떨어지면 공백 출력
        cout << ' '; 
    }
    else {
        if (num / 3 == 0) // num이 3보다 작으면 별 출력
            cout << '*';
        else // 그렇지 않으면 재귀함수 호출
            star(i, j, num / 3);
    }
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; // 크기
    cin >> n; // 크기 입력
    for (int i = 0; i < n; i++) { // 별 출력
        for (int j = 0; j < n; j++)
            star(i, j, n); // 재귀함수 호출
        cout << endl; // 줄바꿈
    }
	return 0; // 프로그램 종료
}

/*
    문제 설명: 2447 별 찍기 - 10
    재귀적인 패턴으로 별을 찍어 보자. N이 3의 거듭제곱(3, 9, 27, ...)이라고 할 때, 크기 N의 패턴은 N×N 정사각형 모양이다.
    크기 3의 패턴은 가운데에 공백이 있고, 가운데를 제외한 모든 칸에 별이 하나씩 있는 패턴이다.
    ***
    * *
    ***
    N이 3보다 클 경우, 크기 N의 패턴은 공백으로 채워진 가운데의 (N/3)×(N/3) 정사각형을 크기 N/3의 패턴으로 둘러싼 형태이다.
    예를 들어 크기 27의 패턴은 예제 출력 1과 같다.

    입력: 첫째 줄에 N이 주어진다. N은 3의 거듭제곱이다. 즉 어떤 정수 k에 대해 N=3k이며, 이때 1 ≤ k < 8이다.

    출력: 첫째 줄부터 N번째 줄까지 별을 출력한다.

    풀이: 재귀함수를 이용하여 풀이하였다. i, j가 num으로 나누어 떨어지면 공백을 출력하고, 그렇지 않으면 재귀함수를 호출한다.
*/