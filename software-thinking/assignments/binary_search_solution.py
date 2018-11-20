def find_min_square_root(n):
    start = 0
    end = n-1
    mid = 0
    while start <= end:
        mid = int((start+end)/2)
        if n <= mid**2:
            end = mid-1
        else:
            start = mid+1
    return mid

def main():
    n = int(input())
    print(find_min_square_root(n))

if __name__ == "__main__":
    main()

