public class principal {
  public static void main(String[] args)
  {
      nube nube1 = new nube(10, 20);
      nube nube2 = new nube(12,21);

      if(nube1.rain() > nube2.rain())
      {
          System.out.println("nube 1 es mayor");
      }
      if(nube1.rain() < nube2.rain())
      {
          System.out.println("nube 2 es mayor");
      }
  }
}