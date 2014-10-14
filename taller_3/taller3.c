#include <stdio.h>
#include <stdlib.h>
float *load_matrix(char *filename, int *n, int *m);
//float *multiplicacion(float *matrix, int *n, int *m);
int main(int argc, char **argv){
  float *matrix,*C;
  int n_row, n_cols;
  int i, j,k;

  matrix = load_matrix(argv[1], &n_row, &n_cols);
  C=load_matrix(argv[1], &n_row, &n_cols);
  for(i=0;i<n_row;i++){
    for(j=0;j<n_cols;j++){
      printf(" %f ", matrix[i*n_cols + j]);
    }
    printf("\n");
  }
printf("\n");
printf("Esta es la matriz de multiplicación\n");
//multiplicacion(matrix,&n_row, &n_cols);
return 0;
}

float *load_matrix(char *filename, int *n, int *m){
  float *matrix,*C;
  FILE *in;
  int n_row, n_cols;
  int i;
  int j,k;

  if(!(in=fopen(filename, "r"))){
    printf("Problem opening file %s\n", filename);
    exit(1);
  }
}
//float *multiplicacion(float *matrix, int *n, int *m){
//float C;
//float *A;
//int n_row, n_cols;
 //int i;
//  int j,k;
//for(i=0;i<n_row;i++){
//      for(j=0;j<n_cols;j++){
//          C=0;
    //      for(k=0;k<n_cols;k++){
  //            C=(matrix[i*n_cols+k]*matrix[k*n_cols+j])+C;
//	  }
	  
//	  A[i*n_cols+j]=C;
	//printf(" %f ", A[i*n_cols + j]);
//	}
      // printf("\n");
// }
//return A;
//}
