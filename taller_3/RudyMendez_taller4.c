#include <stdio.h>
#include <stdlib.h>
// programa que tiene como entrada una matriz y como salida calcula la exponencial de esta matriz que es otra matriz, se imprime en pantalla
// se debe correr el archivo con cc RudyMendez_taller4.c matrix.dat
// la exponencial comienza a converger a los 10 primeros términos en las primeras dos decimales


float *load_matrix(char *filename, int *n, int *m);// función que carga la matriz
float *multiplicacion(float *matrix, int n, int m);//función que define la multiplicacion de dos matrices
float *mult_n(float *matrix, int n_row, int n_cols,int n );//función que define la multiplicacion de la misma matriz n veces
float *suma_mult_n(float *matrix,int n_row, int n_cols,int n);//función que realiza la sumatoria de la exponencial con n terminos
float factorial(int n);// función que define el factorial de un numero n

int main(int argc, char **argv){
  float *matrix,*C,*F,*D;
  int n_row, n_cols,n;
  int i, j,k;
  float fact;

  matrix = load_matrix(argv[1], &n_row, &n_cols);
 
n=10;// numero de terminos que se quieren en la sumatoria
D=suma_mult_n(matrix,n_row, n_cols,n);
printf("\n");
printf("La exponencial de la matriz de entrada es\n");
printf("\n"); 
for(i=0;i<n_row;i++){
    for(j=0;j<n_cols;j++){
      printf(" %f ", D[i*n_cols + j]);
    }
    printf("\n");
  }
printf("\n"); 

  return 0;
}

float *load_matrix(char *filename, int *n, int *m){
  float *matrix;
  FILE *in;
  int n_row, n_cols;
  int i;
  int j,k;

  if(!(in=fopen(filename, "r"))){
    printf("Problem opening file %s\n", filename);
    exit(1);
  }

  fscanf(in, "%d %d\n", &n_row, &n_cols);
 // printf("%d %d\n", n_row, n_cols);

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
	
	}
     
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

