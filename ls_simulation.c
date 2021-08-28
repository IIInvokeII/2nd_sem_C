#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>

void ls(char *dir, char *option, int depth)
{
	struct dirent *curdir;	//Directory Entry structure, which has info about the directory like the name
	DIR *iter;	//Pointer of type DIR used to traverse through directories
	iter = opendir(dir);	//assignment of initial directory
	if(iter==NULL)	//error handling
	{
		printf("\nError, could not access directory.");
	}
	else
	{
		while( (curdir = readdir(iter)) != NULL)	//read the directory and return its information
		{
			if(strcmp("-R",option)==0)	//If user has chosen to use the "-R" option 
			{
				char *curdirname = (char*)malloc(strlen(curdir->d_name)*sizeof(char));
				curdirname = curdir->d_name;
				if(curdirname[0]=='.')	
					continue;
				//checking for hidden files and skipping them, since they are not needed for recursive output
				printf("\n");
				for(int i=0;i<depth;i++)
				{
					printf("----|");
				}
				printf("%s",curdir->d_name);
				DIR *temp;
				char *next = (char*)malloc((strlen(dir) + strlen(curdir->d_name) + 2)*sizeof(char));
				next[0]='\0';
				strcat(next,dir); strcat(next,curdir->d_name); strcat(next,"/");
				//setting up the subdirectory path for recursively calling the ls command for that
				temp = opendir(next);
				if(temp!=NULL)	//if the subdirectory is not empty, it will display its contents
				{
					ls(next,option,depth+1);
				}
				free(next);	//freeing the string next that will hold the next subarray.
			}
			else if(strcmp("-a",option)==0)	// if the user has chosen "-a" option
			{
				printf("\n");
				for(int i=0;i<depth;i++)
				{
					printf("----|");
				}
				printf("%s",curdir->d_name);
			}
			else	// if the user has given the default option
			{
				char *curdirname = (char*)malloc(strlen(curdir->d_name)*sizeof(char));
				curdirname = curdir->d_name;
				if(curdirname[0]=='.')
					continue;
				//checking for hidden files and skipping them, since they are not needed for recursive output
				printf("\n");
				for(int i=0;i<depth;i++)
				{
					printf("----|");
				}
				printf("%s",curdir->d_name);
			}
		}
	}
}

int main(int argc, char *argv[])
{
	if(argc<3)
	{
	//This is the case of just "ls" = "./a.out /home/kali/". 
	//The simple ls command output without hidden files or recursion. 
		ls(argv[1],"",0);
	}
	else
	{
	//This covers the case of "ls -a" = "./a.out /home/kali/ -a" (all files output)
	//and
	//"ls -R" = "./a.out /home/kali/ -R" (recursive output)
		ls(argv[1],argv[2],0);
	}
	return 0;
}
