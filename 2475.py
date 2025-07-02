# 2475번 검증수

import sys
input = sys.stdin.readline
def main():
    n = list(map(int, input().split()))
    result = 0
    for i in n:
        result += i * i
    print(result % 10)
    
if __name__ == "__main__":
    main()