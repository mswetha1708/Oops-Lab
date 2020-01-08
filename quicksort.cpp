//QuickSort
#include<iostream>
using namespace std;

class sort
{
    private:
        int beg,end,i,j,a[100],n,b[100];
    public:
        int partition1(int beg,int end);
         int partition2(int beg,int end);
        void input();
        //void print();
       void quicksort1(int beg,int end);
       void quicksort2(int beg,int end);
};


/*void sort::print()
{
     cout<<"The sorted array is \n";
    for(int p=0;p<n;p++)
    {
        cout<<a[p]<<"\t";
    }
}*/
/*
int sort::partition(int beg,int end)
{
    i=beg+1;
    int temp1,temp2;
    j=end;
    int pivot=a[beg];
    while(i<=j)
    {
       
        while(a[i]<=pivot && i<end) 
        i++;
        while(a[j]>pivot && j>beg) 
        j--;
        if((i==end || j==beg) && i==j)
        	break;
        if(i<j)
        {temp1=a[i];
        a[i]=a[j];
        a[j]=temp1;}
    }
    temp2=a[beg];
    a[beg]=a[j];
    a[j]=temp2;
    cout<<j<<" ";
    return j;
}
*/
/*
int sort::partition(int beg,int end)
{
    i=beg;
    int temp1,temp2;
    j=end;
    int pivot=a[beg];
    while(i<j)
    {
       
        while(a[i]<=pivot && i<end) 
        i++;
        while(a[j]>pivot && j>beg) 
        j--;
        if(i<j)
        {temp1=a[i];
        a[i]=a[j];
        a[j]=temp1;}
    }
    temp2=a[beg];
    a[beg]=a[j];
    a[j]=temp2;
    cout<<j<<" ";
    return j;
}
*/
/*
//End as pivot
int sort::partition(int beg,int end)
{
    i=beg-1;
    int temp1,temp2;
    j=beg;
    int pivot=a[end];
    while(j<end)
    {
       
        if(a[j]<=pivot) 
        {
         i++;
        temp1=a[i];
        a[i]=a[j];
        a[j]=temp1;}
      j++;
    }
    temp2=a[end];
    a[end]=a[i+1];
    a[i+1]=temp2;
    cout<<i+1<<" ";
    return i+1;
}
*/
/*
int sort::partition(int beg,int end)
{
 int mid=(beg+end)/2;
 int pivot=a[mid];
  i=beg;
    int temp1,temp2;
    j=end;
    while(i<j)
    {
       
        while(a[i]<=pivot && i<end) 
        i++;
        while(a[j]>pivot && j>beg) 
        j--;
        if(i<j)
        {temp1=a[i];
        a[i]=a[j];
        a[j]=temp1;}
    }
    temp2=a[mid];
    a[mid]=a[j];
    a[j]=temp2;
    cout<<j<<" ";
    return j;
}
*/
int c1=0,c2=0;
int sort::partition1(int beg,int end)
{
 int pivot=a[beg];
  i=beg;
    int temp1,temp2;
    j=end;
    while(i<j)
    {
       
        while(a[i]<=pivot && i<end) 
        i++;
        while(a[j]>pivot && j>beg) 
        j--;
        c2++;
        if(i<j)
        {temp1=a[i];
        a[i]=a[j];
        a[j]=temp1;}
    }
    temp2=a[beg];
    a[beg]=a[j];
    a[j]=temp2;
    return j;
   
}

int sort::partition2(int beg,int end)
{
 cout<<end<<beg<<"\n";
 int x=rand()%(end-beg+1);
 int pivot=b[beg+x];int pos=beg+x;
  i=beg;
    int temp1,temp2;
    j=end;
    while(i<j)
    {
       
        while(b[i]<=pivot && i<end) 
        	i++;
        while(b[j]>pivot && j>beg) 
        j--;
        if(pos==i && i<j)
        		{pos=j;}
        if(pos==j && i<j)
        		{pos=i;}
        	c1++;
        if(i<j)
        {temp1=b[i];
        b[i]=b[j];
        b[j]=temp1;}
        		
    }
    temp2=pivot;
    b[pos]=b[j];
    b[j]=temp2;
    return j;
   
}

/*
int sort::partition2(int beg,int end)
{
 int x=rand()%(end-beg+1);
  i=beg;
    int temp1,temp2,pos=beg+x;
    temp1=b[pos];
    b[pos]=b[beg];
    b[beg]=temp1;
    int pivot=b[beg];
    j=end;
    while(i<j)
    {
       
        while(b[i]<=pivot && i<end) 
        	i++;
        while(b[j]>pivot && j>beg) 
        j--;
        	c1++;
        if(i<j)
        {temp1=b[i];
        b[i]=b[j];
        b[j]=temp1;}
        		
    }
    temp2=b[beg];
    b[beg]=b[j];
    b[j]=temp2;
    return j;
   
}
*/
void sort::quicksort1(int beg,int end)
{
    if(beg<end)
    {
        i=partition1(beg,end);
        quicksort1(beg,i-1);
        quicksort1(i+1,end);
    }
   
}

void sort::quicksort2(int beg,int end)
{
    if(beg<end)
    {
        i=partition2(beg,end);
        quicksort2(beg,i-1);
        quicksort2(i+1,end);
    }
   
}

void sort::input()
{
    cout<<"enter the number of elements in the array\n";
    cin>>n;int l;
    cout<<"Enter the values\n";
    for(l=0;l<1000;l++)
    {for(int k=0;k<n;k++)
    { 
     a[k]=rand()%1000;b[k]=a[k];}
    quicksort1(0,n-1);
    quicksort2(0,n-1);
     for(int p=0;p<n;p++)
    {
        cout<<a[p]<<"\t";
    }
    cout<<"c2:"<<c2<<"\n";
     for(int p=0;p<n;p++)
    {
        cout<<b[p]<<"\t";
    }
    cout<<"c1:"<<c1<<"\n";
    }
    cout<<"Avg(random)"<<c1*1.0/l<<"\nAvg(normal)"<<c2*1.0/l;
    //print();
}

int main()
{
    srand(time(0));
    sort s;
    s.input();
    
  
   

}
