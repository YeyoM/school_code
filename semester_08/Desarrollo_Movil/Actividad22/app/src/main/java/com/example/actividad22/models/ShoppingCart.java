package com.example.actividad22.models;

import java.util.ArrayList;
import java.util.List;
public class ShoppingCart {
    private static ShoppingCart instance;
    private final List<CartItem> cartItems;

    private ShoppingCart() {
        cartItems = new ArrayList<>();
    }

    public static ShoppingCart getInstance() {
        if (instance == null) {
            instance = new ShoppingCart();
        }
        return instance;
    }

    public void addItem(MenuItem menuItem) {
        // Comprobar si el elemento ya está en el carrito
        for (CartItem item : cartItems) {
            if (item.getMenuItem().getId() == menuItem.getId()) {
                // Si ya está, incrementar la cantidad
                item.setQuantity(item.getQuantity() + 1);
                return;
            }
        }
        // Si no está, añadir nuevo elemento
        cartItems.add(new CartItem(menuItem, 1));
    }

    public void removeItem(int menuItemId) {
        for (int i = 0; i < cartItems.size(); i++) {
            if (cartItems.get(i).getMenuItem().getId() == menuItemId) {
                cartItems.remove(i);
                return;
            }
        }
    }

    public void updateQuantity(int menuItemId, int quantity) {
        for (CartItem item : cartItems) {
            if (item.getMenuItem().getId() == menuItemId) {
                if (quantity <= 0) {
                    removeItem(menuItemId);
                } else {
                    item.setQuantity(quantity);
                }
                return;
            }
        }
    }

    public List<CartItem> getCartItems() {
        return cartItems;
    }

    public void clearCart() {
        cartItems.clear();
    }

    public double getTotal() {
        double total = 0;
        for (CartItem item : cartItems) {
            total += item.getSubtotal();
        }
        return total;
    }

    public int getItemCount() {
        int count = 0;
        for (CartItem item : cartItems) {
            count += item.getQuantity();
        }
        return count;
    }
}