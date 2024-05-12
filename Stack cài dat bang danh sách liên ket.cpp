//Stack cài ??t b?ng danh sách liên k?t
#include <stdio.h>
#include<conio.h>
typedef struct sinhvien
{
	char hoten[40];
	int tuoi;
}sinhvien;
typedef struct node
{
	sinhvien data;
	node *link;
}node;
typedef struct stack
{
	node *top;


}stack;
void khoitao(stack &s)
{
	s.top=NULL;
}
int empty(stack s)
{
	return s.top==NULL?1:0;

}
void push(stack &s,sinhvien x)
{
	node *p;
	p=new(node);
	p->data=x;
	p->link=s.top;
	s.top=p;
}
sinhvien pop(stack &s)
{
	node *p;
	if(!empty(s))
		p=s.top;
		s.top=p->link;
	return p->data;
}
int main()
{
	int n;stack s;sinhvien x;
	printf("\nmhap vao so phan tu:");
	scanf("%d",&n);
	khoitao(s);
	for(int i=0;i<n;i++)
	{
		printf("\nnhap ho ten:");
		fflush(stdin);gets(x.hoten);
		printf("\nnhap tuoi:");
		scanf("%d",&x.tuoi);
		push(s,x);
	}
	while(!empty(s))
	{
		x=pop(s);
		printf("\nho ten :%s",x.hoten);
		printf("\ntuoi:%d",x.tuoi);
	}
	getch();
}

