#include <stdio.h>

#define MAX 100

typedef struct {
    int row;
    int col;
    int value;
} Element;

void convertToSparse(int matrix[MAX][MAX], int rows, int cols, Element sparse[MAX], int *sparseCount) {
    *sparseCount = 0;

    // Converting the matrix to sparse format
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                sparse[*sparseCount].row = i;
                sparse[*sparseCount].col = j;
                sparse[*sparseCount].value = matrix[i][j];
                (*sparseCount)++;
            }
        }
    }
}

void addSparseMatrices(Element sparseA[MAX], int countA, Element sparseB[MAX], int countB, Element result[MAX], int *resultCount) {
    int indexA = 0, indexB = 0;
    *resultCount = 0;

    // Performing addition of the sparse matrices
    while (indexA < countA && indexB < countB) {
        if (sparseA[indexA].row < sparseB[indexB].row ||
            (sparseA[indexA].row == sparseB[indexB].row && sparseA[indexA].col < sparseB[indexB].col)) {
            result[*resultCount] = sparseA[indexA];
            indexA++;
        } else if (sparseA[indexA].row > sparseB[indexB].row ||
                   (sparseA[indexA].row == sparseB[indexB].row && sparseA[indexA].col > sparseB[indexB].col)) {
            result[*resultCount] = sparseB[indexB];
            indexB++;
        } else {
            result[*resultCount] = sparseA[indexA];
            result[*resultCount].value += sparseB[indexB].value;
            indexA++;
            indexB++;
        }
        (*resultCount)++;
    }

    // Copying remaining elements from sparseA, if any
    while (indexA < countA) {
        result[*resultCount] = sparseA[indexA];
        indexA++;
        (*resultCount)++;
    }

    // Copying remaining elements from sparseB, if any
    while (indexB < countB) {
        result[*resultCount] = sparseB[indexB];
        indexB++;
        (*resultCount)++;
    }
}

void printSparseMatrix(Element sparse[MAX], int count) {
    printf("Sparse Matrix:\n");
    printf("Row\tColumn\tValue\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].col, sparse[i].value);
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    int matrixA[MAX][MAX], matrixB[MAX][MAX];
    Element sparseA[MAX], sparseB[MAX], result[MAX];
    int countA, countB, resultCount;

    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter the elements of matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    printf("Enter the elements of matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    convertToSparse(matrixA, rowsA, colsA, sparseA, &countA);
    convertToSparse(matrixB, rowsB, colsB, sparseB, &countB);

    printf("\nMatrix A:\n");
    printSparseMatrix(sparseA, countA);

    printf("\nMatrix B:\n");
    printSparseMatrix(sparseB, countB);

    addSparseMatrices(sparseA, countA, sparseB, countB, result, &resultCount);

    printf("\nAddition Result:\n");
    printSparseMatrix(result, resultCount);

    return 0;
}
