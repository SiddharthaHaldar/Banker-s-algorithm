#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
	float x;
	float y;
	int cat;
	float dist;
};

int knn(Point a[],Point p,int k){
	int n = sizeof(a)/sizeof(a[0]);
	for(int x=0;x<n;x++)
	{
		a[x].dist = sqrt((a[x].x - p.x) * (a[x].x - p.x) + (a[x].y - p.y) * (a[x].y - p.y));
	}
	for(int x=0;x<=n-1;x++)
	{
		for(int y=0;y<=x-1;y++)
		{
			if(a[y].dist>a[y+1].dist){
				Point temp=a[y];
				a[y]=a[y+1];
				a[y+1]=temp;
			}
		}
	}
	int freq1,freq2;
	while(true)
	{
    freq1=0,freq2=0;
	for(int x=0;x<k;x++)
	{
		if(a[x].cat==0)
			freq1+=1;
		else
			freq2+=1;		
	}
 	if(freq1==freq2)
 		k+=1;
    else
    	break;
 }
   return (freq1>freq2?0:1);
}

int main()
{
	int n = 17; // Number of data points
    Point arr[n];
 
    arr[0].x = 1;
    arr[0].y = 12;
    arr[0].cat = 0;
 
    arr[1].x = 2;
    arr[1].y = 5;
    arr[1].cat = 0;
 
    arr[2].x = 5;
    arr[2].y = 3;
    arr[2].cat = 1;
 
    arr[3].x = 3;
    arr[3].y = 2;
    arr[3].cat = 1;
 
    arr[4].x = 3;
    arr[4].y = 6;
    arr[4].cat = 0;
 
    arr[5].x = 1.5;
    arr[5].y = 9;
    arr[5].cat = 1;
 
    arr[6].x = 7;
    arr[6].y = 2;
    arr[6].cat = 1;
 
    arr[7].x = 6;
    arr[7].y = 1;
    arr[7].cat = 1;
 
    arr[8].x = 3.8;
    arr[8].y = 3;
    arr[8].cat = 1;
 
    arr[9].x = 3;
    arr[9].y = 10;
    arr[9].cat = 0;
 
    arr[10].x = 5.6;
    arr[10].y = 4;
    arr[10].cat = 1;
 
    arr[11].x = 4;
    arr[11].y = 2;
    arr[11].cat = 1;
 
    arr[12].x = 3.5;
    arr[12].y = 8;
    arr[12].cat = 0;
 
    arr[13].x = 2;
    arr[13].y = 11;
    arr[13].cat = 0;
 
    arr[14].x = 2;
    arr[14].y = 5;
    arr[14].cat = 1;
 
    arr[15].x = 2;
    arr[15].y = 9;
    arr[15].cat = 0;
 
    arr[16].x = 1;
    arr[16].y = 7;
    arr[16].cat = 0;
 
    /*Testing Point*/
    Point p;
    p.x = 2.5;
    p.y = 7;
    
    int k=3;
    int c=knn(arr,p,k);
    cout << "This point belongs to class:";
    cout << c;
    return 0;
}
