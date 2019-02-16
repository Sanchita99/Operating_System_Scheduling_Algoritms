#include<stdio.h>
#include<limits.h>

int main()
{
	
	int n,i,j,m,min=INT_MAX,c=0;
	float av_wt=0;
	float av_tat=0;
	
	printf("Enter number of processes\n");
	scanf("%d",&n);
	
	int a[n],b[n],ct[n],bt[n],tat[n],wt[n],ac[n];
	
	printf("Enter arrival time\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		ac[i]=a[i];
		b[i]=i;
		if(min>a[i])
			min=a[i];
	}
	
	printf("Enter burst time\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&bt[i]);
	}
	
	printf("Order:\n");
	
	if(min!=0)
	{
		printf("|idle for %d sec| ",min);
		c=min;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i]<a[j])
			{
				m=a[i];
				a[i]=a[j];
				a[j]=m;
				
				m=b[i];
				b[i]=b[j];
				b[j]=m;
			}
		}
	}
	
	for(i=0;i<n;i++)
	printf("%d ",b[i]+1);
	printf("\n");
	
	for(i=0;i<n;i++)
	{
		if(ct[b[i-1]]<ac[b[i]])
			{
				c=ac[b[i]]-ct[b[i-1]]+c;
			//	printf("idle for %d sec\n as ac is %d and ct is %d and c is %d\n",ac[p[z]]-ct[p[z-1]],ac[p[z]],ct[p[z-1]],c);
				printf("|idle for %d sec| ",ac[b[i]]-ct[b[i-1]]);		
			}
			//printf("%d ",b[i]+1);

		ct[b[i]]=bt[b[i]]+c;
		c=ct[b[i]];
		tat[b[i]]=ct[b[i]]-ac[b[i]];
		wt[b[i]]=tat[b[i]]-bt[b[i]];

	}
	
	printf("\n");
		
	printf("Process\tArrival Time\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n");
	
	for(i=0;i<n;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n",i+1,ac[i],bt[i],ct[i],tat[i],wt[i]);
	}
	
	for(i=0;i<n;i++)
	{
		av_tat=tat[i]+av_tat;
		av_wt=wt[i]+av_wt;
	}
	printf("avg tat : %f \n avg wt : %f",(av_tat/n),(av_wt/n));
	
	return 0;
}
