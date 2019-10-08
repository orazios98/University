package app;

class PrintUpperCase implements PrintMode
{
    @Override
    public void print(String s)
    {
        System.out.println(s.toUpperCase());
    }
}

class PrintLowerCase implements PrintMode{
    @Override
    public void print(String s)
    {
        System.out.println(s.toLowerCase());
    }
}

public class Main1
{
    public static void main(String[] args) {
        HelloWorld hw = new HelloWorld();
        hw.printHelloWorld(new PrintUpperCase());
        hw.printHelloWorld(new PrintLowerCase());    
    }
}