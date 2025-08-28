#include<stdio.h>

void main()
{
int x,y,z;
printf("X\tY\tZ\tXY+Z");

for(x=0;x<=1;++x)
for(y=0;y<=1;++y)
for(z=0;z<=1;++z)
{
if(x*y+z==2)
printf("\n%d\t%d\t%d\t1",x,y,z);
else
printf("\n%d\t%d\t%d\t%d",x,y,z,x*y+z);
}
}
