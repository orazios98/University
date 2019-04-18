package com.company;

public class InPiedi implements Postura {
    @Override
    public void spara() {
        System.out.println("50 danni");
    }

    @Override
    public void impreca() {
        System.out.println("*****");
    }

    @Override
    public String getName() {
        return "InPiedi";

    }
}
