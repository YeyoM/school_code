package com.example.actividad14;

public class DiziModel {

    int diziResimi;
    String diziAdi;
    String diziYapimYili;
    String diziKanal;

    public DiziModel(int diziResimi, String diziAdi, String diziYapimYili, String diziKanal) {
        this.diziResimi = diziResimi;
        this.diziAdi = diziAdi;
        this.diziYapimYili = diziYapimYili;
        this.diziKanal = diziKanal;
    }

    public int getDiziResimi() {
        return diziResimi;
    }

    public void setDiziResimi(int diziResimi) {
        this.diziResimi = diziResimi;
    }

    public String getDiziAdi() {
        return diziAdi;
    }

    public void setDiziAdi(String diziAdi) {
        this.diziAdi = diziAdi;
    }

    public String getDiziYapimYili() {
        return diziYapimYili;
    }

    public void setDiziYapimYili(String diziYapimYili) {
        this.diziYapimYili = diziYapimYili;
    }

    public String getDiziKanal() {
        return diziKanal;
    }

    public void setDiziKanal(String diziKanal) {
        this.diziKanal = diziKanal;
    }
}
