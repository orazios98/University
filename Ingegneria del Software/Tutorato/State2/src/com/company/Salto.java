package com.company;

public class Salto implements Postura {
    @Override
    public void spara() {
        System.out.println("CRETINO, sto saltando, come faccio a sparare?");
    }

    @Override
    public void impreca() {
        System.out.println("******");
    }

    @Override
    public Postura up() {
        return new Sdraiato();
    }

    @Override
    public Postura down() {
        return new InPiedi();
    }
}
