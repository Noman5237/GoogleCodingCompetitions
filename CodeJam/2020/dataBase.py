#!/usr/bin/python3

import sys
import random
import copy

def read_int():
    return int(input())

def write_int(a):
    print(a, flush=True)

def query(a):
    write_int(a)
    return read_int()

def int_list_str(int_list):
    return "".join(list(map(str, int_list)))

def str_int_list(s):
    return list(map(int, s))


def reverse(s):
  return s[::-1]

def complement(s):
  return [i^1 for i in s]


def solve(b):
    data = [0] * b
    l = 1
    r = b
    same_bits = None
    diff_bits = None
    
    nq = 0
    collected = 0
    while collected != b and l < r:
        # When the flash happens we need to make some extra calls
        if (nq != 0 and nq % 10 == 0):
            if same_bits != None:
                if data[same_bits - 1] != query(same_bits):
                    data = complement(data)
                nq += 1

            if diff_bits != None:
                if data[diff_bits - 1] != query(diff_bits):
                    data = reverse(data)
                nq += 1


        data[l - 1] = query(l)
        data[r - 1] = query(r)
        
        nq += 2
        collected += 2

        if same_bits == None:
            if data[l - 1] == data[r - 1]:
                same_bits = l

        if diff_bits == None:
            if data[l - 1] != data[r - 1]:
                diff_bits = l

        l += 1
        r -= 1

    return data


def main():
    T, b = list(map(int, input().split(" ")))
    ans = ""
    for t in range(T):
        ans = solve(b)
        ans = int_list_str(ans)
        print(ans, flush=True)
        verdict = input()
        if verdict == "N":
            sys.exit(0);


if __name__ == '__main__':
  main()
