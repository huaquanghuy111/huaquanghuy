#include<stdio.h>
#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>

#define Max 100
//ham bai 1
//bai tap goi co ban
//bai 1 in ra bang ma ascii thanh 5 cot
//ham chuyen doi ma thap phan sang ma nhi phan
//de tat ca bien cuc bo, cac ham 
int epsilon=0.001;

typedef struct {
	int id;
	char Name[Max];
	char  Ngay_sinh[50];
	char dia_chi [50];
	char gioi_tinh [30];
	char que_quan[30];
	
}SINHVIEN;

SINHVIEN sv[Max];
int n;//so sinh vien
int N;//so phan tu trong day

long Binconvert(int k){
	long sum=0;//bien luu so nhi phan
	int i=1;
	int rem;//bien luu so du khi chi k cho 2
	do{
		rem=k%2;
		sum+=(i*rem);
		i=i*10;
		k=k/2;
	}while(k>0);
	return sum;
}
//ham chuyen so co so 10 sang co so 8
long Otcconvert(int k){
	long sum=0;//bien luu so bat phan
	int i=1;
	int rem;//bien luu so du khi chi k cho 8
	do{
		rem=k%8;
		sum+=(i*rem);
		i=i*10;
		k=k/8;
	}while(k>0);
	return sum;
}
//ham bai 5
//ham tinh gia tri sin(x) theo taylo
float Sinx(float x){
	float sin=0;
	float p=x;
	int i=1;
	do{
		sin+=p;
		i+=2;
		p=p*(-1)*(x*x)/(i*(i-1));
		
	}while(fabs(p)>epsilon);
	return sin;
	
}
//ham tinh gia tri cos (x)
float Cosx(float x){
	float cos=0;
	float p=1;
	int i=0;
	do{
		cos+=p;
		i+=2;
		p=p*(-1)*(x*x)/(i*(i-1));
	}while(fabs(p)>epsilon);
//	printf("%f\n", cos);
	return cos;
	
}
//ham tinh gia tri e^x
float Exp(float x){
	float exp=0;
	float p=1;
	int i=0;
	
	do{
		exp+=p;
		i+=1;
		p=p*(x/i);

	}while(fabs(p)>epsilon);
	
	return exp;
}
//ham bai 7
//bai toan lai suat tiet kiem
//viet ham tinh so tien nhan duoc sau m thang lai suat k%, so tien ban dau la T
float savingMoney1(float T, int m, float k){
	int i;
	for(i=1; i<=m;i++){
		T=T+T*k;
	}return T;
}
//viet ham tinh so thang de sau khi gui tu T ban dau se nhan duoc S
int Month(float S,float T,float k){
	int i=0;
	while(T<=S){
		T=T+T*k;
		i++;
	}
	return i;
}
//viet ham tinh tien gui ban dau T de sau m thang se co S
float FirstMoney(float S, int m, float k){
	float T=S;
	int i;
	for (i=m; i>0;i--){
		T=T/(1+k);
		
	}
	return T;
}
//ham bai 10
//nhap vao xau ch, ki tu z, kiem tra xem ki tu z co xuat hien trong xau ch hay khong, neu co thi xuat hien  lan, o nhung vi tri nao,
void Checkchar(char Str [100], char x){
	int i;
	int dem=0;
	for(i=0;i<strlen(Str);i++){
		if(Str[i]==x)
			dem++;
	
	}
	if(dem==0)
	{
		printf("ki tu %c khong xuat hien trong xau Str\n",x);
	}
	else{
		printf("ki tu %c xuat hien %d lan, o nhung vi tri\n",x,dem);
		for(i=0;i<strlen(Str);i++){
			if(Str[i]==x)
				printf("%d ",i);
		}
		printf("\n");
	}
	
}
//nhap xau Str, xet xem xau co bao nhieu loai ki tu, moi loai xuat hien bao nhieu lan
void TypeofChar(char Str [100]){
	int dem [256];
	int i;
	for(i=0;i<=256;i++)
		dem[i]=0;
	for(i=0;i<strlen(Str);i++){
		dem[Str[i]]++;
	}
	//tinh so phan tu cua mang dem[];
	int d=0;
	for(i=0;i<256;i++)
	{
		if(dem[i]!=0)
			d++;

	}
	printf("so loai phan tu cua chuoi la:%d\n",d);
	for(i=0;i<256;i++){
		if(dem[i]!=0){
			printf("ki tu %c xuat hien %d lan\n",i,dem[i]);
		}
	}
}
//sap xep lai ki tu trong 1 xau theo thu tu a,b,c
void SortString(char A[100]){
	int i;
	int j;
	for(i=0; i<strlen(A)-1;i++){
		for(j=i+1;j<strlen(A);j++){
			if(A[i]>A[j]){
				char temp = A[i];
				A[i]=A[j];
				A[j]=temp;
				
			}
		}
	}
	printf("xau sau khi duoc sap xep: ");
	puts(A);
}
//ham kiem tra xem xau co dang ten hay khong

int TypeName(char str [50]){
	int i;
	 for(i=0; i<strlen(str); i++){
	 	if(str[i]>='0' && str[i]<='9'){
	 		return 0;
		 }
	 }
	 return 1;
}//ham xoa ki tu thu k
void deleteK(char str[50], int k ){
	int i;
	for(i=k; i<strlen(str);i++){
		str[i]=str[i+1];
		
	}
}//ham chuan hoa ten
void Chuanhoa(char str [50]){
	
	
	//xoa cach dau
	int i;
	while(str[0]==' '){
		deleteK(str, 0);
		
	}
	//xoa cach duoi
	while(str[strlen(str)-1]==' '){
		deleteK(str,strlen(str)-1);
	}

		
	
	
	//xoa ki tu cach trung nhau o giua
	for(i=0; i<strlen(str); i++){
		if(str[i]==' ' && str[i+1]==' '){
			deleteK(str,i);
			i--;
		}
	}
	strlwr(str);
	str[0]=str[0]-32;
	for(i=0; i<(strlen(str)-1); i++){
		if(str[i]==' '){
			str[i+1]=str[i+1]-32;
		}
	}
	
	//puts(str);
	

	
	}
	void tachten(char name[50],char lastname [50]){
		int i,j;
		i=strlen(name)-1;
		j=0;
		strcpy(lastname,"");
		while(name[i]!=' ' && i>=0){
			lastname[j++]=name[i--];
		}
		lastname[j++]='\0';
		strrev(lastname);
	}
	//ham bai 8
	//cac ham cho bai tap 8 cuoi ki
//ham tim gia tri lon nhat
void NhapMang(int A[100],int * n){
	printf("nhap so phan tu cua day\n");
	scanf("%d", n);
	int i;
	for(i=0;i<*n;i++){
		printf("nhap phan tu thu %d\n",i);
		scanf("%d",&A[i]);
	}
	
}
//void nhap mang qua file
void inputFile(int A[100], int *n, char filename[30]){
	FILE *fn;
	int i;
	fn=fopen(filename,"r");
	if(fn==NULL){
		printf("mo file khong thanh cong\n");
		
	}
	fscanf(fn,"%d\n",n);
	for(i=0;i<*n;i++){
		fscanf(fn,"%d",&A[i]);
	}
	fclose(fn);
	
}
void output(int  A [100],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
}
void findMax(int A[100],int n){
	
	int i;
	int max;
	max=A[0];
	for(i=1;i<n;i++){
		if(max<A[i]){
			max=A[i];
		}
	}
	printf("gia tri max cua day la: %d\n",max);
	printf("xuat hien o nhung vi tri la: ");
	for(i=0; i<n;i++){
		if(A[i]==max)
			printf("%d ",i);
	}
	printf("\n");
	int max2=-30000;
	for(i=0;i<n;i++){
		if(max2<A[i]&&A[i]<max){
			max2=A[i];
		}
	}
	printf("gia tri lon thu 2 trong day la: %d \n",max2 );
	printf("xuat hien o nhung vi tri la: ");
	for(i=0;i<n;i++){
		if(A[i]==max2)
			printf("%d ",i);
	}
	printf("\n");
	
	
}
void findMin(int A[100],int n){
	
	int i;
	int min;
	min=A[0];
	for(i=1;i<n;i++){
		if(min>A[i]){
			min=A[i];
		}
	}
	printf("gia tri min cua day la: %d\n",min);
	printf("xuat hien o nhung vi tri la: ");
	for(i=0; i<n;i++){
		if(A[i]==min)
			printf("%d ",i);
	}
	printf("\n");
	int min2=30000;
	for (i=0;i<n;i++){
		if(min2>A[i]&&A[i]>min){
			min2=A[i];
		}
	}
	printf("gia tri nho thu 2 cua day la : %d\n", min2);
	printf("xuat hien o nhung vi tri la : ");
	for(i=0;i<n;i++){
		if(A[i]==min2)
			printf("%d ",i);
	}
	printf("\n");
	
}

//ham tinh trung binh cac phan tu, cac pt duong ,cac pt am
void Average(int A[100],int n){
	int i;
	int tongduong=0;
	int ptduong=0;
	int tongam=0;
	int ptam=0;
	int tong=0;
	for(i=0;i<n;i++){
		tong+=A[i];
		if(A[i]>0){
			ptduong++;
			tongduong+=A[i];
		}
		if(A[i]<0){
			ptam++;
			tongam+=A[i];
		}
	}
	float avg=(float)tong/n;
	float avg1=(float)tongduong/ptduong;
	float avg2=(float)tongam/ptam;
	printf("trung binh cac phan tu trong day la: %f\n",avg);
	printf("trung binh cac phan tu duong trong day la: %f\n",avg1);
	printf("trung binh cac phan tu am trong day la: %f\n",avg2);
}
void InforX(int A[100],int n,int x){
	int i;
	int dem=0;
	for(i=0;i<n;i++){
		if(A[i]==x)
			dem++;
	}
	if(dem==0)
		printf("%d khong xuat hien trong day\n",x);
	else{
		printf("%d xuat hien trong day %d lan\n",x,dem);
		printf("o nhung vi tri: ");
		for(i=0;i<n;i++){
			if(A[i]==x)
				printf("%d ", i);
		}
		printf("\n");
	}
}
//ham kiem tra so nguyen to
int isPrime(int n){
	if(n<2)
		return 0;
	else{
		int i;
		for(i=2; i<n; i++){
			if(n%i==0)
				return 0;
		}
		return 1;
	}
}
//ham kiem tra so chinh phuong
int soChinhPhuong(int k){
	int i;
	for(i=1;i<k;i++){
		if(i*i==k){
			return 1;
		}
	}
	
	
		return 0;
	
}
//ham kiem tra so fibonaci
int isFibonaci(int k){
	int f1=1;
	int f2=1;
	int f3=2;
	if(k<0)
		return 0;
	else if (k<4){
		return 1;
	}
	while (f3<k){
		f1=f2;
		f2=f3;
		f3=f1+f2;
	}
	if(f3==k){
		return 1;
	}else{
		return 0;
	}
}
//ham in so nguyen to,chinh phuong,fibonaci
void InDsSo(int A [100],int n){
	int i;
	printf("so nguyen to trong day la: ");
	for(i=0;i<n;i++){
		if(isPrime(A[i])==1)
			printf("%d ",A[i]);
	}
	printf("\n");
	printf("so chinh phuong  trong day la: ");
	for(i=0;i<n;i++){
		if(soChinhPhuong(A[i])==1)
			printf("%d ",A[i]);
	}
	printf("\n");
	printf("so fibonaci trong day la: ");
	for(i=0;i<n;i++){
		if(isFibonaci(A[i])==1)
			printf("%d ",A[i]);
	}
	printf("\n");
}
//ham dem xem day co bao nhieu bo k so lien tiep tao thanh cap so cong
int Capsocong(int A[100],int n, int k){
	int count =0;
	int i,j;
	for(i=0;i<n-k;i++){
		int d=A[i+1]-A[i];
		int sophantu=1;
		for(j=i;j<i+k-1;j++){
			if(A[j+1]-A[j]!=d)
				break;
			sophantu++;
		
		}
		if(sophantu==k)
			count++;
	}
	return count ;
}
int Capsonhan(int A[100],int n, int k){
int count =0;
	int i,j;
	for(i=0;i<n-k;i++){
		float d=(float) A[i+1]/A[i]; //printf("d = %f\n",d);
		int sophantu=1;
		for(j=i;j<i+k-1;j++){
			if(A[j+1]/A[j]!=d)
				break;
			sophantu++;
		
		}
		if(sophantu==k)
			count++;
	}
	return count ;
}
//ham kiem tra day doi xung
int CheckPandinum(int A [100],int n){
	int i;

		for(i=0;i<n/2;i++){
			if(A[i]!=A[n-1-i])
				return 0;
		}
		 return 1;
	
		
	}
//ham sap xep day so tang dan	
void SortIncreArr(int A[100],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(A[i]>A[j]){
				int temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
		}
	}
	output(A,n);
}
//ham sap xep day so giam dan	
void SortDecreArr(int A[100],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(A[i]<A[j]){
				int temp=A[i];
				A[i]=A[j];
				A[j]=temp;
			}
		}
	}
	output(A,n);
}
void IncreaEven(int A[100],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		if(A[i]%2==0){
		
			for(j=i+1;j<n;j++){
				if(A[j]%2==0){
				
					if(A[i]>A[j]){
						int temp=A[i];
						A[i]=A[j];
						A[j]=temp;
					}
				}
			}
		}
	}
	output(A,n);
}
void DecreaEven(int A[100],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		if(A[i]%2==0){
		
			for(j=i+1;j<n;j++){
				if(A[j]%2==0){
				
					if(A[i]<A[j]){
						int temp=A[i];
						A[i]=A[j];
						A[j]=temp;
					}
				}
			}
		}
	}
	output(A,n);
}
void IncreaOdd(int A[100],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		if(A[i]%2!=0){
		
			for(j=i+1;j<n;j++){
				if(A[j]%2!=0){
				
					if(A[i]>A[j]){
						int temp=A[i];
						A[i]=A[j];
						A[j]=temp;
					}
				}
			}
		}
	}
	output(A,n);
}
void DecreaOdd(int A[100],int n){
	int i,j;
	for(i=0;i<n-1;i++){
		if(A[i]%2!=0){
		
			for(j=i+1;j<n;j++){
				if(A[j]%2!=0){
				
					if(A[i]<A[j]){
						int temp=A[i];
						A[i]=A[j];
						A[j]=temp;
					}
				}
			}
		}
	}
	output(A,n);
}
//in ra day con co nhieu phan tu lien tiep  cung dau nhat
void dayconcungdau(int A[100],int n){
	int max=1;
	int k=0;
	int i;int index;
	for(i=0;i<n-1;i++){
		if(A[i]*A[i+1]>0){
			k++;
		}
		else{
			k++;
			if(max<k){
				max=k;
				index=i-max;
			}
			k=0;
				
		}
	}
	printf("day con gom cac so nguyen cung dau nhieu phan tu nhat gom %d phan tu\n",max);
	printf("day con do la: ");
	for(i=index+1;i<=index+max;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	
			
}
void dayconnguyento(int A[100],int n){
	int max=1;
	int k=0;
	int i;int index;
	for(i=0;i<n;i++){
		if(isPrime(A[i])==1){
			k++;
		}
		else{
			
			if(max<k){
				max=k;
				index=i-max;
			}
			k=0;
				
		}
	}
	printf("day con gom cac so nguyen la nguyen to nhieu phan tu nhat gom %d phan tu\n",max);
	printf("day con do la: ");
	for(i=index;i<index+max;i++){
		printf("%d ",A[i]);
	}
	printf("\n");
	
			
}
//ham kiem tra tinh tang dan, giam dan cua day
void TinhTangGiam(int A [100],int n){
	if(A[1]-A[0]>0){
		int i;
		for(i=1;i<n-1;i++){
			if(A[i+1]-A[i]<0)
				break;
				
		}
		//printf("%d\n",i);
		if(i==n-1)
			printf(" la day tang\n");
		else{
			printf("khong la day so tang /giam\n");
		}
	}
	if(A[1]-A[0]<0){
		int i;
		for(i=1;i<n-1;i++){
			if(A[i+1]-A[i]>0)
				break;
				
		}
		//printf("%d\n",i);
		if(i==n-1)
			printf(" la day giam\n");
		else{
		
			printf("khong la day so tang /giam\n");
		}
	}
	if(A[1]-A[0]==0)
		printf(" khong la day tang/giam\n");
	
	
}
//ham xoa bot ki tu khoi mot mang
void xoaphantu(int a [100],int (*n),int vitri)
{
	int i;
	for(i=vitri+1;i<(*n);i++){
		a[i-1]=a[i];
	}
	(*n)--;
//	realloc(a,(*n),*sizeof(int *));
}
//ham xet xem xoa bao nhieu ki tu va nhung ki tu nao de day thanh day tang or giam
void suaDaytanggiam(int a[100],int n){
	int Index[30];
	int i;
	int j=0;
	int dem=0;
	if(a[1]-a[0]>0){
	
		for(i=0;i<n-1;i++){
			//printf("vi tri cua i %d\n",i);
			if(a[i+1]<a[i] &&a[i]>a[i-1]){
				
				Index[j]=i+1;
				j++;
				xoaphantu(a,&n,i+1);
				dem++;
				//printf("vi tri bi xoa %d\n",i);
				i--;
			}
		}
		
	}
	if(a[1]-a[0]<0){
	
		for(i=0;i<n-1;i++){
			
			if(a[i+1]>a[i] &&a[i]<a[i-1]){
				Index[j]=i+1;
				j++;
				xoaphantu(a,&n,i+1);
				dem++;
				i--;
				
			}
		}
	}
		
		printf("day so sau khi xoa:");
		output(a,n);
		printf("\n xoa it nhat %d phan tu",dem);
		printf("\n Tai nhung vi tri la: ");
		output (Index,j);
	}
	// ham tao mang b tu mang a ma bot di 1 phan tu
	void bfroma( int a[100],int b[100],int n,int k){
		int i;
		for(i=0;i<k;i++){
			b[i]=a[i];
			
		}
		for(i=k+1;i<n;i++){
			b[i-1]=a[i];
		}
	}
	//ham bot mot phan tu de day doi xung
	void editPandinum(int a[100],int b[100],int n){
		int i;
		int vitri;
		int check;
		for(i=0;i<n;i++){
			bfroma(a,b,n,i);
			//output(b,n-1);
		//	printf("\n");
			//printf("%d\n",CheckPandinum(b,n-1));
			if(CheckPandinum(b,n-1)==1){
				check=1;
				vitri=i;
				printf("vi tri can xoa la:%d\n",vitri);
				printf("day sau khi xoa la: ");
				output(b,n-1);
			}
		}
		if(check!=1)
				printf("day sau khi bot khong doi xung\n");
		}
		void CopyArr(int Scr [100], int Goa[100],int n){
			int i;
			for(i=0;i<n;i++){
				Goa[i]=Scr[i];
			}
		}
		//ham bai 14
	void NhapDS_file(char filename[])
{
    int i;
    FILE *fn; 
    char name[30]; 
    char birth[30];
    char adress[100];
    char gender[10];
    char qq[30];
     
    fn = fopen(filename,"r"); 
    if(fn==NULL)
    	printf("mo file khong thanh cong");
	fscanf(fn,"%d\n",&n);

    for (i=0; i<n; i++)
	{
		//id
		fscanf(fn,"%d\n",&sv[i].id);
		//ten
		fgets(name,30,fn);
		name[strlen(name)-1] = name[strlen(name)];
		strcpy(sv[i].Name,name);
		//ngay sinh
		fgets(birth,30,fn);
		birth[strlen(birth)-1] = birth[strlen(birth)];
		strcpy(sv[i].Ngay_sinh,birth);
		//dia chi
		fgets(adress,100,fn);
		adress[strlen(adress)-1] = adress[strlen(adress)];
		strcpy(sv[i].dia_chi,adress);
		//gioi tinh
		fgets(gender,10,fn);
		gender[strlen(gender)-1] = gender[strlen(gender)];
		strcpy(sv[i].gioi_tinh,gender);
		//que quan
		fgets(qq,30,fn);
		qq[strlen(qq)-1]=qq[strlen(qq)];
		strcpy(sv[i].que_quan,qq);
			
		
	}
	fclose(fn);
}

void Chen_Xau(char *s, int d)
{
     int i;
     for ( ;strlen(s)<d;)
        strcat(s," "); 
 
}


//in thong tin sinh vien theo 1 dong
void In_DSLine(SINHVIEN h,char filename[30]){
	FILE *fprt;
	fprt=fopen(filename,"at");
	if(fprt==NULL){
		printf("error!Khong mo duoc file \n");
		
	}
	
	char name[50]; 
    char birth[30];
    char adress[100];
    char gender[10];
    char qq[30];
    
    strcpy(name,h.Name);
    Chen_Xau(name,30);
    Chuanhoa(h.Name);
    strcpy(birth,h.Ngay_sinh);
    Chen_Xau(birth,30);
    
    strcpy(adress,h.dia_chi);
    Chen_Xau(adress,100);
    Chuanhoa(h.dia_chi);
    strcpy(gender,h.gioi_tinh);
    Chen_Xau(gender,10);
    Chuanhoa(h.gioi_tinh);
    strcpy(qq,h.que_quan);
    Chen_Xau(qq,30);
    Chuanhoa(h.que_quan);
    printf("\n%-5d%-25s%-15s%-30s%-10s%-20s",h.id,h.Name,h.Ngay_sinh,h.dia_chi,h.gioi_tinh,h.que_quan);
    fprintf(fprt,"\n%-5d%-25s%-15s%-30s%-10s%-20s",h.id,h.Name,h.Ngay_sinh,h.dia_chi,h.gioi_tinh,h.que_quan);
    fclose(fprt);
	
}
//in thong tin 1 sinh vien theo dang the sinh vien
void StudentCard(SINHVIEN h, char filename[30]){
	FILE *fprt;
	fprt=fopen(filename,"at");
	if(fprt==NULL)
		printf("error!Mo file khong thanh cong\n");
		//in man hinh
		Chuanhoa(h.Name);
		Chuanhoa(h.dia_chi);
		Chuanhoa(h.que_quan);
		Chuanhoa(h.gioi_tinh);
	printf("*****************THE SINH VIEN**************\n");
	printf("============================================\n");
	printf("Ma sinh vien:%d\n",h.id);
	printf("Ho va ten:%s\n",h.Name);
	printf("Dia chi: %s\n",h.dia_chi);
	printf("Gioi tinh: %s\n",h.gioi_tinh);
	printf("Que quan: %s\n",h.que_quan);
	printf("=============================================\n");
	//in vao file
	fprintf(fprt,"*****************THE SINH VIEN**************\n");
	fprintf(fprt,"============================================\n");
	fprintf(fprt,"Ma sinh vien:%d\n",h.id);
	fprintf(fprt,"Ho va ten:%s\n",h.Name);
	fprintf(fprt,"Dia chi: %s\n",h.dia_chi);
	fprintf(fprt,"Gioi tinh: %s\n",h.gioi_tinh);
	fprintf(fprt,"Que quan: %s\n",h.que_quan);
	fprintf(fprt,"=============================================\n");
	fclose(fprt);
	
}
void InDS(char filename[30])
{
    int i;
    FILE *fn;
    fn=fopen(filename,"at");
	if(fn==NULL)
		printf("error!Mo file khong thanh cong\n");
    fprintf(fn,"%-5s%-25s%-15s%-30s%-10s%-20s","MSV","Name","DoB","Ads","gender","Hometown");
	printf("%-5s%-25s%-15s%-30s%-10s%-20s","MSV","Name","DoB","Ads","gender","Hometown");
    for (i=0; i<n; i++)
        In_DSLine(sv[i],filename);
    fclose(fn);
}
void DStheophong(char filename[30],int k){
	int i;//int j;
	//int NameRoom=1;
	FILE *fn;
	fn=fopen(filename,"at");
		if(k>=n){
		
			for(i=0;i<n;i++){
			
				In_DSLine(sv[i],filename);
				fn=fopen(filename,"at");
				fprintf(fn,"   Phong %d\n",i+1);
				printf("   Phong %d\n",i+1);
			}
		}
		if(k<n){
			
			int svphong = n/k;
			//int svdu = n-svphong*(k-1);
			for(i=0;i<svphong*(k-1);i++){
				In_DSLine(sv[i],filename);
				fn=fopen(filename,"at");
				printf("   Phong %d\n",(i/svphong)+1);
				fprintf(fn,"   Phong %d\n",(i/svphong)+1);
			}
			for(i=svphong*(k-1);i<n;i++){
				In_DSLine(sv[i],filename);
				fn=fopen(filename,"at");
				printf("   Phong VIP\n");
				fprintf(fn,"   Phong VIP\n");
			}
		}
		
	

	fclose(fn);
	
}
void SeachInform(int *ops,char filename[30]){
	int i;
	printf("\nTim kiem theo:\n");
	printf("1. Ho va ten\n");
	printf("2. ten\n");
	printf("3.Que quan\n");
	NhapDS_file(filename);
	printf("nhap lua chon\n");
	scanf("%d",ops);
	char text[100];//dong minh nhap vao

	char lname2[30];//lay ten tu ho ten tu file
	switch(*ops){
		case 1:
			printf("nhap ho va ten\n");
			fflush(stdin);
			gets(text);
			Chuanhoa(text);
			
			for(i=0;i<n;i++){
				if(strcmp(sv[i].Name,text)==0){
					In_DSLine(sv[i],filename); 
				}
			}
			break;
			//tim theo ten
			case 2:
			printf("nhap ten\n");
			fflush(stdin);
			gets(text);
			Chuanhoa(text);
			printf(" ten vua nhap: ");
			puts(text);
		
			
			
			
			for(i=0;i<n;i++){
				tachten(sv[i].Name,lname2);
				if(strcmp(text,lname2)==0){
					In_DSLine(sv[i],filename); 
				}
			}
			break;
			case 3:
			printf("nhap ten\n");
			fflush(stdin);
			gets(text);
			Chuanhoa(text);
		
		
			
			for(i=0;i<n;i++){
				if(strcmp(text,sv[i].que_quan)==0){
					In_DSLine(sv[i],filename); 
				}
			}
			break;
	}
}//them, bot sinh vien
void AddStudent(SINHVIEN h, int *n, int pos){
//	printf(" n ban dau] la %d \n",*n);
	if(pos>*n)
		pos=*n;
	if(pos<0){
		pos=0;
	}
	int i;
	for(i=*n;i>pos;i--){
		sv[i]=sv[i-1];
	}
	printf("\nnhap thong tin cho sinh vien\n");
	
	printf("nhap ma sinh vien:\n");
	scanf("%d",&h.id);
	printf("nhap ten sinh vien:\n");
	fflush(stdin);
	gets(h.Name);
	printf("nhap ngay sinh cua sinh vien\n");
	fflush(stdin);
	gets(h.Ngay_sinh);
	printf("nhap dia chi cua sinh vien\n");
	fflush(stdin);
	gets(h.dia_chi);
	printf("nhap gioi tinh cho sinh vien\n");
	fflush(stdin);
	gets(h.gioi_tinh);
	printf("nhap que quan cua sinh vien\n");
	fflush(stdin);
	gets(h.que_quan);
	sv[pos]=h;
	(*n)++;
	printf("n sau khi tang:%d\n",*n);
//	In_DSLine(sv[pos],"MyFileWriter");
	
}
//ham xoa sinh vien
void DeleteStudent( int *n, int *pos){
	InDS("MyFileWriter");
	printf(" \nnhap vi tri muon xoa\n");
	scanf("%d",pos);
	if(*pos<0)
		*pos=0;
	if(*pos>*n){
		*pos=*n;
	}
	int i;
	for(i=*pos;i<(*n)-1;i++){
		sv[i]=sv[i+1];
	}
	(*n)--;
}
//ham sua thong tin sinh vien theo ma sinh vien
void changeInfo(SINHVIEN ch,int *msv,char filename [30]){
	InDS("MyFileWriter");
	printf("\nnhap ma sinh vien ban muon chinh sua\n");
	scanf("%d",msv);
	int i; 
	
		for(i=0;i<n;i++){
		if(*msv==sv[i].id){
			
			printf("sinh vien can chinh sua thong tin la\n");
			In_DSLine(sv[i],filename);
			printf("chinh sua thong tin\n");
			printf("Ma sinh vien\n");
			scanf("%d",&ch.id);
			printf("Ho va ten \n");
			fflush(stdin);
			gets(ch.Name);
			printf("ngay sinh cua sinh vien\n");
			fflush(stdin);
			gets(ch.Ngay_sinh);
			printf("dia chi cua sinh vien\n");
			fflush(stdin);
			gets(ch.dia_chi);
			printf("gioi tinh cho sinh vien\n");
			fflush(stdin);
			gets(ch.gioi_tinh);
			printf("que quan cua sinh vien\n");
			fflush(stdin);
			gets(ch.que_quan);
			sv[i]=ch;
			printf("thong tin sau khi chinh sua la\n");
			In_DSLine(sv[i],filename);
			
			
		}
	}

		
}
