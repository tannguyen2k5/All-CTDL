//Bài 10: M?t s? ?ng d?ng thu?t toán
//?ng d?ng thu?t toán s?p x?p ngoài
#include"stdio.h"
#include"conio.h"
#include"string.h"
#include"time.h"
#include"stdlib.h"   

typedef struct
{
	char Maso[10];
	char HoTen[40];
} SinhVien;

FILE *f0,*f1,*f2;
int m,n,Eor;
SinhVien x1,x2,x,y;

int kiemtra(char *FileName,char maso[10])
{
	FILE *f;
	int Found=0; 
	SinhVien sv;
	fflush(stdin);
	f=fopen(FileName,"rb");
	while (!feof(f) && Found==0)
	{
		fread(&sv,sizeof(sv),1,f);
		if (strcmp(sv.Maso,maso)==0)
		 Found=1;
	}
	fclose(f);
	return (Found);
}

void WriteFile(char *FileName)
{
	FILE *f;
	int n,i;
	SinhVien sv;
	f=fopen(FileName,"ab");
	printf("Nhap bao nhieu sinh vien? ");
	scanf("%d",&n);
	fflush(stdin);
	for(i=1;i<=n;i++)
	{ 	
		printf("Sinh vien thu %i\n",i); 
		printf("	- MSSV: ");
		gets(sv.Maso);
		if(kiemtra(FileName,sv.Maso)==1||strcmp(sv.Maso," ")==0)
		printf("\nMa so bi trung hoac rong!!!");
		else
		{
		printf("	- Ho ten: ");
		gets(sv.HoTen); 
		fwrite(&sv,sizeof(sv),1,f); 
		fflush(stdin);	
		} 
	}
	fclose(f);
	printf("\nBam phim bat ky de tiep tuc\n");
	getch();
}

void ReadFile(char *FileName)
{
	FILE *f;
	 SinhVien sv; 
	 f=fopen(FileName,"rb");
	printf("	MSSV	|	Ho va ten\n");
	fread(&sv,sizeof(sv),1,f);
	while (!feof(f))
	{
		printf("	%s	|	%s\n",sv.Maso,sv.HoTen);
		fread(&sv,sizeof(sv),1,f);
	}
	fclose(f);
	
	printf("\nBam phim bat ky de tiep tuc\n");
	//getch();
}

void Search(char *FileName)
{
	char MSSV[10]; 
	FILE *f;
	int Found=0; 
	SinhVien sv;
	fflush(stdin);
	printf("Ma so sinh vien can tim: ");
	gets(MSSV);
	f=fopen(FileName,"rb");
	while (!feof(f) && Found==0)
	{
		fread(&sv,sizeof(sv),1,f);
		if (strcmp(sv.Maso,MSSV)==0)
			 Found=1;
	}
	fclose(f);
	if (Found == 1)
	printf("Tim thay SV co ma %s. Ho ten la: %s",sv.Maso,sv.HoTen);
	else
	printf("Tim khong thay sinh vien co ma %s",MSSV);
	
	printf("\nBam phim bat ky de tiep tuc!!!\n");
	getch();
}

void Delete(char *FileName)
{
	FILE *f1,*f2; 
	int Found=0; 
	char MSSV[10];
	SinhVien sv;
	fflush(stdin);
	printf("Ma so sinh vien can xoa:");
	gets(MSSV);
	f1=fopen(FileName,"rb"); 
	f2=fopen("e:\\Tam.Dat","wb");
	fread(&sv,sizeof(sv),1,f1);
	while (!feof(f1))
	{
		if(strcmp(sv.Maso,MSSV)!=0)
			fwrite(&sv,sizeof(sv),1,f2);
		else
			 Found=1;
		fread(&sv,sizeof(sv),1,f1);
	}
	fclose(f1);  fclose(f2);
	
	f1=fopen(FileName,"wb"); 
	f2=fopen("e:\\Tam.Dat","rb");
	fread(&sv,sizeof(sv),1,f2);
	while(!feof(f2))
	{
		fwrite(&sv,sizeof(sv),1,f1);
		fread(&sv,sizeof(sv),1,f2);
	}
	fclose(f1);  fclose(f2);
	remove("e:\\Tam.Dat");
	/*remove("e:\\Sinhvien.Dat");//xoa file goc
	rename("e:\\Tam.Dat","d:\\Sinhvien.Dat");// doi ten file Tam thanh file Sinhvien*/

	
	if(Found==1)
	
		printf("\n Da xoa sinh vien ma so %s",MSSV);
	
	else
		printf("\n Khong tim thay ma sinh vien");
		printf("\n Nhan phim bat ki de tiep tuc");
			
}
// Sap xep tap tin
void copy(FILE *fi,FILE *fj)
{
	fread(&x,sizeof(x),1,fi);
	fwrite(&x,sizeof(x),1,fj);
	if(!feof(fi))
	{
		fread(&y,sizeof(y),1,fi);
		if(!feof(fi))
		{
			long curpos=ftell(fi)-sizeof(y);
			fseek(fi,curpos,0);
		}
		else
			Eor=1;	
	}
	if(feof(fi))
	{
		Eor=1;
	}
	else
	{
		if(atoi(x.Maso)>atoi(y.Maso))
		{
			Eor=1;
		}
		else
		{
			Eor=0;
		}
	}
}
void copyRun(FILE *fi,FILE *fj)
{
	do
	{
		copy(fi,fj);
	}
	while(!Eor);
 	
}
void phanbo()
{
	do
	{
		copyRun(f0,f1);
		if(!feof(f0))
			copyRun(f0,f2);
	}
	while(!feof(f0));
	fclose(f0);
	fclose(f1);
	fclose(f2);
	
}
void tronRun()
{
	do
	{
		fread(&x1,sizeof(x1),1,f1);
		long curpos=ftell(f1)-sizeof(x1);
		fseek(f1,curpos,0);
		fread(&x2,sizeof(x2),1,f2);
		curpos=ftell(f2)-sizeof(x2);
		fseek(f2,curpos,0);
		if(atoi(x1.Maso)<=atoi(x2.Maso))
		{
			copy(f1,f0);
			if(Eor)
				copyRun(f2,f0);
		}
		else
		{
			copy(f2,f0);
			if(Eor)
				copyRun(f1,f0);
		}
	}
	while(!Eor);
}
void tron()
{
	while((!feof(f1)) && (!feof(f2)))
	{
		tronRun();
		m++;
	}
	while(!feof(f1))
	{
		copyRun(f1,f0);
		m++;
	}
	while(!feof(f2))
	{
		copyRun(f2,f0);
		m++;
	}
	fclose(f0);
	fclose(f1);
	fclose(f2);
}
void sort(char *FileName)
{
	
	
		f0=fopen("e:\\SinhVien.Dat","rb");
		f1=fopen("e:\\SinhVien1.Dat","wb");
		copyRun(f0,f1);
		if(feof(f0))
		{
			printf("\n Danh sach da co thu tu");
			fclose(f0);
			fclose(f1);
		}
		else
		{
			do
			{
				f0=fopen("e:\\SinhVien.Dat","rb");
				f1=fopen("e:\\SinhVien1.Dat","wb");
				f2=fopen("e:\\SinhVien2.Dat","wb");
				phanbo();
				f0=fopen("e:\\SinhVien.Dat","wb");
				f1=fopen("e:\\SinhVien1.Dat","rb");
				f2=fopen("e:\\SinhVien2.Dat","rb");
				m=0;
				tron();
			}
			while(m!=1);
			printf("\n Da sap xep xong danh sach");
			remove("e:\\SinhVien1.Dat");
			remove("e:\\SinhVien2.Dat");	
		}
	printf("\nBam phim bat ky de tiep tuc!!!\n");	
}
int main()
{
	int c;
	for (;;)
	{
		printf("1. Nhap DSSV\n"); 
		printf("2. In DSSV\n"); 
		printf("3. Tim kiem\n");
		printf("4. Xoa sinh vien\n");
		printf("5. Sap Xep\n");
		printf("6. Thoat\n");
		printf("Ban chon 1, 2, 3, 4, 5, 6:"); 
		scanf("%d",&c);
		if(c==1)
			WriteFile((char*)"e:\\SinhVien.Dat");
		else
			if (c==2)
				ReadFile((char*)"e:\\SinhVien.Dat");
		else 
			if (c==3) 
				Search((char*)"e:\\SinhVien.Dat");
		else 
			if(c==4)
				Delete((char*)"e:\\SinhVien.Dat");
		else
			if(c==5)
				sort((char*)"e:\\SinhVien.Dat");
		else
			break;
	}
	
	return 0;
}

?ng d?ng ng?n x?p ?? tính t? h?p
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

