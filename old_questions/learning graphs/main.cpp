#include <bits/stdc++.h>
using namespace std;



class Graph{
    int V; //number of vertices

    //pointer to an array containing adjacency lists
    list<int> *adj;

    //a recurvise fuction used by dfs
    void DFSUtil(int v, bool visited[]);


    public:
        Graph(int V);

        //function to add edge to a graph
        void addEdge(int v, int w);

        //DFS traversal of the vertices reachable from v
        void DFS(int v);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w); //add w to v's list
}

void Graph::DFSUtil(int v, bool visited[]){

    //mark the current node as visited and print it
    visited[v] = true;
    cout<< v << " ";
    
    //recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for(i = adj[v].begin(); i!= adj[v].end(); ++i)
        if(!visited[*i])
            DFSUtil(*i, visited);
}

//DFS traversal of the vertices reachable form v
//it uses DFSUtil()
void Graph::DFS(int v){
    bool *visited = new bool[V];
    for(int i=0; i<V; i++)
        visited[i]=false;

    
    //call the recursive helper function
    //to print DFS traversal

    DFSUtil(v, visited);
}



int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 

    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.DFS(2); 

    return 0;
}