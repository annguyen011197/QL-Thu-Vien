// QLThuVien.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "Nhap.h"
#include "Xuat.h"
#include "Xuli.h"
#include <cstdlib>

int _tmain(int argc, _TCHAR* argv[])
{
	char ten[1000][40], ten_ID[1000][9], ten_cm[1000][40], dc[1000][200], ten_e[1000][40];
	char sach[1000][40], sach_ID[1000][9], sach_ten[1000][40], sach_xb[1000][200], sach_tl[1000][40];
	int ten_ns[1000][3], ten_gt[1000], ten_nl[1000][3], ten_nh[1000][3], the[1000][10], ngaymuon[1000][3], ngaytradk[1000][3];
	int sach_nxb[1000], sach_gia[1000], sach_sq[1000], thet[1000][10], ngaytrat[1000][3];
	char n;
	int dem = 0, dem_s = 0, demt = 0, demtt = 0, ID = 0, demsm = 0, demm = 0, sID = 0;
	fflush(stdin);
	do{
		system("cls");
		menu();
		char c, e;
		int k;
		k = chonmuc(c);
		switch (k)
		{
		case 1:
		{
				  thuchien1(ten_e, ten, ten_ID, ten_cm, dc, ten_ns, ten_gt, ten_nl, ten_nh, dem, c, ID);
				  break;
		}
		case 2:
		{
				  thuchien2(sach_tl, sach, sach_ID, sach_ten, sach_xb, sach_nxb, sach_gia, sach_sq, dem_s, c, sID);
				  break;
		}
		case 3:
		{
				  thuchien3(ten, ten_ID, sach, sach_ID, the, ngaymuon, ngaytradk, dem, ten_cm, demt, sach_sq, ten_nh, ten_nl);
				  break;
		}
		case 4:
		{
				  thuchien4(ten_ID, sach_ID, the, thet, ngaymuon, ngaytradk, dem, demt, sach_sq, demtt, ngaytrat, sach_gia, demm);
				  break;
		}
		case 5:
		{
				  thuchien5(dem, demt, demtt, dem_s, the, sach_tl, c, ten_gt, demm);
		}
		}
		printf("Nhap E de thoat chuong trinh-Nhap phim bat ki de tiep tuc: ");
		fflush(stdin);
		scanf("%c", &n);
	} while (n != 'E');
	return 0;
}



