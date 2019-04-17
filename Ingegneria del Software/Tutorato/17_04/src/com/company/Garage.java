package com.company;

public class Garage {
    public static Auto getBerlina(int d)
    {
        return new Berlina(decision(d));
    }


    public static Auto getMini(int d)
    {
        return new Mini(decision(d));
    }

    private static Motore decision(int d)
    {
        if(d > 1000)
            return new Fire();
        else
            return new CommonRail();
    }
}
