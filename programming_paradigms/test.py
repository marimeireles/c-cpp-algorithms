# -*- coding: utf-8 -*-
import sys

from functools import lru_cache

nums = None
start = 0
largest = 0
smallest = 0

@lru_cache(maxsize=None)
def calc(x, i):
    if x > largest or x < 0:
        return -float('inf')

    if i == len(nums):
        return x

    # indent = '{:>{fill}}'.format('', fill=depth)
    # print(f'{indent}x: {x}, next: {nums[i]}, left: {x-nums[i]}, right: {x+nums[i]}')
    left = calc(x-nums[i], i+1)
    right = calc(x+nums[i], i+1)

    return max(left, right)


N = int(sys.stdin.readline())
for _ in range(N):
    _, start, largest, smallest = map(int, sys.stdin.readline().split())
    nums = list(map(int, sys.stdin.readline().split()))
    print(calc(start, 0))
