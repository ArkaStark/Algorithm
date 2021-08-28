#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

class Graph{
    int V;
    list<int> *adj;

    public:
        Graph(int V);
        Graph(Graph &g2) {V = g2.V; adj = g2.adj; } 
        void addEdge(int u, int v);
        void printGraph(int V);
        int edge(int v);
        Graph contractEdge();
        int vert();
};

Graph :: Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
}

void Graph::printGraph(int V) 
{ 
    cout << "\n Adjacency list of vertex "
            << V << "\n head "; 
    for (auto x : adj[V]) 
        cout << "-> " << x; 
    cout<<endl; 
} 

int Graph::vert(){
    return this->V;
}

int Graph::edge(int v){
    int c = 0;
    list<int> :: iterator i;
    for(i = adj[v].begin(); i != adj[v].end(); i++){
        c++;
    }
    return c;
}

Graph Graph::contractEdge(){
    
    srand(time(NULL));
    int V = this->V;
    int ur = rand()%V;
    int E = this->edge(ur);
    int vr = 0;
    if(E) 
        vr = rand()%E;
    list<int> :: iterator i;
    int c=0;
    for(i = adj[ur].begin(); i != adj[ur].end(); i++){
        if(c == vr){
            vr = *i;
            break;
        }
        c++;
    }
    if(ur>vr){
        int t = ur;
        ur = vr;
        vr = t;
    }
   //cout<<V<<"#"<<ur<<"..."<<vr<<endl;
   //this->printGraph(ur);
    Graph g_new(V-1);
    for(int i=0; i<V; i++){
        //cout<<i<<"**";
        if(i==vr){
            //cout<<i<<"**";
            list<int> :: iterator j;
            for(j = adj[i].begin(); j != adj[i].end(); j++){
                //cout<<*j<<"**";
                if(*j != ur){
                    if(*j > vr)
                        g_new.addEdge(ur, (*j)-1);
                    else
                        g_new.addEdge(ur, *j);
                }
            }
        }
        else if(i>vr){
            list<int> :: iterator j;
            for(j = adj[i].begin(); j != adj[i].end(); j++){
                if(*j == vr && i != ur)
                    g_new.addEdge(i-1, ur);
                else if(*j > vr)
                    g_new.addEdge(i-1, (*j)-1);
                else if(*j < vr)
                    g_new.addEdge(i-1, *j);
            }
        }
        else{
            list<int> :: iterator j;
            for(j = adj[i].begin(); j != adj[i].end(); j++){
                if(*j == vr && i != ur)
                    g_new.addEdge(i, ur);
                else if(*j > vr)
                    g_new.addEdge(i, (*j)-1);
                else if(*j < vr)
                    g_new.addEdge(i, *j);
            }
        }
    }
    
    return g_new;
}


int main(){
    fstream f;
    f.open("./kargerMinCut.txt", ios::in);
    string line="";
    Graph g(200);
    while(getline(f, line)){
        int l = line.length();
        int x=1, i=0, u = 0, v = 0;
        for(i=0; i<l; i++){
            if(line[i] == '\t'){
                //cout<<"*";
                if(x == 0)
                    g.addEdge(u-1, v-1);
                x =0;
                v = 0;
            }
            else{
                if(x)
                    u = 10*u + (line[i] - '0');
                else
                    v = 10*v + (line[i] - '0');
            }
        }
    }

    Graph g_test(4);
    g_test.addEdge(0,1);
    g_test.addEdge(0,2);
    g_test.addEdge(1,0);
    g_test.addEdge(1,2);
    g_test.addEdge(1,3);
    g_test.addEdge(2,0);
    g_test.addEdge(2,1);
    g_test.addEdge(2,3);
    g_test.addEdge(3,1);
    g_test.addEdge(3,2);

    int minCut = INT_MAX;

    for(int i=0; i<100; i++){
        cout<<minCut<<endl;
        Graph g_x = g;
        while(g_x.vert() > 2){
            //cout<<g.vert()<<endl;
            g_x = g_x.contractEdge();
        }
        if(minCut > g_x.edge(0))
            minCut = g_x.edge(0);
    }
    cout<<endl<<endl<<minCut;
    return 0;
}