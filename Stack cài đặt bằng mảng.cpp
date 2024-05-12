//Stack cài ??t b?ng m?ng
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define N 20
typedef struct Node
{       long maso;
	char hoten[40];
	char diachi[100];
}node;
typedef struct stack
{
	int top;
	node list[N];
}stack;
void khoitao(stack &s)
{
	s.top=-1;
}
int empty(stack s)
{
	return s.top==-1?1:0;
}
int full(stack s)
{
	return s.top==N-1?1:0;
}
void push(stack &s,node x)
{
	if(!full(s))
	s.list[++s.top]=x;
}
node pop(stack &s)
{ node x;
	if(!empty(s))
	x=s.list[s.top--];
	return x;
}
int main()
{
	int n;stack s;node x;
	int t1; char *t2 ; char *t3 ;
	printf("\n nhap vao so phan tu:");
	scanf("%d",&n);
	khoitao(s);
	for(int i=0;i<n;i++)
	{
		printf("\n nhap ma so:");
		scanf("%d",&x.maso);
		printf("\n nhap ho ten:");
		fflush(stdin);
		gets(x.hoten);
		printf("\n nhap dia chi :");
		fflush(stdin);
		gets(x.diachi);
		push(s,x);
	}
while(!empty(s))
{
	x=pop(s);
     printf("\nMa so:%d Ho ten:%s Dia chi:%s",x.maso,x.hoten,x.diachi);
     /*  printf("\n ma so:%d",x.maso);
       printf("\n ho ten:%s",x.hoten);
       printf("\n dia chi:%s",x.diachi);
      */
}
}

