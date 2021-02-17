#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void main(){
	char *str,*new;
	int n,i,j,cnt;
	printf("\n enter how many characters...\n");
	scanf("%d",&n);
	str=(char *)malloc(n*sizeof(char));
	new=(char *)malloc(n*sizeof(char));
	printf("Enter String Of %d Characters....",n);
	gets(str);
	for(i=0;i<n;i++){
	scanf("%c",&str[i]);
	}
	str[i]='\0';
	printf("\n Len=%d i=%d",n,i);
	for(i=0,j=0;i<n;i++){
		if((str[i]<65 && str[i]>90) || (str[i]<97 && str[i]>122)){
			new[j++]=str[i];
		}
		else{
			cnt=0;
			while((str[i]<65 && str[i]>90) || (str[i]<97 && str[i]>122)){
				
			}
		}
	}
	
}