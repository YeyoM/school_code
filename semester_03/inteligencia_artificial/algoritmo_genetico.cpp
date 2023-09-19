

/* AG con elitismo se guarda en la primera posicion de la poblacion (poblacionActual[0])
el individuo mejor para que no se pierda y en cada generacion se actualiza. 
De este individuo, el algoritmo se asegura de sacar al menos una copia para
la seleccion y que asi pueda influir en la formacion de nuevos individuos 
a partir de individuo X dado y con un Y mejor encontrado */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANIO_POB 500
#define LONG_INDIV 200

//  Estructura para el individuo
struct individuo {
	int cromosoma[LONG_INDIV]; 
	int cantidadCeros; /*-------------IDENTIFICADOR DE LA FUNCI?N DE CEROMAX----------------*/
};

int longitud;
int numGeneraciones;
int tamanio;
float probMutacion;
float probCruza;
int numevaluaciones;

void Inicializar_Parametros(void);
void Inicializar_Poblacion(struct individuo *poblacionActual);
void Evaluar_Poblacion(struct individuo *poblacionActual);
int  Mejor_de_Poblacion(int generacion, struct individuo *poblacionActual);
void Seleccion_Individuos(struct individuo *poblacionActual, struct individuo *poblacionTemporal);
void Cruzamiento(struct individuo *poblacionActual, struct individuo *poblacionTemporal);
void Mutacion(struct individuo *poblacionActual);
void Imprimir_Mejor(struct individuo *poblacionActual);

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char *argv[]) {

	struct individuo poblacionActual [TAMANIO_POB];
	struct individuo poblacionTemporal [TAMANIO_POB];
	
	int generacion = 0;
	numevaluaciones=0;
	srand(time(NULL));
	Inicializar_Parametros();
	Inicializar_Poblacion(poblacionActual);
	do {
		printf("generacion %d\n", generacion);
		Evaluar_Poblacion(poblacionActual);
		if (Mejor_de_Poblacion(generacion, poblacionActual)==0) {
			system("PAUSE");
			return 0;
		}
		Seleccion_Individuos(poblacionActual, poblacionTemporal);
		Cruzamiento(poblacionActual, poblacionTemporal);
		Mutacion(poblacionActual);
		generacion++;
	} while (generacion < numGeneraciones);

	system("PAUSE");
	return 0;
}

void Inicializar_Parametros(void) {
	// leer los parAmetros del algoritmo genEtico
	printf
    ("Tamano maximo de la poblacion es 500 y tamano maximo del cromosoma es 200\n");
	printf("Longitud del cromosoma para el problema a resolver:");
	scanf("%d", &longitud);
	printf("NUmero de generaciones que evoluciona el AG:");
	scanf("%d", &numGeneraciones);
	printf("Tamanio de la poblaciOn simulada:");
	scanf("%d", &tamanio);
	printf("Probabilidad de mutacion:");
	scanf("%f", &probMutacion);
	printf("Probabilidad de cruzamiento:");
	scanf("%f", &probCruza);
	
}

void Inicializar_Poblacion(struct individuo *poblacionActual) {
	int i, j;
	
	for (i=0; i<tamanio; i++) {
		for (j=0; j<longitud; j++) {
			if ((rand()%100)+1 <= 50) {
				poblacionActual[i].cromosoma[j]=1;
			} else {
				poblacionActual[i].cromosoma[j]=0;
			}
		}
	}
}
void Evaluar_Poblacion(struct individuo *poblacionActual) { 
	int i, j;
	int ceros;/*------VARIABLE CONTABLE DE LOS CEROS-----*/

	for (i=0; i<tamanio; i++) {
		ceros=0;
		for (j=0; j<longitud; j++) {
			if (poblacionActual[i].cromosoma[j]==0) ceros++;
		}
		poblacionActual[i].cantidadCeros = ceros;
		numevaluaciones++;
	}
}
int  Mejor_de_Poblacion(int generacion, struct individuo *poblacionActual) {
	int i,j,t = 0;
	struct individuo temp, mejor;
	
	mejor = poblacionActual[0];
	for (i=1; i<tamanio; i++) {
		if (poblacionActual[i].cantidadCeros > mejor.cantidadCeros) {
			mejor = poblacionActual[i];
			t = i;  
		}
	}
	temp = poblacionActual[0];
	poblacionActual[0] = mejor;   // guardamos el mejor en la posiciOn 0 de la poblaciOn
	poblacionActual[t] = temp;
	printf("\nMejor soluciOn hasta la generacion %d\n", generacion);
	for (i=0; i < longitud; i++)
		printf("%d", poblacionActual[0].cromosoma[i]); 
	printf(" %d \n", poblacionActual[0].cantidadCeros); 
	printf("\nPoblacion Actual en la generacion %d\n", generacion);
	for(i=0; i < tamanio; i++) {
		for (j=0; j < longitud; j++) {
			printf("%d", poblacionActual[i].cromosoma[j]);
		}
		printf("  %d\n", poblacionActual[i].cantidadCeros);
	}
	printf("Enter\n");
	getchar();
	if (poblacionActual[0].cantidadCeros == longitud) {
		printf("La soluciOn Optima se obtuvo en la generaciOn: %d\n", generacion);
		numevaluaciones=numevaluaciones - (tamanio-t);
		printf("Numero de evaluaciones: %d\n", numevaluaciones);
		for (int i=0; i < longitud; i++)
		printf("%d", poblacionActual[0].cromosoma[i]); 
		printf("\n");
		return 0;
	}
	else return 1;
}
void Seleccion_Individuos(struct individuo *poblacionActual, struct individuo *poblacionTemporal) {
	int suma, i, j, cont;
	double probabilidades[TAMANIO_POB];
	double probabilidadAcumulativa[TAMANIO_POB];
	double aleatorio;
	
	// copiar el mejor individuo de la poblacion actual a la poblacion temporal
	poblacionTemporal[0]=poblacionActual[0];
	// primero suma las aptitudes de todos los individuos
	suma = 0;
	for (i=0; i<tamanio; i++) {
		suma += poblacionActual[i].cantidadCeros;
	}
	// obtener las probabilidades de selecciOn de cada individuo
	for (i=0; i<tamanio; i++) {
		probabilidades[i] = ((double)poblacionActual[i].cantidadCeros) / ((double)suma);
	}
	// calcular la probabilidad acumulativa
	probabilidadAcumulativa[0] = probabilidades[0];
	for (i=1; i<tamanio; i++) {
		probabilidadAcumulativa[i] = probabilidadAcumulativa[i-1] + probabilidades[i];
	}
	// girar la ruleta
	cont = 1; /* el mejor individuo esta en la posicion 0 garantiza 
				que este seleccionado al menos una vez,  por eso cont=1 */
	do {
		aleatorio = ((double)(rand()%100)+1) / 100.0;
		for (i=0; i<TAMANIO_POB; i++) { 
			if (aleatorio <= probabilidadAcumulativa[i]) {
				poblacionTemporal[cont] = poblacionActual[i];
				cont++;
				break;
			}
		}
	} while (cont < tamanio);
}

void Cruzamiento(struct individuo *poblacionActual, struct individuo *poblacionTemporal) {
	// generar una nueva poblaciOn por cruzamiento
int padre1;
int padre2;
int puntoCruza;
int hijo;
int i,j;

hijo = 1;
do {
		// generar dos nUmeros aleatorios diferentes
		padre1 = rand()%tamanio;
		do {
			padre2 = rand()%tamanio;
		} while (padre1 == padre2);
		// copiar los dos padres a la poblaciOn actual
		poblacionActual[hijo]   = poblacionTemporal[padre1];
		poblacionActual[hijo+1] = poblacionTemporal[padre2];
		if ((double)((rand()%100)+1)/100 < probCruza) {
		   puntoCruza= rand()%longitud;
		   for (i=puntoCruza; i< longitud; i++) {
		       poblacionActual[hijo].cromosoma[i] = poblacionTemporal[padre2].cromosoma[i];
			   poblacionActual[hijo+1].cromosoma[i] = poblacionTemporal[padre1].cromosoma[i];
		   }	
        }  
	hijo = hijo + 2;  // hijo debe ser actualizado en 2
	} while (hijo < (tamanio-1));
} // fin de Cruzamiento
	
void Mutacion(struct individuo *poblacionActual) {
	int i;
	int individuoQueMuta;
	int bitQueMuta;
	
	for (i=0; i<probMutacion*tamanio; i++) {
		individuoQueMuta = rand()%tamanio+1;
		bitQueMuta       = rand()%longitud;
		if (poblacionActual[individuoQueMuta].cromosoma[bitQueMuta]==0) {
			poblacionActual[individuoQueMuta].cromosoma[bitQueMuta] = 1;
		} else {
			poblacionActual[individuoQueMuta].cromosoma[bitQueMuta] = 0;
		}
	}
} // fin de la mutacion  
