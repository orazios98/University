package com.company;

public class Berlina implements Auto {

    private Motore m;

    public Berlina(Motore x)
    {
        m = x;
    }

    @Override
    public String getTipo() {
        return "Berlina";
    }

    @Override
    public int getPeso() {
        return 800;
    }

    @Override
    public float getDistanza(int t) {
        return (float) t * t * m.getPotenza() / getPeso();
    }
}
