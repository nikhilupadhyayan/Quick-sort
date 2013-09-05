#include<stdio.h>
void swapp(int *a,int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
int partitionn(int* a,int start,int endd)
{

    int pivot=a[start];
    int pivot_pos=start;
    int i=start;
    int j=endd;
    do
    {

        while(a[i]<=pivot){i=i+1;}
        while(a[j]>pivot)j=j-1;
        swapp(a,i,j);
    }
    while(i<j);
    swapp(a,i,j);
    swapp(a,pivot_pos,j);
    return j;
}
void quicksort(int* a ,int start,int sizee)//sizee is index of last element i.e number of elements -1
{
    if(start<sizee)
    {



    int s=partitionn(a,start,sizee);
    quicksort(a,0,s-1);
    quicksort(a,s+1,sizee);
    }
}
void display(int *a,int n)
{
    int i;
    for(i=0;i<n;++i)
    {
        printf("%2d",a[i]);
    }
}
#define LAST_INDEX 5
int main()
{
    int a[]={9,8,3,4,5,6};
    printf("Before sorting:");
    display(a,LAST_INDEX+1);
    printf("\n");

    quicksort(a,0,LAST_INDEX);
    printf("After sorting:");
    display(a,LAST_INDEX+1);
}
