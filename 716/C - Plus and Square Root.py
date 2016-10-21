n = int(input())

prev = 2;

for i in range(2,n+2):
	val = i*(i-1)
	x = (val*val - prev)/(i-1)
	print(int(x))
	prev = val