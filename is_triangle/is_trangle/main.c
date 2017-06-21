//
//  main.c
//  shu
//
//  Created by 许梦婷 on 2017/6/20.
//  Copyright © 2017年 macjuleishu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high)
{
    int key;
    key = arr[low];
    while(low<high)
    {
        while(low <high && arr[high]>= key)
            high--;
        if(low<high)
            arr[low++] = arr[high];
        while(low<high && arr[low]<=key)
            low++;
        if(low<high)
            arr[high--] = arr[low];
    }
    arr[low] = key;
    return low;
}

void quick_sort(int arr[], int start, int end)
{
    int pos;
    if (start<end)
    {
        pos = partition(arr, start, end);
        quick_sort(arr,start,pos-1);
        quick_sort(arr,pos+1,end);
    }
}

int main(void)
{
    int n=0;
    int is_tri=0;
    scanf("%d", &n);
    int a[1000000];
    for (int i=0;i<n;i++)
        scanf("%d", &a[i]);
    quick_sort(a,0,a[n-1]);
    for (int i = 2; i < n; i++)
        if (a[i - 2] + a[i - 1] > a[i] && a[i] > 0)
            is_tri = 1;
    if(is_tri==1)
        printf("YES");
    else
         printf("NO");
    return 0;
    
}