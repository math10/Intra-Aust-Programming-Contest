// Alter - Shibli
import java.util.Scanner;
import java.math.*;

/*
 * Number of binary trees which has N elements:
 *
 *      (2N)!
 * ---------------
 *  (N + 1)! * N!
 *
 *  http://en.wikipedia.org/wiki/Catalan_number
 *
 *
 * In order to speed up Catalan number calculation
 * we find a pattern for calculating current Catalan
 * number using previous one (it is very slow to
 * simply precalculate 1000 answers by using the
 * formula above)
 *
 *      (2 * (N + 1))!
 *  --------------------------- =
 *  ((N + 1) + 1)! * (N + 1)!
 *
 *       (2N + 2) * (2N + 1) * 2N!
 *  ---------------------------------- =
 *  (N + 1) * (N + 2) * N! * (N + 1)!
 *
 *  (2N + 2) * (2N + 1)
 *  ------------------- * CATALAN(N)
 *   (N + 1) * (N + 2)
 */

public class Main {

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        BigInteger arr[] = new BigInteger[2000];

        BigInteger a,b,c,d,e,f,g;
        g = new BigInteger("1000000007");

        arr[0] = BigInteger.valueOf(1);
        arr[1] = BigInteger.valueOf(1);

        for(int i = 2; i <= 1999; i++ )
        {
            arr[i] = arr[i-1].multiply(BigInteger.valueOf(i));
        }
        while( sc.hasNext() )
        {
           int t = sc.nextInt();
           for(int kase = 1; kase <= t; kase++ )
           {
               int n = sc.nextInt();
               int x,y,z;
               x = 2*n;
               y = n+1;
               z = n;
               a = arr[x];
               b = arr[y];
               c = arr[z];
               e = a.divide(b.multiply(c));
               f = e.mod(g);
               System.out.println(f);

           }
        }
    }
}


