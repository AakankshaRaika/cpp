def max_subarray(a):
	max_ending_here = max_so_far = 0
	for x in a:
		max_ending_here = max(0, max_ending_here+x)
		max_so_far = max(max_so_far,max_ending_here)
		print '{0} - {1}'.format(max_ending_here,max_so_far)
	return max_so_far

if __name__=='__main__':
	a = [-2,1,-3,4,-1,2,1,-5,4]
	print max_subarray(a)
