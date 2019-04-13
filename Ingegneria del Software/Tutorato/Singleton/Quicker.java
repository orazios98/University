public class Quicker
{
    private string[] s={"pippo","pluto","topolino"};
    private int x;
    private static Quicker t;
    private Quicker()
    {
        t=new Quicker();
        x=0;
    }

    public String getNextValue()
    {
        if(x>2) x=0;
        return
    }
}