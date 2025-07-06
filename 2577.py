# 2577 숫자의 개수

import sys

def main():
    imput = sys.stdin.readline
    a = int(imput())
    b = int(imput())
    c = int(imput())
    result = a * b * c
    for i in range(10):
        print(str(result).count(str(i)))
    
if __name__ == "__main__":
    main()