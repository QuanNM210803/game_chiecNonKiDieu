#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>// random
#include<string.h>
#include"danhmuc.h"//khai bao cac prototypes cua cac ham

int chonTu(char *tuDuocChon,char *cauHoiBiMat,char *yNghia)//ham chon tu ngau nhien tu tep tin danhmuctubimat.txt
{
	FILE *f=NULL;
	int soTTTu=0,soThuTuDuocChon=0;
	int luuKiTu;//bien nay de kieu int vi ham fgetc tra ve gia tri cua mot so nguyen
	f=fopen("danhmuctubimat.txt","r");//tep danhmuc.txt duoc tao tu trc va mo ra de doc
	if(f!=NULL)
	{
		do
		{
			luuKiTu=fgetc(f);//lenh doc tung ki tu 1 trong tep danhmuc.txt va luu vao bien luuKiTu
			if(luuKiTu=='\n')//neu doc den ki tu xuong dong thi sothututu tang(soTTTu)
			soTTTu++;
		}while(luuKiTu!=EOF);//dieu kien vong lap la tep ko bi loi va doc het tep
		// tim soThuTuDuocChon(vidu co 4 tu thi soThuTuDuocChon nam trong khoang tu 0 den 3)
		soThuTuDuocChon=chonNgauNhien(soTTTu);
		cauhoi(cauHoiBiMat,soThuTuDuocChon);//truyen vao ham cau hoi stt cua tu dc chon nham chon dc cau hoi tuong ung
		giaithichtubimat(yNghia,soThuTuDuocChon);
		rewind(f);//dua con tro ve dau tep tin danhmuc.txt
		while(soThuTuDuocChon>0)
		{
			luuKiTu=fgetc(f);//lenh doc tung ki tu 1 trong tep danhmuc.txt va luu vao bien luuKiTu
			if(luuKiTu=='\n')//neu doc den ki tu xuong dong thi soThuTuDuocChon giam
			soThuTuDuocChon--;
		}
		/*ham fgets doc ki tu va dung lai khi va chi khi 1 trong cac dieu kien sau
		  1.doc duoc n-1 ki tu
		  2. ki tu newline(xuong dong) duoc doc
		  3.gap end of file(EOF)*/
		fgets(tuDuocChon,50,f);//doc va luu tu bi mat vao chuoi tuDuocChon(toi da 49 ki tu do ki tu cuoi la NULL)
		tuDuocChon[strlen(tuDuocChon)-1]='\0';//do ki tu cuoi la xuong dong nen phai chuyen ki tu do thanh ki tu \0
		fclose(f);//dong tep tin
	}
	return 1;// tra ve gia tri dung=1(true)
}

//ham chon ngau nhien tubimat
int chonNgauNhien(int soTTTu)
{
	srand(time(NULL));//muon dung lenh rand thi phai dung lenh nay
	return (rand()%soTTTu);//chon ngau nhien so tu 0 den (soTTTu-1)
}

//ham tim cau hoi ung voi cau tra loi
int cauhoi(char *cauhoibimat,int soThuTuDuocChon)
{
	FILE *f=NULL;
	int luuKiTu;
	f=fopen("danhmuccauhoi.txt","r");
	if(f!=NULL)
	{
	while(soThuTuDuocChon>0)
	{
		luuKiTu=fgetc(f);
		if(luuKiTu=='\n')
		soThuTuDuocChon--;
	}
	fgets(cauhoibimat,100,f);
	cauhoibimat[strlen(cauhoibimat)-1]='\0';
	fclose(f);
	}
	return 1;
}

//ham giai thich y nghia tu bi mat
int giaithichtubimat(char *ynghia,int soThuTuDuocChon)
{
	FILE *f=NULL;
	int luuKiTu;
	f=fopen("giaithichtubimat.txt","r");
	if(f!=NULL)
	{
	while(soThuTuDuocChon>0)
	{
		luuKiTu=fgetc(f);
		if(luuKiTu=='\n')
		soThuTuDuocChon--;
	}
	fgets(ynghia,300,f);
	ynghia[strlen(ynghia)-1]='\0';
	fclose(f);
	}
	return 1;
}

//ham tong
int hamxuli()
{
	char kiTu=0;//ki tu don le ma nguoi choi nhap vao
	char tuBiMat[50];//tu bi mat cua chuong trinh
	int i,doDaiTu=0;//do dai tu bi mat
	int soLuotDoan=10;//so luot doan cua nguoi choi
	int *soKiTuBiMat;//mang co chua cac dang bolean(true/fales).neu dung tra ve 1, sai tra ve 0
	char *cumTu;
	char cauHoiBiMat[100];//bien chua cau hoi bi mat
	char yNghia[300];
	
	    //neu chon tu,chon cau hoi ko thanh cong,lap tuc thoat chuong trinh
	if(!chonTu(tuBiMat,cauHoiBiMat,yNghia))
		{
			exit(0);
		}
		doDaiTu=strlen(tuBiMat);//dem do dai tu bi mat
		printf("\nCAU HOI:%s",cauHoiBiMat);
		printf("\nDay la mot cum tu co %d ki tu.",doDaiTu);
		soKiTuBiMat=malloc(doDaiTu*sizeof(int));//cap phat bo nho cho mang soKiTuBiMat
	if(soKiTuBiMat==NULL)//neu cap phat ko thanh cong thi lap tuc dung chuong trinh
		{
			exit(0);
		}
		//gan mang soKiTuBiMat=0(false)
	for(i=0;i<doDaiTu;i++)
		{
				soKiTuBiMat[i]=0;
		}
		/*tro choi se tiep tuc neu so luot doan>0 va khong danh chien thang*/
		while(soLuotDoan>0 && !win(soKiTuBiMat,doDaiTu))
		{
			printf("\nban co %d luot doan.\n",soLuotDoan);
			printf("tu bi mat la gi?    ");
			for(i=0;i<doDaiTu;i++)
			{
				/*neu doan dung thi in ra ki tu doan dung neu sai thi in ra ki tu * */
				if(soKiTuBiMat[i])
					printf("%c",tuBiMat[i]);
				else
					printf("*");
			}
			printf("\nxin moi ban doan 1 tu.   ");
			kiTu=dockitu();//goi ham de nguoi choi doc ki tu nhap vao
			//kiem tra xem ki tu co trong tu bi mat ko. neu ko co thi so luot doan giam
			if(kiTu=='3')//neu nhap vao ki tu 3, thi se cho phep nguoi choi dua ra dap an cuoi cung luon
			{
				cumTu=malloc(sizeof(char)*doDaiTu);//cap phat bo nho cho mang cumTu
				printf("Dap an cuoi cung cua ban la gi?(hay can nhac voi dap an cua minh, co 10 nguoi dang doi bi TREO CO do)  ");
				doccumtu(doDaiTu,cumTu);//ham nay giup truyen cau tra loi cua nguoi choi vao bien cumTu
				kiemtracumtu(doDaiTu,cumTu,tuBiMat,soKiTuBiMat);//ktra cumTu dung ko va tra ve cac gia tri 0 or 1 vao bien soKiTuBiMat
				free(cumTu);//giai phong bo nho
				break;//thoat ra khoi vong lap luon
			}
			else //neu ki tu nhap vao ko phai la '3'
			{
			if(!kiemtrakitu(soKiTuBiMat,kiTu,tuBiMat))
			{
				printf("                *\n");
	  			printf("                *\n");
	  			printf("                *\n");
	  			printf("                *\n");
	  			printf("                *   *  *\n");
	  			printf("                * *     *\n");
	  			printf("                *       *\n");
	  			printf("                *     *\n");
	  			printf("                *  *\n");
	  			printf("                *                  OH NO, DA CO NGUOI BI TREO CO,\n");
	  			printf("             * *                   BAN NEN CAN NHAC O LUA CHON TIEP THEO,HIHI!!!\n");
	  			printf("          *   *  *\n");
	  			printf("        *    *     *\n");
	  			printf("            *       *\n");
	  			printf("           *\n");
	  			printf("         *   *\n");
	  			printf("        *     *\n");
	  			printf("       *       *\n");
	  			printf("      *         *\n");
				soLuotDoan--;
			}
			else
			{
				printf("\nki tu %c, la mot dap an chinh xac.Xin chuc mung!!!",kiTu);
			}
			}
		}
	if(win(soKiTuBiMat,doDaiTu))//neu chien thang 
		{
			printf("\n\nxin chuc mung ban da chien thang!!!\n");
			printf("tu bi mat la:%s",tuBiMat);
		}
	else//nguoc lai neu thua
		{
			printf("\n\nno no no, ban da that bai hihi !!!");
			printf("\ncum tu kho dung khong nao??? hmmmm");
			printf("\ntu bi mat la:%s",tuBiMat);
		}
		printf("\nCO THE BAN CHUA BIET:%s",yNghia);
	free(soKiTuBiMat);//giai phong bo nho cho mang soKiTuBiMat
	
	int tieptuc;
	int danhgia;
	FILE *danhGia;//bien file danh gia
	int danhgiachuongtrinh[6]={0,0,0,0,0,0};//so luot danh gia ung voi tung sao
	
	danhGia=fopen("danhgiachuongtrinh","r");//mo file de doc
	fread(danhgiachuongtrinh,sizeof(int)*6,1,danhGia);//truyen bien danhgiachuongtrinh vao file danhgiachuongtrinh

    printf("\n\nBan co muon choi lai khong?(1.yes/2.no)   ");
    scanf("%d",&tieptuc);
    while(getchar()!='\n');
    switch(tieptuc)
    {
    	case 1:
    		hamxuli();
    		break;
    	case 2:
    		printf("\n\nCam on ban da tham gia chuong trinh,hehe!!!");
    		printf("\nBan danh gia sao ve chuong trinh nay?(tu 1 den 5 sao)   ");
    		scanf("%d",&danhgia);
    		while(getchar()!='\n');
    		switch(danhgia)
    		{
    			case 1:
    				danhgiachuongtrinh[0]++;//neu chon 1 thi cong them 1 danh gia
    				printf("\n*(kem)\n");
    				printf("oh nooo, chung toi se co gang thay doi de game hap dan hon.xin cam on ban!!!");
    				break;
    			case 2:
    				danhgiachuongtrinh[1]++;//neu chon 2 thi cong them 1 danh gia
    				printf("\n* *(khong tot)\n");
    				printf("oh nooo, chung toi se co gang thay doi de game hap dan hon.xin cam on ban!!!");
    				break;
    			case 3:
    				danhgiachuongtrinh[2]++;//neu chon 3 thi cong them 1 danh gia
    				printf("\n* * *(kha tot)\n");
    				printf("xin cam on ban!!!");
    				break;
    			case 4:
    				danhgiachuongtrinh[3]++;//neu chon 4 thi cong them 1 danh gia
    				printf("\n* * * *(tot)\n");
    				printf("xin cam on ban!!! toi rat vui do=)))))");
    				break;
    			case 5:
    				danhgiachuongtrinh[4]++;//neu chon 5 thi cong them 1 danh gia
    				printf("\n* * * * *(rat tot)\n");
    				printf("waoooo, xin cam on ban!!! toi rat vui do=)))))");
    				break;
			}
			danhgiachuongtrinh[5]++;
			printf("\nSo luot binh chon(%d):\n",danhgiachuongtrinh[5]);
			for(i=0;i<5;i++)
			{
				printf("%d sao:%d\n",i+1,danhgiachuongtrinh[i]);//in ra so luot danh gia
			}
			fclose(danhGia);//dong file
			danhGia=fopen("danhgiachuongtrinh","w");//mo file de ghi
			fwrite(danhgiachuongtrinh,sizeof(int)*6,1,danhGia);//ghi lai so luot danh gia ma nguoi choi vua danh gia
			fclose(danhGia);//dong file
    		break;
	}
	return 0;
}
	
void main()//ham co nhiem vu dan chuong trinh
{
	int luaChon;
	int sansang;
	
	printf("Chao mung ban den voi tro choi Nguoi Treo Co!!!\n");
	printf("\nBan da san sang choi chua?");
	printf("\n1.Toi da san sang.");
	printf("\n2.Huong dan.\n");
	printf("Lua chon cua ban la???  ");
	scanf("%d",&luaChon);
	while(getchar()!='\n');
	switch(luaChon)
	{
	case 1:
		hamxuli();
		break;
	case 2:
		printf("\nChuong trinh se dua ra 1 tu hoac 1 cum tu bi mat(neu la cum tu thi ko chua dau cach) duoc an boi cac dau sao(*).\n");
		printf("Nhiem vu cua nguoi choi la doan tung ki tu trong tu(cum tu) do.\n");
		printf("Ban co 10 luot doan. Moi lan doan sai so luot doan se bi tru di va SE CO NGUOI BI TREO CO, doan dung se khong bi tru.\n");
		printf("Nguoi choi chien thang khi tim duoc chinh xac tu(cum tu).\n");
		printf("LUU Y:neu nguoi choi muon tra loi dap an cuoi cung khi chua mo het cac ki tu thi NHAN PHIM '3'\n");
		printf("1.Ban san sang den voi thu thach nay chu???  ");
		scanf("%d",&sansang);
		while(getchar()!='\n');
		switch(sansang)
		case 1:
			hamxuli();
			break;
	break;
    }
}

//ham su dung cho phep nguoi choi tra  loi dap an cuoi cung
char doccumtu(int doDaiTu,char *cumTu)
{
	int i=0;
	char *cumtunhapvao;
	gets(cumtunhapvao);
	for(i=0;i<doDaiTu;i++)
	{
		if(*(cumtunhapvao+i)<=122 && *(cumtunhapvao+i)>=97)//chuyen chu thuong thanh chu hoa
		{
		*(cumtunhapvao+i)-=32;
		}
		*(cumTu+i)=*(cumtunhapvao+i);//gan ki tu trong cumtunhapvao cho cumTu
	}
	return 0;
}

//ham kiem tra cum tu danh cho nguoi choi tra loi dap an cuoi cung luon
int kiemtracumtu(int doDaiTu,char *cumTu,char tuBiMat[],int soKiTuBiMat[])
{
	int i=0;
	for(i=0;i<doDaiTu;i++)
	{
		if(*(cumTu+i)==tuBiMat[i])
		soKiTuBiMat[i]=1;//neu tung ki tu khop voi tuBiMat thi soKiTuBiMat[i]=1
	}
	return 0;
}

//ham doc ki tu nhap vao cua nguoi choi
char dockitu()
{
	char kiTuNhapVao;
	kiTuNhapVao=getchar();//doc ki tu dau tien duoc nhap vao tu ban phim
	kiTuNhapVao=thuongsanghoa(kiTuNhapVao);//dung ham de chuyen sang ki tu hoa
	while(getchar()!='\n');/*lan luot doc cac ki tu tiep theo.neu chua gap ki tu \n thi ko the thoat ra khoi vong lap.
	chuong trinh chi co the tiep tuc neu gap ki tu \n*/
	return kiTuNhapVao;//tra ve ki tu nhap vao cho bien kiTu trong ham main
}

// ham chuyen chu thuong sang chu hoa
char thuongsanghoa(char kiTuThuong)
{
	if(kiTuThuong<=122 && kiTuThuong>=97)
	{
	kiTuThuong-=32;
	}
	return kiTuThuong;
}

//ham dieu kien chien thang
int win(int soKiTuBiMat[],int doDaiTu)
{
	//nhac lai kieu bolean. gia tri 1 la true, 0 la false
	int i;
	int nguoichoichienthang=1;
	for(i=0;i<doDaiTu;i++)
	{
		if(soKiTuBiMat[i]==0)//tro choi chien thang khi mang soKiTuBiMat deu co gia tri=1
		/* neu chi can soKiTuBiMat[i] nao do bang 0 thi nguoichoichienthang=0 va khi do ham win tra ve
		gia tri 0, tuc la false(chua chien thang)*/
		{
			nguoichoichienthang=0;
		}
	}
	return  nguoichoichienthang;//tra ve xem nguoi choi thang hay thua
}

//ham kiemtrakitu xem co ki tu nao trung voi ki tu nhap vao khong
int kiemtrakitu(int soKiTuBiMat[],char kiTu,char tuBiMat[])
{
	int i;
	int kiTuChinhXac=0;//ban dau gan=0(false)
	for(i=0;tuBiMat[i]!='\0';i++)
	{
		if(kiTu==tuBiMat[i])//neu ki tu doan dung
		{
			kiTuChinhXac=1;//thi gan=1(true)
			soKiTuBiMat[i]=1;//thi gan=1(true)
		}
	}
	return kiTuChinhXac;//tra ve xem ki tu nguoi choi vua doan dung hay sai
}






