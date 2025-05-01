package com.example.actividad22.models;

public class MenuItem {
    private final int id;
    private final String name;
    private final String description;
    private final double price;
    private final int imageResource;

    public MenuItem(int id, String name, String description, double price, int imageResource) {
        this.id = id;
        this.name = name;
        this.description = description;
        this.price = price;
        this.imageResource = imageResource;
    }
    public int getId() {
        return id;
    }
    public String getName() {
        return name;
    }
    public String getDescription() {
        return description;
    }
    public double getPrice() {
        return price;
    }
    public int getImageResource() {
        return imageResource;
    }

}
