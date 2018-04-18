#include<stdio.h>

int p=5,r=3,x,y;

int proc[] = {0, 1, 2, 3, 4}; 
    // Available instances of resources
    int avail[3] = {3, 3, 2};
 
    // Maximum R that can be allocated
    // to processes
    int max[5][3] = {{7, 5, 3},
                     {3, 2, 2},
                     {9, 0, 2},
                     {2, 2, 2},
                     {4, 3, 3}};
 
    // Resources allocated to processes
    int allot[5][3] = {{0, 1, 0},
                      {2, 0, 0},
                      {3, 0, 2},
                      {2, 1, 1},
                      {0, 0, 2}};   
		   
int safety(int avail[],int pro[])
{
	int need[5][3];
	int comp[5]={0,0,0,0,0};
	int safeseq[5];
	int c=0;
	for(x=0;x<p;x++)
	{
		for(y=0;y<r;y++)
		{
			need[x][y]=max[x][y]-allot[x][y];
		}
	}
	while(c<p){
		for(x=0;x<p;x++)
		{
			if(comp[x]==0){
				int flag=1;
				for(y=0;y<r;y++){
					if(need[x][y]>avail[y])
					{ flag=0;
					  break;
					}
				 }
				 if(flag==1){
				    comp[x]=1;
					safeseq[c]=x;
					c+=1;
					for(y=0;y<r;y++){
					   avail[y]=avail[y]+allot[x][y];  
				    }	
				 }
			}
		}
	}
for(x=0;x<5;x++)
{
	printf("%d ",safeseq[x]);
}
return 0;
}
int main()
{
	safety(avail,proc);
	return 0;
}
