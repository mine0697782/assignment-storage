dic = { 20188595 : "jerry" , 20186372 : "sungkim" , 20163619 : "jin" , 20186920 : "jaewon" , 20170399 : "alice" , 20151357 : "bob" , 20176064 : "choidavid" , 20183663 : "parkjohn" , 20181252 : "eddy" , 20151391 : "ming" , 20181688 : "minjae" }

while 1:
	select = int(input("\t\t\t출석부\n\n\n\t무엇을 하시겠습니까?\n\n\t1.학번, 이름 추가 \n\t2.학번, 이름 검색 \n\t3.학번, 이름 정렬 \n\t4.학번, 이름 삭제 \n\t5.프로그램 종료\n\n\t번호 입력 : "))

	while 1:
		if select==1 : #추가
			input_id = input("\t학번 입력 : ")
			if dic.get(input_id)!='None' :
				print("이미 존재하는 학번입니다. 이름을 변경하시겠습니까?(yes,no) ",end='')
					if input()=='yes' :
						
			input_name input("\t이름 입력 : ")
			
	
		elif select==2 : #검색
	
		elif select==3 : #정렬
	
		elif select==4 : #삭제
	
		elif selcet==5 : #종료
	
		else : #에러


