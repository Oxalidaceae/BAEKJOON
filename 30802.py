# 30802 웰컴 키트

import sys

def main():
    shirts = 0
    n = int(sys.stdin.readline())
    lists = sys.stdin.readline().split()
    t, p = map(int, sys.stdin.readline().split())
    for i in range(6):
        if int(lists[i]) % t == 0:
            shirts += int(int(lists[i]) / t)
        else:
            shirts += int(int(lists[i]) / t) + 1
    
    print(shirts)
    print(int(n / p), n % p)
    
if __name__ == "__main__":
    main()