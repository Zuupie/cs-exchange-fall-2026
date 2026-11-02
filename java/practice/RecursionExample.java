import java.util.Scanner;

public class RecursionExample {
    public static void main(String[] args){
        Scanner scnr = new Scanner(System.in);

        System.out.println("Input the number you want the factorial from: ");
        int num = scnr.nextInt();
        int facNum = factorial(num);

        System.out.println("The factorial of " + num + " is " +facNum);

        scnr.close();
    }

    private static int factorial(int n){
        if(n == 0){
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }
}
