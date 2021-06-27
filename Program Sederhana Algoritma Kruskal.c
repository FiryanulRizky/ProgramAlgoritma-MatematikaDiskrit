#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int i,j,a,b,u,v,n,urut_edge=1;
int min,minmatriks=0,matriks[100][100],graph[100];
int inf = 999;
char panah=26,panah1=27,garisH=196,garisV=179;
int cari(int);
int perulangan(int i,int j);

int main()
{
printf("\nInput banyak verteks : ");
scanf("%d",&n);
printf("\nInput Matriks Ketetanggaan dari Graph : \n\n  ");
for(i=0;i<n;i++)
{
    printf("%c ",i+65);
}
    printf("\n");
    for(i=0;i<n;i++){
        printf("%c ",i+65);
        for(j=0;j<n;j++){
            scanf("%d",&matriks[i][j]);
            if(matriks[i][j]==0)
            matriks[i][j]=inf;
        }
    }
printf("\nedges Minimum Spaning Tree nya adalah :\n\n");
while(urut_edge<n){
    for(i=1,min=inf; i<n; i++) //perulangan untuk mencari edge terkecil
    {
        for(j=1; j<n; j++) //perulangan untuk mencari
        {
            if(matriks[i][j]<min)
            {
                min=matriks[i][j];
                a=u=i;
                b=v=j;
            }
        }
    }
    u=cari(u);
    v=cari(v);
    if(perulangan(u,v))
    {
        printf("\n%d edge (%d %c%c%c%c %d) = %d\n",urut_edge++,a,panah1,garisH,garisH,panah,b,min);
        minmatriks +=min;
    }
    matriks[a][b]=matriks[b][a]=inf;
}
printf("\n\tTotal Minimum = %d\n",minmatriks);
getch();
}

int cari(int i){
    while(graph[i])
    i=graph[i];
    return i;
}

int perulangan(int i,int j){
    if(i!=j)
    {
        graph[j]=i;
        return 1;
    }
    return 0;
}
