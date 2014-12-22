t = input();
while t>0:
	n = input()
	arr = float(0.0)
	for i in range(1,n+1):
		arr = float(float(arr) + float(1.0/i))
	print "%.6f" % arr
	t = t-1
