package com.example.proyectoparcial2_1;

public class MenuItem {
    private final String nombre;
    private final String descripcion;
    private final double precio;
    private final int imagenId;

    public MenuItem(String nombre, String descripcion, double precio, int imagenId) {
        this.nombre = nombre;
        this.descripcion = descripcion;
        this.precio = precio;
        this.imagenId = imagenId;
    }

    public String getNombre() {
        return nombre;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public double getPrecio() {
        return precio;
    }

    public int getImagenId() {
        return imagenId;
    }
}