# 10828 스택

import sys

class stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if self.items:
            return self.items.pop()
        return -1

    def size(self):
        return len(self.items)

    def empty(self):
        return 1 if not self.items else 0

    def top(self):
        if self.items:
            return self.items[-1]
        return -1

def main():
    input = sys.stdin.readline
    n = int(input().rstrip())
    s = stack()
    results = []
    for _ in range(n):
        command = input().rstrip().split()
        if command[0] == 'push':
            s.push(int(command[1]))
        elif command[0] == 'pop':
            results.append(s.pop())
        elif command[0] == 'size':
            results.append(s.size())
        elif command[0] == 'empty':
            results.append(s.empty())
        elif command[0] == 'top':
            results.append(s.top())
    print('\n'.join(map(str, results)))

if __name__ == "__main__":
    main()