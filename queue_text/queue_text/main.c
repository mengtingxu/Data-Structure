//
//  main.c
//  queue_text
//
//  Created by 许梦婷 on 2017/6/20.
//

#include<stdio.h>
#include<stdlib.h>
struct lnode
{
    int data;
    struct lnode *next;
};  //创建队列中的节点

int findmax(struct lnode* start)
{
    struct lnode* p=start;
    int max=start->data;
    p=p->next;
    for(;p!=start;)
    {
        if(p->data>max)
        {
            max=p->data;
        }
        p=p->next;
    }
    return max;
}  //找出整个循环队列中最大的数 并只遍历一次即可

int main()
{
    int time;
    int n;
    int num;
    int index;
    int max;
    scanf("%d",&n); //测试样例的数目
    struct lnode * a[n];
    struct lnode * teacher[n];
    struct lnode* r[n];
    struct lnode *p;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&num ,&index); //num是任务队列的长度，index是老师的计算任务的位置
        a[i]=(struct lnode*)malloc(sizeof(struct lnode));  //存储每个队列的头节点
        r[i]=a[i];
        p=a[i];
        scanf("%d",&p->data); //此时p r a中都存着每个队列的头节点
        
        for(int j=0;j<(num-1);j++)
        {
            p=(struct lnode*)malloc(sizeof(struct lnode));
            scanf("%d",&p->data);
            r[i]->next=p;
            r[i]=p;
        }
        p->next=a[i];
        p=a[i]; //构成循环队列，并且此时p指向头节点
        
        teacher[i]=a[i];
        for(int j=0;j<index;j++)
            teacher[i]=teacher[i]->next;  //找到老师计算任务的位置
    }
    for(int i=0;i<n;i++)
    {
        time=0;
        p=a[i];
        for(;;)
        {
            max=findmax(p);  //先找出该队列中最大的数
            if(p->data==max)
            {
                time++;
                if(p==teacher[i])
                    break;
                r[i]->next=p->next;
                p=p->next;
            }
            else
            {
                p=p->next;
                r[i]=r[i]->next;
            }
        }
        printf("%d\n",time);
    }
    return 0;
}