#include<iostream>
using namespace std;
/*class CE
{
 int A[100],n,amt;
 public:
 	void Read();
 	void sort();
 	void print();
};
void CE :: Read()
{
 cout<<"Enter number of denominations";
 cin>>n;
 cout<<"Enter deniminations";
 for(int i=0;i<n;i++)
 	cin>>A[i];
 cout<<"Enter Amount: ";cin>>amt;
}

void CE :: sort()
{
 int i,j;
 for(i=1;i<n;i++)
 	for(j=i;j<n;j--)
 		if(A[j]<=A[j-1])
 			{
 			 int temp=A[j];
 			 	A[j]=A[j-1];
 			 	A[j-1]=temp;
 			}
 		else
 			break;
 			
 for(i=0;i<n;i++)
 	cout<<A[i]<<" ";
}
void CE :: print()
{
 int x=amt,count=0,i;
 for(i=n-1;i>=0;i--)
 		{count+=x/A[i];cout<<x/A[i]<<","<<A[i]<<" Rupee notes"<<"\n";x=x%A[i];}
 cout<<"Total Notes: ";cout<<count;
}
int main()
{
 CE c;
 c.Read();
 c.sort();
 c.print();
 return 0;
}
*/
struct wp{int p,w;float r;};
class KS
{
 int n,M,T[100];wp X[100];
 public:
 	void Read();
 	void sort();
 	void print();
 	
};
void KS :: Read()
{
 cout<<"Enter Size";
 cin>>n;
 cout<<"Enter Weight price";
 for(int i=0;i<n;i++)
 	{cin>>X[i].w>>X[i].p;}
 cout<<"Enter bag size";cin>>M;
  cout<<"price per unit weight array:(before sorting) ";
 for(int i=0;i<n;i++)
 	{X[i].r=X[i].p*1.0/X[i].w;cout<<X[i].r<<" ";}

}

void KS :: sort()
{
/*
 int i,j;
 for(i=1;i<n;i++)
 	for(j=i;j<n;j--)
 		if(X[j].p<=X[j-1].p)
 			{
 			  	int temp=X[j].p;
 			 	X[j].p=X[j-1].p;
 			 	X[j-1].p=temp;
 			}
 		else
 			break;*/
 int i,j;
  for(i=0;i<n;i++)
  	for(j=0;j<n-i-1;j++)
  		if(X[j].r>=X[j+1].r)
  			{
  			 wp temp;
  			 temp=X[j];
  			 X[j]=X[j+1];
  			 X[j+1]=temp;
  			}
  cout<<"\nWeight By price array:(After sorting) ";
 for(int i=0;i<n;i++)
 	{cout<<X[i].r<<" ";}
}

void KS :: print()
{
 int i,x=M,count=0,j;
 for(i=n-1;i>=0;i--)
 	{
 	 if(X[i].w>x)
 	 	{count++;
 	 	 X[i].w=x;x-=X[i].w;
 	 	}
 	 else
 	 {count++;x-=X[i].w;}
 	 
 	if(x==0)
 		break;
 	}
 cout<<"Number of items taken";cout<<count;
 	
 if(count==0)
 	{cout<<"No items";return;}
 cout<<"Items in bag";
 for(i=n-1,j=0;j<count;i--,j++)
 	cout<<X[i].w<< " ";
 	
}
int main()
{
 KS c;
 c.Read();
 c.sort();c.print();
 return 0;
}
