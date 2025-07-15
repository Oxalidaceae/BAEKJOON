# 2775 부녀회장이 될테야

import sys

def main():
    T = int(sys.stdin.readline())
    while T > 0:
        T -= 1
        k = int(sys.stdin.readline())
        n = int(sys.stdin.readline())
        
        apt = [i for i in range(1, n + 1)]
        
        for floor in range(k):
            for i in range(1, n):
                apt[i] += apt[i - 1]
        
        print(apt[-1])

if __name__ == "__main__":
    main()