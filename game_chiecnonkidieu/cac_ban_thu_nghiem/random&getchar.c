//#include <stdio.h>
//#include <stdlib.h>
//#include<time.h>
//void main()
//{
//	int i;
//	srand(time(NULL));// ko hieu y nghia lam nhung hau nhu co dinh
//	for(i=0;i<10;i++)
//	{
//		printf("%d\n",rand()%100);//so chon tu 0 den 99
//	}
//	getch();
//}

#include <stdio.h>//getchar(nhan ki tu dau tien nhap vao)

int main ()
{
   char c;
	int n;
   printf("Nhap ky tu: ");
   scanf("%d",&n);
   c = getchar();

   printf("Ky tu vua nhap: ");
   printf("%c",c);

   return(0);
}

//#include<stdio.h>//chuong trinh goi tra tri tu 1 file roi cong gia tri do voi 1 roi lai luu tro lai vao file do
//#include<conio.h>
//void main()
//{
//	FILE *f;
//	int danhgia,i2[2]={0,0},i,j;
//	
//	for(j=0;j<6;j++)
//	{
//	printf("\ndanh gia:");
//	scanf("%d",&danhgia);
//	f=fopen("danhgiathunghiem.txt","r");
//	fread(i2,sizeof(int)*2,1,f);
//	switch(danhgia)
//	{
//		case 4:
//			i2[0]++;
//			break;
//		case 5:
//			i2[1]++;
//			break;
//	}
//	for(i=0;i<2;i++)
//	{
//		printf("%d  ",i2[i]);
//	}
//	fclose(f);
//	
//	fopen("danhgiathunghiem.txt","w");
//	fwrite(i2,sizeof(int)*2,1,f);
//	fclose(f);
//	}	
//	getch();
//}










