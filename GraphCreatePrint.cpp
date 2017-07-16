/*a Djikstra algorithm implementation in C++*/

#include<bits/stdc++.h>
#include<iostream>

using namespace std;

typedef pair <int,int> iPair;

class Graph{
	public:
		Graph(int V);
		void addEdge(int u, int v, int w);
		void traverse();
	private:
		int V;
		list <iPair> *adj;
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w){
	adj[u].push_back(make_pair(v,w));
	adj[v].push_back(make_pair(u,w));
}

void Graph::traverse(){
	vector <bool> visited(V,NULL);
	priority_queue < int, vector<int>, greater<int> > pq;
	pq.push(0);
	while(!pq.empty()){
		int j = pq.top();
		visited[j] = 1;
		pq.pop();
		for(list<iPair>::iterator i = adj[j].begin(); i!=adj[j].end(); i++){
			if (visited[(*i).first]!=1){ 
				pq.push((*i).first);
				visited[(*i).first] = 1;
					}//if
					}//for
		cout<<j<<" ";
		}//while
}//traverse

//main method
int main(){
	int NodeNum, prompt1=0, prompt2=0,  u, v, w;
	while (prompt1!=2){
		prompt2 = 0;
		cout<<"\nCreating a graph..\n\n";
		cout<<"1\tContinue\n";
		cout<<"2\tExit\n";
		cin>>prompt1;
		switch (prompt1){
			case 1:{
				cout<<"Enter the number of Vertices:  ";
				cin>>NodeNum;
				Graph g(NodeNum);
				while(prompt2 != 2){
					cout<<"\n1\tAddEdge";
					cout<<"\n2\tDone!!\n\n";
					cin>>prompt2;
					switch(prompt2){
						case 1:{
							cout<<"Enter source, destination and weight of the edge separated by space: ";
							cin>>u>>v>>w; cout<<endl;
							g.addEdge(u,v,w);
							break;}
						case 2:{
							cout<<endl; g.traverse(); cout<<endl;
							break;}
						default:{
							cout<<"Fuck You!!\n";
							break;}
							}//innerSwitch
						}//innerWhile
				break;}
			case 2:{
				break;}
			default:{
				cout<<"Fuck You!!\n";
				break;}
			}//switch
		}//while
	return 0;
}
