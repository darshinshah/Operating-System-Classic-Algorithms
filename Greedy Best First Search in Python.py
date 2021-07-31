import numpy as np
from queue import PriorityQueue

def initialize():
  graph=np.array([
  [0  ,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,1	,1	,0	,0	,1],
  [0	,0	,0	,0	,0	,1	,1	,0	,0	,0	,0	,0	,0	,1	,0	,0	,0	,1	,0	,0],
  [0	,0	,0	,1	,0	,0	,0	,0	,0	,0	,0	,0	,0	,1	,1	,0	,0	,0	,0	,0],
  [0	,0	,1	,0	,0	,0	,0	,0	,0	,0	,1	,0	,0	,0	,0	,0	,0	,0	,0	,0],
  [0	,0	,0	,0	,0	,0	,0	,1	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0],
  [0	,1	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,1	,0	,0	,0	,0],
  [0	,1	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0],
  [0	,0	,0	,0	,1	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,1	,0	,0],
  [0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,1	,0	,0	,0	,0	,0	,0	,1	,0],
  [0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,1	,0	,0	,0	,0	,0	,1	,0	,0	,0],
  [0	,0	,0	,1	,0	,0	,0	,0	,0	,1	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0],
  [0	,0	,0	,0	,0	,0	,0	,0	,1	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0],
  [0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,1	,0	,0	,0	,1],
  [0	,1	,1	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,1	,0	,0	,0	,0	,0],
  [0	,0	,1	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,1  ,0  ,1	,0	,0	,0	,0],
  [1	,0	,0	,0	,0	,1	,0	,0	,0	,0	,0	,0	,1	,0	,1	,0	,0	,0	,0	,0],
  [1	,0	,0	,0	,0	,0	,0	,0	,0	,1	,0	,0	,0	,0	,0	,0  ,0	,0  ,0  ,0],
  [0	,1	,0	,0	,0	,0	,0	,1	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,1	,0],
  [0	,0	,0	,0	,0	,0	,0	,0	,1	,0	,0	,0	,0	,0	,0	,0	,0	,1	,0	,0],
  [1	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0	,0  ,1  ,0  ,0  ,0  ,0  ,0  ,0  ,0],
  [366, 0, 160, 242, 161, 176, 77,151,226,244,241,234,380,100,193,253,329,80,199,374]
  ])
  return graph

def dispq(queue):
  #copying queue for deep copy
  #queue format is (priority no, data(starting from 1))
  newqueue = PriorityQueue()
  for i in queue.queue:
    newqueue.put(i)
  while not newqueue.empty():
    next_item = newqueue.get()
    print(next_item)

def start_node():
  #start node 1 - 20 choose
  #for : node ka successor with 1 in map 
  snode = int(input('Enter a start node value in between 1 - 20'))
  snode = snode-1
  if snode<0 or snode>20:
    print('ERROR ==> Please Enter A Start node Vlaue in between the given range only!!!\n')
    snode=start_node()
    return snode #meet ko samjana hain
  else:
    print('Starting Node Selected is ==> ',snode) 
    return snode

#main here
graph = initialize()   
q = PriorityQueue()
visited=np.array([0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0])

#insert start node
snode=start_node()
visited[snode]=1
q.put((graph[20][snode],snode+1))

#this prints the first node in the priority queue
#print('The Initial or the starting node is : ')
#dispq(q)

while not q.empty():
  u = (q.get()[1])-1 #this will store the data of the priority queue in the 
  print('The Selected Node is : ',u) #u has starting index = 0
  if u==1: # since the node to be found is B it is index =1
    print('Goal Node Found !!')
    break
  else:
    for i in range(0,20):
      if graph[u][i]==1 and visited[i]==0:
        visited[i]=1
        q.put((graph[20][i],i+1))
        print(visited)