#include <stdio.h>

float base = 0,
      altu = 0,
      area = 0,
      peri = 0;

int main() {
    printf("Ingrese la medida de la base:\n");
    scanf("%f", &base);
    printf("Ingrese la medida de la altura:\n");
    scanf("%f", &altu);
    area = (base * altu) / 2;
    peri = (altu + altu) * 2;
    printf("Los resultados son:\narea: %.2f\nperimetro: %.2f", area, peri);
    return 0;
}
