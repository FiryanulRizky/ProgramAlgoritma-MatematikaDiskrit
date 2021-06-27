#include <stdio.h>

    int main ()
    {
        int a,b,c,vertex,i,j;
        int graph[vertex][vertex];
        printf("Program Menentukan Kode Prufer pada Himpunan Vertex Tree\n");
        printf("========================================================\n\n");
        printf("Masukkan Jumlah Vertex dari tree : ");
        scanf("%d",&vertex);
        int derajat=0;
        int prufer[vertex];
        for(b=0;b<vertex;b++) {
            for(c=0;c<vertex;c++)
                graph[b][c]=0;
            prufer[b]=0;
        }
        printf("Jumlah Edge : %d",vertex-1);
        printf("\n");
        for(b=0;b<vertex-1;b++) {
            printf("\nMasukkan masing - masing vertex untuk edge %d : ",b+1);
            printf("\nVertex 1 : "); scanf("%d",&i);
            printf("Vertex 2 : "); scanf("%d",&j);
            graph[i-1][j-1]=1;
            graph[j-1][i-1]=1;
        }
        printf("\nHasil Input Matriks : \n");
            for(b=0;b<vertex;b++){
                printf("%d : ",b+1);
                for(c=0;c<vertex;c++)
                    printf("%d",graph[b][c]);
                printf("\n");
            }

            for(a=0;a<vertex-2;a++){
                for(b=0;b<vertex;b++){
                    for(c=0;c<vertex;c++){
                        derajat += graph[b][c];
                        if(graph[b][c]==1)
                            prufer [a] = c;
                    }
                    if(derajat==1)
                        break;
                    derajat = 0;
                }
                graph[b][prufer[a]]=0;
                graph[prufer[a]][b]=0;
                derajat=0;
            }
            printf("\nHasil Kode Prufer : ");
            for(b=0;b<vertex-2;b++)
                printf("%d",prufer[b]+1);
    }
