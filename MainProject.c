#include<stdio.h>
#include "Mylib.h"

#define Max 100


//int epsilon=0.0001;
int main(){
	int optionMain;
	int i;
	while(1){
		printf("******************************************************************\n");
		printf("**		Menu bai tap lon cuoi ki mon C/C++		**\n");
		printf("**			1.Bai 1					**\n");
		printf("**			2.bai 5					**\n");
		printf("**			3.bai 7					**\n");
		printf("**			4.bai 8					**\n");
		printf("**			5.bai 10				**\n");
		printf("**			6.bai 14				**\n");
		printf("**			7.exit					**\n");
		printf("******************************************************************\n");
		printf("nhap lua chon...\n");
		scanf("%d",&optionMain);
		float x;
		int option;
		int opt5;
		float ki;//lai suat
		float T;
		float S;
		int m;
		int opt1;
		int Arr [100];
		SINHVIEN h;
		SINHVIEN ch;
		int msv;
		int pos;
		int k;int i;
		int src;
		switch (optionMain){
			case 1:
				printf("\n%-10s%-10s%-10s%-10s%12s\n","Ma","Kitu","Bin","Oct","Hex");
				for(i=32;i<127;i++){
				printf("%-10d%-10c%-10d%-10d%-10c",i,i,Binconvert(i),Otcconvert(i),32);
				printf("%X",i);
				printf("\n");
			
				}
					break;
				case 2:
					while(opt5!=4){
	
						printf("**		Menu bai 5	**\n");
						printf("**		1.Tinh sin(x)	**\n");
						printf("**		2.Tinh cos (x)	**\n");
						printf("**		3.Tinh e^(x)	**\n");
						printf("**		4.exit		**\n");
						printf("nhap lua chon:...\n");
						scanf("%d",&opt5);
						switch(opt5){
							case 1:
								printf("nhap x\n");
								scanf("%f",&x);
								printf("sin x la %.5f\n",Sinx(x));
								break;
							case 2:
								printf("nhap x\n");
								scanf("%f",&x);
								printf("cos x la %.5f\n", Cosx(x));
								break;
							case 3:
								printf("nhap x\n");
								scanf("%f",&x);
								printf("e mu x la %.5f\n",Exp(x));
								break;
							
							
							
						}
					
					//	break;
						
						
					}
					break;
					
					
					
						
					
					
					
					case 3:
						while(opt1!=4){
							printf("**		MENU BAI 7				**\n");
							printf("**	1. tinh tien nhan duoc sau khi gui m thang	**\n");
							printf("**	2. tinh so thang de nhan duoc so tien moi	**\n");
							printf("**	3. tinh so tien ban dau can gui			**\n");
							printf("**	4.exit						**\n");
							printf("**********************************************************\n");
							printf("nhap lua chon...\n");
							scanf("%d",&opt1);
							switch(opt1){
								case 1:
									printf("nhap tien gui\n");
									scanf("%f",&T);
									printf("nhap so thang gui\n");
									scanf("%d",&m);
									printf("nhap lai suat\n");
									scanf("%f",&ki);
									printf("so tien nhan duoc la: %f \n",savingMoney1(T,m,ki));
									break;
								case 2:
									printf("Nhap tien gui\n");
									scanf("%f",&T);
									printf("nhap tien nhan\n");
									scanf("%f",&S);
									printf("nhap lai suat\n");
									scanf("%f",&ki);
									printf(" so thang gui se la:%d\n",Month(S,T,ki));
									break;
								case 3:
									printf("Nhap tien nhan \n");
									scanf("%f",&S);
									printf("Nhap so Thang\n");
									scanf("%d",&m);
									printf("Nhap lai suat\n");
									scanf("%f",&ki);
									printf("can gui so tien ban dau la %f \n",FirstMoney(S,m,ki));
									break;
								
							}
		
						}
						break;
						case 4:
							
							//NhapMang(Arr,&N);
							inputFile(Arr,&N,"arraynumber.txt");
							int test[100];
							CopyArr(Arr,test,N);
							while(opt1!=10){
								printf("**			Menu Bai 8						**\n");
								printf("**	1. gia tri va vi tri cua max, min, va max nhi va min nhi		**\n");
								printf("**	2. gia tri trung binh cac phan tu,cac phan tu  duong,cac phan tu am	**\n");
								printf("**	3. tim so lan xuat hien cua X trong day					**\n");
								printf("**	4. in ra so chinh phuong, so nguyen to, so fibonaci trong day		**\n");
								printf("**	5. kiem tra trong day co bao nhieu bo so lien tiep tao thanh CSC,CSN	**\n");
								printf("**	6. kiem tra day co phai day doi xung hay khong				**\n");
								printf("**	7. kiem tra tinh tang giam cua day so					**\n");
								printf("**	8. Sap xep day theo yeu cau						**\n");
								printf("**	9. In ra day con cua day						**\n");
								printf("**	10. exit								**\n");
								printf("**********************************************************************************\n");
								printf("nhap lua chon...");
								int opt1;int x;
								int b[100];
								int k;
								int test [100];
								scanf("%d",&opt1);
		
								switch(opt1){
									case 1:
										output(Arr,N);
										findMax(Arr,N);
										findMin(Arr,N);
										break;
									case 2:
										output(Arr,N);
										Average(Arr,N);
										break;
									case 3:
				
										printf("nhap gia tri X\n");
										scanf("%d",&x);
										output(Arr,N);
										InforX(Arr,N,x);
										break;
									case 4:
										output(Arr, N);
										InDsSo(Arr,N);
										break;
									case 5:
										output(Arr,N);
										printf("nhap so k\n");
										scanf("%d",&k);
										printf("So bo %d so lien tiep tao thanh cap so cong la: %d\n",k,Capsocong(Arr,N,k));
										Capsonhan(Arr, N, k);
										printf("So bo %d so lien tiep tao thanh cap so nhan la: %d\n",k,Capsocong(Arr,N,k));
										break;
									case 6:
										output(Arr,N);
										if(CheckPandinum(Arr,N)==1){
										printf("day la day doi xung\n");
				
										}else{
											printf("day la khong la day doi xung\n");
											editPandinum(Arr,b,N);
										}
										break;
									case 7:
										output(Arr, N);
										TinhTangGiam(Arr,N);
										suaDaytanggiam(Arr,N);
			
										break;
									case 8:
										printf(" day so ban dau: ");
										output(Arr,N);
										CopyArr(Arr,test,N);
										printf("day so sap xep tang cac phan tu la : ");
										SortIncreArr(test,N);
										printf("day so sap xep giam cac phan tu la: ");
										SortDecreArr(test, N);
										CopyArr(Arr,test,N);
										printf(" day so sap xep tang theo so chan la : ");
										IncreaEven(test,N);
										CopyArr(Arr,test,N);
										printf(" day so sap xep giam theo so chan la : ");
										DecreaEven(test,N);
										CopyArr(Arr,test,N);
										printf(" day so sap xep tang theo so le la : ");
										IncreaOdd(test,N);
										CopyArr(Arr,test,N);
										printf(" day so sap xep giam theo so le la : ");
										DecreaOdd(test,N);
										break;
									case 9:
										printf(" day so ban dau la: ");
										output(Arr,N);
										dayconcungdau(Arr,N);
										dayconnguyento(Arr,N);
										break;
				
									}
								}
								break;
							case 5:
								while(option !=5){
			
	
										printf("**		Menu bai 10 						**\n");
										printf("**	1. kiem tra su xuat hien cua ki tu ch trong xau st		**\n");
										printf("**	2. dem so loai ki tu trong xau st va so lan xuat hien cua chung	**\n");
										printf("**	3. Sap xep lai xau theo thu tu abc				**\n");
										printf("**	4. Chuan hoa ten va sap xep theo tu dien			**\n");
										printf("**	5. exit								**\n");
										printf("**************************************************************************\n");
										printf("nhap lua chon\n");
										int option;
										char A [100];
										int comp1, comp2;
										int i,j;
										char fullname[50][50];
										char lastname[50][50];
										int n;
										FILE *fn;
					
										scanf("%d",&option);
										switch (option){
											case 1:
					
												printf("nhap xau\n");
												fflush(stdin);
												gets(A);
												printf("xau vua nhap\n");
												puts(A);
												char x;
												printf("nhap ki tu k\n");
												scanf("%c",&x);
												Checkchar(A,x);
												break;
					
											case 2:
					
												printf("nhap xau\n");
												fflush(stdin);
												gets(A);
												printf("xau vua nhap\n");
												puts(A);
												TypeofChar(A);
												break;
											case 3:
					
												printf("nhap xau\n");
												fflush(stdin);
												gets(A);
												printf("xau vua nhap\n");
												puts(A);
												SortString(A);
												break;
											case 4:
					
					
												fn = fopen("dsten_bai10.txt","r");
												if(fn==NULL){
													printf("Mo tep khong thanh cong\n");
												}
					
												fscanf(fn,"%d\n",&n);
												char name [30];
												for(i=0;i<n;i++){
													fgets(name,30,fn);
													Chuanhoa(name);
													name[strlen(name)-1]=name[strlen(name)];
													strcpy(fullname[i],name);
												}
												fclose(fn);
												for(i=0;i<n-1;i++){
													for(j=i+1;j<n;j++){
														tachten(fullname[i],lastname[i]);
														tachten(fullname[j],lastname[j]);
							
														comp1= strcmp(lastname[i],lastname[j])>0;
														comp2= strcmp(lastname[i],lastname[j])==0&&strcmp(fullname[i],fullname[j])>0;
														if(comp1 || comp2){
															char s[30];
															strcpy(s, fullname[i]);
															strcpy(fullname[i],fullname[j]);
															strcpy(fullname[j],s);
														}
													}
												}
												for(i=0;i<n;i++){
													puts(fullname[i]);
												}
												break;
											
					
										}
									}
									break;
									case 6:
										printf("danh sach sinh vien la:\n");
										NhapDS_file("MyList_read.txt");
	
	/*int i;
	
	int k;int ops;
	
	//
//	SINHVIEN h;
//	
	//In_DSLine(h,"MyFileWriter");
	int pos;
	*/
	
										while(1){
	
											printf("\n**	Menu bai 14				**\n");
											printf("**	1.In danh sach sinh vien theo dang bang	**\n");
											printf("**	2.Chia phong cho sinh vien		**\n");
											printf("**	3.In danh sach sinh vien theo dang the	**\n");
											printf("**	4.Tim kiem thong tin sinh vien		**\n");
											printf("**	5.Them moi sinh vien vao danh sach	**\n");
											printf("**	6.Xoa sinh vien khoi danh sach		**\n");
											printf("**	7.Sua thong tin sinh vien		**\n");
											printf("**	8.exit					**\n");
											printf("**************************************************\n");
											printf("nhap lua chon...\n");
											int luachon;
											scanf("%d",&luachon);
											switch(luachon){
												case 1:
													InDS("MyFileWriter");
														break;
												case 2:
													printf("nhap so phong thi\n");
													scanf("%d",&k);
													DStheophong("MyFileWriter",k);
													break;
												case 3:
													for(i=0;i<n;i++){
													StudentCard(sv[i],"MyFileWriter");
													}
													break;
												case 4:
													SeachInform(&src,"filechuanhoa.txt");
													break;
												case 5:
													AddStudent(h,&n,n+1);
													InDS("MyFileWriter");
													break;
												case 6:
													DeleteStudent(&n,&pos);
													InDS("MyFileWriter");
													break;
												case 7:
													changeInfo(ch,&msv,"MyFileWriter");
													printf("danh sach sinh vien sau khi chinh sua\n");
													InDS("MyFileWriter");
		
													break;
												case 8:
													exit(1);
			
											}
										}
	
						
							
			}
		}
	getch();

	
	return 0;
	
	
}

