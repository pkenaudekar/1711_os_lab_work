/*Author: Pratik Kenaudekar
Date Created: 4th October 2017
Date Modified: 4th October 2017
Program: WAP to replace all the occurrence of a given word with another word.

*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include<string.h>

void main(int argc, char *argv[])
{
	int i=0,j,count = 0;
	ssize_t bytes_read;
	char buff[1000],temp[1000], *pch;
	if(argc !=4)
	{
		write(1,"\nInvalid no of arguments\nusage: ./prog13.exe filename1 serchfor replacewith",100);
		exit(-1);
	}
	int file1 = open(argv[1], O_RDONLY);
	int file2 = open("temp.txt", O_RDWR | O_CREAT );
	if (file1 < 0) 
	{
		perror("error");
		exit(1);
	}
	bytes_read = read(file1, buff, sizeof(buff));
	while(1)
	{
		pch = strstr (buff,argv[2]);
		if(pch)
		{
			strncpy (pch,argv[3],strlen(argv[3]));
			
			printf("\n%s",buff);
		}
		else 
		{
			break;
		}		 
	}
	
	stpcpy(temp,buff);
	close(file1);
	write(file2, temp,strlen(temp));	
	close(file2);
	exit(0);
}
