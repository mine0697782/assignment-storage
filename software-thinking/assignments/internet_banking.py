class account:
	def __init__(self, name, number, balance):
		self.name = name #이름
		self.number = number #계좌번호
		self.balance = balance #잔액

	def injection(self, money): #인출
		if self.balance >= money:
			self.balance -= money
			return 1
		else:
			print("잔액이 부족합니다.")
			return 0

	def deposit(self, money): #입금
		self.balance += money

	def __str__(self):
		massege = "User Name : " + self.name + "\nAccount address : " + self.number + "\nBalance : " + str(self.balance) + "\n"

		return massege


def transfer(sender, receiver, money): #계좌이체, 두개의 인스턴트 정보를 받는 함수로 선언
	if sender.injection(money):
		receiver.deposit(money)
	else :
		print("잔액이 부족합니다.")

#################################
#				#
#	사용자의 정보 선언	#
#				#
#################################
Jeong = account("Jeong","110454448403",1000000000)

print(Jeong)
 
