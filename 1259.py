# 1259 팰린드롬수

import sys

def main():
    while True:
        n = str(sys.stdin.readline().strip())
        if n == '0':
            break
        is_palindrome = True
        for i in range(len(n) // 2):
            if n[i] != n[len(n) - 1 - i]:
                is_palindrome = False
                break
        if is_palindrome:
            print("yes")
        else:
            print("no")

if __name__ == "__main__":
    main()