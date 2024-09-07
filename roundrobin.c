#include <stdio.h>
#include<limits.h>
typedef struct process {
int id,at,bt,tat,wt,x,rt,res;
}pro;
void main(){
int n,comp=0,tq,i,small,sat;
float x=0,y=0;
printf("Enter No of processes and Time Quantum=");
scanf("%d %d",&n, &tq);

pro p[n];
for(i=0;i<n;i++){
	printf("Enter AT and BT of %d:-",i);
	scanf("%d %d",&p[i].at,&p[i].bt);
	p[i].id=i;
	p[i].x=p[i].at;
	p[i].rt=p[i].bt;
	p[i].res=-1;
}

for(int j=n-2;j>=0;j--)// To sort ussing arrival times.
	for(i=0;i<=j;i++)
		if(p[i].at>p[i+1].at){
		pro	temp=p[i];
			p[i]=p[i+1];
			p[i+1]=temp;
		}
small=0;
sat=small;
for (int time=0;comp!=n;){int m;
	for (i=0;i<n;i++)
		if(p[i].x<=time && p[i].rt &&p[small].x >p[i].x )
			small=i;
	if (p[small].res<0) p[small].res=time-p[small].at;
	if (p[small].rt>=tq)	m=tq;
	else m=p[small].rt;
	p[small].rt-=m;
	time+=m;

	
for (i=0;i<n;i++)
		if(p[i].x<=time && p[i].rt && p[sat].x<p[i].x)
				sat=i;
				
if (sat!=small) p[small].x=p[sat].x+1;

		
printf("|P%d| ",p[small].id);
	if (p[small].rt==0){
		comp++;
		p[small].tat=time-p[small].at;
		p[small].wt=p[small].tat-p[small].bt;
		x+=p[small].tat;
		y+=p[small].wt;
		p[small].x=INT_MAX;
	}
}
printf("\npid\tat\tbt\ttat\twt\trt\n");
for (i=0;i<n;i++)
printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i].id,p[i].at,p[i].bt,p[i].tat,p[i].wt,p[i].res);
printf("Avg WT=%f and TAT=%f\n",y/n,x/n);
}
