#include <stdio.h>
#include <math.h>

char check(int n, int arr[n][n], int i, int j){
	if(arr[i][j]==0){
		return 'Y';
	}
	else{
		return 'N';
	}
}
	

void next(int no, int n, int i, int j, int arr[n][n]){
	if(i>2)	i%=3;
	if(j>2)	j%=3;
	if(i<0 && i%3==-1)	i=2;
	if(i<0 && i%3==-2)	i=1;
	if(i<0 && i%3==0)	i=0;
	if(check(n, arr, i ,j)=='Y'){
		arr[i][j]= no;
		next(no++, n, i--, j++, arr);
	}
	else{
		arr[i+1][j-2]=no;
		next(no++, n, i-1, j+1, arr);
	}
}

void initialize( int n,int arr[n][n]){
	int i,j, no=1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			arr[i][j]=0;
		}
	}
	i=n/2; j=n-1;
	arr[i][j]=no;
	
	no++;
	next(no, n, i--, j++, arr);
}

int magicSquare(int n){
	n=(n*((n*n)+1))/2;
	return n;
}

void printArr(int n , int arr[n][n]){
	int i,j;
	for(i=0;i<n;i++){
			int count=1;
			for(j=0;j<n;j++){
				count++;
				printf("%d ",arr[i][j]);
				if(count==4)	printf("\n");
			}
	}
}

int main(){
	int n;
	scanf("%d",&n);
	int arr[n][n];
	
	int magicNumber = magicSquare(n);
	printf("Magic Number is %d\n",magicNumber);
	
	initialize(n,arr);
	
	printArr(n, arr);
	
	return 0;
}
