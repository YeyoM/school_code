package com.example.proyectoparcial2_2;

public class TravelItem {
    private final String destino;
    private final String descripcion;
    private final double precio;
    private final int imagenId;
    private final String duracion;

    public TravelItem(String destino, String descripcion, double precio, int imagenId, String duracion) {
        this.destino = destino;
        this.descripcion = descripcion;
        this.precio = precio;
        this.imagenId = imagenId;
        this.duracion = duracion;
    }

    public String getDestino() {
        return destino;
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

    public String getDuracion() {
        return duracion;
    }
}
