package com.company;

public class Accovacciato implements  Postura {
    @Override
    public void spara() {
        System.out.println("100 danni");

    }

    @Override
    public void impreca() {
        System.out.println("******");
    }

    @Override
    public String getName() {
        return "Accovacciato";
    }
}
