#include <stdio.h>
#include <math.h> 
int main()
{ 
int n, x;
int s=0;
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
scanf("%d",&x);
int a=pow(x,2);
s=s+(i%2)*a;
}
printf("%d",s);
return 0;
}
