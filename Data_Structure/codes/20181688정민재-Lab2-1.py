def magic(n):
    square = [[0 for i in range(n)] for j in range(n)]
    key = 2
    i = 0
    j = n//2
    square[i][j] = 1
    
    row = 0
    col = 0

    while(key<=n*n):
        row = n-1 if i-1 < 0 else i-1
        col = n-1 if j-1 < 0 else j-1
        
        if square[row][col] != 0:
            i = (i+1) % n
        else:
            i = row
            j = col
        square[i][j] = key
        key += 1
    
    return square


n = int(input())
if n%2 == 0:
    print("It's not an odd")
else:
    print(magic(n))
