#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int hori_x[50],hori_y[50],vert_x[50],vert_y[50],length_hori[10],length_ver[10];
    char word[10];
} minus;
minus m1;

void assign_coordinate(char**,int);
void free_memory(char**,int);
void display(char**,int);
int main()
{
    int size1,size2;
    char ch;
    printf("The grid size of sudoku:--->");
    scanf("%d",&size1);
   
    char **arr = (char**)malloc(size1*sizeof(char*)); // created grid
    for(int i=0; i<size1; i++)
        arr[i] = (char*)malloc(size1*sizeof(char));
   
    printf("Enter the values in the grid:-->\n");  // input values in grid (+) or (-)
    for(int i=0; i<size1; i++)
        for(int j=0; j<size1; j++)
        {
            while(scanf("%c",&ch) == '\n'){}
            arr[i][j] = ch;
        }

    printf("ENter the words separated by (,):--->");
    char *words = (char*)malloc(size2*sizeof(char));
    fgets(words,20,stdin);
    display(arr,size1);


    free_memory(arr,size1);   
    return 0;
}

void display(char **arr, int size)
{
    for(int i=0; i<size; i++)
    {
        for(int j=0; j<size; j++)
            printf("%c",&arr[i][j]);
        printf("\n");
    }
}

void assign_coordinate(char **arr, int size)
{
    int count=0;
    for(int i=0; i<size; i++)                     //horizontal scanning of elements
    {
        for(int j=0; j<size; j++)
        {
            if(arr[i][j] == '-')
            {
                m1.hori_x[count] = i;
                m1.hori_y[count] = j;
                count++;
            } 
        }
        m1.hori_x[count] = -1;
        m1.hori_y[count] = -1;
        count++;
    }
}

void free_memory(char **arr, int size)
{
    for(int i=0; i<size; i++)
        free(arr[i]);
    free(arr);
}