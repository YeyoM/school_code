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
public class VectorExample {
    public static void main(String[] args) {
        // Longitud del vector
        int n = 5;
  
        // Declarando el vector v de longitud n
        Vector<Integer> v = new Vector<Integer>(n);
  
        // Agregando elementos al vector (al final)
        for (int i = 1; i <= n; i++)
            v.add(i);
  
        // Mostramos los elementos
        System.out.println(v);
  
        // Quitarl el elemento en el indice 3
        v.remove(3);
  
        // Mostramos el vector
        System.out.println(v);
  
        // Mostramos el vector elemento por elemento
        for (int i = 0; i < v.size(); i++)
            System.out.print(v.get(i) + " ");
    }
}
