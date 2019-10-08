public class TestAlgo
{
    Algo a = new Algo();

    public static void main(String[] args) {
        TestAlgo t = new TestAlgo();

        t.testAltb();
        
    }

    private void testAltb()
    {
        String ret = a.compare(0,1);
        if(ret.equals("A < B"))
            System.out.println("OK testAltB");
        else
            System.out.println("Failed testAltB");
    }
}