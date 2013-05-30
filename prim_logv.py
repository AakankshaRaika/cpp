"""
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
"""

from sys import maxint

MAX = maxint

def max(a,b):
	if a>b:
		return a
	return b

def min(a,b):
	if a>b:
		return b
	return a

class primHeap:
	def __init__(self,s):
		self.size = s
		self.current = s
		self.pos = [i for i in range(self.size)]
		self.heap = []
		self.heap.append({"key":0,"val":0})
		for i in range(1,self.size):
			node = {"key":i,"val":MAX}
			self.heap.append(node)

	def __heapify(self,i):
		smallest = i
		left = 2*i+1
		right = 2*1+2
		if left<self.current and self.heap[left]["val"]<self.heap[i]["val"]:
			smallest = left
		if right<self.current and self.heap[right]["val"]<self.heap[smallest]["val"]:
			smallest = right
		if smallest != i:
			self.pos[self.heap[smallest]["key"]] = i
			self.pos[self.heap[i]["key"]] = smallest
			self.__swap(smallest,i)
			self.__heapify(smallest)

	def __swap(self,k1,k2):
		t = self.heap[k1]
		self.heap[k1] = self.heap[k2]
		self.heap[k2] = t

	def get_size(self):
		return self.current

	def empty(self):
		return self.current==0

	def top(self):
		return self.heap[0]

	def pop(self):
		root = {"key":-1,"val":-1}
		if self.current <= 0:
			return root
		root = self.heap[0]
		self.heap[0] = self.heap[self.current-1]
		self.pos[root["key"]] = self.current-1
		self.pos[self.heap[0]["key"]] = 0
		self.current = self.current-1
		self.__heapify(0)
		return root

	def update(self,k):
		i = self.pos[k["key"]]
		self.heap[i]["val"] = k["val"]
		while i and self.heap[i]["val"]<self.heap[(int)((i-1)/2)]["val"]:
			self.pos[self.heap[i]["key"]] = (int)((i-1)/2)
			self.pos[self.heap[(int)((i-1)/2)]["key"]] = i
			self.__swap(i,(int)((i-1)/2))
			i = (int)((i-1)/2)

	def Print(self):
		for i in range(self.current):
			print "{0} - {1}".format(self.heap[i]["key"],self.heap[i]["val"])
		for i in range(self.size):
			print self.pos[i]

	def isPresent(self,v):
		if self.pos[v]<self.current:
			return True
		return False

	def weight(self,v):
		return self.heap[self.pos[v]]["val"]

V = 1
e = 1
mst = []

def primMST(adj):
	parent = []
	prim = primHeap(V)
	for i in range(V):
		parent.append(-1)
	while not prim.empty():
		k = prim.pop()
		u = k["key"]
		for j in range(len(adj[u])):
			v = adj[u][j]["dest"]
			if prim.isPresent(v) and adj[u][j]["wt"]<prim.weight(v):
				k1 = {}
				k1["key"] = v
				k1["val"] = adj[u][j]["wt"]
				parent[v] = u
				prim.update(k1)
	for i in range(1,V):
		print "{0} - {1}".format(parent[i],i)



if __name__ == "__main__":
	adj = []
	V,e = raw_input().split()
	V = int(V)
	for i in range(V):
		adj.append([])
	e = int(e)
	for i in range(e):
		st,dt,wt = raw_input().split()
		st = int(st)
		dt = int(dt)
		wt = int(wt)
		adj[st].append({"dest":dt,"wt":wt})
		adj[dt].append({"dest":st,"wt":wt})
	primMST(adj)
	#for i in range(V):
	#	print len(adj[i])
