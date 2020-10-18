#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Display_array_from_pointer(char *ptr,int h,int w)          
{
	int i,l;
	for( i=0;i<h;i++)
	{
		for(l=0;l<w;l++)
		{
			
			printf("| %c ",*(ptr+(i*w)+l));
		}
		printf("|\n");
	}
	printf("\n\n\n");
}

int *sifreleme(char *ptr_key,int key_w,char *ptr_msg)
{
	int buldu=0;
	int i,l,*ptr_sifreli;
	ptr_sifreli=(int *) malloc (strlen(ptr_msg)*sizeof(int));
	
	for(i=0;i<strlen(ptr_msg);i++)
	{
		buldu=0;
		for(l=0;l<strlen(ptr_key);l++)
		{
			if(*(ptr_key+l)==*(ptr_msg+i))
			{
				*(ptr_sifreli+i)=(l%key_w)+10*((l-(l%key_w))/key_w)+11;
				buldu=1;
				break;
			}
		}
		if(buldu==0) *(ptr_sifreli+i)=-1;
	}
	return ptr_sifreli;
}

char *matrisolustur(int satirsayisi,int sutunsayisi)
{
	char kova,*ptr_matris;
	int i;
	ptr_matris= (char *) malloc (satirsayisi*sutunsayisi*sizeof(char));
	
	for(i=0;i<satirsayisi*sutunsayisi;i++)
	{
		*(ptr_matris+i)='*';
		
	}
	Display_array_from_pointer(ptr_matris,satirsayisi,sutunsayisi);
	printf("please use the letters in the alphabet you have created.\n\n");
	for(i=0;i<satirsayisi*sutunsayisi;i++)
	{
		
		printf("YOUR LETTERS FOR ENCRYPTION:\n\n\n");
		scanf("%c",&kova);
		getchar();
		printf("\n");
		*(ptr_matris+i)=kova;
		Display_array_from_pointer(ptr_matris,satirsayisi,sutunsayisi);	
	}
	return ptr_matris;
}
	main()
{
	char *ptr_key,*ptr_msg;
	int satirsayisi,sutunsayisi,i,*ptr_sifreli;
	printf("NUMBER OF ROW:\n");
	scanf("%d",&satirsayisi);
	getchar();
	printf("NUMBER OF COLUMN:\n");
	scanf("%d",&sutunsayisi);
	getchar();
	ptr_key=matrisolustur(satirsayisi,sutunsayisi);
	
	ptr_msg=(char *) malloc (100*sizeof(char));
	printf("YOUR TEXT:\n");
	gets(ptr_msg);
	ptr_sifreli=sifreleme( ptr_key, sutunsayisi, ptr_msg);
	for( i=0;i<50;i++)
	{
		if(*(ptr_msg+i)=='\0')
		{
			break;
		}
		printf("%d ", *(ptr_sifreli+i));
	}
	
}
