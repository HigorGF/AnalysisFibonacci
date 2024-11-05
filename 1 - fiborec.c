#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>  // gettimeofday

int callOrder=0;

void indent(int n) {
  for (int i=0;i<n;i++) {
    putchar('\t');
  }
}

//Teste

long int fibonaccir(long int n, int nivel) {
	//indent(nivel);
	//printf ("%02d - Entrou no cálculo de F(%ld). \n", ++callOrder, n);
	if(n <= 1) {
		return n;
	} else {
		int aux1=fibonaccir(n-1, nivel+1);
		//indent(nivel);
		//printf ("%02d - Retornou ao cálculo de F(%ld). \n", ++callOrder, n);
		int aux2=fibonaccir(n-2, nivel+1);
		//indent(nivel);
		//printf ("%02d - Retornou ao cálculo de F(%ld). \n", ++callOrder, n);
		return ( aux1 + aux2);
	}
}

void main (void) {
    struct timeval begin, end;
    gettimeofday(&begin, 0);

    printf ("%ld \n", fibonaccir(40,0));

    gettimeofday(&end, 0);

    long seconds = end.tv_sec - begin.tv_sec;
    long microseconds = end.tv_usec - begin.tv_usec;
    long elapsed = seconds*1e6 + microseconds;
    printf("\n HEREEEE %ld\t \n", elapsed);
}