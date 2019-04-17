package com.company;

public class Mini extends Berlina{

    public Mini(Motore x)
    {
        super(x);
    }

    @Override
    public String getTipo() {
        return "Mini";
    }

    @Override
    public int getPeso() {
        return 600;
    }

}
