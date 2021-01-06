#include<stdio.h>
#include<string.h>
#include <ctype.h>
#include<assert.h>

int main(int args, char *word[]){
	char arrtemp[128]={'\0'}; //128 because thats limit that were given \0 is the null sequence temp array
	int check=0;//used to check
	char end='\0'; //null sequence end is the null sequence
	char c= 'a'; //start and for EOF
	int i=0; // used for iteration
	while(c!=EOF){//iterates until EOF is hit
		c = getchar(); //gets string
		arrtemp[i]=c; // places  string into iteration
		i++;
		if (isalpha(c)==0 && c!='\''){ // checks to see if c is letters or not if it is letters comes as 0 if not then 1
			for(int i=1;i<args;i++){
				end=arrtemp[i-1];
				arrtemp[i]='\0';
				int result = strncmp(arrtemp,word[i],strlen(word[i]));
				if(result == 0){
					printf("CENSORED");
					printf("%c", end);
					check = 1;
				}
				else{
					if(check!=1 && i==args-1 && c!=EOF){
						printf("%s",arrtemp);
					}
				}
			}					
			for(int j=0;j<i;j++){
				arrtemp[j]='\0';
			}
			end='\0';
			i=0;
			check=0;
		}
	}
	return 0;
}
