/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package collections;

import java.io.*;
import java.util.*;

/**
 *
 * @author Usuario
 */
public class ArrayListExample {
    public static void main(String[] args) {    
        
        // Declarando el arrayList 
        ArrayList<Integer> al = new ArrayList<Integer>();
  
        // Agregando elementos al final 
        for (int i = 1; i <= 5; i++)
            al.add(i);
  
        // Mostramos los elementos
        System.out.println(al);
  
        // Quitamos el elemento en el indice 3
        al.remove(3);
  
        // Mostramos los elementos
        System.out.println(al);

        // Mostramos el vector elemento por elemento
        for (int i = 0; i < al.size(); i++)
            System.out.print(al.get(i) + " ");
    }
}
