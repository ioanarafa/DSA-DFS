#include <stdio.h>
#include <stdlib.h>
int t = 0;

typedef struct{
    int n;//nr de noduri
    int **adj;//mat de adiacenta
    int* vizitat;
    int *start;
    int* finish;
}Graf;

//1
void dfs(Graf g, int s)//nodul de la care pornim
{
    printf("%d ", s);
    g.vizitat[s]=1;
    g.start[s]= ++t;

    //cautam primul vecin si plec sa il parcurg pe el
    for(int i=1; i<= g.n; i++)
    {
        if(g.vizitat[i] == 0 && g.adj[s][i] == 1)
            dfs(g,i);
    }
    g.finish[s]= ++t;

}

int main()
{
    FILE* f =fopen("grafdfs.txt", "r");
    if(f==NULL)
    {
        return 0;
    }

    Graf g;
    fscanf(f, "%d", &g.n);

    g.adj=(int**)calloc(g.n + 1, sizeof(int*)); //alocam memorie pt matricea de adiacenta
    for(int i = 1; i<= g.n +1; i++)
    {
        g.adj[i]=(int*)calloc(g.n +1, sizeof(int));
    }

    g.vizitat = (int)calloc(g.n +1, sizeof(int));
    g.start = (int)calloc(g.n +1, sizeof(int));
    g.finish= (int)calloc(g.n +1, sizeof(int));

    int x,y;
    while(fscanf(f, "%d %d", &x, &y)==2)
    {
        g.adj[x][y]=1;
    }

    dfs(g,1);

    return 0;
}
