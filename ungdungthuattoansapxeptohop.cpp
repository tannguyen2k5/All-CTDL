//?ng d?ng ng?n x?p ?? tính t? h?p
#include <stdio.h>
#include <conio.h>
typedef struct Trangthai
{
	int n;
	int k;
}Trangthai;
typedef struct node
{
	Trangthai data;
	node *link;
}node;
typedef struct stack
{
	node *top;
}stack;
void Init(stack &s)
{
	s.top=NULL;
}
int Empty(stack s)
{
	return s.top==NULL?1:0;
}
void Push(stack &s,Trangthai x)
{
	node *p;
	p=new(node);
	p->data=x;
	p->link=s.top;
	s.top=p;
}
Trangthai Pop(stack &s)
{
	node *p;
	if(!Empty(s))
		p=s.top;
		s.top=p->link;
	return p->data;
}
long Combo(int n,int k)
{		
		stack st; long TH=0;
		Trangthai tt, tt1,tt2; 
		Init(st);
		tt={n,k};
		Push(st,tt);
		while (!Empty(st))
		{
		tt=Pop(st);
		if(tt.k==0 || tt.n==tt.k)	
			TH = TH + 1;
		if(tt.k>0 && tt.n>tt.k)	
			{
			printf("A");	
			tt1={tt.n-1,tt.k-1};
			Push(st,tt1);
			tt2={tt.n-1,tt.k};
			Push(st,tt2);
			}
		}
	return TH;
}
int main()
{
int n, k;
printf("\n Nhap vao n:");	scanf("%d",&n);
printf("\n Nhap vao k:"); 	scanf("%d",&k);
printf("\n Ket qua:%d",Combo(n,k));
getch();
}

