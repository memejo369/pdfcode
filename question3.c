#include<stdio.h>
#include<stdbool.h>
void fifoPageReplacement(int rs[],int n,int nf){
    int frames[nf];
    int page_order[nf];
    int PF=0;
    int current_page=0;

    //initial frame with -1
    for(int i=0;i<nf;i++)
    {
        frames[i]=-1;
        page_order[i]=-1;
    }

    for(int i=0;i<n;i++)
    {
        bool page_found=false;
        for(int j=0;j<nf;j++)
        {
            if(frames[j]==rs[i])
            {
                page_found=true;
                break;
            }
        }
        if(!page_found)
        {
            frames[current_page]=rs[i];
            page_order[current_page]=rs[i];
            current_page=(current_page+1)%nf;
            PF++;
        }
        printf("Memory : ");
        for(int j=0;j<nf;j++)
        {
            if(frames[j]!=-1)
            {
                printf("%d ",frames[j]);
            }
            else printf("E ");
        }
        printf("\n");
    }
    printf("Total No. of page fault is : %d",PF);
}
int main()
{
    int rs[]={3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int n=sizeof(rs) / sizeof(rs[0]);
    int nf;
    printf("Enter the No. of frames : \t");
    scanf("%d",&nf);
    fifoPageReplacement(rs,n,nf);
}