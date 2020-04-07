# Created By: Anonyman637
# Created On: 9/1/2019 3:39:35 PM


def trouble_sort(l):
    done = False
    while not done:
        done = True
        for i in range(len(l) - 2):
            if l[i] > l[i + 2]:
                done = False
                l[i:i + 3] = l[i:i + 3][::-1]


def check_sorted(l):
    for i in range(len(l) - 1):
        if l[i] > l[i + 1]:
            return i
    else:
        return "OK"


no_of_tests = int(input())
for t in range(1, no_of_tests + 1):
    no_of_items = int(input())
    arr = list(map(int, input().split(" ")))
    trouble_sort(arr)
    res = check_sorted(arr)
    print("Case #{0}: {1}".format(t, res))
