#include<iostream>
using namespace std;
struct node{char X;int f;node*lptr;node* rptr;};
struct Queue{int front,rear;node **A;int size;};
class code
{
	Queue *FQ,*SQ;
 	public:
 		void insert(Queue *Q,node*item);
 		node*del(Queue *Q);
 		Queue* read(int y);
 		node* createnode(char a,int y);
 		void read2();
 		void deread2(node* root);
 		void print(node * root,int A[],int top);
 		void print2(int A[],int top);
 		 node* gf( Queue* Q);
 		node* retmin();
 		node* buildtree();
};
void code ::insert(Queue *Q,node*item)
{
	
 	if(Q->front==Q->size-1)
 		return;
 	if(Q->front==-1)
		Q->front=Q->rear=0;
	else
		Q->rear++;
	Q->A[Q->rear]=item; 		
}
node* code ::del(Queue *Q)
{
	node*temp;
 	if(Q->front==-1)
 		return temp;
 	temp=Q->A[Q->front];
 	if(Q->front==Q->rear)
 		Q->front=Q->rear=-1;
 	else
 		Q->front++; 
 	return temp;	
}
Queue* code ::read(int y)
{
	Queue *Q=new Queue; 
 	Q->size=y;
 	Q->front=-1;Q->rear=-1;
 	Q->A =new node*[Q->size];
 	return Q;
}
node* code :: createnode(char a,int y)
{
 node *item=new node;
 item->X=a;
 item->f=y;
 item->lptr=NULL;
 item->rptr=NULL;
 return item;
}
void code ::read2()
{
 int A[100];char b[100]; int n;node *item;
 cout<<"Enter no: of elements";
 cin>>n;
 cout<<"Enter char: Enter frequency";
 for(int i=0;i<n;i++)
 	{
 	 cin>>b[i]>>A[i];
 	}
 FQ=read(n);SQ=read(n);
for(int i=0;i<n;i++)
 	{
 	 item=createnode(b[i],A[i]);
 	 insert(FQ,item);
 	}
 node *root=buildtree();
 int C[100],top=0;
 cout<<"Encoded char and frequencies: \n";
 print(root,C,top);
 deread2(root);
}
node* code ::retmin()
{
 if(FQ->front==-1)
 	{return del(SQ);}
 else if(SQ->front==-1)
 	{return del(FQ);}
 	if(gf(FQ)->f<gf(SQ)->f)
 		{return del(FQ);}
 	return del(SQ);
}
node* code :: gf(Queue*Q)
{
 return Q->A[Q->front];
}
node * code ::buildtree()
{
 node* lptr,*rptr,*top;
 while(!(FQ->front==-1 && SQ->front==SQ->rear && SQ->front!=-1))
 	{
 	 cout<<"Hello";
 	 lptr=retmin();cout<<lptr->f;
 	 rptr=retmin();cout<<rptr->f;
 	 top=createnode('+',lptr->f+rptr->f);
 	 top->lptr=lptr;
 	 top->rptr=rptr;
 	 insert(SQ,top);
 	}
 return del(SQ);
}
void code ::print(node * root,int C[],int top)
{
 if(root->lptr)
 	{
 	 C[top]=0;
 	 print(root->lptr,C,top+1);
 	}
 if(root->rptr)
 	{
 	 C[top]=1;
 	 print(root->rptr,C,top+1);
 	}
 if(root->lptr==NULL && root->rptr==NULL)
 	{
 	 cout<<root->X<<" ";
 	 print2(C,top);
 	 
 	}
}
void code :: print2(int C[],int top)
{
 for(int i=0;i<top;i++)
 	cout<<C[i];
 	cout<<"\n";
}
void code ::deread2(node * root)
{
 char BS[100],A[100];node *curr=root;int c=0,i;
 cout<<"Enter binary string to be decoded";cin>>BS;
 for(i=0;BS[i];i++)
 	{
 	 if(BS[i]=='0')
 	 	curr=curr->lptr;
 	 if(BS[i]=='1')
 	 	curr=curr->rptr;
 	 if(curr->lptr==NULL && curr->rptr==NULL)
 	 	{A[c]=curr->X;
 	 	 c++;
 	 	 curr=root;
 	 	} 	 	
 	}
 	A[c]='\0';cout<<A;
 	//for(i=0;i<c;i++)
 		//cout<<A[i];
}
int main()
{
 code c;
 	c.read2();
 return 0;
}
