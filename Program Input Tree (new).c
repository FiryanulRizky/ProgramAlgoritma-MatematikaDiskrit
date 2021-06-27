#include <stdio.h>
#include <stdlib.h>

struct tree {
    int info;
    struct tree *kanan;
    struct tree *kiri;
};
struct tree *temp1, *temp2, *baru, *root;

void main () {
    int i,n,x;
    printf("Program Sederhana Input Tree\n");
    printf("============================\n\n");
    printf("Masukkan Bilangan : ");
    scanf("%d",&n);
    printf("Ketik Bil 1 : ");
    scanf("%d",&root->info);
    for(i=2;i<=n;i++)
    {
        printf("Ketik Bil %d : ",i);fflush(stdin);
        scanf("%d",&x);fflush(stdin);
        baru=(struct tree*)malloc(sizeof(struct tree));fflush(stdin);
        baru->info=x;fflush(stdin);
        temp1=root;fflush(stdin);
        while(temp1!=NULL)
        {
            temp2 = temp1;
            if(temp1->info<baru->info)
            {
                temp1=temp1->kanan;
            }
            else {
                temp1=temp1->kiri;
            }
        }
        if(temp2->info>baru->info)
        {
            temp2->kanan=baru;
        }
        else {
            temp2->kiri=baru;
        }
    }
}
