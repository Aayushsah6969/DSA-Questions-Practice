#include <stdio.h>
int main() {
    int row, col,i,j,sum=0;
    printf("Enter row and column: ");
    scanf("%d%d",&row,&col);
    int arr[row][col];
    printf("Enter elements in array: ");
    for( i =0; i<row; i++){
        for( j=0; j<col; j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("Your matrix is: \n");
    for( i =0; i<row; i++){
        for(j=0; j<col; j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}