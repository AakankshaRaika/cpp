#prim V2
from sys import maxint
MAX = maxint
def minKey(keys,mst):
	mn = MAX
	minkey = 0
	for i in range(len(keys)):
		if mst[i]==False and keys[i]<mn:
			mn = keys[i]
			minkey = i
	return minkey

def primMST(graph):
	l = len(graph)
	mst = []
	keys = []
	parent = []
	for i in range(l):
		keys.append(MAX)
		mst.append(False)
		parent.append(-1)
	keys[0] = 0
	parent[0] = -1
	for i in range(l-1):
		u = minKey(keys,mst)
		mst[u] = True
		for v in range(l):
			if graph[u][v]!=0 and mst[v]==False and graph[u][v]<keys[v]:
				keys[v] = graph[u][v]
				parent[v] = u
	for i in range(1,l):
		print "{0} - {1} : {2}".format(parent[i],i,graph[i][parent[i]])


if __name__ == "__main__":
	graph = [(0,2,0,6,0),(2,0,3,8,5),(0,3,0,0,7),(6,8,0,0,9),(0,5,7,9,0)]
	primMST(graph)
