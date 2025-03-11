package com.example.actividad14;

import android.annotation.SuppressLint;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;
import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

public class DiziAdapter extends RecyclerView.Adapter<DiziAdapter.tanimla> {
    Context context;
    List<DiziModel> list;

    public DiziAdapter(Context context, List<DiziModel> list) {
        this.context = context;
        this.list = list;
    }

    @NonNull
    @Override
    public tanimla onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(context).inflate(R.layout.layout, parent, false);
        return new tanimla(view);
    }

    @Override
    public void onBindViewHolder(@NonNull tanimla holder, @SuppressLint("RecyclerView") final int position) {

        holder.dizi_Adi.setText(list.get(position).getDiziAdi());
        holder.dizi_Yil.setText(list.get(position).getDiziYapimYili());
        holder.dizi_Platform.setText(list.get(position).getDiziKanal());
        holder.dizi_Resim.setImageResource(list.get(position).getDiziResimi());

        holder.dizi_Resim.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(context, list.get(position).getDiziAdi(), Toast.LENGTH_SHORT).show();
            }
        });

    }

    @Override
    public int getItemCount() {
        return list.size();
    }

    public class tanimla extends RecyclerView.ViewHolder {

        ImageView dizi_Resim;
        TextView dizi_Adi;
        TextView dizi_Yil;
        TextView dizi_Platform;

        public tanimla(@NonNull View itemView) {
            super(itemView);

            dizi_Resim = itemView.findViewById(R.id.imageview_resim);
            dizi_Adi = itemView.findViewById(R.id.textview_dizi_adi);
            dizi_Yil = itemView.findViewById(R.id.textview_dizi_yapim_yili);
            dizi_Platform = itemView.findViewById(R.id.textview_dizi_platform);


        }
    }

}