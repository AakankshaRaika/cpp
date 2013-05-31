def max_subarray_simp(A):
    max_ending_here = max_so_far = 0
    for x in A:
        max_ending_here = max(0, max_ending_here + x)
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far

def max_subarray_with_index(a):
	max_ending_here = max_so_far = 0
	ini = fin = 0
	for i in range(len(a)):
		if max_ending_here+a[i]<=0:
			max_ending_here = a[i]
			ini = i
		else:
			if max_ending_here<=0:
				max_ending_here = a[i]
				ini = i
			else:
				max_ending_here = max_ending_here + a[i]
		if max_so_far<max_ending_here:
			max_so_far = max_ending_here
			fin = i
		if ini>fin:
			ini = fin
	print '{0} - {1}'.format(ini,fin)
	return max_so_far

if __name__=='__main__':
	a = [-2, 1, -3, 4, -1, 2, 1, -4, 9]
	print max_subarray_with_index(a)
