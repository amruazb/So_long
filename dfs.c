#include <stdio.h>
#include <stdlib.h>

int visited[4] = {0,0,0,0};
int a [3][4] = {
    {0,1,1,1}, 
    {0,1,0,1},
    {0,0,1,1},
};
    


void DFS(int i)
{
	int j;
	printf("%d ", i);
	j = 0;
    visited[i] = 1;
	while(j < 4)
	{
		if(a[i][j] == 1 && visited[j] == 0)
			DFS(j);
		j++;
	}
}

int main()
{
	DFS(0);
	return 0;
}
