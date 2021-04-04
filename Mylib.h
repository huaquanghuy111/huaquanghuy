#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include"Mylib.c"
//chi include file .c, khai bao prototype cua function
//ham bai 1;
long Binconvert(int k);
long Otcconvert(int k);
//ham bai 5;
float Sinx(float x);
float Cosx(float x);
float Exp(float x);
//ham bai 7
float savingMoney1(float T, int m, float k);
int Month(float S,float T,float k);
float FirstMoney(float S, int m, float k);
//ham bai 8;
void inputFile(int A[100], int *n, char filename[30]);
void NhapMang(int A[100],int * n);
void output(int  A [100],int n);
void findMax(int A[100],int n);
void findMin(int A[100],int n);
void Average(int A[100],int n);
void InforX(int A[100],int n,int x);
int isPrime(int n);
int soChinhPhuong(int k);
int isFibonaci(int k);
void InDsSo(int A [100],int n);
int Capsocong(int A[100],int n, int k);
int Capsonhan(int A[100],int n, int k);
int CheckPandinum(int A [100],int n);
void SortIncreArr(int A[100],int n);
void SortDecreArr(int A[100],int n);
void IncreaEven(int A[100],int n);
void DecreaEven(int A[100],int n);
void IncreaOdd(int A[100],int n);
void DecreaOdd(int A[100],int n);
void dayconcungdau(int A[100],int n);
void dayconnguyento(int A[100],int n);
void TinhTangGiam(int A [100],int n);
void xoaphantu(int a [100],int (*n),int vitri);
void suaDaytanggiam(int a[100],int n);
void bfroma( int a[100],int b[100],int n,int k);
	void editPandinum(int a[100],int b[100],int n);
	void CopyArr(int Scr [100], int Goa[100],int n);
//ham bai 10;
void Checkchar(char Str [100], char x);
void TypeofChar(char Str [100]);
void SortString(char A[100]);
int TypeName(char str [50]);
void deleteK(char str[50], int k );
void Chuanhoa(char str [50]);
void tachten(char name[50],char lastname [50]);
//ham bai 14
void NhapDS_file(char filename[]);
void Chen_Xau(char *s, int d);
void In_DSLine(SINHVIEN h,char filename[30]);
void StudentCard(SINHVIEN h, char filename[30]);
void InDS(char filename[30]);
void DStheophong(char filename[30],int k);
void SeachInform(int *ops,char filename[30]);
void AddStudent(SINHVIEN h, int *n, int pos);
void DeleteStudent( int *n, int *pos);
void changeInfo(SINHVIEN ch,int *msv,char filename [30]);

