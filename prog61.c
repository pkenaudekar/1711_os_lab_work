/*Author: Pratik Kenaudekar
Date Created: 19th February 2018
Date Modified: 19th February 2018
Program: WAP to perform following operations
-Accept n numbers from user
-In Parent Process, display the number in ascending order
-In Child Process displays the number in descending order
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <utime.h>
#include <sys/wait.h>
void main()
{
	int pid;
	int status,size;
    int num[50], i, j,temp;
	printf("\nEnter the number of elements to be inserted in an array:");
	scanf("%d",&size);
	printf("\nEnter %d number in the array:",size);
	for(i=0;i<size;i++)
	{
		scanf("%d",&num[i]);
	}
	
	pid=fork();
	if(pid<0)
    {
        printf("\n Error ");
        exit(1);
    }
    else if(pid==0)
    {
		printf("\n-------------Under Child Process-------------\n");
        printf("\nThe number in desending order:\n");
		for (i = 0; i < size-1; i++)
		{			
			for (j = 0; j < size-i-1; j++)
			{				
				if (num[j] < num[j+1])
				{
					temp = num[j];
					num[j] = num[j+1];
					num[j+1] = temp;
				}
			}
		}
		for(i=0;i<size;i++)
		{
			printf("%d ",num[i]);
		}
		printf("\n----------------------------------------------\n");
		exit(1);
	}
    else
    {
		wait(&status);
		printf("\n-------------Under Parent Process-------------\n");
       	printf("\nThe number in ascending order:\n");
		
		for (i = 0; i < size-1; i++)
		{			
			for (j = 0; j < size-i-1; j++)
			{				
				if (num[j] > num[j+1])
				{
					temp = num[j];
					num[j] = num[j+1];
					num[j+1] = temp;
				}
			}
		}
			
		for(i=0;i<size;i++)
		{
			printf("%d ",num[i]);
		}
		printf("\n----------------------------------------------\n");
        exit(1);
    }
   
}

