# 2920 음계

import sys

def main():
    input = sys.stdin.readline
    scale = list(map(int, input().split()))
    
    if scale == list(range(1, 9)):
        print("ascending")
    elif scale == list(range(8, 0, -1)):
        print("descending")
    else:
        print("mixed")
        
if __name__ == "__main__":
    main()