package com.example.actividad22.adapters;

import android.annotation.SuppressLint;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.example.actividad22.R;
import com.example.actividad22.models.CartItem;
import com.example.actividad22.models.ShoppingCart;

import java.util.List;
public class CartAdapter extends RecyclerView.Adapter<CartAdapter.CartViewHolder> {

    private final List<CartItem> cartItems;
    private final ShoppingCart cart;

    public CartAdapter(List<CartItem> cartItems) {
        this.cartItems = cartItems;
        this.cart = ShoppingCart.getInstance();
    }

    @NonNull
    @Override
    public CartViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_cart, parent, false);
        return new CartViewHolder(view);
    }

    @SuppressLint({"DefaultLocale", "NotifyDataSetChanged"})
    @Override
    public void onBindViewHolder(@NonNull CartViewHolder holder, int position) {
        CartItem item = cartItems.get(position);

        holder.nameTextView.setText(item.getMenuItem().getName());
        holder.priceTextView.setText(String.format("$%.2f", item.getMenuItem().getPrice()));
        holder.quantityTextView.setText(String.valueOf(item.getQuantity()));
        holder.subtotalTextView.setText(String.format("$%.2f", item.getSubtotal()));
        holder.imageView.setImageResource(item.getMenuItem().getImageResource());

        // Configurar botones de cantidad
        holder.btnIncrease.setOnClickListener(v -> {
            cart.updateQuantity(item.getMenuItem().getId(), item.getQuantity() + 1);
            notifyDataSetChanged();
        });

        holder.btnDecrease.setOnClickListener(v -> {
            if (item.getQuantity() > 1) {
                cart.updateQuantity(item.getMenuItem().getId(), item.getQuantity() - 1);
            } else {
                cart.removeItem(item.getMenuItem().getId());
            }
            notifyDataSetChanged();
        });

        holder.btnRemove.setOnClickListener(v -> {
            cart.removeItem(item.getMenuItem().getId());
            notifyDataSetChanged();
        });
    }

    @Override
    public int getItemCount() {
        return cartItems.size();
    }

    public static class CartViewHolder extends RecyclerView.ViewHolder {
        ImageView imageView;
        TextView nameTextView;
        TextView priceTextView;
        TextView quantityTextView;
        TextView subtotalTextView;
        Button btnIncrease;
        Button btnDecrease;
        Button btnRemove;

        public CartViewHolder(@NonNull View itemView) {
            super(itemView);
            imageView = itemView.findViewById(R.id.product_image);
            nameTextView = itemView.findViewById(R.id.product_title);
            priceTextView = itemView.findViewById(R.id.product_price);
            quantityTextView = itemView.findViewById(R.id.cart_item_quantity);
            subtotalTextView = itemView.findViewById(R.id.product_price);
            btnIncrease = itemView.findViewById(R.id.btn_increase);
            btnDecrease = itemView.findViewById(R.id.btn_decrease);
            btnRemove = itemView.findViewById(R.id.button_remove);
        }
    }
}
