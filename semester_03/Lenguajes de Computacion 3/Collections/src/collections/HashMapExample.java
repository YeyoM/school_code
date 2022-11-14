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
public class HashMapExample {
     public static void main(String args[])
    {
        // Declaramos
        HashMap<Integer, String> hm1 = new HashMap<>();
 
        // Declaramos (forma 2)
        HashMap<Integer, String> hm2 = new HashMap<Integer, String>();
 
        // Agregamos elementos
        hm1.put(1, "one");
        hm1.put(2, "two");
        hm1.put(3, "three");
 
        hm2.put(4, "four");
        hm2.put(5, "five");
        hm2.put(6, "six");
 
        // Mostramos los elementos
        System.out.println("Mappings of HashMap hm1 are : "
                           + hm1);
    
        // Mostramos los elementos
        System.out.println("Mapping of HashMap hm2 are : "
                           + hm2);
    }
}
