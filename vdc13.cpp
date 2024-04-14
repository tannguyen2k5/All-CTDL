#include<stdio.h>
#include<conio.h>
#include<string.h>
typedef struct
{
char Ma[10];
char HoTen[40];
} SinhVien;
void WriteFile(char *FileName)
{
FILE *f;
int n,i;
SinhVien sv;
f=fopen(FileName,"ab");
printf("Nhap bao nhieu sinh vien? ");scanf("%d",&n);
fflush(stdin);
for(i=1;i<=n;i++)
{
printf("Sinh vien thu %i\n",i);
printf("- MSSV: ");gets(sv.Ma);
printf("- Ho ten: ");gets(sv.HoTen);
fwrite(&sv,sizeof(sv),1,f);
fflush(stdin);
}
fclose(f);
printf("Bam phim bat ky de tiep tuc");
getch();
}
void ReadFile(char *FileName)
{
FILE *f; SinhVien sv; f=fopen(FileName,"rb");
printf("MSSV | Ho va ten\n");
fread(&sv,sizeof(sv),1,f);
while (!feof(f))
{
printf("%s | %s\n",sv.Ma,sv.HoTen);
fread(&sv,sizeof(sv),1,f);
}
fclose(f);
printf("Bam phim bat ky de tiep tuc!!!");
getch();
}
void Search(char *FileName)
{
char MSSV[10]; FILE *f;
int Found=0; SinhVien sv;
fflush(stdin);
printf("Ma so sinh vien can tim: ");gets(MSSV);
f=fopen(FileName,"rb");
while (!feof(f) && Found==0)
{
fread(&sv,sizeof(sv),1,f);
if (strcmp(sv.Ma,MSSV)==0) Found=1;
}
fclose(f);
if (Found == 1)
printf("Tim thay SV co ma %s. Ho ten la: %s",sv.Ma,sv.HoTen);
else
printf("Tim khong thay sinh vien co ma %s",MSSV);
printf("\nBam phim bat ky de tiep tuc!!!");
getch();
}
int main()
{
int c;
for (;;)
{
printf("1. Nhap DSSV\n");
printf("2. In DSSV\n");
printf("3. Tim kiem\n");
printf("4. Thoat\n");
printf("Ban chon 1, 2, 3, 4: "); scanf("%d",&c);
if(c==1)
WriteFile("d:\\SinhVien.Dat");
else if (c==2)
ReadFile("d:\\SinhVien.Dat");
else if (c==3) Search("d:\\SinhVien.Dat");
else break;
}
return 0;
}
