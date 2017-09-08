#include "stdafx.h"
#include "Xuli.h"
#include <string>

char inttochar(int i)
{
	switch (i)
	{
	case 0:
		return '0';
		break;
	case 1:
		return '1';
		break;
	case 2:
		return '2';
		break;
	case 3:
		return '3';
		break;
	case 4:
		return '4';
		break;
	case 5:
		return '5';
		break;
	case 6:
		return '6';
		break;
	case 7:
		return '7';
		break;
	case 8:
		return '8';
		break;
	case 9:
		return '9';
		break;
	}
}
int ktngaythang(int a[][3], int dem)
{
	if ((0<a[dem][1] && a[dem][1] <= 12)) {
		switch (a[dem][1])
		{
		case 1 || 3 || 5 || 7 || 8 || 10 || 12:
			if (a[dem][0]<0 || a[dem][0]>31) {
				return 0;
			}
			break;
		case 2:
			if ((a[dem][2] % 400 == 0) || (a[dem][2] % 4 == 0 && a[dem][2] % 100 != 0)){
				if (a[dem][0]<0 || a[dem][0]>29) {
					return 0;
				}
			}
			else {
				if (a[dem][0]<0 || a[dem][0]>28) {
					return 0;
				}
			}
		default:
			if (a[dem][0]<0 || a[dem][0]>30) {
				return 0;
			}
			break;
		}
	}
	else {
		return 0;
	}
}
void chuyenthuong(char a[])
{
	for (int i = 0; i<strlen(a); i++){
		if ('A' <= a[i] && a[i] <= 'Z') {
			a[i] = a[i] + 32;
		}
	}
}
void ngayhet(int a[][3], int dem, int b[][3])
{
	b[dem][0] = a[dem][0];
	b[dem][1] = a[dem][1];
	b[dem][2] = a[dem][2] + 4;
}
int timID(char ten_ID[][10], char ID[], int dem)
{
	for (int i = 0; i <= dem; i++){
		if (strcmp(ten_ID[i], ID) == 0){
			return i;
		}
	}
	return -1;
}
void xoa_ten(char a[][40], int i, int dem)
{
	for (; i < dem; i++){
		strcpy(a[i], a[i + 1]);
		a[i][strlen(a[i + 1]) + 1] = '\0';
	}
}
void xoa_tenID(char a[][9], int i, int dem)
{
	for (; i < dem; i++){
		strcpy(a[i], a[i + 1]);
		a[i][strlen(a[i + 1]) + 1] = '\0';
	}
}
void xoa_tendc(char a[][200], int i, int dem)
{
	for (; i < dem; i++){
		strcpy(a[i], a[i + 1]);
		a[i][strlen(a[i + 1]) + 1] = '\0';
	}
}
void xoa_tenns(int a[][3], int i, int dem)
{
	for (; i < dem; i++){
		for (int j = 0; j < 3; j++){
			a[i][j] = a[i + 1][j];
		}
	}
}
void xoa_tengt(int a[], int i, int dem)
{
	for (; i < dem; i++){
		a[i] = a[i + 1];
	}
}
int timID(char ten_ID[][40], char ID[], int dem)
{
	for (int i = 0; i < dem; i++){
		if (strcmp(ten_ID[i], ID) == 0){
			return i;
		}
	}
	return -1;
}
void rutchuoi(char a[])
{
	for (; a[0] == ' ';)
	for (int i = 0; i < strlen(a); ++i)
	{
		a[i] = a[i + 1];
	}
	int size = strlen(a);
	while (a[size] == ' ')
	{
		a[size] = a[size + 1];
		size--;
	}
	size = strlen(a);
	int j;
	int i = 0;
	while (i <= strlen(a) - 1)
	{
		if (a[i] == ' '&&a[i + 1] == ' ')
		{
			int j = i;
			do
			{
				a[j] = a[j + 1];
			} while (a[++j] != 0);
		}
		else{
			i++;
		}
	}
}
int timten(char ten[][40], char a[], int dem, int &i)
{
	i = i + 1;
	char ten1[2000][40];
	for (int k = 0; k < dem; k++)
	{
		strcpy(ten1[k], ten[k]);
	}
	chuanhoa(a);
	for (; i < dem; i++)
	{
		if (strcmp(ten1[i], a) == 0) {
			return i;
		}
	}
	return -1;
}
void viethoa(char a[])
{
	a[0] = a[0] - 32;
	for (int i = 0; i < strlen(a); i++)
	{
		if (a[i] == ' ') {
			a[i + 1] = a[i + 1] - 32;
		}
	}
}
void chuanhoa(char a[])
{
	rutchuoi(a);
	chuyenthuong(a);
	viethoa(a);
}
int ktnamnhuan(int a)
{
	if ((a % 4 == 0 && a % 4 != 0) || (a % 400 == 0)){
		return 0;
	}
	else {
		return 1;
	}
}
void congngay(int a[][3], int b[][3], int demt)
{
	if (a[demt][1] == 2) {
		if (ktnamnhuan(a[demt][2] == 1))
		{
			if (a[demt][0] > 21){
				b[demt][0] = a[demt][0] + 7 - 28;
				b[demt][1] = a[demt][1] + 1;
				b[demt][2] = a[demt][2];
			}
			else {
				b[demt][0] = a[demt][0] + 7;
				b[demt][1] = a[demt][1];
				b[demt][2] = a[demt][2];
			}
		}
		else {
			{
				if (a[demt][0] > 22){
					b[demt][0] = a[demt][0] + 7 - 29;
					b[demt][1] = 3;
					b[demt][2] = a[demt][2];
				}
				else {
					b[demt][0] = a[demt][0] + 7;
					b[demt][1] = a[demt][1];
					b[demt][2] = a[demt][2];
				}
			}
		}
	}
	if (a[demt][1] == 1 || 3 || 5 || 7 || 8 || 10) {
		if (a[demt][0] >= 25) {
			b[demt][0] = a[demt][0] + 7 - 31;
			b[demt][1] = a[demt][1] + 1;
			b[demt][2] = a[demt][2];
		}
		else {
			b[demt][0] = a[demt][0] + 7;
			b[demt][1] = a[demt][1];
			b[demt][2] = a[demt][2];
		}
	}
	if (a[demt][1] == 4 || 6 || 9 || 11){
		if (a[demt][0] >= 24) {
			b[demt][0] = a[demt][0] + 7 - 31;
			b[demt][1] = a[demt][1] + 1;
			b[demt][2] = a[demt][2];
		}
		else {
			b[demt][0] = a[demt][0] + 7;
			b[demt][1] = a[demt][1];
			b[demt][2] = a[demt][2];
		}
	}
	if (a[demt][1] == 12)
	{
		if (a[demt][0] >= 25) {
			b[demt][0] = a[demt][0] + 7 - 31;
			b[demt][1] = a[demt][1] + 1;
			b[demt][2] = a[demt][2] + 1;
		}
		else {
			b[demt][0] = a[demt][0] + 7;
			b[demt][1] = a[demt][1];
			b[demt][2] = a[demt][2];
		}
	}
}
int demngay(int a[][3], int demtt)
{
	int s = 0;
	for (int i = 0; i < a[demtt][2]; i++){
		if (ktnamnhuan(i) == 0) {
			s = s + 366;
		}
		else {
			s = s + 365;
		}
	}
	for (int i = 1; i < a[demtt][1]; i++) {
		if (i == 1 || 3 || 5 || 7 || 8 || 10 || 12) {
			s = s + 31;
		}
		else {
			if (i != 2) {
				s = s + 30;
			}
			else {
				if (ktnamnhuan(a[demtt][2]) == 0) {
					s = s + 29;
				}
				else {
					s = s + 28;
				}
			}
		}
	}
	s = s + a[demtt][0];
	return s;
}
int trungay(int a[][3], int b[][3], int m, int n)
{
	int k = demngay(a, m);
	int l = demngay(b, n), c;
	if (k <= l) {
		printf("Nop dung hen\n");
		c = 0;
	}
	else  {
		printf("Nop tre:%d\n", k - l);
		c = l - k;
	}
	return c;
}
void xoa(char a[][40], int &n)

{
	for (int i = 1; i < n - 1; i++) {

		for (int k = i + 1; k < n; k++) {

			if (strcmp(a[i], a[k]) == 0)

			{

				for (int j = k; j <= n - 1; j++){

					strcpy(a[j], a[j + 1]);
				}

				n--;

				k--;

			}
		}
	}

}
int cmnd(char a[][40], int dem, char ID[])
{
	for (int i = 0; i < dem; i++) {
		if (strcmp(a[i], ID) == 0) {
			return 0;
		}
	}
	return -1;
}