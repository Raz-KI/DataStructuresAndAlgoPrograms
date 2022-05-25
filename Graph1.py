#Adjacenct list from num of elements and raw representation
num_nodes=5
vert=[[0,1],[0,4],[4,1],[4,3],[3,1],[3,2],[1,2]]
class GraphAdj():
    def __init__(self,nodes,verts):
        self.nodes=nodes        
        #Here we create an empty list with same number of elements as the vertices list
        #This method of creating an empty list leaves us with far lesser bugs
        self.data=[]
        for _ in range(self.nodes):
            self.data.append([])
        #Now we iterate over the verts list that is passed from outside
        #Since we will get list as the iteration we split the list elemets into two variables
        #Then since we have a pretty basic graph we can use what we have used here ie. We append both 
        #items to each other so ultimately all connections are recorded
        for n1,n2 in verts:
            self.data[n1].append(n2)
            self.data[n2].append(n1)
        #Now self.data is our Adjacency list
        print(self.data)
    def show(self):
        coun=0
        for i in self.data:
            print(coun,":",' '.join(map(str, set(i))))
            coun+=1
        print("\n")
    def addEdge(self,nod1,nod2):
        self.data[nod1].append(nod2)
        self.data[nod2].append(nod1)
graph=GraphAdj(num_nodes,vert)
graph.show()
graph.addEdge(0,3)
graph.show()