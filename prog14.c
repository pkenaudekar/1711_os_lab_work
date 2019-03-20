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
	int i=0,j=0,count = 0,k = 0,n = 0,flag = 0;
	ssize_t bytes_read;
	char buff[1000],temp[1000], *pch, new[1000], word[100];
	if(argc !=3)
	{
		write(1,"\nInvalid no of arguments\nusage: ./prog13.exe filename1 serchfor",100);
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
	stpcpy(word,argv[2]);
	/*while(1)
	{
		pch = strstr (buff,argv[2]);
		if(pch)
		{
			strncpy (pch,"$",1);
			
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
	exit(0);*/
	for(i = 0 ; buff[i] != '\0' ; i++)
    {
        k = i;     
        while(buff[i] == word[j])
        {
            i++,j++;
            if(j == strlen(word))
            {
                flag = 1;
                break;
            }
        }
		j = 0;
		if(flag == 0)
			i = k;      
		else
			flag = 0;

		new[n++] = buff[i];
    }
    new[n] = '\0';
	printf("\n%s",new);
	close(file1);
	write(file2, new,strlen(new));	
	close(file2);
	exit(0);
}
