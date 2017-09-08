#include "stdafx.h"
#include "Nhap.h"
#include <string>
#include "Xuli.h"

void nhapten(char ten[][40], int &dem)
{
	char b[40];
	fflush(stdin);
	gets(b);
	chuanhoa(b);
	int k = strlen(b), i;
	for (i = 0; i <= k; i++) {
		ten[dem][i] = b[i];
	}
	ten[dem][i++] = '\0';
	dem++;
}
void nhapngaythang(int a[][3], int dem)
{
	do{
		for (int i = 0; i <= 2; i++) {
			switch (i)
			{
			case 0:
				printf("Nhap vao ngay: ");
				scanf("%d", &a[dem][0]);
				break;
			case 1:
				printf("Nhap vao thang: ");
				scanf("%d", &a[dem][1]);
				break;
			case 2:
				printf("Nhap vao nam: ");
				scanf("%d", &a[dem][2]);
				break;
			}
		}
		if (ktngaythang(a, dem) == 0) {
			printf("\n NGAY THANG NAM SAI - XIN NHAP LAI\n\n");
		}
	} while (ktngaythang(a, dem) == 0);
}
void nhapgt(int a[], int dem)
{
	char b[40];
	int k, l;
	do {
		printf("Nhap gioi tinh: ");
		fflush(stdin);
		gets(b);
		chuyenthuong(b);
		k = strcmp(b, "nam"), l = strcmp(b, "nu");
	} while (k != 0 && l != 0);
	if (strcmp(b, "nam") == 0) {
		a[dem] = 1;
	}
	else {
		a[dem] = 0;
	}
}
void nhapcm(char ten[][40], int dem)
{
	char b[40];
	do{
		do {
			printf("Nhap cmnd: ");
			fflush(stdin);
			gets(b);
			int k = strlen(b), i;
			for (i = 0; i <= k; i++) {
				ten[dem][i] = b[i];
			}
			ten[dem][i++] = '\0';
			if (cmnd(ten, dem, b) == 0) {
				printf("\n Chung minh nhan dan nay da dang ki roi\n\n");
			}
		} while (cmnd(ten, dem, b) == 0);
	} while (strlen(b) != 9);
	dem++;
}
void nhapdc(char ten[][200], int dem)
{
	char b[1000];
	printf("Nhap dia chi: ");
	fflush(stdin);
	gets(b);
	chuanhoa(b);
	int k = strlen(b), i;
	for (i = 0; i <= k; i++) {
		ten[dem][i] = b[i];
	}
	ten[dem][i++] = '\0';
	dem++;
}
void nhapmail(char ten[][40], int dem)
{
	char b[40];
	fflush(stdin);
	gets(b);
	chuanhoa(b);
	int k = strlen(b), i;
	for (i = 0; i <= k; i++) {
		ten[dem][i] = b[i];
	}
	ten[dem][i++] = '\0';
	dem++;
}
void nhapxb(char ten[][200], int dem)
{
	char b[200];
	fflush(stdin);
	gets(b);
	chuanhoa(b);
	int k = strlen(b), i;
	for (i = 0; i <= k; i++) {
		ten[dem][i] = b[i];
	}
	ten[dem][i++] = '\0';
	dem++;
}
void nhape(char ten[][40], int dem)
{
	char b[40];
	fflush(stdin);
	gets(b);
	int k = strlen(b), i;
	for (i = 0; i <= k; i++) {
		ten[dem][i] = b[i];
	}
	ten[dem][i++] = '\0';
	dem++;
}