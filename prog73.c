/*Author: Pratik Kenaudekar
Date Created: 12th March 2018
Date Modified: 12th March 2018
Program: WAP to display the records where student name starts with letter A
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
#include <sys/times.h>

void main()
{
	char name[20];
	int i,rollno,sub1,sub2,sub3,sub4;
	FILE *file1;
	file1=fopen("f1.txt", "r");
	if(file1==NULL)
	{
		perror("Error");
	}
	while(fscanf(file1, "%s %d %d %d %d %d",&name,&rollno,&sub1,&sub2,&sub3,&sub4)>0)
	{
		if(name[0]=='A')
		{
			printf("Name:%s Roll No:%d, Subject 1:%d, Subject 2:%d, Subject 3:%d, Subject 4:%d",name,rollno,sub1,sub2,sub3,sub4);
		}
	}
	
	fclose(file1);	
}

