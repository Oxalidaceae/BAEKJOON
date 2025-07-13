# 15829 Hashing

import sys

def hash_function(string, length):
    result = 0
    p = 31
    for i in range(length):
        result += (ord(string[i]) - ord('a') + 1) * (p ** i)
    return result

def main():
    n = int(sys.stdin.readline().strip())
    string = sys.stdin.readline().strip()
    res = hash_function(string, n)
    print(res % 1234567891)

if __name__ == "__main__":
    main()