
n = 0
k = 0

generated5 = {
 5 : [1, 2, 3, 4, 5, 2, 1, 4, 5, 3, 3, 5, 1, 2, 4, 4, 3, 5, 1, 2, 5, 4, 2, 3, 1] ,
 6 : None,
 7 : [1, 2, 3, 4, 5, 3, 1, 4, 5, 2, 4, 5, 2, 1, 3, 5, 3, 1, 2, 4, 2, 4, 5, 3, 1] ,
 8 : [1, 2, 3, 4, 5, 2, 1, 4, 5, 3, 3, 5, 1, 2, 4, 5, 4, 2, 3, 1, 4, 3, 5, 1, 2] ,
 9 : [1, 2, 3, 4, 5, 2, 1, 4, 5, 3, 4, 5, 1, 3, 2, 3, 4, 5, 2, 1, 5, 3, 2, 1, 4] ,
10 : [1, 2, 3, 4, 5, 2, 1, 4, 5, 3, 3, 4, 5, 1, 2, 5, 3, 1, 2, 4, 4, 5, 2, 3, 1] ,
11 : [1, 2, 3, 4, 5, 2, 3, 1, 5, 4, 3, 5, 4, 1, 2, 4, 1, 5, 2, 3, 5, 4, 2, 3, 1] ,
12 : [1, 2, 3, 4, 5, 2, 3, 1, 5, 4, 3, 4, 5, 1, 2, 5, 1, 4, 2, 3, 4, 5, 2, 3, 1] ,
13 : [1, 2, 3, 4, 5, 2, 3, 1, 5, 4, 5, 1, 4, 2, 3, 4, 5, 2, 3, 1, 3, 4, 5, 1, 2] ,
14 : [1, 2, 3, 4, 5, 2, 1, 4, 5, 3, 3, 4, 5, 1, 2, 4, 5, 2, 3, 1, 5, 3, 1, 2, 4] ,
15 : [1, 2, 3, 4, 5, 2, 3, 1, 5, 4, 3, 4, 5, 1, 2, 4, 5, 2, 3, 1, 5, 1, 4, 2, 3] ,
16 : [1, 2, 3, 4, 5, 2, 3, 4, 5, 1, 4, 1, 5, 2, 3, 5, 4, 1, 3, 2, 3, 5, 2, 1, 4] ,
17 : [1, 2, 3, 4, 5, 2, 4, 1, 5, 3, 4, 3, 5, 2, 1, 5, 1, 4, 3, 2, 3, 5, 2, 1, 4] ,
18 : [1, 2, 3, 4, 5, 2, 4, 5, 1, 3, 3, 5, 4, 2, 1, 4, 3, 1, 5, 2, 5, 1, 2, 3, 4] ,
19 : [1, 2, 3, 4, 5, 2, 5, 1, 3, 4, 3, 4, 5, 1, 2, 4, 3, 2, 5, 1, 5, 1, 4, 2, 3] ,
20 : [1, 2, 3, 4, 5, 2, 5, 4, 1, 3, 3, 4, 5, 2, 1, 4, 3, 1, 5, 2, 5, 1, 2, 3, 4] ,
21 : [2, 1, 3, 4, 5, 1, 5, 4, 2, 3, 3, 4, 5, 1, 2, 4, 3, 2, 5, 1, 5, 2, 1, 3, 4] ,
22 : [3, 1, 2, 4, 5, 1, 5, 4, 2, 3, 2, 4, 5, 3, 1, 4, 3, 1, 5, 2, 5, 2, 3, 1, 4] ,
23 : [4, 1, 2, 3, 5, 1, 5, 3, 4, 2, 2, 4, 5, 1, 3, 3, 2, 4, 5, 1, 5, 3, 1, 2, 4] ,
24 : None,
25 : [5, 1, 2, 3, 4, 1, 5, 3, 4, 2, 2, 4, 5, 1, 3, 3, 2, 4, 5, 1, 4, 3, 1, 2, 5]
}

def valid(arr, i, j):
    st = (i // n) * n
    ed = st + n
    for p in range(st, ed, 1):
        if arr[p] == j:
            return False
    
    st = (i % n)
    ed = n * n
    for p in range(st, ed, n):
        if arr[p] == j:
            return False
    
    return True


def trace(arr):
    t = 0;
    for i in range(n):
        t += arr[n * i + i]
    return t


def show(arr):
    for i in range(n):
        for j in range(n):
            print(arr[n * i + j], end=" ")
        print()


def latin_square(arr):
    for i in range(n * n):
        if arr[i] == 0:
            for j in range(1, n + 1, 1):
                if valid(arr, i, j):
                    arr[i] = j
                    if latin_square(arr):
                        return True
            arr[i] = 0
            return False

    if trace(arr) == k:
        return True 
    else:
        return False


def main():
    global n, k
    T = int(input())
    for t in range(1, T + 1):
        n, k = list(map(int, input().split(" ")))
        print("Case #", t, ": ", sep="", end="")
        arr = [0] * (n * n)

        if (n <= k <= n * n) and n == 5 and generated5[k] != None:
            print("POSSIBLE")
            show(generated5[k])
        elif (n <= k <= n * n) and n != 5 and latin_square(arr) == True:
            print("POSSIBLE")
            show(arr)
        else:
            print("IMPOSSIBLE")


def generate():
    global n, k
    for k in range(n, n * n + 1):
        arr = [0] * (n * n)
        if latin_square(arr) == True:
            print(k, ":", arr, ",")
        else:
            print(k, ": ", None, ",")


if __name__ == "__main__":
    main()
