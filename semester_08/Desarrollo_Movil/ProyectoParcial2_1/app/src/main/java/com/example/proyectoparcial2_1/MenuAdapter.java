package com.example.proyectoparcial2_1;

import android.annotation.SuppressLint;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

public class MenuAdapter extends RecyclerView.Adapter<MenuAdapter.MenuViewHolder> {

    private final Context context;
    private final List<MenuItem> menuItems;

    public MenuAdapter(Context context, List<MenuItem> menuItems) {
        this.context = context;
        this.menuItems = menuItems;
    }

    @NonNull
    @Override
    public MenuViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(context).inflate(R.layout.item_menu, parent, false);
        return new MenuViewHolder(view);
    }

    @SuppressLint({"SetTextI18n", "DefaultLocale"})
    @Override
    public void onBindViewHolder(@NonNull MenuViewHolder holder, int position) {
        MenuItem currentItem = menuItems.get(position);

        holder.nombre.setText(currentItem.getNombre());
        holder.descripcion.setText(currentItem.getDescripcion());
        holder.precio.setText("$" + String.format("%.2f", currentItem.getPrecio()));
        holder.imagen.setImageResource(currentItem.getImagenId());
    }

    @Override
    public int getItemCount() {
        return menuItems.size();
    }

    public static class MenuViewHolder extends RecyclerView.ViewHolder {
        ImageView imagen;
        TextView nombre, descripcion, precio;

        public MenuViewHolder(@NonNull View itemView) {
            super(itemView);
            imagen = itemView.findViewById(R.id.item_imagen);
            nombre = itemView.findViewById(R.id.item_nombre);
            descripcion = itemView.findViewById(R.id.item_descripcion);
            precio = itemView.findViewById(R.id.item_precio);
        }
    }
}
