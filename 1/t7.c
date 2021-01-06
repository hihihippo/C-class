#include <stdio.h>

int main(){
	int a[100];
	for (int i =0;i<1000;i++){
		int m = scanf("%d",&a[i]);
		if (m == EOF){
			return 0;
		}
		
		for (int j = 0;j<a[i];j++){
			
			printf("*");
		}
		printf("\n");

	}
	return 0;
}