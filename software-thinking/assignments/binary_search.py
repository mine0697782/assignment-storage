def find_min_square_root(n):
	start = 0
	end = n-1
	mid = 0
	while start <= end:
		mid = int((start+end)/2)
		if mid*mid > n:

		
	return result


def main():
	n = int(input())
	print(find_min_square_root(n))

if __name__=="__main__":
	main()
