#include <stdio.h>
#include <conio.h>


void ghivaofile(char *tenfile)
{
	FILE *fp = fopen(tenfile, "w");
	if(fp == NULL)
	{
		printf("ko the mo file %s.\n", tenfile);
		return;
	}
	
	char line[256];
	printf("\nNhap noi dung muon ghi: ");
	while (fgets(line, sizeof(line), stdin) != NULL)
	{
		fprintf(fp, "%s", line);
	}
	
	fclose(fp);
	printf("\nGhi file thanh cong!");
}

void docvanoithem(char *tenfile)
{
	FILE *fp = fopen(tenfile, "r");
	if (fp == NULL)
	{
		printf("\nKo the mo file %s.", tenfile);
		return;
	}


char line[256];
while (fgets(line,sizeof(line), fp) != NULL)
{
	printf("%s", line);
}
	printf("Nhap noi dung muon noi them: ");
	char noidungmoi[256];
	fgets(noidungmoi,sizeof(noidungmoi), stdin);
	fprintf(fp, "%s", noidungmoi);
	fclose(fp);
	printf("Noi them thong tin thanh cong!\n");
}

int main()
{
	int luachon;
	char tenfile[256];
	
	while (1)
	{
		printf("\nMenu\n");
		printf("1. Ghi vao tep tin\n");
		printf("2. Doc va in tep tin\n");
		printf("3. Doc va in va noi them\n");
		printf("4. Thoat\n");
		printf("Nhap lua chon cua ban");
		printf("%d", &luachon);
	
	switch(luachon)
	{
		case 1:
			printf("Nhap ten file: ");
			scanf("%s", tenfile);
			ghivaofile(tenfile);
			break;
		case 2:
			printf("Nhap ten file:");
			scanf("%s", tenfile);
			docvanoithem(tenfile);
			break;
		case 3:
			printf("Nhap ten tep tin: ");
			scanf("%s", tenfile);
			docvanoithem(tenfile);
			break;
		case 4:
			exit(0);
		default:
		printf("Lua chon sai. Vui long chon lai!\n");	
	}
}
return 0;
}

