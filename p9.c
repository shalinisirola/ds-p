#include<stdio.h>
#include<conio.h>

void dfs(int n, int a[10][10], int source, int s[10])
	{
	int i;
	s[source]=1;
	printf("%d\t", source);

	for(i=1;i<=n;i++){
		if( s[i] == 0 && a[source][i] == 1){
			dfs(n,a,i,s);
		}
	}
}

int main()
{
	int n,a[10][10],i,j,source,s[10];
	printf("Enter the Number of Nodes \n");
	scanf("%d",&n);

	printf("Enter the Adjacency Matrix \n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}

	printf("Enter the Source Node \n");
	scanf("%d",&source);

	for(i=1;i<=n;i++){
		s[i]=0;
	}

	printf("The DFS order is \n");
	dfs(n,a,source,s);

}
                                  

