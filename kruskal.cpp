//Kruskal Algorithm
#include<iostream>
using namespace std;
struct Edge{int s,d,c;};
class Graph
{
 Edge E[100],CE[100];int n,v,p[100];
 public:
 	void read();
 	void sort();
 	int find(int n);
 	void unions(int n1,int n2);
 	void chooseedge();
};
void Graph :: read()
{
 	cout<<"Enter no: of edges";cin>>n;
 	cout<<"Enter no: of vertices";cin>>v;
 	cout<<"Enter source,Destn,Cost";
 	for(int i=0;i<n;i++)
 		cin>>E[i].s>>E[i].d>>E[i].c;
 	 
}
int Graph :: find(int n)
{
 	while(p[n]>0)
 		{
 		 n=p[n];
 		}
 	return n;
}
void Graph :: unions(int n1,int n2)
{
 if(p[n1]*(-1)>=p[n2]*(-1))
 		{
 		p[n1]=p[n1]+p[n2];
 		p[n2]=n1;
 		}
 else
 	{
 	 p[n2]=p[n1]+p[n2];
 	 p[n1]=n2;
 	}
}

void Graph :: chooseedge()
{
 int i,c=0,temp1,temp2;
 for(i=0;i<v;i++)
 	p[i]=-1;
 unions(E[0].s,E[0].d);
 cout<<find(E[0].s);
 CE[0]=E[0];
 c++;
 for(i=1;i<n;i++)
 	{
 	 if(c==v-1)
 		break;
 	temp1=find(E[i].s);
 	temp2=find(E[i].d);
 	 if(temp1!=temp2)
 	 	{unions(temp1,temp2);
 	 	 CE[c]=E[i];c++;}
 	}
 
 	cout<<"S"<<"D"<<"C"<<"\n";
 for(i=0;i<c;i++)
 	cout<<CE[i].s<<CE[i].d<<CE[i].c<<"\n";		
} 	
int main()
{
Graph G;
G.read();G.chooseedge();
 return 0; 	
}
