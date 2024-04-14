#include<stdio.h>
#include<conio.h>
int main()
{
FILE *f1,*f2;
f1=fopen("D:\\Baihat.txt","wt");
f2=fopen("D:\\Baica.txt","wt");
if (f1!=NULL && f2!=NULL)
{
int ch=fgetc(f1);
while (! feof(f1))
{
fputc(ch,f2);
ch=fgetc(f1);
}
int fcloseall();
}
getch();
return 0;
}
