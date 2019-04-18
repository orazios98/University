package com.company;

public class Main {

    public static void main(String[] args) {
        Auto a1 = Garage.getBerlina(10000);
        Auto a2 = Garage.getMini(100);

        int t=10;

        System.out.println(a1.getTipo() + " = " + a1.getDistanza(t));
        System.out.println(a2.getTipo() + " = " + a2.getDistanza(t));
	// write your code here
    }
}
