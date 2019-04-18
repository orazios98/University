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

    public void insultaElfo(){}

    public void alza()
    {
        switch(p.getName())
        {
            case "InPiedi": p=new Salto(); break;
            case "Salto" : p=new Sdraiato(); break;
            case "Accovacciato" : p=new InPiedi(); break;
            case "Sdraiato" : p=new Accovacciato(); break;
        }

    }
    public void abbassa()
    {
        switch (p.getName())
        {
            case "InPiedi": p=new Accovacciato(); break;
            case "Salto" : p= new InPiedi(); break;
            case "Accovacciato" : p=new Sdraiato(); break;
            case "Sdraiato" : p=new Salto(); break;
        }
    }
}
