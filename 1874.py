# 1874 스택 수열

import sys

def main():
    input = sys.stdin.readline
    count = 1
    temp = True
    stack = []
    op = []

    N = int(input())
    for i in range(N):
        num = int(input())
        while count <= num:
            stack.append(count)
            op.append('+')
            count += 1

        if stack[-1] == num:
            stack.pop()
            op.append('-')

        else:
            temp = False
            break

    if temp == False:
        print("NO")
    else:
        for i in op:
            print(i)

if __name__ == "__main__":
    main()