package com.example.proyectoparcial2_2;

import android.annotation.SuppressLint;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

public class TravelAdapter extends RecyclerView.Adapter<TravelAdapter.TravelViewHolder> {

    private final Context context;
    private final List<TravelItem> travelItems;

    public TravelAdapter(Context context, List<TravelItem> travelItems) {
        this.context = context;
        this.travelItems = travelItems;
    }

    @NonNull
    @Override
    public TravelViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(context).inflate(R.layout.item_travel, parent, false);
        return new TravelViewHolder(view);
    }

    @SuppressLint({"SetTextI18n", "DefaultLocale"})
    @Override
    public void onBindViewHolder(@NonNull TravelViewHolder holder, int position) {
        TravelItem currentItem = travelItems.get(position);

        holder.destino.setText(currentItem.getDestino());
        holder.descripcion.setText(currentItem.getDescripcion());
        holder.precio.setText("$" + String.format("%.2f", currentItem.getPrecio()));
        holder.duracion.setText(currentItem.getDuracion());
        holder.imagen.setImageResource(currentItem.getImagenId());

        holder.btnReservar.setOnClickListener(v -> {
            Toast.makeText(context, "Viaje a " + currentItem.getDestino() + " reservado", Toast.LENGTH_SHORT).show();
        });
    }

    @Override
    public int getItemCount() {
        return travelItems.size();
    }

    public static class TravelViewHolder extends RecyclerView.ViewHolder {
        ImageView imagen;
        TextView destino, descripcion, precio, duracion;
        Button btnReservar;

        public TravelViewHolder(@NonNull View itemView) {
            super(itemView);
            imagen = itemView.findViewById(R.id.item_imagen);
            destino = itemView.findViewById(R.id.item_destino);
            descripcion = itemView.findViewById(R.id.item_descripcion);
            precio = itemView.findViewById(R.id.item_precio);
            duracion = itemView.findViewById(R.id.item_duracion);
            btnReservar = itemView.findViewById(R.id.btn_reservar);
        }
    }
}
