//10830 행렬 제곱
#include <iostream>
#include <vector>
using namespace std;
#define MOD 1000 // 나머지
typedef vector<vector<int>> Matrix; // 행렬 정의

Matrix multiply(const Matrix& A, const Matrix& B, int N) { // 행렬 곱셈 함수
    Matrix C(N, vector<int>(N, 0)); // 결과 행렬
    for (int i = 0; i < N; i++) { // 행
        for (int j = 0; j < N; j++) { // 열
            for (int k = 0; k < N; k++) { // 곱셈
                C[i][j] += (A[i][k] * B[k][j]) % MOD; // 나머지 연산 후 더하기
                C[i][j] %= MOD; // 나머지 연산
            }
        }
    }
    return C; // 결과 반환
}

Matrix power(Matrix A, long long B, int N) { // 행렬 제곱 함수
    Matrix result(N, vector<int>(N, 0)); // 결과 행렬
    for (int i = 0; i < N; i++) // 단위 행렬
        result[i][i] = 1; // 대각선은 1
    while (B > 0) { // B가 0보다 클 경우
        if (B % 2 == 1) result = multiply(result, A, N); // 홀수일 경우 곱셈 후 나머지 연산
        A = multiply(A, A, N); // 곱셈 후 나머지 연산
        B /= 2; // 나누기
    }
    return result; // 결과 반환
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 행렬 크기
    long long B; // 제곱 수
    cin >> N >> B; // 입력

    Matrix matrix(N, vector<int>(N)); // 행렬
    for (int i = 0; i < N; i++) { // 행렬 입력
        for (int j = 0; j < N; j++) { // 열
            cin >> matrix[i][j]; // 입력
            matrix[i][j] %= MOD; // 나머지 연산
        }
    }

    Matrix result = power(matrix, B, N); // 행렬 제곱
    for (int i = 0; i < N; i++) { // 결과 출력
        for (int j = 0; j < N; j++) { // 열
            cout << result[i][j] << ' '; // 출력
        }
        cout << '\n'; // 줄바꿈
    }
    return 0; // 프로그램 종료
}

/*
    https://www.acmicpc.net/problem/10830

    문제 설명: 10830 행렬 제곱
    크기가 N*N인 행렬 A가 주어진다. 이때, A의 B제곱을 구하는 프로그램을 작성하시오. 수가 매우 커질 수 있으니, A^B의 각 원소를 1,000으로 나눈 나머지를 출력한다.

    입력: 첫째 줄에 행렬의 크기 N과 B가 주어진다. (2 ≤ N ≤  5, 1 ≤ B ≤ 100,000,000,000)
    둘째 줄부터 N개의 줄에 행렬의 각 원소가 주어진다. 행렬의 각 원소는 1,000보다 작거나 같은 자연수 또는 0이다.

    출력: 첫째 줄부터 N개의 줄에 걸쳐 행렬 A를 B제곱한 결과를 출력한다.

    풀이: 행렬의 제곱을 구하는 방법은 분할 정복을 이용하여 행렬의 제곱을 구할 수 있다. 분할 정복을 이용하여 행렬의 제곱을 구하는 방법은 다음과 같다.
    1. 행렬 A가 주어졌을 때, B가 1일 경우 A를 반환한다.
    2. B가 홀수일 경우, A^(B-1)을 구하고 A를 곱한다.
    3. B가 짝수일 경우, A^(B/2)을 구하고 A를 곱한다.
    4. 위의 과정을 반복한다.
*/