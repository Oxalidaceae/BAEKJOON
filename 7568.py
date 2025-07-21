# 7568 덩치

import sys

def main():
    input = sys.stdin.readline
    n = int(input().rstrip())
    people = [tuple(map(int, input().split())) for _ in range(n)]

    ranks = []
    for i in range(n):
        rank = 1
        for j in range(n):
            if i != j:
                if people[i][0] < people[j][0] and people[i][1] < people[j][1]:
                    rank += 1
        ranks.append(rank)

    for i in range(n):
        print(ranks[i], end=' ')
    
if __name__ == "__main__":
    main()