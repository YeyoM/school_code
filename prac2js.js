// Aquí inicialio las variables para tener un  poco mas de control 
// No es necesario ni posible asignar que tipo de dato serán las variables
var resultado = 0
const n = 100
var factorial_n = 1
var factorial_n2 = 1


// A diferencia de C u otros lenguajes, javascript, no necesita
// Una función main, simplemente correrá los archivos y funciones
// Que nosotros vayamos llamando, se suele tener a diferencia
// Un archivo llamado main.js en proyectos grandes que será el 
// encargado llevar un orden
for (i = 2; i <= n; i++) {
    for (j = 2; j <= i; j++) {
        factorial_n = factorial_n * j;
    }
    for (k = 1; k <= (i - 2); k++) {
        factorial_n2 = factorial_n2 * k;   
    }
    resultado = (factorial_n) / (factorial_n2 * 2);
    // console.log() es la función equivalente a printf()
    console.log(`El resultado de las combinaciones de (${i}, 2) es:`);
    console.log(resultado);
    resultado = 0;
    factorial_n2 = 1;
    factorial_n = 1;
}