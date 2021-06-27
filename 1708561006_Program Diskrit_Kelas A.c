#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pilih=0;

void menu(){
    printf("Nama : Muhammad Firyanul Rizky\n");;
    printf("NIM  : 1708561006\n\n");
    printf("\t\tTUGAS AKHIR MATEMATIKA DISKRIT II\n");
    printf("\tPROGRAM STUDI TEKNIK INFORMATIKA UNUD 2017/2018\n\n");
	printf("**=============================**========================**\n");
	printf("||     ALGORITMA PADA GRAPH    ||   ALGORITMA PADA TREE  ||\n");
	printf("||-----------------------------||------------------------||\n");
	printf("|| 1. Pewarnaan Graph          || 5. Kode Prufer         ||\n");
	printf("|| 2. Algoritma Djikstra       || 6. Algoritma Kruskal   ||\n");
	printf("|| 3. Algoritma Floyd Warshall || 7. Algoritma Prim      ||\n");
	printf("|| 4. Algoritma Bellman Ford   ||                        ||\n");
	printf("**=============================**========================**\n\n");
	printf("\t\t\tPilihan : 8 = Keluar\n\n");
	printf("Pilihan menu : ");scanf("%d",&pilih);
}

void pewarnaan(){
    printf("\nMenu 1 ( Algoritma Graph )\n\n");
	printf("-- PEWARNAAN GRAPH --\n\n");
    int n,i,j,k,temp,eror=0,warna=0;
    //Inisialisasi Variabel & Input
	printf("Masukkan jumlah vertek = ");scanf("%d",&n);
	int m[n][n],count[n],colored[n],sort[n],save[n];
	printf("Hubungan matriks = \n\n  ");
	for(i=0;i<n;i++){
		printf("%c ",i+65);
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("%c ",i+65);
		for(j=0;j<n;j++){
			scanf("%d",&m[i][j]);
		}
	}

//SYNTAX DIBAWAH INI ADALAH LANGKAH PENGISIAN ARRAY COUNT (REPRESENTASI DERAJAT VERTEK)
//1. Bertujuan untuk mengisi array count(derajat) menjadi 0
//2. Sort(urutan)sesuai dengan urutan vertek dari 0 sampai n
//3. Dalam langkah ini semua vertek belum diwarnai
	for(i=0;i<n;i++){
		count[i]=0;
		sort[i]=i;
		colored[i]=0;
//4. Hitung derajat yang disimpan pada array count
		for(j=0;j<n;j++){
			count[i]+=m[i][j];
		}
	}
//<END, LANJUT KE SYNTAX & TAHAPAN ALGORITMA BERIKUTNYA>

//SYNTAX DIBAWAH INI ADALAH LANGKAH SORTING DERAJAT VERTEK
//1. Jika derajat vertek setelahnya pada array sort lebih besar dari vertek sekarang
//2. Maka, terlebih dahulu urutan vertek selanjutnya akan dipindahkan ke urutan vertek yang sekarang
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(count[j+1]>count[j]){
				temp=count[j];
				count[j]=count[j+1];
				count[j+1]=temp;

				temp=sort[j];
				sort[j]=sort[j+1];
				sort[j+1]=temp;
			}
		}
	}
//<END, LANJUT KE SYNTAX & TAHAPAN ALGORITMA BERIKUTNYA>

//SYNTAX DIBAWAH INI ADALAH LANGKAH PEWARNAAN DENGAN VERTEK SEBAGAI PERTIMBANGAN TITIK AWAL & SELANJUTNYA
	for(i=0;i<n;i++){
//1. Inisialisasi save(menyimpan vertek yang tidak saling berhubungan)
		for(k=0;k<n;k++){
            save[k] = -1;
        }
//2. Jika vertek pada urutan ke i belum diwarnai maka akan dilakukan proses pewarnaan
		if(colored[sort[i]]==0){
			++warna;
			colored[sort[i]]=warna;
			for(j=0;j<n;j++){
//3. Jika vertek urutan ke i dan urutan ke j tidak saling berhubungan dan vertek j belum diwarnai, maka
    //syntax dibawah ini adalah langkah selanjutnya
if(m[sort[i]][sort[j]]==0&&colored[sort[j]]==0){
//4. Mengecek apakah vertek urutan ke j memiliki hubungan terhadap vertek lain
    //dan tidak pula berhubungan dengan vertek i serta sudah lebih dulu diwarnai
				for(k=0;k<n;k++){
					if(save[k]!=-1){						if(m[save[k]][sort[j]]!=0){
								eror=1;
						}
					}
				}
//5. Langkah dibawah adalah representasi Jika ada vertek urutan ke j
    // tidak memiliki hubungan terhadap vertek lain dan tidak pula berhubungan
    // dengan vertek i yang sudah diwarnai sebelumnya
//6. Selanjutnya Vertek urutan ke j akan diberi warna yang sama dengan vertek urutan ke i
				if(eror==0){
					colored[sort[j]]=warna;
					save[j]=sort[j];
//7. Menyimpan vertek urutan ke-j kedalam array save untuk mengecek apakah vertek lain tidak saling terhubung
    //dengan vertek urutan ke i
//8. Jika memiliki hubungan, maka akan menimbulkan konflik dengan vertek lain
    //dan representasi 0 adalah tanda bahwa vertek urutan ke-j tidak memiliki hubungan dengan vertek urutan ke i
					}
				eror=0;
				}
			}
		}
	}
//<END, LANJUT KE SYNTAX & TAHAPAN ALGORITMA BERIKUTNYA>

//SYNTAX DIBAWAH INI ADALAH LANGKAH DALAM MENAMPILKAN HASIL AKHIR
	for(i=0;i<n;i++){
    printf("\nwarna vertek %c = warna %d",i+65,colored[i]);
	}
	printf("\n\ntotal bilangan kromatik = %d\n\n",warna);
}
//<END, PEWARNAAN GRAPH SUDAH SELESAI>

void djikstra(){
    printf("\nMenu 2 ( Algoritma Graph )\n\n");
	printf("-- ALGORITMA DJIKSTRA --\n\n");
	int n,count,start,min,before,i,j;
	printf("Masukkan jumlah Vertek = "); scanf("%d",&n);
	int m[n][n],visited[n],jarak[n],prev[n];
	//input
	printf("\nMasukkan matriks hubungan : \n\n  ");
	for(i=0;i<n;i++){
		printf("%c ",i+65);
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("%c ",i+65);
		for(j=0;j<n;j++){
			scanf("%d",&m[i][j]);
		}
		for(j=0;j<n;j++){
	if(m[i][j]==0){
		m[i][j]=999;
			}
		}
	}
//SYNTAX DIBAWAH INI ADALAH LANGKAH ALGORITMA DJIKSTRA DALAM INISIALISASI VARIABEL & PEMROSESAN PROGRAM
//1. Inisialisasi jarak setiap vertek dari jarak awal = 999
//2. Dalam tahap ini semua vertek belum dikunjungi
    for(i=0;i<n;i++){
	visited[i]=0;
	jarak[i]=999;
	}
//3. Input vertek awal
	printf("\nMasukkan vertek awal = ");scanf("%d",&start);
	start-=1;
//4. Mengubah jarak vertek awal menjadi 0
	jarak[start]=0;
//5. Mencari sorthest path dan dilakukan sebanyak jumlah vertek
	while(count<n){

		min=999;
//6. Mencari jarak terkecil (lebih kecil dari min) yang ada pada vertek belum terkunjungi
		for(i=0;i<n;i++){
			if(jarak[i]<min && visited[i]==0){
    //maka jarak min menjadi jarak dari setiap vertek
//7. variabel Before akan menyimpan vertek yang memiliki jarak minimum
				min=jarak[i];
				before=i;
			}
		}
		visited[before]=1;
		//before diubah menjadi sudah terkunjungi
//8. Mengubah jarak vertek yang terhubung dengan vertek before
		for(i=0;i<n;i++){
        //jika vertek tersebut belum terkunjungi dan jika
            //jarak vertek before(min) ditambah dengan jarak vertek before ke vertek i
                //maka jarak vertek tersebut akan diubah menjadi
                    //jarak vertek before ditambah dengan jarak vertek before ke vertek i
			if(visited[i]==0){
				if(min+m[before][i]<jarak[i]){
					jarak[i]=min+m[before][i];
					prev[i]=before; //9. Prev menyimpan vertek yang menuju vertek i yaitu vertek before
				}
			}
		}
		count++;
	}
//SYNTAX DIBAWAH INI ADALAH LANGKAH ALGORITMA DJIKSTRA DALAM MENAMPILKAN HASIL AKHIR
	for(i=0;i<n;i++){
		if(i!=start){
        printf("\nJarak dari titik %c ke %c adalah = %d\nDengan jalur %c ke %c adalah : ",start+65,i+65,jarak[i],start+65,i+65);
        j=i;
        printf("%c <-- ",j+65);
            while(j!=start){
                j=prev[j];
                printf("%c ",j+65);
                if(j!=start){
                    printf("<-- ");
                }
            } printf("\n");
		}
	}
	printf("\n");
}
//<END, PROGRAM ALGORITMA DJIKSTRA SUDAH SELESAI>

void floyd(){
    printf("\nMenu 3 ( Algoritma Graph )\n\n");
	printf("-- ALGORITMA FLOYD WARSHALL --\n");
    int n,k,i,j;
//SYNTAX DIBAWAH INI ADALAH LANGKAH ALGORITMA FLOYD WARSHALL DALAM INISIALISASI VARIABEL & PEMROSESAN PROGRAM
//1. Input Vertek dengan Variabel n
	printf("\nMasukkan jumlah vertek : ");scanf("%d",&n);
	int m[n][n],before[n][n];
	printf("\nMasukkan matriks bobot = \n\n  ");
//2. Input pertama merupakan iterasi awal / iterasi 0
	for(i=0;i<n;i++){
		printf("%c ",i+65);
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("%c ",i+65);
		for(j=0;j<n;j++){
			scanf("%d",&m[i][j]);
		}
		for(j=0;j<n;j++){
			if(m[i][j]==0 && i!=j){
				m[i][j]=999;
			}
		}
	}
//3. Akan dilakukan Pengecekan perulangan iterasi, baris, dan kolom sebanyak jumlah vertek
    //k = perulangan iterasi
    //i = perulangan baris
    //j = perulangan kolom
    for(k=0;k<n;k++){
//4. Menyimpan nilai matriks hasil dari iterasi sebelumnya ke matriks before
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			before[i][j]=m[i][j];
			}
		}
	printf("\n\nD(%d) [iterasi ke-%d] :",k+1,k+1);
	for(i=0;i<n;i++){
		printf("\n");
		for(j=0;j<n;j++){
//5. Kondisi - Kondisi
    //jika bobot dari vertek i ke j pada iterasi sebelumnya lebih besar dari
    //penjumlahan bobot vertek i ke vertek k (iterasi ke - k) dan bobot vertek k ke vertek j pada iterasi sebelumnya
    //maka nilai dari bobot vertek i ke j akan setara dengan penjumlahan bobot vertek i ke vertek k
    //dan bobot vertek k ke vertek j
			if(before[i][j] > before[i][k]+before[k][j] ){
				m[i][j]=before[i][k]+before[k][j];
				}
				if(m[i][j]==999){
					printf("~\t");
				}
				else{
					printf("%d\t",m[i][j]);
				}
			}
		}
	}
//6. Mencetak hasil akhir
	printf("\n\nShortest Path (Algoritma Floyd Warshall) : ");
	for(i=0;i<n;i++){
		printf("\n");
		for(j=0;j<n;j++){
			printf("%d\t",m[i][j]);
		}
	}
	printf("\n\n");
}
//<END, PROGRAM ALGORITMA FLOYD WARSHALL SUDAH SELESAI>

void bellman(){
    printf("\nMenu 4 ( Algoritma Graph )\n\n");
	printf("-- ALGORITMA BELLMAN FORD --\n\n");
	int n,count=0,start,i,j;
//SYNTAX DIBAWAH INI ADALAH LANGKAH ALGORITMA BELLMAN FORD DALAM INISIALISASI VARIABEL & PEMROSESAN PROGRAM
//1. Input Vertek dan Matriks Bobot
	printf("Masukkan jumlah vertek : ");scanf("%d",&n);
	int m[n][n],d[n],pred[n],negative[n];
	printf("Masukkan matriks bobot = \n\n  ");
	for(i=0;i<n;i++){
		printf("%c ",i+65);
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("%c ",i+65);
		for(j=0;j<n;j++){
			scanf("%d",&m[i][j]);
		}
		for(j=0;j<n;j++){
	if(m[i][j]==0){
		m[i][j]=999;
			}
		}
	}
//2. Menginisialisasi jarak setiap vertek adalah 999, dan vertek pembuat negatif tidak ada
    for(i=0;i<n;i++){
	d[i]=999;
	negative[i]=-1;
	}
//3. Menginput vertek awal dan membuat jarak dari titik awal menjadi 0
    printf("\nMasukkan vertek awal : ");scanf("%d",&start);
    d[start]=0;
//4. Syntax dibawah ini akan menghitung sebanyak jumlah vertek-1
    while(count<n-1){
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
//5. Kondisi - Kondisi
    //jika jarak titik awal ke vertek i dijumlahkan dengan bobot( jarak) vertek i ke vertek j
    //yang nilainya lebih kecil dari jarak titik awal ke vertek j.
    //maka jarak titik awal ke vertek j akan diubah menjadi penjumlahan dari jarak titik awal ke vertek i
    //dengan bobot(jarak) vertek i ke vertek j
			if(d[i]+m[i][j] < d[j]){
				d[j]= d[i]+m[i][j];
pred[j]=i;
//variabel array predecessor diatas akan menyimpan vertek sebelumnya yang menuju vertek i
				}
			}
		}
	count++;
	}
//6. Syntax dibawah ini adalah langkah pengecekan negatif cycle pada suatu vertek
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
//7. Kondisi - Kondisi
    //jika jarak titik awal ke vertek j berubah lagi pada pengecekan ini,
    //maka vertek tersebut merupakan vertek terhubung dengan negatif cycle
			if(d[i]+m[i][j] < d[j]){
d[j]= (-999); //Syntax disamping adalah jarak dari vertek awal ke vertek j
              //yang kemudian akan diubah menjadi -999
              //karena akan selalu berkurang setiap dilakukan pengecekan
negative[j]=i;//Syntax disamping akan menyimpan vertek
              //yang berhubungan dengan vertek j
              //yang membuat jaraknya menjadi negatif cycle
			}
		}
	}
//8. Menampilkan hasil akhir
	for(i=0;i<n;i++){
		if(i!=start){
printf("\nJarak dari %c ke vertek %c adalah = ",start+65,i+65);
			if(d[i]==(-999)){
printf("-%d dengan vertek pembuat negative %c ",d[i],negative[i]+65);
			}
			else{
				printf("%d",d[i]);
			}
		}
	}
printf("\n\n");
}
//<END, PROGRAM ALGORITMA BELLMAN FORD SUDAH SELESAI>

void pruf_en(){
    printf("\nMenu 1 ( MST - Prufer )\n\n");
	printf("-- DEKONSTRUKSI PRUFER --\n\n");
	int i,j,k,vertek,a,b;
//SYNTAX DIBAWAH INI ADALAH LANGKAH MST ENKODING KODE PRUFER DALAM INISIALISASI VARIABEL & PEMROSESAN PROGRAM
//1. Inisialisasi & Input
	printf("Masukkan jumlah vertek : ");scanf("%d",&vertek);
	int code[vertek-2]; //menyimpan code
	int M[vertek][vertek]; //menyimpan matriks bobot
	int drjt[vertek]; //menyimpan derajat
	//Syntax Dibawah ini adalah inisialisasi code kosong , derajat semua vertek 0 , dan matriks bobot kosong
	for(i=0;i<vertek;i++){
		code[i]=0;
		drjt[i]=0;
		for(j=0;j<vertek;j++){
			M[i][j]=0;
		}
	}
	for(i=0;i<vertek-1;i++){
		printf("\nMasukkan edge = ");scanf("%d %d",&a,&b);
		M[(a-1)][(b-1)]=M[(b-1)][(a-1)]=1;
	}
//2. Syntax dibawah ini adalah langkah menghitung derajat
	for(i=0;i<vertek;i++){
		for(j=0;j<vertek;j++){
			drjt[i]+=M[i][j];
		}
		printf("\nDerajat vertek %d = %d ",i+1,drjt[i]);
	}
//Syntax dibawah ini adalah langkah dalam mencari kode prufer
//3. kode prufer suatu tree berjumlah sebanyak jumlah vertek - 2
	for(k=0;k<vertek-2;k++){
//4. mencari vertek dengan angka terkecil dan derajat 1
//5. perulangan ini akan mendapatkan nilai vertek dengan angka terkecil
//6. karena di mulai dari vertek awal dan jika sudah ketemu kode untuk edge pada vertek tersebut
//7. maka perulangan akan dipaksa berhenti, dengan begitu akan didapat vertek terkecil
		for(i=0;i<vertek;i++){
			if(drjt[i]==1){
//8. Mencari vertek yang berhubungan dengan vertek i
				for(j=0;j<vertek;j++){
					if(M[i][j]==1){
						code[k]=j+1;
                //kode yang disimpan adalah vertek j
						drjt[i]--;
						drjt[j]--;
						break;
					}
				}
				M[i][code[k]]=0;
				M[code[k]][i]=0;
				break;
			}
		}
	}
//9. Syntax Dibawah ini adalah langkah dalam mencetak hasil akhir
	printf("\n\nKode Prufer = ");
	for(i=0;i<vertek-2;i++){
		printf("%d ",code[i]);
	}
	printf("\n\n");
}
//<END, PROGRAM MST - DEKONSTRUKSI PRUFER SUDAH SELESAI>

void pruf_dec(){
	int jml_k,i,j,k,jml_v,temp;
    printf("\nMenu 2 ( MST - Prufer )\n\n");
	printf("-- REKONSTRUKSI PRUFER --\n\n");
//SYNTAX DIBAWAH INI ADALAH LANGKAH MST DEKODING KODE PRUFER DALAM INISIALISASI VARIABEL & PEMROSESAN PROGRAM
//1. Inisialisasi Variabel & Input
	printf("Masukkan jumlah kode = ");scanf("%d",&jml_k);
	int kode[jml_k];
	printf("\nMasukkan kode = ");
	for(i=0;i<jml_k;i++){
		scanf("%d",&kode[i]);
	}
	jml_v=jml_k+2; //Syntax disamping menunjukkan jumlah vertek sama dengan jumlah kode + 2
	int vertek[jml_v];
	int m[jml_v][jml_v];
	for(i=0;i<jml_v;i++){
vertek[i]=i+1;
//2. Mengisi array vertek dengan angka sesuai urutan dari 1 - jumlah vertek
		for(j=0;j<jml_v;j++){
			m[i][j]=0;
		}
	}
	printf("\nTree = ");
	for(i=0;i<jml_k;i++){
		for(j=0;j<jml_v;j++){
if(kode[i]!= vertek[j] && vertek[j]!=0 && kode[i]!=0 ){
				for(k=0;k<jml_k;k++){
					temp=0;
					if(kode[k]!=vertek[j]){
						temp=1;
					}
					else{
						break;
					}
				}
				if(temp==1){
printf("\n[%d] - [%d]",kode[i],vertek[j]);
m[kode[i]-1][vertek[j]-1]=m[vertek[j]-1][kode[i]-1] = 1;
					kode[i]=0;
					vertek[j]=0;

				}
			}
		}
	}
	for(i=0;i<jml_v;i++){
		if(vertek[i]!=0){
			for(j=0;j<jml_v;j++){
				if(vertek[i]!=vertek[j] && vertek[j]!=0 ){
printf("\n[%d] - [%d]",vertek[i],vertek[j]);
m[vertek[i]-1][vertek[j]-1]=m[vertek[j]-1][vertek[i]-1] = 1;
					vertek[i]=0;
					vertek[j]=0;
				}
			}
		}
	}
	printf("\n\nDengan matriks ketetangaan  = \n\n  ");
	for(i=1;i<=jml_v;i++){
		printf("%d ",i);
	}
	for(i=0;i<jml_v;i++){
		printf("\n%d ",i+1);
		for(j=0;j<jml_v;j++){
			printf("%d ",m[i][j]);
		}
	}
	printf("\n\n");
}
//<END, PROGRAM MST - REKONSTRUKSI PRUFER SUDAH SELESAI>

//SYNTAX DIBAWAH INI ADALAH FUNGSI PEMANGGILAN KEDUA FUNGSI PRUFER DIATAS
void prufer(){
	int sel;
    printf("\nMenu 5 ( Minimum Spanning Tree - MST )\n\n");
	printf("   -- KODE PRUFER --  \n\n");
	printf("1. Dekonstruksi Prufer\n");
	printf("2. Rekonstruksi Prufer\n\n");
	printf("Pilihan = ");scanf("%d",&sel);
	switch(sel){
		case 1:
			system("cls");
			pruf_en();
		break;
		case 2:
			system("cls");
			pruf_dec();
		break;
	}
}

void kruskal(){
    printf("\nMenu 6 ( Minimum Spanning Tree - MST )\n\n");
	printf("-- ALGORITMA KRUSKAL --\n\n");
//SYNTAX DIBAWAH INI ADALAH LANGKAH MST - ALGORITMA KRUSKAL DALAM INISIALISASI VARIABEL & PEMROSESAN PROGRAM
//1. Input akan disimpan dalam bentuk struct yang menyimpan vertek terhubung (edge) dan bobot dari edge tersebut
	struct data{
		int bobot[1];
		int edge[2];
	};

	int total=0;
	int i,j,vertek,edge,temp,cek,t,k=0;
//2. Inisialisasi Variabel & Input
	printf("Masukkan jumlah vertek : ");scanf("%d",&vertek);
	printf("Masukkan jumlah edge : ");scanf("%d",&edge);
	int graph[vertek][vertek];
	struct data hub[edge];
	int used[edge];

//3. Inisialisasi nilai awal bobot semua edge infinity
	for(i=0;i<vertek;i++){
		for(j=0;j<vertek;j++){
			graph[i][j]=999;
		}
	}
//4. Mengosongkan array used
	for(i=0;i<edge;i++){
		used[i]=0;
	}
//5. Input bobot
	printf("\n");
	for(i=0;i<edge;i++){
printf("Masukkan edge : ");scanf("%d%d",&hub[i].edge[1],&hub[i].edge[2]);
printf("Bobot : ");scanf("%d",&hub[i].bobot[1]);
graph[hub[i].edge[1]-1][hub[i].edge[2]-1]=hub[i].bobot[1];
graph[hub[i].edge[2]-1][hub[i].edge[1]-1]=hub[i].bobot[1];
		printf("\n");
	}
//6. Cetak matriks - matriks ketetanggaan
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
//7. Sorting berdasarkan bobot dari terkecil hingga terbesar
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

//8. Syntax Dibawah menunjukkan hasil sorting
	printf("\n*===========================*\n");
	printf("        hasil sorting        \n\n");
	for(i=0;i<edge;i++){
		printf("  edge %d - %d <=> bobot = %d \n",hub[i].edge[1],hub[i].edge[2],hub[i].bobot[1]);
	}
        printf("*===========================*\n");

//9. Syntax Dibawah menunjukkan minimum spanning tree
	printf("\n*===========================*\n");
	printf("    Minimum Spanning Tree    \n\n");
	int from,to;
    //from menyimpan vertek awal
	//to menyimpan vertek tujuan
	for(i=0;i<edge;i++){
		from=hub[i].edge[1];
		to=hub[i].edge[2];
//10. Syntax Dibawah akan mengecek apakah edge tersebut membentuk cycle atau tidak
      //dengan cara mencari union graph tersebut
      //jika from dan to merupakan union(gabungan) graph yang sama
      //maka mereka akan membentuk cycle
      //dan jika akhir dari union from dan to sama maka mereka membentuk cycle
      //dengan kata lain jika from sama dengan to
      //maka vertek awal bertemu kembali dengan dirinya sendiri dan akan membentuk cycle
		while(used[from]){
			from=used[from];
		}
		while(used[to]){
			to=used[to];
		}
		if(from!=to){
        printf("    edge %d - %d bobot = %d \n",hub[i].edge[1],hub[i].edge[2],hub[i].bobot[1]);
			total+=hub[i].bobot[1];
//11. Syntax Dibawah adalah langkah menambahkan total bobot
			used[from]=to;
        //syntax diatas akan menyimpan vertek terakhir pada union(gabungan)
        //yang dibuat oleh vertek from
		}

	}
        printf("*===========================*\n");
//12. Mencetak bobot total
	printf("\nbobot total : %d\n\n",total);
}
//<END, PROGRAM MST - ALGORITMA KRUSKAL SUDAH SELESAI>

void prim(){
    printf("\nMenu 7 ( Minimum Spanning Tree - MST )\n\n");
	printf("-- ALGORITMA PRIM --\n\n");
	int n,i,j,awal;
//SYNTAX DIBAWAH INI ADALAH LANGKAH MST - ALGORITMA PRIM DALAM INISIALISASI VARIABEL & PEMROSESAN PROGRAM
//1. Inisialisasi Variabel & Input
	printf("Masukkan jumlah vertek = ");scanf("%d",&n);
	int M[n][n],visited[n];
	printf("\nMasukkan matriks bobot = \n\n  ");
	for(i=0;i<n;i++){
		printf("%c ",i+65);
	}
	printf("\n");
	for(i=0;i<n;i++){
		printf("%c ",i+65);
		for(j=0;j<n;j++){
			scanf("%d",&M[i][j]);
		}
	}
    int jumlah=0,min,end,start,bobot=0;
//2. Keterangan - Keterangan
    //jumlah = jumlah pengecekan yg dilakukan
    //min = jarak minimum
    //end = menyimpan vertek tujuan
    //start = menyimpan vertek asal
    //bobot = total mst
    //inisialisasi semua vertek belum terkunjungi
    for(i=0;i<n;i++){
		visited[i]=0;
	}
//3. Input vertek awal, sehingga nantinya vertek awal menjadi sudah terkunjungi
    printf("\nMasukkan vertex awal yang dipilih : ");
scanf("%d", &awal);
    visited[awal-1]=1;
//4. Pengecekan dilakukan sampai jumlah edge yang didapat sebanyak jumlah vertek -1
    //karena vertek awal tidak dicek lagi
    while(jumlah<n-1){
	min=999;
	for(i=0;i<n;i++){
//5. Kondisi - Kondisi
    //jika vertek i sudah dikunjungi
    //dan bobot vertek i terhadap j lebih kecil dari min , dan juga tidak 0
    //maka bobot min akan dubah menjadi bobot vertek i terhadap j
    //start akan menyimpan vertek i sebagai vertek awal
    //dan end akan menyimpan vertek j sebagai vertek tujuan
		if(visited[i]==1){
			for(j=0;j<n;j++){
				if(M[i][j]<min&&M[i][j]!=0){
					min=M[i][j];
					start=i;
					end=j;
					}
				}
			}
		}
//6. Syntax dibawah ini menunjukkan bobot vertek start dan end akan diubah menjadi 0
		M[start][end]=0;
		M[end][start]=0;
//7. jika vertak start dan vertek end belum terkunjungi maka mereka tidak membuat cycle
//8. jika keduanya sudah terkunjungi maka edge selanjutnya akan membentuk cycle
		if(visited[start]==0||visited[end]==0){
//9. Mencetak edge, menambahkan bobot total
    //dan merubah status vertek end menjadi sudah terkunjungi
    //dan jumlah edge bertambah
			printf("[%c] - [%c]: %d\n",start+65,end+65,min);
			bobot=bobot+min;
			visited[end]=1;
			jumlah++;
		}
	}
//10. Mencetak bobot akhir
	printf("\nTotal bobot adalah = %d \n\n",bobot);
}
//<END, PROGRAM MST - ALGORITMA PRIM SUDAH SELESAI>

//SYNTAX DIBAWAH INI ADALAH FUNGSI PEMANGGILAN KESELURUHAN FUNGSI ALGORITMA DIATAS
int main(){
	do{
		do{
			system("cls");
			menu();
		}while(pilih < 1 || pilih > 8);
		system("cls");
		switch(pilih){
			case 1 : pewarnaan();system("PAUSE");break;
			case 2 : djikstra();system("PAUSE");break;
			case 3 : floyd();system("PAUSE");break;
			case 4 : bellman();system("PAUSE");break;
			case 5 : prufer();system("PAUSE");break;
			case 6 : kruskal();system("PAUSE");break;
			case 7 : prim();system("PAUSE");break;
		}
	}while(pilih!=8);
}
//END, PROGRAM AKHIR MATEMATIKA DISKRIT II SUDAH SELESAI
