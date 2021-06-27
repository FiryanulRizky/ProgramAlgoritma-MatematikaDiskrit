#include <stdio.h>
#include <conio.h>

int main()
{
    int verteks, edge, x, y, t, W=0, k=0, i, j, awal,bobot;

    printf("Masukan jumlah verteks : ");
    scanf("%d",&verteks);

    int graph[verteks][verteks];
    int uji[verteks];

    for(x=0; x<verteks; x++){
        for(y=0; y<verteks; y++){
            graph[x][y]=0;
        }
    }

    printf("Masukan jumlah edge : ");
    scanf("%d",&edge);
    for(x=0; x<edge; x++){
        printf("Masukan edge %d : ",x+1);
        scanf("%d %d",&i, &j);
        printf("Masukan bobot : ");
        scanf("%d",&bobot);
        graph[i-1][j-1]=bobot;
        graph[j-1][i-1]=bobot;
    }
    system("cls");
    printf("Hasil matriks :\n");
    for(x=0; x<verteks; x++){
        printf("%d : ",x+1);
        for(y=0; y<verteks; y++){
            printf("%d ",graph[x][y]);
        }
        printf("\n");
    }
    printf("\nMasukkan verteks awal yang dipilih : ");
    scanf("%d", &awal);

    awal=awal-1;
    int batas=0, min, a, b;
    for(i=0;i<verteks;i++)
    {
        uji[i]=999;
    }

    uji[awal]=awal;
    while(batas<verteks-1){
        min=999;
        for(i=0;i<verteks;i++){
            if(uji[i]==i){
                for(j=0;j<verteks;j++){
                    if(graph[i][j]<min&&graph[i][j]!=0){
                        min = graph[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        graph[a][b]=0;
        graph[b][a]=0;

        int sama=0, v=0;
        for(i=0;i<verteks;i++){
            if(uji[i]==b){
                sama++;
            }
        }
        if (sama==0){
            printf("%d - %d : %d\n",a+1,b+1,min);
            W+=min;
            uji[b]=b;
        }
        batas++;
    }

    printf("Total : %d",W);
}
