#include <stdio.h>
#include <limits.h>

int main(){
printf("No of machines and task:");
int vm,tsk;
scanf("%d%d",&vm,&tsk);
int array[vm][tsk],temp[vm][tsk];
printf("Enter the details of all the tasks machine by machine:\n");
for (int i=0;i<vm;i++)
{	
		printf("Enter the details of all the task  of machine %d:",i+1);
		for (int j=0;j<tsk;j++){
			scanf("%d",&array[i][j]);
			temp[i][j]=array[i][j];
			}
}
int machine[vm],task[tsk],result[3][tsk];
printf("The details are as follow:\n");
for (int i=0;i<vm;i++){printf("VM%d: ",i+1);
	for (int j=0;j<tsk;j++)
		printf("%d .  ",array[i][j]);
	printf("\n");}
	
int nTask=0;	
while(nTask<tsk){
	int mac,index;
	for (int i=0;i<vm;i++)
	{	int min=INT_MAX;
			for (int j=0;j<tsk;j++)
			{
				if (min>temp[i][j])
				{
					min=temp[i][j];
					index=j;
					mac=i;
				}
				
			}
			for (int k=0;k<tsk;k++)
				temp[mac][k]+=min;
			for (int k=0;k<vm;k++)
				temp[k][index]=INT_MAX;
			if (nTask<=tsk){
				result[0][nTask]=mac+1;
				result[1][nTask]=index+1;
				result[2][nTask++]=min;}
			else
				break;
			
	}
	
}

printf("The scheduled Task are as follow:\nMachine\tTask\tFinishTime\n");
	for (int i=0;i<tsk;i++)
		printf("%d \t%d \t%d \n",result[0][i],result[1][i],result[2][i]);






return 0;}
