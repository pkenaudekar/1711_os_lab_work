/*Author: Pratik Kenaudekar
Date Created: 4th October 2017
Date Modified: 4th October 2017
Program: Write a C program that takes 2 file names as arguments and 2 possible options
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include <malloc.h>
#include <fcntl.h>
#include <unistd.h>

void main(int argc, char *argv[])
{
	int i=0,j,lines=0,bytes_read,lineno;
	char buff[1000],trans1[1000],trans2[1000];
	if(argc < 3 || argc > 4)
	{
		write(1,"\nInvalid no of arguments\nusage: ./prog8.exe [s/c] filename1 filename2",69);
		exit(-1);
	}
	if(strcmp(argv[1],"s")==0)
	{
		int file1 = open(argv[2], O_RDONLY);
		if (file1 < 0) 
		{
			perror("error");
			exit(1);
		}
		int file2 = open(argv[3], O_WRONLY | O_CREAT);
		int file3 = open("temp.txt", O_WRONLY | O_CREAT | O_TRUNC);
		while (bytes_read = read(file1, buff, sizeof(buff))) 
		{
			for (i=0; i<bytes_read; i++)
			{
				if (buff[i] == '\n')
				{
					++lines;
				}
			}
		}
		
		lineno=lines/2;
		lines=0;
		i=j=0;
		while(i<strlen(buff))
		{
			if (buff[i] == '\n')
			{
				++lines;
			}
			if(lines<=lineno)
			{
				trans1[i]=buff[i];
			}	
			else
			{
				trans2[j]=buff[i];
				j++;
			}
			i++;
		}
		write(file2, trans2,strlen(trans2));	
		close(file2);
		write(file3, trans1,strlen(trans1));	
		close(file3);
		remove(argv[2]);
		rename("temp.txt", argv[2]);
		write(1, "\nFile split successfully",24);		
		printf("\nbuff: %s",buff);
		printf("\ntrans1: %s",trans1);
		printf("\ntrans2: %s",trans2);
		exit(-1);
	}
	else if(strcmp(argv[1],"c")==0)
	{
	}
	else
	{
		write(1,"\nInvalid input\nusage: ./prog8.exe [s/c] filename1 filename2",60);
		exit(-1);
	}
}
