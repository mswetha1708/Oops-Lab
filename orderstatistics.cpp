//Finding ith largest element
#include<iostream>
using namespace std;
class sort
{
 int A[100],n,k;
public:
	void read();
	int select(int A[],int beg,int end,int i,int n2);
	//void select();
	int partition(int x,int beg,int end);
};

void sort ::read()
{
 cout<<"enter size";cin>>n;cin>>k;cout<<"Enter number";
 for(int i=0;i<n;i++)
 	cin>>A[i];
 cout<<"Answer is"<<select(A,0,n-1,k-1,n);
 //cout<<partition(12,0,n-1);
} 

//checked-partition works perfectly
int sort :: partition(int x,int beg,int end) 
{
 int pos;
 for(pos=beg;pos<=end;pos++)
 	if(A[pos]==x)
 		break;
 int temp=x;
 A[pos]=A[beg];
 A[beg]=temp;
 int i,j;
 i=beg;j=end;
 int pivot=A[beg];
 while(i<j)
 {
  while(A[i]<=pivot && i<=end)
  	i++;
  while(A[j]>pivot && j>beg)
   j--;
  if(i<j)
  	{
  	 temp=A[i];
  	 A[i]=A[j];
  	 A[j]=temp;
  	}  
 }
 temp=A[beg];
 A[beg]=A[j];
 A[j]=temp;
 cout<<"\n";
 for(i=0;i<n;i++)
 	cout<<A[i]<<" ";
 cout<<"\n";
 return j;
}
int r2=0;
int sort :: select(int X[],int beg,int end,int l,int n2)
//void sort :: select()
{	cout<<beg<<end;
	int b[100],c[100],d=beg,e=0,i,j,m,r;
 		int y,x;
 	if(n2<=5)
 		{
 		 for(i=beg,r=0;i<=end;i++,r++)
 		 	for(j=beg;j<n2-r-1+beg;j++)
 		 		if(X[j]>=X[j+1])
 		 			{ cout<<"sort";
 		 			 int temp=X[j];
 		 			 X[j]=X[j+1];
 		 			 X[j+1]=temp;
 		 			}
 		 		//	for(i=beg;i<=end;i++)
 		 			//	cout<<l<<" ";
 		 			return X[l];
 		}
 	while(1)
 		{
 		  //int m=0;
 		 for(i=0;i<5 && d<=end;i++)
 		 	{c[i]=X[d];d++;}
 		 int w=i;
 		 for(i=0;i<w;i++)
 		 	for(j=0;j<w-i-1;j++)
 		 		if(c[j]>=c[j+1])
 		 			{
 		 			 int temp=c[j];
 		 			 c[j]=c[j+1];
 		 			 c[j+1]=temp;
 		 			}
 		 b[e]=c[w/2];e++;
 		 if(d>end)
 		 	break;
 		 }
 		 //cout<<e;Checked while-works perfectly
 	//for(i=0;i<e;i++)
 	//cout<<b[i]<<" ";
 	//if(e>5)
   { 	r2++; // cout<<"r2:"<<r2;
   	x=select(b,0,e-1,(e-1)/2,e);}
 	/*else
 	 {cout<<"Hi";
 	  x=select(b,0,e-1,(e-1)/2,e);}*/
 	 while(r2>1)
 	 	{ r2--;return x;}
 	  r2=0;
 	  //cout<<x; 
 	m=partition(x,beg,end);cout<<x<<m;
 	if(m==k-1)
 		return x;
 	else if(m>k-1)
 		{//cout<<"Hello"<<beg<<m-1<<k;
 		 y=select(A,beg,m-1,k-1,m-beg);}
 	else
 		{//cout<<"Hello"<<m+1<<k-m-2;
 		 y=select(A,m+1,end,k-1,end-m);}
 	return y;
}	

int main()
{
 sort s;s.read();
 return 0;
}
