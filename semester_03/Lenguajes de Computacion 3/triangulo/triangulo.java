public class triangulo {
  public static void main(String[] args) {
    int lado1 = 2;
    int lado2 = 4;
    int lado3 = 5;
    
    if (lado1 == lado2 && lado2 == lado3) {
      System.out.println("Equilatero");
    } else if (lado1 == lado2 || lado2 == lado3 || lado1 == lado3) {
      System.out.println("Isosceles");
    } else {
      System.out.println("Escaleno");
    }
  }
}
