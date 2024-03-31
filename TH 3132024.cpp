#include <stdio.h>
#include <conio.h>
#include <stdio.h>

int n;
void nhapmang(int a[], int n)
{
	for(int i = 0; i<n; i++)
	{
		printf("\na[%d]= ", i);
		scanf("%d", &a[i]);
	}
}

void xuatmang(int a[], int n)
{
	for(int i =0; i<n; i++)
	{
		printf("\na[%d]= %d", i, a[i]);
	}
}

int timkiemtt(int a[], int b[], int x, int n)
{
	int dem=0;
	for(int i = 0; i<n; i++)
	{
		if(x==a[i])
		{
			b[dem]=i;
			dem++;
		}
	}
	if(dem==0)
	{
		return 0;
	}
	printf("\n%d da xuat hien %d lan", x, dem);
	printf("\no vi tri:");
	for(int i=0; i<dem; i++)
	{
		printf("%d", b[i]);
	}
}

int main()
{
	int n;
	int a[100];
	printf("Nhap so luong phan tu co trong mang: ");
	scanf("%d", &n);
	nhapmang(a,n);
	xuatmang(a,n);
	timkiemtt(a,n,dem,b)
}
