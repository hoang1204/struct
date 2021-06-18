#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct hocsinh
{
	char ten[30],diachi[30],gtinh[30],ngaysinh[30];
	int maso;
	float tb;
};
void nhap(hocsinh p[],int n)
{
	
	for (int i=0;i<n;i++)
		{
			printf("Nhap thong tin hoc sinh thu %d",i+1);
			printf("\nMa hoc sinh: "); fflush(stdin);
			scanf("%d",&p[i].maso);
			printf("\nHo va ten: ");fflush(stdin);
			gets(p[i].ten);
			printf("\nNgay thang nam sinh: ");fflush(stdin);
			gets(p[i].ngaysinh);
			printf("\nDia chi: ");fflush(stdin);
			gets(p[i].diachi);
			printf("\nGioi tinh: ");fflush(stdin);
			gets(p[i].gtinh);
			printf("\nDiem trung binh: ");fflush(stdin);
			scanf("%f",&p[i].tb);
		}
}
void xuatfile(hocsinh p[],int n)
{
	FILE *f=fopen("hocsinh.txt","w");
	if (f==NULL)
	{
		printf("ERROR");
		exit(1);
	}
	fprintf(f,"\n_____________DANH SACH HOC SINH________________");
	fprintf(f,"\n%-20s%-20s%-20s%-20s%-20s%-20s","Ma hoc sinh","Ho va ten","Ngay sinh","Dia chi","Gioi tinh","Diem trung binh");
	for(int i=0;i<n;i++)
	{
		fprintf(f,"\n%-20d%-20s%-20s%-20s%-20s%-20.2f",p[i].maso,p[i].ten,p[i].ngaysinh,p[i].diachi,p[i].gtinh,p[i].tb);
	}
}
void tb(hocsinh p[],int n)
{
	int max=p[0].tb;int vt=0;
	for (int i=1;i<n;i++)
	{
		if (max<p[i].tb)
		{
			max=p[i].tb;
			vt=i;
		}
	}
	printf("\n_____________HOC SINH DIEM CAO NHAT________________");
	printf("\n%-20s%-20s%-20s%-20s%-20s%-20s","Ma hoc sinh","Ho va ten","Ngay sinh","Dia chi","Gioi tinh","Diem trung binh");
	printf("\n%-20d%-20s%-20s%-20s%-20s%-20.2f",p[vt].maso,p[vt].ten,p[vt].ngaysinh,p[vt].diachi,p[vt].gtinh,p[vt].tb);
}
int main()
{
	struct hocsinh p[100];
	int n;
	do
	{
		printf("\nNhap so hoc sinh: ");
		scanf("%d",&n);
		if (n<=0) printf("\nNhap sai");
	}while(n<=0);
	nhap(p,n);
	xuatfile(p,n);
	tb(p,n);
}
