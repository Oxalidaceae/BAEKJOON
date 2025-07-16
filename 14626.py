# 14626 ISBN

import sys

def main():
    isbn = input()

    # 인덱스가 짝수면 1, 홀수면 3인 가중치 리스트 생성
    weights = [1 if i % 2 == 0 else 3 for i in range(13)] 

    star_idx = isbn.index('*')                # '*' 문자가 위치한 인덱스(0~12) 찾기

    result = 0                                # 가중치 합산 결과(체크섬 계산용) 초기화
    for i in range(13):                       # ISBN의 각 위치 순회
        if isbn[i] == '*':                    # '*' 자리는 건너뜀
            continue
        result += int(isbn[i]) * weights[i]   # 숫자 × 해당 가중치를 결과에 누적

    # '*' 자리에 들어갈 0~9 중 올바른 숫자를 순차 탐색
    for digit in range(10):                   
        total = result + digit * weights[star_idx]  # 가설 숫자 적용 후 총합 계산
        if total % 10 == 0:                         # ISBN-13 조건: 총합이 10으로 나누어 떨어짐
            print(digit)
            break

if __name__ == "__main__":                    
    main()