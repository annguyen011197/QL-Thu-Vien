#include "stdafx.h"
#include "Xuat.h"
#include "Xuli.h"
#include "Nhap.h"
#include <string>

void xuatten(char a[][40], int dem){
	for (int i = 0; i < dem; i++) {
		printf("%d	", i);
		puts(a[i]);
		printf("\n");
	}
}
void Ten_ID(char a[][9], int dem, int q)
{
	fflush(stdin);
	char b[4] = "NID";
	int k = dem;
	strcpy(a[q], b);
	for (int i = 7; i>2; i--)
	{
		a[q][i] = inttochar(k % 10);
		k = k / 10;
	}
	a[q][8] = '\0';
	puts(a[q]);
}
void S_ID(char a[][9], int dem, int q){
	fflush(stdin);
	char b[4] = "SID";
	int k = dem;
	strcpy(a[q], b);
	for (int i = 7; i>2; i--)
	{
		a[q][i] = inttochar(k % 10);
		k = k / 10;
	}
	a[q][8] = '\0';
	puts(a[q]);
}
void menu()
{
	printf("		QUAN LI THU VIEN\n");
	printf("Chuc nang:\n");
	printf("	1a-Xem danh sach doc gia\n");
	printf("	 b-Them doc gia\n");
	printf("	 c-Chinh sua thong tin doc gia\n");
	printf("	 d-Xoa thong tin doc gia\n");
	printf("	 e-Tim kiem doc gia theo CMND\n");
	printf("	 f-Tim kiem theo ten\n");
	printf("	2a-Xem danh sach cac sach trong thu vien\n");
	printf("	 b-Them sach\n");
	printf("	 c-Chinh sua thong tin 1 quyen sach\n");
	printf("	 d-Xoa thong tin sach\n");
	printf("	 e-Tim kiem sach theo ISBN(Ma sach)\n");
	printf("	 f-Tim kiem theo ten\n");
	printf("	3-Lap phieu muon sach\n");
	printf("	4-Lap phieu tra sach\n");
	printf("	5a-Thong le so luong sach trong thu vien\n");
	printf("	 b-Thong ke so luong sach theo the loai\n");
	printf("	 c-Thong ke so luong doc gia\n");
	printf("	 d-Thong ke so luong doc gia theo gioi tinh\n");
	printf("	 e-Thong ke so sach dang duoc muon\n");
	printf("	 f-Thong ke so doc gia bi tre hen\n");
}
int chonmuc(char &c)
{
	int k;
	do {
		printf("Nhap muc chuc nang(1->5): ");
		scanf_s("%d", &k);
		if (k != 3 && k != 4) {
			choncn(c);
		}
	} while (k < 1 || k>5);
	return k;
}
char choncn(char &c)
{
	do {
		printf("Nhap chuc nang (a->f):");
		fflush(stdin);
		scanf_s("%c", &c);
	} while (c<'a' || c>'f');
	return c;
}
void xuattc(char sach_tl[][40], char sach[][40], char sach_ID[][9], char sach_ten[][40], char sach_xb[][200], int sach_nxb[], int sach_gia[], int sach_sq[], int i)
{
	printf("Ten sach:");
	puts(sach[i]);
	printf("Ma sach:");
	puts(sach_ID[i]);
	printf("Ten tac gia:");
	puts(sach_ten[i]);
	printf("Ten nha xuat ban:");
	puts(sach_xb[i]);
	printf("Nam xuat ban %d\n", sach_nxb[i]);
	printf("Gia sach: %d\n", sach_gia[i]);
	printf("So quyen: %d\n", sach_sq[i]);
}
void xuattt(char ten_e[][40], char ten[][40], char ten_ID[][9], char ten_cm[][40], char dc[][200], int ten_ns[][3], int ten_gt[], int ten_nl[][3], int ten_nh[][3], int i)
{
	printf("Ten:");
	puts(ten[i]);
	printf("ID:");
	puts(ten_ID[i]);
	printf("\nNgay sinh: %d/%d/%d", ten_ns[i][0], ten_ns[i][1], ten_ns[i][2]);
	printf("\nCMND:");
	puts(ten_cm[i]);
	if (ten_gt[i] == 0) {
		printf("Gioi tinh: Nu");
	}
	else {
		printf("Gioi tinh: Nam");
	}
	printf("\nNgay lam the: %d/%d/%d\n", ten_nl[i][0], ten_nl[i][1], ten_nl[i][2]);
	printf("\nNgay het han: %d/%d/%d\n", ten_nh[i][0], ten_nh[i][1], ten_nh[i][2]);
}
void thuchien1(char ten_e[][40], char ten[][40], char ten_ID[][9], char ten_cm[][40], char dc[][200], int ten_ns[][3], int ten_gt[], int ten_nl[][3], int ten_nh[][3], int &dem, char c, int &ID)
{
	switch (c)
	{
	case 'a':
	{
				if (dem > 0){
					for (int i = 0; i < dem; i++){
						fflush(stdin);
						puts(ten_ID[i]);
						printf("	");
						puts(ten[i]);
						printf("\n");
					}
				}
				else {
					printf("\nHien khong co doc gia nao ca\n\n");
				}
				break;
	}
	case 'b':
	{
				char p;
				do {
					printf("Nhap ten: ");
					nhapten(ten, dem);
					printf("Ma doc gia: ");
					Ten_ID(ten_ID, ID, dem - 1);
					printf("\nNhap ngay thang nam sinh: \n");
					nhapngaythang(ten_ns, dem - 1);
					nhapgt(ten_gt, dem - 1);
					nhapcm(ten_cm, dem - 1);
					nhapdc(dc, dem - 1);
					printf("Nhap e-mail: ");
					nhape(ten_e, dem - 1);
					printf("\nNhap ngay lam the: \n");
					do{
						nhapngaythang(ten_nl, dem - 1);
						if (demngay(ten_ns, dem - 1) > demngay(ten_nl, dem - 1)) {
							printf("\nNGAY THANG NAM SAI\n\n");
						}
					} while (demngay(ten_ns, dem - 1) > demngay(ten_nl, dem - 1));
					ngayhet(ten_nl, dem - 1, ten_nh);
					printf("\n The het han vao ngay:%d/%d/%d\n", ten_nh[dem - 1][0], ten_nh[dem - 1][1], ten_nh[dem - 1][2]);
					ID = dem;
					printf("Bam ENTER de nhap tiep");
					fflush(stdin);
					scanf("%c", &p);
				} while (p == '\n');
				break;
	}
	case 'c':
	{
				char ID[9], m;
				printf("Nhap ma doc gia can chinh sua thong tin\n Ma doc gia co dang NIDxxxxx voi xxxxx la so thu tu cua doc gia\n Nhap ma: ");
				fflush(stdin);
				gets(ID);
				if (timID(ten_ID, ID, dem) == -1) {
					printf("Khong co ma doc gia nay\n");
				}
				else {
					int k = timID(ten_ID, ID, dem);
					xuattt(ten_e, ten, ten_ID, ten_cm, dc, ten_ns, ten_gt, ten_nl, ten_nh, timID(ten_ID, ID, dem));
					printf("Ban co muon chinh sua thong tin doc gia nay-Nhap y de thuc hien: ");
					fflush(stdin);
					scanf("%c", &m);
					if (m == 'y') {
						printf("Nhap ten: ");
						nhapten(ten, k);
						printf("\nNhap ngay thang nam sinh: \n");
						nhapngaythang(ten_ns, k - 1);
						nhapgt(ten_gt, k - 1);
						nhapcm(ten_cm, k - 1);
						nhapdc(dc, k - 1);
						printf("Nhap e-mail: ");
						nhape(ten_e, k - 1);
						printf("\nNhap ngay lam the: \n");
						nhapngaythang(ten_nl, k - 1);
						ngayhet(ten_nl, k - 1, ten_nh);
					}
					break;
				}
	}
	case 'd':
	{
				char ID[9], m;
				printf("Nhap ma doc gia can xoa thong tin\n Ma doc gia co dang NIDxxxxx voi xxxxx la so thu tu cua doc gia\n Nhap ma: ");
				fflush(stdin);
				gets(ID);
				if (timID(ten_ID, ID, dem) == -1) {
					printf("Khong co ma doc gia nay\n");
				}
				else {
					int k = timID(ten_ID, ID, dem);
					xuattt(ten_e, ten, ten_ID, ten_cm, dc, ten_ns, ten_gt, ten_nl, ten_nh, timID(ten_ID, ID, dem));
					printf("Ban co muon xoa thong tin doc gia nay-Nhap y de thuc hien: ");
					fflush(stdin);
					scanf("%c", &m);
					if (m == 'y') {
						xoa_ten(ten, k, dem);
						xoa_tenID(ten_ID, k, dem);
						xoa_tendc(dc, k, dem);
						xoa_ten(ten_cm, k, dem);
						xoa_tenns(ten_ns, k, dem);
						xoa_tenns(ten_nl, k, dem);
						xoa_tenns(ten_nh, k, dem);
						xoa_tengt(ten_gt, k, dem);
						dem = dem - 1;
					}
				}
				break;
	}
	case 'e':
	{
				char ID[9], m;
				printf("Nhap CMND can tim thong tin\n CMND gom 9 so \n Nhap : ");
				fflush(stdin);
				gets(ID);
				if (timID(ten_cm, ID, dem) == -1) {
					printf("Khong co doc gia nay\n");
				}
				else {
					int k = timID(ten_cm, ID, dem);
					xuattt(ten_e, ten, ten_ID, ten_cm, dc, ten_ns, ten_gt, ten_nl, ten_nh, timID(ten_cm, ID, dem));
				}
				break;
	}
	case 'f':
	{
				if (dem > 0){
					char ID[40], m;
					int i = -1, flag = 0;
					printf("Nhap ten can tim thong tin\n  \n Nhap : ");
					fflush(stdin);
					gets(ID);
					for (; i <= dem;){
						int k = timten(ten, ID, dem, i);
						if (k != -1) {
							xuattt(ten_e, ten, ten_ID, ten_cm, dc, ten_ns, ten_gt, ten_nl, ten_nh, k);
							flag++;
						}
						if (flag == dem){
							printf("Khong co ten nay");
						}
					}
				}
				else {
					printf("\nHien khong co doc gia nao ca\n\n");
				}
				break;
	}
	}
	void thuchien2(char sach_tl[][40], char sach[][40], char sach_ID[][9], char sach_ten[][40], char sach_xb[][200], int sach_nxb[], int sach_gia[], int sach_sq[], int &dem, char c, int &sID)
	{
		switch (c)
		{
		case 'a':
		{
					if (dem > 0){
						for (int i = 0; i < dem; i++){
							fflush(stdin);
							puts(sach_ID[i]);
							printf("	");
							puts(sach[i]);
							printf("\n");
						}
					}
					else {
						printf("\nHien khong co sach nao ca\n\n");
					}
					break;
		}
		case 'b':
		{
					char p;
					do {
						fflush(stdin);
						printf("Nhap ten sach: ");
						nhapten(sach, dem);
						printf("Ma sach: ");
						S_ID(sach_ID, sID, dem - 1);
						printf("Nhap ten tac gia: ");
						nhapmail(sach_ten, dem - 1);
						printf("Nhap ten nha xuat ban: ");
						nhapxb(sach_xb, dem - 1);
						printf("Nhap nam xuat ban:	");
						scanf("%d", &sach_nxb[dem - 1]);
						printf("Nhap the loai sach:	");
						nhapmail(sach_tl, dem - 1);
						printf("Nhap gia sach: ");
						scanf("%d", &sach_gia[dem - 1]);
						printf("Nhap so quyen : ");
						scanf("%d", &sach_sq[dem - 1]);
						sID = dem;
						printf("Bam ENTER de nhap tiep");
						fflush(stdin);
						scanf("%c", &p);
					} while (p == '\n');
					break;
		}
		case 'c':
		{
					char ID[9], m;
					printf("Nhap ma sach can chinh sua thong tin\n Ma sach co dang SIDxxxxx voi xxxxx la so thu tu cua sach\n Nhap ma: ");
					fflush(stdin);
					gets(ID);
					if (timID(sach_ID, ID, dem) == -1) {
						printf("\nKhong co ma sach nay\n\n");
					}
					else {
						int k = timID(sach_ID, ID, dem);
						xuattc(sach_tl, sach, sach_ID, sach_ten, sach_xb, sach_nxb, sach_gia, sach_sq, k);
						printf("Ban co muon chinh sua thong tin doc gia nay-Nhap y de thuc hien: ");
						fflush(stdin);
						scanf("%c", &m);
						if (m == 'y') {
							printf("Nhap ten sach: ");
							nhapten(sach, k);
							printf("Nhap ten tac gia: ");
							nhapmail(sach_ten, k - 1);
							printf("Nhap ten nha xuat ban: ");
							nhapxb(sach_xb, k - 1);
							printf("Nhap nam xuat ban:	");
							scanf("%d", &sach_nxb[k - 1]);
							printf("Nhap the loai sach:	");
							nhapmail(sach_tl, k - 1);
							printf("Nhap gia sach: ");
							scanf("%d", &sach_gia[k - 1]);
							printf("Nhap so quyen : ");
							scanf("%d", &sach_sq[k - 1]);
						}
					}
					break;
		}
		case 'd':
		{
					char ID[9], m;
					printf("Nhap ma sach can xoa thong tin\n Ma sach co dang SIDxxxxx voi xxxxx la so thu tu cua sach\n Nhap ma: ");
					fflush(stdin);
					gets(ID);
					if (timID(sach_ID, ID, dem) == -1) {
						printf("\nKhong co ma sach nay\n\n");
					}
					else {
						int k = timID(sach_ID, ID, dem);
						xuattc(sach_tl, sach, sach_ID, sach_ten, sach_xb, sach_nxb, sach_gia, sach_sq, k);
						printf("Ban co muon xoa thong tin doc gia nay-Nhap y de thuc hien: ");
						fflush(stdin);
						scanf("%c", &m);
						if (m == 'y') {
							xoa_ten(sach, k, dem);
							xoa_tenID(sach_ID, k, dem);
							xoa_ten(sach_tl, k, dem);
							xoa_ten(sach_ten, k, dem);
							xoa_tendc(sach_xb, k, dem);
							xoa_tengt(sach_nxb, k, dem);
							xoa_tengt(sach_gia, k, dem);
							xoa_tengt(sach_sq, k, dem);
						}
					}
					break;
		}
		case 'e':
		{
					char ID[9], m;
					printf("Nhap ma sach can xem thong tin\n Ma sach co dang SIDxxxxx voi xxxxx la so thu tu cua sach\n Nhap ma: ");
					fflush(stdin);
					gets(ID);
					if (timID(sach_ID, ID, dem) == -1) {
						printf("\nKhong co ma sach nay\n\n");
					}
					else {
						int k = timID(sach_ID, ID, dem);
						xuattc(sach_tl, sach, sach_ID, sach_ten, sach_xb, sach_nxb, sach_gia, sach_sq, k);
					}
					break;
		}
		case 'f':
					if (dem > 0){
						char ID[40], m;
						int i = -1, flag = 0;
						printf("Nhap ten can tim thong tin\n  \n Nhap : ");
						fflush(stdin);
						gets(ID);
						for (; i <= dem;){
							int k = timten(sach, ID, dem, i);
							if (k != -1) {
								xuattc(sach_tl, sach, sach_ID, sach_ten, sach_xb, sach_nxb, sach_gia, sach_sq, k);
								flag++;
							}
							if (flag == dem){
								printf("Khong co ten nay");
							}
						}
					}
					else {
						printf("\nHien khong co sach nao ca\n\n");
					}
					break;
		}
	}
	void thuchien3(char ten[][40], char ten_ID[][9], char sach[][40], char sach_ID[][9], int the[][10], int ngaymuon[][3], int ngaytradk[][3], int dem, char ten_cm[][40], int &demt, int sach_sq[], int ten_nh[][3], int ten_nl[][3])
	{
		if (dem > 0){
			char ID[9], m, tID[9];
			int i = -1, flag = 0;
			printf("Nhap ma doc gia can muon sach\n \n Nhap: ");
			fflush(stdin);
			gets(tID);
			int o = timID(ten_ID, tID, dem);
			if (o == -1){
				printf("Khong co doc gia\n");
			}
			else {
				the[demt][0] = o;
				printf("Nhap so quyen ");
				scanf("%d", &the[demt][1]);
				int u = 2, m = 0;
				for (int i = 1; i <= the[demt][1]; i++)
				{
					char sID[9];
					printf("Nhap ma sach cua quyen thu %d:", i);
					fflush(stdin);
					gets(sID);
					int m = timID(sach_ID, sID, dem);
					the[demt][u] = m;
					fflush(stdin);
					puts(sach_ID[m]);
					puts(sach[m]);
					if (sach_sq[m] > 0) {
						sach_sq[m] = sach_sq[m] - 1;
						u++;
					}
					else {
						printf("Sach da het\n");
						the[demt][1] = the[demt][1] - 1;
						i = i - 1;
					}
				}
				if (the[demt][1] > 0)
				{
					printf("Nhap ngay muon:");
					do {
						nhapngaythang(ngaymuon, demt);
						congngay(ngaymuon, ngaytradk, demt);
						if (demngay(ten_nl, o) > demngay(ngaymuon, demt)) {
							printf("\nNHAP SAI\n\n");
						}
					} while (demngay(ten_nl, o) > demngay(ngaymuon, demt));
					int e = demngay(ngaymuon, demt);
					int w = demngay(ten_nh, o);
					if (e < w) {
						printf("Tra sach truoc ngay: %d/%d/%d\n", ngaytradk[demt][0], ngaytradk[demt][1], ngaytradk[demt][2]);
					}
					else {
						printf("The da het han\n");
						the[demt][0] = -1;
						demt = demt - 1;
					}
				}
				else
				{
					the[demt][0] = -1;
					demt = demt - 1;
				}
			}
			demt = demt + 1;
		}
		else {
			printf("Hien khong co doc gia nao ca\n");
		}
	}
	void thuchien4(char ten_ID[][9], char sach_ID[][9], int the[][10], int thet[][10], int ngaymuon[][3], int ngaytradk[][3], int dem, int demt, int sach_sq[], int &demtt, int ngaytrat[][3], int sach_gia[], int &demm)
	{
		if (demt > 0){
			char ID[9], tID[9];
			int i = -1, flag = 0, p = 0, m;
			printf("Nhap ma doc gia can tra sach\n \n Nhap: ");
			fflush(stdin);
			gets(tID);
			int o = timID(ten_ID, tID, dem);
			thet[demt][0] = o;
			printf("Nhap phim bat ki  de tra sach-Nhap c de bao lam mat sach\n");
			for (int v = 0; v < demt; v++) {
				if (the[v][0] == o) {
					for (int k = 2; the[v][k] >= 0; k++) {
						char b;
						printf("Tra sach co ma sach  ");
						puts(sach_ID[the[v][k]]);
						fflush(stdin);
						scanf("%c", &b);
						if (b == 'c') {
							p = p + 2 * sach_gia[the[v][k]];
						}
						else {
							sach_sq[the[v][k]] = sach_sq[the[v][k]] + 1;
							the[v][1] = the[v][1] - 1;
						}
					}
					printf("Nhap ngay tra:");
					nhapngaythang(ngaytrat, demtt);
					m = trungay(ngaytrat, ngaytradk, demtt, o);
					if (m != 0) {
						demm = demm + 1;
					}
					p = p + m * 5000;
					printf("Tien phat :%d\n", p);
				}
			}

		}
		else {
			printf("\nHien khong co phieu muon nao ca\n\n");
		}
	}
	void thuchien5(int dem, int demt, int demtt, int dem_s, int the[][10], char sach_tl[][40], char c, int ten_gt[], int demm)
	{
		switch (c)
		{
		case 'a':
		{
					printf("So luong sach trong thu vien: %d\n", dem_s);
					break;
		}
		case 'c':
		{
					printf("So luong doc gia: %d\n", dem);
					break;
		}
		case 'e':
		{
					int s = 0;
					for (int i = 0; i < demt; i++) {
						s = the[i][1] + s;
					}
					printf("So luong sach dang duoc muon: %d\n", s);
					break;
		}
		case 'd':
		{
					int s0 = 0, s1 = 0;
					for (int i = 0; i < dem; i++) {
						if (ten_gt[i] == 0) {
							s0 = s0 + 1;
						}
						else {
							s1 = s1 + 1;
						}
					}
					printf("So doc gia nam la: %d\n", s1);
					printf("So doc gia nua la: %d\n", s0);
		}
		case 'b':
		{
					int k = dem_s, u;
					char a[1000][40];
					for (int i = 0, u = 0; i < dem_s; i++) {
						strcpy(a[u], sach_tl[i]);
						u = u + 1;
					}
					xoa(a, k);
					for (int m = 0; m < k; m++){
						int s = 0;
						for (int i = 0; i < dem_s; i++){
							if (strcmp(a[m], sach_tl[i]) == 0){
								s = s + 1;
							}
						}
						puts(a[m]);
						printf("So luong: %d\n", s);
					}
					break;
		}
		case 'f':
		{
					printf("So doc gia bi tre hen la: %d\n", demm);
					break;
		}
		}
	}