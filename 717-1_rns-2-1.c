#include <stdio.h>
#include <math.h> 
int main()
{ 
int n, x;
int k=0;
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
scanf("%d",&x);
if(x>=0) 
k++;
}
printf("%d",k);
return 0;
}
