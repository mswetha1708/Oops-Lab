//Dijkstra Algorithm
#include<iostream>
using namespace std;
struct node {int u,v,w;};
class graph
{
 int V,mark[100],dist[100],dis[100];int C[100][100],s;
 node N[100];int E;
 public:
 	void read();
 	int mindist();
 	void Dijkstra(int s);
 	void Bellmanford(int s);
 	void cbf();
 	void calldijstra(); 
 	void print1(int s);
 	void print2(int s);	
};

void graph :: read()
{
 int i,we,j,k;
 cout<<"Number of Computers";cin>>V;
 cout<<"Enter Edges";cin>>E;
 cout<<"Enter computer number1, number2, distance";
 for(i=0;i<V;i++)
 	for(j=0;j<V;j++)
 		C[i][j]=0;
 for(i=0;i<E;i++)
 	{
 	 cin>>j>>k>>we;
 	 N[i].u=j;N[i].v=k;N[i].w=we;
 	 C[j-1][k-1]=we;C[k-1][j-1]=we;
 	} 
}
int graph :: mindist()
{
 int min=10000,pos=0,i;
 for(i=0;i<V;i++)
 	if(mark[i]==0 && dist[i]<min)
 		{min=dist[i];pos=i;}
 return pos;
}
void graph :: Dijkstra(int s)
{
    
	int i,pos,j;
 	for(i=0;i<V;i++)
 		mark[i]=0;
 	for(i=0;i<V;i++)
 		dist[i]=10000;
 	dist[s-1]=0;
 	for(i=1;i<V;i++)
 		{   pos=mindist();
 			mark[pos]=1;
 			for(j=0;j<V;j++)
 				if(dist[j]>dist[pos]+C[pos][j] && C[pos][j]!=0)
 					{dist[j]=dist[pos]+C[pos][j];}
 					
 		}	
}
void graph :: Bellmanford(int s)
{
 int i,j;
 for(i=1;i<=V;i++)
 	dis[i]=10000;
 dis[s]=0;
 //cout<<E;
 for(i=1;i<=V;i++)
 	{
 		for(j=0;j<E;j++)
 			if(dis[N[j].v]>dis[N[j].u]+N[j].w)
 				dis[N[j].v]=dis[N[j].u]+N[j].w;
 				
 	}		
}
void graph :: calldijstra()
{
 int i=0;
 for(i=0;i<V;i++)
 	{
 	 cout<<"With "<<i+1<<"as source:\n";
 	 Dijkstra(i+1);
 	 print1(i);
 	}
}
void graph :: cbf()
{
 int i=0;
 cout<<"BELLMAN FORD";
 for(i=0;i<V;i++)
 	{
 	 cout<<"With "<<i+1<<"as source:\n";
 	 Bellmanford(i+1);
 	 print2(i+1);
 	}
}
void graph :: print1(int s)
{
 int i;
 for(i=0;i<V;i++)
 	if(i!=s)
 		{
  		 cout<<"to"<<i+1<<"th computer-shortest path"<<dist[i]<<"\n";
  		}  
}
void graph :: print2(int s)
{
 int i;
 for(i=1;i<=V;i++)
 	if(i!=s)
 		{
  		 cout<<"to"<<i<<"th computer-shortest path"<<dis[i]<<"\n";
  		}  
}
int main()
{
 graph G;
 G.read();
 G.calldijstra();
 G.cbf();
 return 0;
}
