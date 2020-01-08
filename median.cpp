#include<iostream>
using namespace std;
class hit
{
 int k;
 public:
        int a[10];
        int input();
        void output();
        int selection(int a[10],int beg,int end,int i);
        int partition(int b[10],int x,int n);
        int sort(int c[10],int beg,int end,int pos);//check if beg<end
};


int hit::input()
{
 cout<<"\nEnter the hits of 10 websites \n";
 for(int i=0;i<10;i++)
 {
  cin>>a[i];
 }
 cout<<"\nEnter the kth smallest element to be found:\n";
 cin>>k;
 return(k);
}


void hit::output()
{
 cout<<"\nThe Entered hits are : ";
 for(int i=0;i<10;i++)
 {
  cout<<a[i]<<"\t";
 } 
}

int hit::selection(int a[10],int beg,int end,int i)
{
 int n=end-beg+1;
 int b[((n/5)+1)];
 int c[5];
 int y=5;
 int u;
 cout<<"hyorgarray";
 for(int ms=beg;ms<=end;ms++)
 	cout<<ms<<":"<<a[ms]<<" ";
 if(n<=5)      //base case
 { 
  return(sort(a,beg,end,i));
 }
 for(int j=beg,k=beg+4,t=0;t<n/5;t++,j+=5,k+=5)             //splitting the array into 5 elemental array and finding the median of each array and storing it in b
 {
  //cout<<"size: "<<5/2+j;
  b[t]=sort(a,j,k,5/2+j);
  cout<<b[t]<<" "<<t;
 }
 y=5*(n/5);
         //finding the median for the residual batch             
 if(n%5==0)                     //the no. of elements in b changes when n%5==0.To avoid junk memory , flag with y 
 {
  y=0;
 }
 else
 {
  b[n/5]=sort(a,y,((y+n%5)-1),(n%5)/2);  
  y=1;cout<<"The last element of b"<<b[n/5];
 }
 
 int x;
 if(y==1)
 {
  y=(n)/5+1;
  x=selection(b,0,n/5,y/2-1); //finding median of median
 }
 else if(y==0)
 {
  y=(n/5);
  x=selection(b,0,y-1,y/2-1);  //finding median of median
 }
 //cout<<"xis"<<x;
 int k;
 k=partition(a,x,n);         //finding position of median of median.
 if(i<k)                   //pruning the unwanted parts
 {
  //cout<<"JJJJ";
  return(selection(a,0,k-1,i));
 }
 else if(i==k)
 {
  return(a[k]);
 }
 else
 { //cout<<"hi";
  return(selection(a,k+1,n-1,i));  
 }
}

int hit::partition(int b[10],int x,int n)
{
 int pos,temp;
 for(pos=0;pos<n;pos++)
 {
  if(b[pos]==x)
  {
   break;
  }
 }
 int i=0;
 int j=n-1;
 temp=b[0];
 b[0]=b[pos];
 b[pos]=temp; 
 while(i<j)
 {
  while(b[i]<=x && i<n)
  {
   i++;
  }
  while(b[j]>x && j>0)
  {
   j--;
  }
  if(i<j)
  {
   temp=b[i];
   b[i]=b[j];
   b[j]=temp;
  }
 }
 temp=b[0];
  b[0]=b[j];
  b[j]=temp;
  cout<<"\n";
 for(int k=0;k<n;k++)
 	cout<<b[k];
 cout<<"\n";
 cout<<j;
 return(j);
}

int hit::sort(int c[10],int beg,int end,int pos)
{
 int t;
 if(beg<=end)
 {
  for(int i=beg;i<=end;i++)
  {
   for(int j=beg;j<end;j++)
   {
    if(c[j]>c[j+1])
    {
     t=c[j];
     c[j]=c[j+1];
     c[j+1]=t;
    }
   }
  }
  return(c[pos]);
 }
}

int main()
{
 hit o;
 int t;
 int i;
 i=o.input()-1;
 t=o.selection(o.a,0,9,i);
 o.sort(o.a,0,9,i);
 o.output();
 cout<<"\nThe "<<i+1<<"th smallest element is: "<<t;
 //t=o.selection(o.a,0,9,4);
 //cout<<"\nThe median of the array :"<<t;
}
 

 
