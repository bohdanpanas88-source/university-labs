public class Main
{
    public static void main(String[] args)
    {
        // Cap
        System.out.println("\tFirst tabulation");
        System.out.println("\t------------------");
        System.out.println("\t|  krok    |  y  |");
        System.out.println("\t------------------");

        int start_1 = 0; // start tabulation
        int end_1 = 5; // end tabulation
        double tab_1 = 0.5; // steps
        double y; // variable

        // function of tabulation
        for(double i = start_1; i <= end_1; i += tab_1)
        {
            y = Math.pow(4 * Math.pow(i, 3) + Math.pow(i, 2), 0.25);
            System.out.printf("\t%4f | %4f%n", i, y); // outputs
            System.out.println("\t------------------");
        }

        System.out.println("\n");

        // Cap
        System.out.println("\tSecond tabulation");
        System.out.println("\t------------------");
        System.out.println("\t|  krok    |  y  |");
        System.out.println("\t------------------");

        double start_2 = -10; // start tabulation
        int end_2 = 10; // end tabulation
        int tab_2 = 2; // steps

        // function of tabulation
        while(start_2 <= end_2)
        {
            if(start_2 < 0)
            {
                y = Math.sin(Math.cos(start_2));
            } else {
                y = Math.cos(Math.sin(start_2));
            }
            System.out.printf("\t%4f | %4f%n", start_2, y); // outputs
            System.out.println("\t------------------");
            start_2 += tab_2;
        }
    }
}
