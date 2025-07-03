# 31403번 A + B - C

import sys

input = sys.stdin.readline
def main():
    a = int(input())
    b = int(input())
    c = int(input())
    print(a + b - c)
    d = str(a) + str(b)
    print(int(d) - c)
    
if __name__ == "__main__":
    main()