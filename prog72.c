/*Author: Pratik Kenaudekar
Date Created: 12th March 2018
Date Modified: 12th March 2018
Program: WAP to store the student details consisting of Name, Roll No, Marks in 4 subject
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
	file1 = fopen ("f1.txt", "w");
	printf("\nEnter 4 students details\n");
	for(i=0;i<4;i++)
	{
		printf("\nFor Student number %d:",i+1);
		printf("\nName:");
		scanf("%[^\n]s",name);
		printf("Roll No:");
		scanf("%d",&rollno);
		printf("Subject 1 marks:");
		scanf("%d",&sub1);
		printf("Subject 2 marks:");
		scanf("%d",&sub2);
		printf("Subject 3 marks:");
		scanf("%d",&sub3);
		printf("Subject 4 marks:");
		scanf("%d",&sub4);
		fprintf(file1, "%s %d %d %d %d %d\r\n",name,rollno,sub1,sub2,sub3,sub4);
		getchar();
	}
	fclose(file1);	
}

