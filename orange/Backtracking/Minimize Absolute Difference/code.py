visited = set([])
rs_min = 9.0e10
ans = []

def calc(a, b, c, d):
    tmp = (a/b - c/d)

    return tmp if tmp > 0 else tmp * -1

    # return abs(a/b - c/d)

def backtrack(arr, subset, ind):
    global rs_min
    global visited
    global ans

    for i in range(len(arr)):
        if i in visited:
            continue
        
        subset.append(i)
        visited.add(i)

        if len(subset) == 4:
            rs = calc(arr[subset[0]], arr[subset[1]], arr[subset[2]], arr[subset[3]])

            if rs_min > rs:
                rs_min = rs
                ans = subset.copy()

            subset.pop()
            visited.remove(i)
            continue

        backtrack(arr, subset, i)
        subset.pop()
        visited.remove(i)

def main():
    arr = [None] * 5
    subset = []

    arr = [int(item) for item in input().split()]
    
    backtrack(arr, subset, 0)

    print(f'{ans[0]} {ans[1]} {ans[2]} {ans[3]}')


main()
