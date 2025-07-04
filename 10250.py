# 10250 ACM 호텔

import sys

def main():
    input = sys.stdin.readline
    t = int(input())
    for _ in range(t):
        h, w, n = map(int, input().split())
        room = n // h + 1
        floor = n % h
        if floor == 0:
            floor = h
            room -= 1
        print(f"{floor}{room:02d}")
        
if __name__ == "__main__":
    main()