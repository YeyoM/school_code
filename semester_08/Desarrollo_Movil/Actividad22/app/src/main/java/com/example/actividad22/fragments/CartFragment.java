package com.example.actividad22.fragments;

import android.annotation.SuppressLint;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.Fragment;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.example.actividad22.R;
import com.example.actividad22.adapters.CartAdapter;
import com.example.actividad22.models.ShoppingCart;

public class CartFragment extends Fragment {

    private CartAdapter adapter;
    private TextView totalTextView;
    private ShoppingCart cart;

    @SuppressLint("NotifyDataSetChanged")
    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_cart, container, false);

        // Inicializar componentes
        RecyclerView recyclerView = view.findViewById(R.id.cart_recycler_view);
        totalTextView = view.findViewById(R.id.tv_total);
        Button checkoutButton = view.findViewById(R.id.btn_checkout);
        Button clearCartButton = view.findViewById(R.id.btn_clear_cart);

        // Obtener instancia del carrito
        cart = ShoppingCart.getInstance();

        // Configurar RecyclerView
        recyclerView.setLayoutManager(new LinearLayoutManager(getContext()));
        adapter = new CartAdapter(cart.getCartItems());
        recyclerView.setAdapter(adapter);

        // Actualizar el total
        updateTotal();

        // Configurar botones
        checkoutButton.setOnClickListener(v -> {
            if (cart.getItemCount() > 0) {
                Toast.makeText(getContext(), "Processing...", Toast.LENGTH_SHORT).show();
                // Aquí se implementaría la lógica de finalización del pedido
            } else {
                Toast.makeText(getContext(), "Your cart is empty", Toast.LENGTH_SHORT).show();
            }
        });

        clearCartButton.setOnClickListener(v -> {
            cart.clearCart();
            adapter.notifyDataSetChanged();
            updateTotal();
            Toast.makeText(getContext(), "Empty Cart", Toast.LENGTH_SHORT).show();
        });

        return view;
    }

    @SuppressLint("NotifyDataSetChanged")
    @Override
    public void onResume() {
        super.onResume();
        // Actualizar la UI cuando el fragment se muestra
        adapter.notifyDataSetChanged();
        updateTotal();
    }

    @SuppressLint("DefaultLocale")
    private void updateTotal() {
        totalTextView.setText(String.format("Total: $%.2f", cart.getTotal()));
    }
}