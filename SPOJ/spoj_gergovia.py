def abs(x):
	if x<0:
		return -1*x
	return x

if __name__ == "__main__":
	while 1:
		n = input()
		if n==0:
			break
		a = map(int, raw_input().split())
		res = tot = 0
		for i in range(n):
			tot = tot + a[i]
			res = res + abs(tot)
		print res
