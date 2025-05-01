package com.example.actividad22.adapters;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;
import android.annotation.SuppressLint;

import com.example.actividad22.R;
import com.example.actividad22.models.MenuItem;
import com.example.actividad22.models.ShoppingCart;

import java.util.List;
public class MenuAdapter extends RecyclerView.Adapter<MenuAdapter.MenuViewHolder> {

    private List<MenuItem> menuItems;
    private ShoppingCart cart;

    public MenuAdapter(List<MenuItem> menuItems) {
        this.menuItems = menuItems;
        this.cart = ShoppingCart.getInstance();
    }

    @NonNull
    @Override
    public MenuViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_menu, parent, false);
        return new MenuViewHolder(view);
    }

    @SuppressLint("DefaultLocale")
    @Override
    public void onBindViewHolder(@NonNull MenuViewHolder holder, int position) {
        MenuItem item = menuItems.get(position);

        holder.nameTextView.setText(item.getName());
        holder.descriptionTextView.setText(item.getDescription());
        holder.priceTextView.setText(String.format("$%.2f", item.getPrice()));
        holder.imageView.setImageResource(item.getImageResource());

        // Configurar el botón para añadir al carrito
        holder.addToCartButton.setOnClickListener(view -> {
            cart.addItem(item);
            Toast.makeText(view.getContext(),
                    item.getName() + " added to the cart",
                    Toast.LENGTH_SHORT).show();
        });
    }

    @Override
    public int getItemCount() {
        return menuItems.size();
    }

    // ViewHolder para los elementos del menú
    public static class MenuViewHolder extends RecyclerView.ViewHolder {
        ImageView imageView;
        TextView nameTextView;
        TextView descriptionTextView;
        TextView priceTextView;
        Button addToCartButton;

        public MenuViewHolder(@NonNull View itemView) {
            super(itemView);
            imageView = itemView.findViewById(R.id.item_image);
            nameTextView = itemView.findViewById(R.id.item_name);
            descriptionTextView = itemView.findViewById(R.id.item_description);
            priceTextView = itemView.findViewById(R.id.item_price);
            addToCartButton = itemView.findViewById(R.id.btn_add_to_cart);
        }
    }
}
