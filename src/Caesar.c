/************************************************************************/  
/*caeser.c 
/* 凯撒密码是把明文字符按照相同的位移量向后移动 
/*比如明文can，位移量为3，密文为fdq 
/*本程序仅对英文字母和数字有效 
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
		printf("加密文件——1\n");  
		printf("解密文件——2\n");  
		printf("退出程序——0\n");
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
    printf("输入欲加密字符串：");  
    scanf("%s",str);  
    printf("输入加密密钥：");  
    scanf("%d",&key);  
	int i;
	for(i=0;i<strlen(str);i++){
		ch=str[i];
		if(ch>=48&&ch<=57)//数字加密  
        {  
            c=((ch-48)+key)%10;  
            cipher[i]=c+48;  
        }  
        else if(ch>=65&&ch<=90)//大写英文字母加密  
        {  
            c=((ch-65)+key)%26;  
            cipher[i]=c+65;   
        }  
        else if(ch>=97&&ch<=122)//小写英文字母加密  
        {  
            c=((ch-97)+key)%26;  
            cipher[i]=c+97;   
        }  
        else  
            cipher[i]=ch;   
	}
	cipher[i]=0x00;
	printf("密文: %s\n",cipher);

}  
void decipher()  
{  
	int key;  
    char ch,c;  
    char str[1024];  
	char plain[1024];
    FILE *infile,*outfile;  
    printf("输入解密字符串：");  
    scanf("%s",str);  
	printf("input is %s\n",str);
	while(1){
		printf("输入解密密钥-或0退出：");  
		scanf("%d",&key); 
		if(key==0) return;
		int i;
		for(i=0;i<strlen(str);i++){
			ch=str[i];
			if(ch>=48&&ch<=57)//数字解密  
			{  
				c=((ch-48)-key+10)%10;//此处+10是防止，c==负数  
				plain[i]=c+48;  
			}  
			else if(ch>=65&&ch<=90)//大写英文字母解密  
			{  
				c=((ch-65)-key+26)%26;  
				plain[i]=c+65;   
			}  
			else if(ch>=97&&ch<=122)//小写英文字母解密  
			{  
				c=((ch-97)-key+26)%26;  
				plain[i]=c+97;   
			}  
			else  
				plain[i]=ch;   
		}
		plain[i]=0x00;
		printf("明文： %s\n",plain);
	}

}  