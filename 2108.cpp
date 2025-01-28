//2108 통계학
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, sum = 0, maxValue = -4001, minValue = 4001, range = 0, median = 0; // 최댓값, 최솟값, 범위, 중앙값
    double mean = 0.0; // 평균
    cin >> n; // 입력받을 수의 개수

    vector<int> arr(n); // 입력받을 수를 저장할 벡터
    unordered_map<int, int> frequency; // 빈도수를 저장할 해시맵

    for (int i = 0; i < n; i++) { // n개의 수를 입력받아 벡터에 저장하고, 최댓값, 최솟값, 빈도수를 저장
        cin >> arr[i]; // 수 입력
        sum += arr[i]; // 합계 계산
        maxValue = max(maxValue, arr[i]); // 최댓값 계산
        minValue = min(minValue, arr[i]); // 최솟값 계산
        frequency[arr[i]]++; // 빈도수 계산
    }

    mean = static_cast<double>(sum) / n; // 평균 계산
	mean = static_cast<int>(round(mean)); // 평균 반올림

    sort(arr.begin(), arr.end()); // 벡터 정렬
    median = arr[n / 2]; // 중앙값 계산

    int mode = arr[0]; // 최빈값
    int maxFrequency = 0; // 최빈값의 빈도수
    int currentFrequency = 0; // 현재 빈도수
    bool isSecondMode = false; // 두 번째 최빈값이 있는지 확인
    for (int i = 0; i < n; i++) { // 최빈값 계산
        currentFrequency = 1; // 현재 빈도수 초기화
        while (i + 1 < n && arr[i] == arr[i + 1]) { // 현재 값과 다음 값이 같으면 빈도수 증가
            currentFrequency++; // 빈도수 증가
            i++; // 인덱스 증가
        }

        if (currentFrequency > maxFrequency) { // 최빈값이 최빈값의 빈도수보다 크면 최빈값과 최빈값의 빈도수 갱신
            maxFrequency = currentFrequency; // 최빈값의 빈도수 갱신
            mode = arr[i]; // 최빈값 갱신
            isSecondMode = false; // 두 번째 최빈값이 있는지 확인
        }
        else if (currentFrequency == maxFrequency && !isSecondMode) { // 최빈값이 최빈값의 빈도수와 같고, 두 번째 최빈값이 없으면
            mode = arr[i]; // 최빈값 갱신
            isSecondMode = true; // 두 번째 최빈값이 있는지 확인
        }
    }

    range = maxValue - minValue; // 범위 계산

    cout << mean << '\n' << median << '\n' << mode << '\n' << range; // 평균, 중앙값, 최빈값, 범위 출력
    return 0; // 프로그램 종료
}

/*
    문제 설명: 2108 통계학
        수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다.
        단, N은 홀수라고 가정하자.
        산술평균: N개의 수들의 합을 N으로 나눈 값
        중앙값: N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
        최빈값: N개의 수들 중 가장 많이 나타나는 값
        범위: N개의 수들 중 최댓값과 최솟값의 차이
        N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.

    입력: 첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 단, N은 홀수이다. 그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 정수의 절댓값은 4,000을 넘지 않는다.

    출력: 첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.
          둘째 줄에는 중앙값을 출력한다.
          셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
          넷째 줄에는 범위를 출력한다.
    
    풀이: 입력받을 수의 개수를 입력받고, 입력받을 수를 저장할 벡터와 빈도수를 저장할 해시맵을 선언한다.
          n개의 수를 입력받아 벡터에 저장하고, 최댓값, 최솟값, 빈도수를 저장한다.
*/