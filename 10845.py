# 10845 큐

import sys

class queue:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)

    def pop(self):
        if self.items:
            return self.items.pop(0)
        return -1

    def size(self):
        return len(self.items)

    def empty(self):
        return 1 if not self.items else 0

    def front(self):
        if self.items:
            return self.items[0]
        return -1
    
    def back(self):
        if self.items:
            return self.items[-1]
        return -1

def main():
    input = sys.stdin.readline
    n = int(input().rstrip())
    q = queue()
    results = []
    for _ in range(n):
        command = input().rstrip().split()
        if command[0] == 'push':
            q.push(int(command[1]))
        elif command[0] == 'pop':
            results.append(q.pop())
        elif command[0] == 'size':
            results.append(q.size())
        elif command[0] == 'empty':
            results.append(q.empty())
        elif command[0] == 'front':
            results.append(q.front())
        elif command[0] == 'back':
            results.append(q.back())
    print('\n'.join(map(str, results)))

if __name__ == "__main__":
    main()