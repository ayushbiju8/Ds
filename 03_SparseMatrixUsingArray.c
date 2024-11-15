#include <stdio.h>
#define MAX 10

void createMatrix(int matrix[MAX][MAX],int *rows,int *cols){
    printf("Enter the no of rows :");
    scanf("%d",rows);
    printf("Enter the no of cols :");
    scanf("%d",cols);
    for (int i=0;i < *rows;i++){
        for (int j=0;j < *cols;j++){
            printf("Enter the element at [%d][%d] : ",i,j);
            scanf("%d",&matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX][MAX],int *rows,int *cols){
    for (int i=0;i < *rows;i++){
        for (int j=0;j < *cols;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

void toTupleForm(int matrix[MAX][MAX],int *rows,int *cols,int tuple[MAX][3]){
    tuple[0][0]=*rows;
    tuple[0][1]=*cols;
    int k=1;
    for (int i = 0; i < *rows; i++){
        for (int j = 0; j < *cols; j++){
            if (matrix[i][j]!=0){
                tuple[k][0]=i;
                tuple[k][1]=j;
                tuple[k][2]=matrix[i][j];
                k++;
            } 
        }
    }
    tuple[0][2]=k-1;
}

void displayTuple(int tuple[MAX][3]){
    int rows = tuple[0][2]+1;
    int cols = 3;
    for (int i=0;i < rows;i++){
        for (int j=0;j < cols;j++){
            printf("%d ",tuple[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int rows,cols;
    int matrix[MAX][MAX];
    int tuple[MAX][3];
    createMatrix(matrix,&rows,&cols);
    printf("Normal Matrix\n");
    displayMatrix(matrix,&rows,&cols);
    toTupleForm(matrix,&rows,&cols,tuple);
    printf("\nTuple Form \n");
    displayTuple(tuple);
}


// Include standard input-output library and define a constant MAX for matrix size

// Function to create a matrix with user input
// Step 1: Prompt the user to input the number of rows and columns
// Step 2: For each position in the matrix, prompt the user to enter an element

// Function to display the matrix in its normal form
// Step 1: For each row, print all elements in that row, separated by spaces

// Function to convert the matrix to tuple form (sparse matrix representation)
// Step 1: Initialize the first row of the tuple with the matrix's total rows, columns, and number of non-zero elements
// Step 2: For each non-zero element in the matrix, store its row index, column index, and value in the tuple array
// Step 3: Store the total count of non-zero elements in the tuple's first row

// Function to display the matrix in tuple form
// Step 1: For each row in the tuple, print all three values: row index, column index, and value

// Main function
// Step 1: Declare necessary variables for the matrix and tuple representations
// Step 2: Call 'createMatrix' to initialize the matrix with user inputs
// Step 3: Display the normal form of the matrix
// Step 4: Convert the matrix to tuple form using 'toTupleForm'
// Step 5: Display the tuple form of the matrix
