# 1676 팩토리얼 0의 개수

import sys

def main():
    input = sys.stdin.readline
    n = int(input().rstrip())

    count = 0 # 0의 개수
    div = 5 # 5의 배수를 찾기 위해 사용하는 기준값
    while n >= div:
        # N! 안에 있는 div의 배수가 몇 개인지를 세는 과정
        count += n // div
        # div를 5배로 늘림
        div *= 5

    print(count)

if __name__ == "__main__":
    main()