#include <stdio.h>
#include <stdlib.h>
float *load_matrix(char *filename, int *n, int *m);
float *multiplicacion(float *matrix, int n, int m);
float *mult_n(float *matrix, int n_row, int n_cols,int n );
float *suma_mult_n(float *matrix,int n_row, int n_cols,int n);
float factorial(int n);

int main(int argc, char **argv){
  float *matrix,*C,*F,*D;
  int n_row, n_cols;
  int i, j,k;
  float fact;

  matrix = load_matrix(argv[1], &n_row, &n_cols);
  C= load_matrix(argv[1], &n_row, &n_cols);

 
  
for(i=0;i<n_row;i++){
      for(j=0;j<n_cols;j++){
	
	C[i*n_cols + j]=0;
	}
}

D=suma_mult_n(matrix,n_row, n_cols,10);


for(i=0;i<n_row;i++){
    for(j=0;j<n_cols;j++){
      printf(" %f ", D[i*n_cols + j]);
    }
    printf("\n");
  }
printf("\n"); 


//fact=factorial(5);

//printf("aqui va el factorial %f",fact);
//printf("\n");
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

  fscanf(in, "%d %d\n", &n_row, &n_cols);
  printf("%d %d\n", n_row, n_cols);

  matrix = malloc(n_row * n_cols * sizeof(float));

  for(i=0;i<n_row;i++){
    for(j=0;j<n_cols;j++){
      fscanf(in, "%f", &matrix[i*n_cols + j]);
    }
  }    
 
  *n = n_row;
  *m = n_cols;
  return matrix;
}

float *multiplicacion(float *matrix, int n_row, int n_cols ){
float *D;
float *A;

int i;
int j,k;
 A = malloc(n_row * n_cols * sizeof(float));
 
for(i=0;i<n_row;i++){
      for(j=0;j<n_cols;j++){
	A[i*n_cols+j]=0;
              for(k=0;k<n_cols;k++){
	            A[i*n_cols+j]=(matrix[i*n_cols+k]*matrix[k*n_cols+j])+A[i*n_cols+j];
	  }
	  
	
	//printf(" %f ", A[i*n_cols + j]);
	}
      // printf("\n");
 }
return A;
}









float *mult_n(float *matrix, int n_row, int n_cols,int n){
int i;

	for(i=0;i<=n;i++){
	matrix=multiplicacion(matrix,n_row, n_cols);

	}
return matrix;

}


float *suma_mult_n(float *matrix,int n_row, int n_cols,int n){
int i,j,k;
float *matriz_n,*matriz_i;
matriz_n = malloc(n_row * n_cols * sizeof(float));
matriz_i = malloc(n_row * n_cols * sizeof(float));

for(j=0;j<n_row;j++){
     		 for(k=0;k<n_cols;k++){
		matriz_i[j*n_cols+k]=0;
		}
}


for(i=0;i<n;i++){	
	matriz_n=mult_n(matrix,n_row, n_cols,i);
	for(j=0;j<n_row;j++){
     		 for(k=0;k<n_cols;k++){
				
				matriz_i[j*n_cols+k]=matriz_i[j*n_cols+k]+matriz_n[j*n_cols+k]/factorial(i);
			}
		}
	}
return matriz_i;
}

float factorial(int n){
int i,x;
x=1;
 for(i=1;i<=n;i++){
	x=x*i;
}

return x;
}

