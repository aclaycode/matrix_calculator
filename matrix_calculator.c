/*-----------------------------------------------------------------------------
* Programmer:  AJ Clay
* Date: 07/06/15
* Name: matrix_calculator.c
* Description: This program performs basic matrix operations:   multiplication,	addition, and transpose.  The program gets size and entries of matrix from user
               and displays matrices on screen.
* Pseudo code: -User is prompted to enter size of matrix A and to enter each value entry of the matrix
               -Matrix A is allocated to store matrix
               -Matrix A is printed
               -User is prompted to do the same thing for matrix B
               -Matrix B is allocated to store matrix
               -Matrix B is printed
               -The program then automatically allocates room for and computes matrix A + matrix A, the transpose of matrix B, and the transpose of matrix B
                multiplied by the original matrix B and then they are all printed to the screen.
               -The storage space in which each matrix occupied is then free'd at the end of the program
 -----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
float* getMatrix(int n, int m);
void printMatrix(float *matPtr, int n, int m);
float*  addMatrices(float *aPtr, float *bptr, int n, int m);
float*  transposeMatrix(float *matPtr, int n, int m);
float*  multMatrices(float *aPtr, float *bptr, int n, int m, int p);

int main(void)
{
  int numRowsA = 0, numColsA = 0, numRowsB = 0, numColsB = 0;
  int i;
  float *Aptr=NULL, *Bptr=NULL, *Cptr=NULL, *BtransposePtr=NULL, *Dptr=NULL;


  //prompt user to input A  matrix
  printf("Enter matrix A:\n");
  do
  {
    printf("How many rows (must be > 0): ");
    scanf("%d", &numRowsA);
  } while(numRowsA <= 0);
  do
  {
    printf("How many columns(must be > 0): ");
    scanf("%d", &numColsA);
  } while(numColsA <= 0);

  Aptr = getMatrix(numRowsA, numColsA);

  //Print out the A matrix:
  printf("\nThe A matrix is:\n");
  printMatrix(Aptr, numRowsA, numColsA);

  //prompt user to input B  matrix
  printf("\nEnter matrix B:\n");
  do
  {
    printf("How many rows (must be > 0): ");
    scanf("%d", &numRowsB);
  } while(numRowsB <= 0);
  do
  {
    printf("How many columns(must be > 0): ");
    scanf("%d", &numColsB);
  } while(numColsB <= 0);
  Bptr = (float *) getMatrix(numRowsB, numColsB);

  //Print out the B matrix:
  printf("\nThe B matrix is:\n");
  printMatrix(Bptr, numRowsB, numColsB);

  //Compute C=A+A and print it
  Cptr = addMatrices(Aptr, Aptr, numRowsA, numColsA);
  printf("\nA + A =\n");
  printMatrix(Cptr, numRowsA, numColsA);

  //Compute transpose of B and print it:
  BtransposePtr = transposeMatrix(Bptr, numRowsB, numColsB);
  printf("\nBtranspose =\n");
  printMatrix(BtransposePtr, numColsB, numRowsB);

  //Compute D = B x Btranspose and print it
  Dptr = multMatrices(Bptr, BtransposePtr, numRowsB, numColsB, numRowsB);
  printf("\nB x Btranspose =\n");
  printMatrix(Dptr, numRowsB, numRowsB);

  //freeing all allocated memory
  free(Aptr);
  free(Bptr);
  free(Cptr);
  free(BtransposePtr);
  free(Dptr);

  return 0;
 }

 float* getMatrix(int n, int m)
 /*********************************************************************************
  *Description: This function mallocs an array large enough to hold an n x m matrix of floats.  The
 *user is then prompted to enter the values  for each row of the matrix.  As the values
 *are entered, they are stored into the array in by-row order.  When all values have
 *been entered, the function returns a pointer to the array.
 *inputs: n = integer = number of rows in the matrix
 *        m = number of columns in the matrix
 *output: The function returns a pointer to a dynamically allocated (n x m) element array of
          floats that holds the matrix, in by-row order.
 **********************************************************************************/
{

  int i, j;
  float *arrayPtr;

  //make sure matrix dimensions are > 0
  if ((n <= 0) || (m <= 0))
  {
    printf("function getMatrix(): matrix dimensions are invalid\n");
    return NULL;
  }
  //Allocate array to hold the matrix
  arrayPtr = (float *) malloc(n*m*sizeof(float));
  if(arrayPtr == NULL)
  {
    printf("function getMatrix: Unable to malloc array\n");
    return NULL;
  }
  //prompt user to enter matrix entries by row
  for(i=0; i < n; i++)
  {
      printf("Enter values for row %d of the matrix:\n", i);
      //input the row entries and store into array
      for(j=0; j < m; j++)
      {
        scanf("%f", (arrayPtr + m*i + j));
      }
  }
  return arrayPtr;
}


 void printMatrix(float *matPtr, int n, int m)
 /***********************************************************************************
 *Description: This function prints the matrix pointed to by matPtr in matrix form.
 * inputs: matPtr is a pointer to a matrix of floats. The dimension of the matrix is n x m.
 *outputs: none.
 ***********************************************************************************/
{
    //initializing variables
    int i;
    int j;

    //looping though matrix passed through function
    for(i=0;i<n;i++)
    {
      for(j=0;j<m;j++)
      {
        printf("%.2f\t", *(matPtr + i*m + j));  //each value of the matrix is printed, in order, as the matrix is looped through
      }
    printf("\n");
    }
}



 float*  addMatrices(float *aPtr, float *bPtr, int n, int m)
 /**********************************************************************************
 *Description: The function adds the array pointed to by aPtr (dimension n x m)
 *and the array pointed to by bPtr (dimension n x m) and returns a pointer to a
 *dynamically allocated array that holds the result matrix (dimension n x m)
 *in by-row order.
 *inputs: aPtr and bPtr are pointers to matrices stored in by-row order. The
 *       matrices are of dimension n x m.
 *output: The function returns a pointer to a dynamically allocated array that holds
 *        the result of adding the input matrices.  The result is an n x m matrix stored in
 *        by-row order. The input arrays are not changed.
 ***********************************************************************************/
{
    //initializing variables
    int i;
    int j;
    float *cPtr;

    //allocating array to hold matrix
    cPtr = (float *)malloc(n*m*sizeof(float));

    if(cPtr!=NULL)
        {
        for(i=0;i<n;i++) //looping through matrices (pointers) passed through function
        {
          for(j=0;j<m;j++)
          {
                *(cPtr + i*m +j) = *(aPtr + i*m + j) + *(bPtr + i*m + j); //aPtr is added to bPtr by value, in order. These values are assigned to cPtr
                                                                          //in order which is the resulting matrix.
          }
        }
    }

return cPtr;   //the resulting matrix (cPtr) is returned
}


 float*  transposeMatrix(float *matPtr, int n, int m)
 /**********************************************************************************
 *Description: This function transposes the array pointed to by matPtr (dimension n x m) and returns
 *a pointer to a dynamically allocated array that holds the result matrix (dimension m x n)
 *in by-row order.
 *inputs: matPtr is a pointer a to an n x m matrix stored in by-row order.
 *output: The function returns a pointer to a dynamically allocated array that holds the
 *        transpose of the input matrix. The result is an m x n matrix stored in by-row order.
         The input matrix is not modified.
 ***********************************************************************************/
{
    //initializing variables
    int i;
    int j;
    float *ptrTrans;

    //allocating array to hold matrix
    ptrTrans = (float *)malloc(n*m*sizeof(float));

    if(ptrTrans!=NULL)
    {
        for(i=0;i<n;i++)  //this loop transposes the matrix passed through the function and stores it in ptrTrans (the resultant pointer)
        {
            for(j=0;j<m;j++)
            {
                *(ptrTrans + j*n + i) = *(matPtr + i*m + j);
            }
        }
    }
    return ptrTrans;
}


 float*  multMatrices(float *aPtr, float *bptr, int n, int m, int p)
 /**********************************************************************************
 *Description: This function multiplies the matrix  pointed to by aPtr (dimension n x m)
 *and the matrix pointed to by bPtr (dimension m x p) and returns a pointer to a
 *dynamically allocated array that holds the result matrix (dimension n x p) in by-row order.
 *inputs: aPtr and bPtr are pointers to matrices stored in by-row order. The matrix
 *        pointed to by aPtr is of dimension n x m. The matrix pointed to by bPtr is of
 *        dimension m x p.
 *output: The function returns a pointer to a dynamically allocated array that holds
 *        the result of multiplying the input matrices.  The result is an n x p matrix
 * 	  stored in by-row order.
 *************************************************************************************/
{
    //initializing variables
    int i;
    int j;
    int k;
    float *ptrMult;

    //allocating array to hold matrix
    ptrMult = (float *)malloc(n*m*sizeof(float));

    if(ptrMult!=NULL)
    {
        for(i=0;i<n;i++) //this loop initializes all elements of ptrMult (the resultant pointer) to zero
        {
            for(j=0;j<m;j++)
            {
                *(ptrMult + i*m+ j) = 0;
            }
        }
    }

        for(i=0;i<n;i++)  //this loop multiplies the two matrices passed through the function and stores them in ptrMult
        {
            for(j=0;j<p;j++)
            {
                for(k=0;k<m;k++)
                {
                    *(ptrMult + i*m + j) = *(ptrMult + i*m+j) + ((*(aPtr + i*m + k))*(*(bptr + k*n + j)));
                }
            }
        }

    return ptrMult;
}