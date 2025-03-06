#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int P[MAX];
void main()
{
    int n,p,f;
    printf("Enter the number of request:");
    scanf("%d",&n);
    printf("Enter the request order:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&P[i]);
    }
    printf("Enter the intial position:\n");
    scanf("%d",&p);
    printf("Enter the final position:\n");
    scanf("%d",&f);

    printf("----------------------Disk scheduling Algorithms--------------------\n\n");
    fcfs(p,n);
    printf("---------------------------------------------------------------------\n\n");
    scan(p,n,f);
    printf("---------------------------------------------------------------------\n\n");
    cscan(p,n,f);
    printf("---------------------------------------------------------------------\n\n");
}
void fcfs(int p,int n)
{
    printf("First Come First Serve SCHEDULING\n\n");
    printf("Pattern:\n");
    int stime,j=1,i=0;
    stime=P[0]-p;
    printf("From %d to %d\n",p,P[0]);
    for(int i=1;i<n;i++)
    {
            printf("From %d to %d\n",P[i-1],P[i]);
            stime=stime+abs(P[i]-P[i-1]);
    }
    printf("\nThe seek time: %d\n\n",stime);
}
void scan(int p,int n,int f)
{
    int a[MAX],b[MAX];
    printf("SCAN SCHEDULING\n");
    printf("Direction of head : right to left\n");
    printf("pattern:\n");
    int stime,j=1,i=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(P[i]>P[j])
            {
              int temp=P[i];
              P[i]=P[j];
              P[j]=temp;
            }
        }
    }
    int k=0,l=0;
    for(int i=0;i<n;i++)
    {
        if(P[i]>p)
        {
            a[k++]=P[i];
        }
        else
        {
            b[l++]=P[i];
        }
    }
    stime=a[0]-p;
    printf("From %d to %d\n",p,a[0]);
    int x;
    for(x=1;x<k;x++)
    {
        printf("From %d to %d\n",a[x-1],a[x]);
        stime+=abs(a[x]-a[x-1]);
    }
    stime=stime+abs(f-a[x-1]);
    printf("From %d to %d\n",a[x-1],f);
    int y;
    stime+=abs(f-b[l-1]);
    printf("From %d to %d\n",f,b[l-1]);
    for(y=l-1;y>0;y--)
    {
        printf("From %d to %d\n",b[y],b[y-1]);
        stime+=abs(b[y]-b[y-1]);

    }
    printf("\nThe seek time: %d\n\n",stime);
}
void cscan(int p,int n,int f)
{
    int a[MAX],b[MAX];
    printf("C-SCAN SCHEDULING\n");
    printf("Direction of head : right to left\n");
    printf("pattern:\n");
    int stime,j=1,i=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(P[i]>P[j])
            {
              int temp=P[i];
              P[i]=P[j];
              P[j]=temp;
            }
        }
    }
    int k=0,l=0;
    for(int i=0;i<n;i++)
    {
        if(P[i]>p)
        {
            a[k++]=P[i];
        }
        else
        {
            b[l++]=P[i];
        }
    }
    stime=a[0]-p;
    printf("From %d to %d\n",p,a[0]);
    int x;
    for(x=1;x<k;x++)
    {
        printf("From %d to %d\n",a[x-1],a[x]);
        stime+=abs(a[x]-a[x-1]);
    }
    stime=stime+abs(f-a[x-1]);
    printf("From %d to %d\n",a[x-1],f);
    int y;
    stime+=abs(f-0);
    printf("From %d to %d\n",f,0);
    stime+=abs(0-b[0]);
    printf("From %d to %d\n",0,b[0]);
    for(y=1;y<l;y++)
    {
        printf("From %d to %d\n",b[y-1],b[y]);
        stime+=abs(b[y]-b[y-1]);

    }
    printf("\nThe seek time: %d\n\n",stime);
}
