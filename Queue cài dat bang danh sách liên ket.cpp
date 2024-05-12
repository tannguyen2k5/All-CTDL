//Queue c�i dat bang danh s�ch li�n ket
#include<stdio.h>
#include<conio.h>
# define N 20
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
typedef struct queu
{
 node *front;
 node *rear;
}queu;
void khoitao(queu &q)
{
 q.front=q.rear=NULL;
}
int empty(queu q)
{
 if(q.front==NULL)
 return 1;
 else
 return 0;
}
void enqueu(queu &q, node*new_ele)
{
 if(q.front==NULL)
 {
  q.front=new_ele;
  q.rear=q.front;
 }
  else
  {
   q.rear->link=new_ele;
   q.rear=new_ele;
  }
 }
sinhvien dequeu(queu &q)
{
 node *p;sinhvien x;
 if(!empty(q))
 {
  p=q.front;
  x=p->data;
  q.front=p->link;
  delete(p);
  }
 return x;
}
int main()
{
 int n;
 sinhvien x;
 queu q;
 node *new_ele;
 printf("\n nhap so phan tu:");
 scanf("%d",&n);
 khoitao(q);
 for(int i=1; i<=n; i++)
  {
   printf("\n nhap hoten:");
   fflush(stdin);
   gets(x.hoten);
   printf("\n nhap tuoi:");
   scanf("%d", &x.tuoi);
   new_ele=new(node);
   new_ele->data=x;
   new_ele->link=NULL;
   enqueu(q,new_ele);
  }
 while(!empty(q))
  {
   x=dequeu(q);
   printf("\n hoten:%s", x.hoten);
   printf("\n tuoi:%d", x.tuoi);
  }
 getch();
 }

