# 1966 프린터 큐

import sys

def main():
    input = sys.stdin.readline
    t = int(input())
    for _ in range(t):
        n, m = map(int, input().split())
        priority = list(map(int, input().split()))
        count = 0
        while True:
            max_priority = max(priority)
            if priority[0] == max_priority:
                count += 1
                if m == 0:
                    print(count)
                    break
                else:
                    priority.pop(0)
                    m -= 1
            else:
                priority.append(priority.pop(0))
                if m == 0:
                    m = len(priority) - 1
                else:
                    m -= 1
                    
if __name__ == "__main__":
    main()