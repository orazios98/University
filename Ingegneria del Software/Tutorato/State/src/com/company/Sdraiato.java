package com.company;

public class Sdraiato implements Postura {
    @Override
    public void spara() {
        System.out.println("200 danni");
    }

    @Override
    public void impreca() {
        System.out.println("per adesso non voglio imprecare");
    }

    @Override
    public String getName() {
        return "Sdraiato";
    }
}
