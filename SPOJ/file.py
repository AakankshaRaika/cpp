f = open('new.txt')
out = open('out.txt','wb')
for line in f:
	line = line.rstrip()
	out.write(line)
f.close()