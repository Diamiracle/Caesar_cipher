/************************************************************************/  
/*caeser.c 
/* ���������ǰ������ַ�������ͬ��λ��������ƶ� 
/*��������can��λ����Ϊ3������Ϊfdq 
/*���������Ӣ����ĸ��������Ч 
/************************************************************************/  
#include<stdio.h>  
#include<stdlib.h>  
#include<string.h>
#define ITEM 2  
void encipher();  
void decipher();  
int main()  
{  
    int flag;  
    void (*menu[ITEM])()={encipher,decipher};  
      
	while (true)
	{
		printf("�����ļ�����1\n");  
		printf("�����ļ�����2\n");  
		printf("�˳����򡪡�0\n");
		scanf("%d",&flag);  
		if(!flag)  
			exit(1);  
		else if(flag==1||flag==2)  
			menu[flag-1](); 
		else
			exit(1);
	}
     
          
    
    return 0;  
}  
void encipher()  
{  
	int key;  
    char ch,c;  
    char str[1024];  
	char cipher[1024];
    FILE *infile,*outfile;  
    printf("�����������ַ�����");  
    scanf("%s",str);  
    printf("���������Կ��");  
    scanf("%d",&key);  
	int i;
	for(i=0;i<strlen(str);i++){
		char ch=str[i];
		if(ch>=48&&ch<=57)//���ּ���  
        {  
            c=((ch-48)+key)%10;  
            cipher[i]=c+48;  
        }  
        else if(ch>=65&&ch<=90)//��дӢ����ĸ����  
        {  
            c=((ch-65)+key)%26;  
            cipher[i]=c+65;   
        }  
        else if(ch>=97&&ch<=122)//СдӢ����ĸ����  
        {  
            c=((ch-97)+key)%26;  
            cipher[i]=c+97;   
        }  
        else  
            cipher[i]=ch;   
	}
	cipher[i]=0x00;
	printf("����: %s\n",cipher);

}  
void decipher()  
{  
	int key;  
    char ch,c;  
    char str[1024];  
	char plain[1024];
    FILE *infile,*outfile;  
    printf("��������ַ�����");  
    scanf("%s",str);  
	printf("input is %s\n",str);
	while(1){
		printf("���������Կ-��0�˳���");  
		scanf("%d",&key); 
		if(key==0) return;
		int i;
		for(i=0;i<strlen(str);i++){
			char ch=str[i];
			if(ch>=48&&ch<=57)//���ֽ���  
			{  
				c=((ch-48)-key+10)%10;//�˴�+10�Ƿ�ֹ��c==����  
				plain[i]=c+48;  
			}  
			else if(ch>=65&&ch<=90)//��дӢ����ĸ����  
			{  
				c=((ch-65)-key+26)%26;  
				plain[i]=c+65;   
			}  
			else if(ch>=97&&ch<=122)//СдӢ����ĸ����  
			{  
				c=((ch-97)-key+26)%26;  
				plain[i]=c+97;   
			}  
			else  
				plain[i]=ch;   
		}
		plain[i]=0x00;
		printf("���ģ� %s\n",plain);
	}

}  