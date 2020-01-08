//MCSSS
#include<iostream>
using namespace std;
int A[20],B[20],n,m,beg,end,flag=0;
class DNA
{
 char S[20],F[20];
 public:
 	void read();
 	void bruteforce();
 	void incdesign();
 	void dividenconquer();
 	void pruning();
 	void print();
};

void DNA :: read()
{
 cout<<"Enter father DNA sequence";
 cin>>F;
 cout<<"Enter sons DNA sequence";
 cin>>S;int i;
  for(i=0;S[i];i++)
 	switch(S[i])
 		{
 		 case 'A':case'a': A[i]=2;break;
 		 case 'G':case'g':A[i]=-1;break;
 		 case 'C':case'c':A[i]=1;break;
 		 case 'T':case't':A[i]=-2;break;
 		 default:cout<<"Invalid alphabet";
 		}
 	
 	  for(i=0;F[i];i++)
 	switch(F[i])
 		{
 		 case 'A':case 'a': B[i]=2;break;
 		 case 'G':case 'g':B[i]=-1;break;
 		 case 'C':case 'c':B[i]=1;break;
 		 case 'T':case 't':B[i]=-2;break;
 		 default:cout<<"Invalid alphabet";
 		}
 int j;
 for(i=0;F[i];i++);n=i;
 for(j=0;S[j];j++);m=j;
 for(i=0;i<m;i++)
 	cout<<A[i];
 		for(i=0;i<n;i++)
 	cout<<B[i];
}

void DNA ::incdesign()
{
 int i,j,msum=0,sum;
 for(i=0;i<m;i++)
  { sum=0;
 	for(j=i;j<m;j++)
 	 {
 	 
 	 sum+=A[j];
 	if(sum>=msum)
 		{msum=sum;beg=i;end=j;}	
 	}
  }
  cout<<msum<<" ";
    for(i=beg;i<=end;i++)
  cout<<S[i];
  cout<<"\n";
  int msum2=0;
  for(i=0;i<n;i++)
  { sum=0;
 	for(j=i;j<n;j++)
 	{
 	 sum+=B[j];
 	if(sum>=msum2)
 		{msum2=sum;beg=i;end=j;}
 		
 	}
  }
  cout<<msum2<<" ";
   for(i=beg;i<=end;i++)
  cout<<F[i];
  cout<<"\n";
}

void DNA ::bruteforce()
{
 int i,j,k,msum=0,sum,beg=0,end=0;
 for(i=0;i<m;i++)
  	for(j=i;j<m;j++)
  {	
    sum=0;	
    for(k=i;k<=j;k++)
 	 {sum+=A[k];}
 	if(sum>=msum)
 		{msum=sum;beg=i;end=j;}
  }
  cout<<msum<<" ";
  for(i=beg;i<=end;i++)
  cout<<S[i];
  cout<<"\n";
  int msum2=0;
   for(i=0;i<n;i++)
    for(j=i;j<n;j++)
  {	
    sum=0;	
    for(k=i;k<=j;k++)
 	 sum+=B[k];
 	if(sum>=msum2)
 		{msum2=sum;beg=i;end=j;}
  }
  cout<<msum2<<" ";
  for(i=beg;i<=end;i++)
  cout<<F[i];
  cout<<"\n";
}

void DNA ::pruning()
{
 int i,sum=0,msum=0,beg=0,end=0;
 for(i=0;i<m;i++)
 	{	 sum=sum+A[i];
 	 if(msum<=sum)
 	 	{msum=sum;end=i;}
 	 if(sum<0)
 	 	{sum=0;beg=i+1;}
 	}
 cout<<msum<<" ";
   for(i=beg;i<=end;i++)
  cout<<S[i];
  cout<<"\n";
 int msum2=0;sum=0,beg=0,end=0;
  for(i=0;i<n;i++)
 	{
 	 sum=sum+B[i];
 	 if(msum2<=sum)
 	 	{msum2=sum;end=i;}
 	 if(sum<0)
 	 	{sum=0;beg=i+1;}
 	}
 cout<<msum2<<" ";
for(i=beg;i<=end;i++)
  cout<<F[i];
  cout<<"\n";
 /*
 if(msum2-msum1<10)
 	cout<<"yes";
 else
 	cout<<"no";
*/
}

int max(int LS,int RS,int msum)
{
 if(LS>RS && LS>msum)
 	return LS;
 else if(RS>LS && RS>msum)
 	return RS;
 else
 return msum;
}
 int mcsss1(int beg,int end)
 	{
 	 int LS,RS,i,msum;
 	 int mid=(beg+end)/2;
 	 if(beg==end)
 	 	if(A[beg]<0)
 	 	return 0;
 	 else
 	 	return(A[beg]);
 	 LS=mcsss1(beg,mid);
 	 RS=mcsss1(mid+1,end);
 	 int lsum=0,losum=0;
 	 for(i=mid-1;i>=beg;i--)
 	 	{
 	 	 lsum=lsum+A[i];
 	 	 if(lsum>=losum)
 	 	 	losum=lsum;
 	 	}
 	  	 int rsum=0,rosum=0;
 	 for(i=mid;i<=end;i++)
 	 	{
 	 	 rsum=rsum+A[i];
 	 	 if(rsum>=rosum)
 	 	 	rosum=rsum;
 	 	}
 	 	 msum=losum+rosum;
 	 	 return(max(LS,RS,msum));
 	 	}
 	 	
 int mcsss2(int beg,int end)
 	{
 	 int LS,RS,i,msum;
 	 int mid=(beg+end)/2;
 	 if(beg==end)
 	 	if(B[beg]<0)
 	 	return 0;
 	 else
 	 	return(B[beg]);
 	 LS=mcsss2(beg,mid);
 	 RS=mcsss2(mid+1,end);
 	 int lsum=0,losum=0;
 	 for(i=mid-1;i>=beg;i--)
 	 	{
 	 	 lsum=lsum+B[i];
 	 	 if(lsum>=losum)
 	 	 	losum=lsum;
 	 	}
 	  	 int rsum=0,rosum=0;
 	 for(i=mid;i<=end;i++)
 	 	{
 	 	 rsum=rsum+B[i];
 	 	 if(rsum>=rosum)
 	 	 	rosum=rsum;
 	 	}
 	 	 msum=losum+rosum;
 	 	 return(max(LS,RS,msum));
 	 	}

void DNA ::dividenconquer()
{
 int msum=mcsss1(0,m-1);
 cout<<msum<<" ";
 int msum2=mcsss2(0,n-1);
 cout<<msum2<<" ";
 /*if(msum2-msum1<10)
 	cout<<"yes";
 else
 	cout<<"no";
 	*/
}


int main()
{
 DNA A;
 A.read();
 A.incdesign();
 A.pruning();
 A.dividenconquer();
 A.bruteforce();
 return 0;

}

