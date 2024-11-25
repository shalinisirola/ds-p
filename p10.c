#include<math.h>
#include<stdio.h>

int main()
{
int n , m , a[100], loc, i, key, newloc;

printf(" Enter the number( < 05) of elements to store \n");
scanf("%d", &n);

printf(" Enter the m value, h(k) = k mod m \n");       
scanf("%d", &m); 
        
for(i=0; i<=10; i++)
a[i] = -999;

for(i=1; i<=n; i++)
{
printf(" Enter the key value to be stored \n");
scanf("%d", &key);

loc = key % m;

if(a[loc] == -999)
a[loc] = key;
else
{
newloc = loc+1;

while(a[newloc] != -999 && newloc<=10)
newloc= newloc+1;

a[newloc] = key;
}
}

printf(" The keys in Hashed location are \n");
for(i=0; i<=10; i++)
printf("a[%d] === >> %d\n", i, a[i]);

}
/*
Enter the number ( < 05) of elements to store
 5
 Enter the m value, h(k) = k mod m
 11
 Enter the key value to be stored
 34
 Enter the key value to be stored
 36
 Enter the key value to be stored
 79
 Enter the key value to be stored
 81
 Enter the key value to be stored
 56
 The keys in Hashed location are
 a[0] === >> -999
 a[1] === >> 34
 a[2] === >> 79
 a[3] === >> 36
 a[4] === >> 81
 a[5] === >> 56
 a[6] === >> -999
 a[7] === >> -999
 a[8] === >> -999
 a[9] === >> -999
 a[10] === >> -999
*/

