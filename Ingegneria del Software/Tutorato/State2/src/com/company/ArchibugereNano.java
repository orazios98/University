package com.company;

public class ArchibugereNano {

    private Postura p;

    ArchibugereNano()
    {
        p=new InPiedi();
    }

    public void spara()
    {
        p.spara();
    }

    public void insultaElfo(){
        p.impreca();
    }

    public void alza()
    {
        p=p.up();

    }
    public void abbassa()
    {
        p=p.down();

    }
}
