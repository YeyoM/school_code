public class trianguloclase {

    int a, b, c;
    
    public trianguloclase(int lado1, int lado2, int lado3) {
        a = lado1;
        b = lado2;
        c = lado3;
    }

    public String tipo() {
        if (a == b && b == c) {
            return "equilatero";
        } else if (a == b || b == c || a == c) {
            return "isosceles";
        } else {
            return "escaleno";
        }
    }
    
}