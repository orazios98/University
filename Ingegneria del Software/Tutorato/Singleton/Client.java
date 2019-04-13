public class Client{
    public static void main(String[] args)
    {
        Quicker q=Quicker.getInstance();
        System.out.println(q.getNextValue());
    }
}