import java.math.BigInteger;
import java.util.Random;

public class Main
{
    public static void main(String[] args)
    {
        int n = 10, m = 10;
        int[][] Array = new int[n][m]; // advertisement array
        int factorial = 0;

        Random random = new Random();

        System.out.println("------------------------Array-----------------------");
        // These loops populate a two-dimensional array and also count the positive numbers along its perimeter.
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                Array[i][j] = random.nextInt(201) - 100; // [100 to -100]
                System.out.printf("%5d" , Array[i][j]);

                boolean Perimeter = (i == 0 || i == n - 1 || j == 0 || j == m - 1); // check perimeter

                if(Perimeter && Array[i][j] > 0) // condition
                {
                    factorial++;
                }
            }
            System.out.println();
        }
        System.out.println("Number of positive numbers on perimeter: " + factorial );

        BigInteger tempFactorial = BigInteger.ONE; // initializes a variable for working with very large integers

        // function for counting factorial
        for(int i = 1; i <= factorial; i++)
        {
            tempFactorial = tempFactorial.multiply(BigInteger.valueOf(i));
        }
        System.out.println("Factorial (" + factorial + "!): " + tempFactorial);

    }
}
