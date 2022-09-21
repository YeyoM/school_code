import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public class files {
  public static void main(String[] args) {
    int arr[] = {11, 21, 3, 40, 5};
    try {
      OutputStream os = new FileOutputStream("text.txt");
      for (int i = 0; i < arr.length; i++) {
        os.write(arr[i]);
      }
      InputStream file = new FileInputStream("text.txt");
      int size = file.available();
      for (int j = 0; j < size; j++) {
        System.out.println(file.read() + "");
      }
      file.close();
      os.close();
    } catch (IOException e) {
      System.out.println("exception");
    }
  }
}
