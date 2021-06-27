#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    printf("\nMenu 6 ( Minimum Spanning Tree - MST )\n\n");
	printf("-- ALGORITMA KRUSKAL --\n\n");
//input akan disimpan dalam bentuk struct yang menyimpan //vertek yg berhubungan (edge) dan bobot dari edge tersebut
	struct data{
		int bobot[1];
		int edge[2];
	};

	int total=0;
	int i,j,vertek,edge,temp,cek,t,k=0;
	//inout
	printf("Masukan jumlah vertek : ");scanf("%d",&vertek);
	printf("Masukan jumlah edge : ");scanf("%d",&edge);
	int graph[vertek][vertek];
	struct data hub[edge];
	int used[edge];

	//inisiasi nilai awal bobot semua edge infinity
	for(i=0;i<vertek;i++){
		for(j=0;j<vertek;j++){
			graph[i][j]=999;
		}
	}
	//mengosongkan array used
	for(i=0;i<edge;i++){
		used[i]=0;
	}
	//input bobot
	printf("\n");
	for(i=0;i<edge;i++){
        printf("Masukan edge : ");scanf("%d%d",&hub[i].edge[1],&hub[i].edge[2]);
        printf("Bobot : ");scanf("%d",&hub[i].bobot[1]);
        graph[hub[i].edge[1]-1][hub[i].edge[2]-1]=hub[i].bobot[1];
        graph[hub[i].edge[2]-1][hub[i].edge[1]-1]=hub[i].bobot[1];
        printf("\n");
	}
	//cetak matriks matriks ketetanggaan
	printf("Matriks ketetanggaan : \n\n");
	for(i=0;i<vertek;i++){
		for(j=0;j<vertek;j++){
			if(graph[i][j]!=999){
				printf("%d ",graph[i][j]);
			}
			else{
				printf("~ ");
			}
		}
		printf("\n");
	}
	//sorting berdasarkan bobot dari terkecil hingga terbesar
	for (i=0;i<edge-1;i++){
	for (j=0;j<edge-i-1;j++){
		if (hub[j+1].bobot[1] < hub[j].bobot[1]){
                temp = hub[j].edge[1];
                hub[j].edge[1]=hub[j+1].edge[1];
                hub[j+1].edge[1]=temp;
                temp = hub[j].edge[2];
                hub[j].edge[2]=hub[j+1].edge[2];
                hub[j+1].edge[2]=temp;
                temp = hub[j].bobot[1];
                hub[j].bobot[1] = hub[j+1].bobot[1];
                hub[j+1].bobot[1] = temp;
            }
        }
	}

	//hasil sorting
	printf("\nhasil sorting : \n\n");
	for(i=0;i<edge;i++){
		printf("edge %d-%d <==> bobot=%d\n",hub[i].edge[1],hub[i].edge[2],hub[i].bobot[1]);
	}

	//minimum spanning tree
	printf("\n== Minimum Spanning Tree ==\n\n");
	int from,to;
	//from menyimpan vertek awal
	//to menyimpan vertek tujuan
	for(i=0;i<edge;i++){
		from=hub[i].edge[1];
		to=hub[i].edge[2];
//mengecek apakah edge tersebut membentuk cycle atau //tidak
		//dengan cara mencari union graph tersebut
//jika from dan to merupakan union(gabungan) graph //yang sama , maka mereka akan membentuk cycle,
// atau akhir dari union from dan to sama , maka //mereka membentuk cycle
// dengan kata lain jika from sama dengan to , berarti //vertek awal bertemu kembali dengan vertek awal yang //berarti cycle
		while(used[from]){
			from=used[from];
		}
		while(used[to]){
			to=used[to];
		}
		if(from!=to){
            printf("edge %d-%d <==> bobot = %d\n",hub[i].edge[1],hub[i].edge[2],hub[i].bobot[1]);
			total+=hub[i].bobot[1];
// menambahkan total bobot
			used[from]=to;
// menyimpan vertek terakhir pada //union(gabungan) yang dibuat oleh vertek from
		}
	}
	//mencetak bobot total
	printf("\nbobot total : %d\n",total);
}
