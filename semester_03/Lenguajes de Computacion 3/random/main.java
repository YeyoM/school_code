import java.util.Random;

public class main {
  public static void main(String[] args){
  
    Random rand = new Random();
    int[] calificaciones = new int[10];
    int calificaiones10 = 0, calificaciones9 = 0, calificacionesMenores = 0;

    for (int i = 0; i < calificaciones.length; i++) {
      calificaciones[i] = rand.nextInt(10);
      System.out.println(calificaciones[i]);
      switch (calificaciones[i]) {
        case 10:
          calificaiones10++;
          break;
        case 9:
          calificaciones9++;
          break;
        default:
          calificacionesMenores++;
          break;
      }
    }

    System.out.println("Calificaciones de 10: " + calificaiones10);
    System.out.println("Calificaciones de 9: " + calificaciones9);
    System.out.println("Calificaciones menores a 9: " + calificacionesMenores);

  }
}
