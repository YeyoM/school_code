import java.util.Random;

public class main {
  public static void main(String[] args){
  
    Random rand = new Random();
    int[] calificaciones = new int[10];

    for (int i = 0; i < calificaciones.length; i++) {
      calificaciones[i] = rand.nextInt(10);
    }

    for (int i = 0; i < calificaciones.length; i++) {
      System.out.println(calificaciones[i]);
    }

  }
}
