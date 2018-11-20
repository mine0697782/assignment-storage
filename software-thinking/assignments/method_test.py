class CounterManager:
	insCount = 0
	def __init__(self):
		CounterManager.insCount += 1
	def staticPrintCount():
		print("Instance Count: ", CounterManager.insCount)
	SPrintCount = staticmethod(staticPrintCount)
	
	def classPrintCount(cls):
		print("Instance Count: ", CounterManager.insCount)
	CPrintCount = classmethod(classPrintCount)

A, b, c = CounterManager.SPrintCount()

CounterManager.SPrintCount()
b.SPrintCount()

CounterManager.CPrintCount()
b.CPrintCount()
