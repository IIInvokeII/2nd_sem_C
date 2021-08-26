#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<math.h>
#include<sys/wait.h>
#include<stdlib.h>

void vowelcount()	//1st Child. Function is self-explanatory
{
	printf("\n\n1. Vowel Count. - 1st Child of Parent Process");
	char a[50];
	printf("\nEnter the string: ");
	scanf(" %[^\n]",a);
	int i=0,c=0;
	for(i=0;i<10;i++)
	{
		if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u' || a[i]=='A' || a[i]=='E' || a[i]=='I' || a[i]=='O' || a[i]=='U')
		{
			c++;
		}
	}
	printf("\nNo. of Vowels: %d",c);
	exit(0);	
//exits the child process. since child process has a copy of the rest of the main code, it will go on to invoke stringlength and armstrong here,
//and once again in the main function. So, we exit here to prevent extra output.
}

void armstrong()	//Grandchild. Function is self explanatory
{
	printf("\n\n3. Armstrong Number. - Child of 2nd Child Process");
	int num;
	printf("\nEnter the number: "); scanf("%d",&num);
	int temp=num,c=0,d=0;
	int sum=0;
	while(temp!=0)
	{
		temp=temp/10;
		d++;
	}
	temp=num;
	while(c<d)
	{
		int rem=temp%10;
		sum=sum+pow(rem,d);
		temp=temp/10;
		c++;
	}
	if(sum==num)
	{
		printf("\n%d is an armstrong number",num);
	}	
	else
	{
		printf("\n%d is NOT an armstrong number",num);
	}
	exit(0);
//same logic to exit here as above
}

void stringlength()	//2nd child of parent.
{
	printf("\n\n2. String Length. - 2nd Child of Parent Process");
	char str[50];
	printf("\nEnter the string: ");
	scanf(" %[^\n]",str);
	int len=strlen(str);
	printf("\nString length = %d",len);
	int pid3=fork();
	wait(NULL);
	if(pid3==0)
	{			
		armstrong();
	}
	else if(pid3==(-1))		
	{
		printf("\nArmstrong process not created");
	}
	_exit(0);
//_exit(0) is a system call and is different from exit(0). This is a complete exit, meaning the execution will stop here.
//I tried with just exit(0) here, but the output repeats yet again. 
}

int main()
{
	int pid1=fork();
	wait(NULL);
	if(pid1==0)
	{
		vowelcount();
	}
	else if(pid1==(-1))
	{
		printf("\nVowelcount process not created.");
	}
	int pid2=fork();
	wait(NULL);
	if(pid2==0)
	{
		wait(NULL);
		stringlength();
	}
	else if(pid2==(-1))
	{
		printf("\nstringlength process not created");
	}
	_exit(0);
	return 0;
}
