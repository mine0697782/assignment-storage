month = [31,28,31,30,31,30,31,31,30,31,30,31] # 월별 일수 저장
blank = 0 # 월별 공백 저장


for i in range(len(month)): # 달력 전체 출력 사이클

	print("\n\n\t\t\t{}월\n\n\n".format(i+1)) # n월 출력 위치 정렬

	print("{}\t{}\t{}\t{}\t{}\t{}\t{}\n\n".format("월","화","수","목","금","토","일")) # 맨 윗줄 요일 출력

	for b in range(blank): # 월별 공백 출력 
		print("\t",end='')

	for day in range(month[i]): # 일 출력
        	print("%d\t"%(day+1),end='')
	        if not((day+blank+1)%7): # 일 줄 넘김
        	        print("\n\n")

	print("\n\n\n") # 간격 조정
	blank = (blank + month[i]) % 7 # 월별 공백 계산
