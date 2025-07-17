# 28702 FizzBuzz
# 3개의 입력 중에 무조건 숫자가 하나 이상이다.

import sys

def main():
    input = sys.stdin.readline

    ans = 0
    for i in [3, 2, 1]:
        tmp = input().rstrip()
        if tmp not in ['Fizz', 'Buzz', 'FizzBuzz']:
            ans = int(tmp) + i

    if ans % 3 == 0 and ans % 5 == 0:
        print('FizzBuzz')
    elif ans % 3 == 0:
        print('Fizz')
    elif ans % 5 == 0:
        print('Buzz')
    else:
        print(ans)
        
if __name__ == "__main__":
    main()