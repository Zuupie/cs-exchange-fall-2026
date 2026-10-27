import java.util.Scanner;

public class TA_prep {

    public static void main(String[] args){
        Scanner scnr = new Scanner(System.in);

        //first_task(scnr);

        //second_task(scnr);

        //countEven(scnr);

        //sumAndDiff(scnr);

        reverseArray(scnr);

        scnr.close();

        
    }

    public static void first_task(Scanner scnr){

        /*
        Create 2 arrays of the same size and compare who has bigger
        values at each position.
        Example Input:
        4
        0 2 3 4
        1 1 1 1
        Example Output:
        Array 2 is greater at index 1
        Array 1 is greater at index 2
        Array 1 is greater at index 3
        Array 1 is greater at index 4 
        */

        int size = scnr.nextInt();
        int[] a1 = new int[size];
        int[] a2 = new int[size];

        for(int i = 0; i < size; i++){
            a1[i] = scnr.nextInt();
        }

        for(int i = 0; i < size; i++){
            a2[i] = scnr.nextInt();
        }

        for(int i = 0; i < size; i++){
            if(a1[i] >= a2[i]){
                System.out.println("Array 1 is greater at index " + i);
            } else if (a2[i] >= a1[i]){
                System.out.println("Array 2 is greater at index " + i);
            } else {
                System.out.println("Both of the Arrays are of the same index");
            }
        } 
    }

    public static void second_task(Scanner scnr){
        /*
        Write a program that takes 3 integers. It continuously
        divides the first integer by the third until it is equal to
        or less than the second. Have it print on the same line
        through the sequence then add a new line at the end.
        Example Input:
        729 9 3
        Example Output:
        729 243 81 27 9
        */

        int one = scnr.nextInt();
        int two = scnr.nextInt();
        int three = scnr.nextInt();

        System.out.print(one + " ");

        while(one > two){
            one /= three;
            System.out.print(one + " ");
        } 
        
        System.out.println();
    
    }

    public static void countEven(Scanner scnr){
        /*
        Write a program that takes an element and makes an array of
        that size. It then takes input for that array and returns
        the number of even and odd elements.
        Example Input:
        5
        2 4 5 8 5
        Example Output:
        Even Numbers:
        3
        Odd Numbers: 2
        */

        int size = scnr.nextInt();

        int[] a = new int[size];
        int even = 0;
        int odd = 0;

        for(int i = 0; i < size; i++){
            a[i] = scnr.nextInt();
        }

        for(int i = 0; i < size; i++){
            if(a[i] % 2 == 0){
               even++;
            }else{
                odd++;
            }
        }
        System.out.println("Even Numbers: " + even + "\nOdd Numbers: " + odd);
    }


    public static void sumAndDiff(Scanner scnr){
        /*
        Write a program
        that takes in an element and makes an array
        of that element size. After inputting the values to the
        array, it returns the total sum of the array (addition) AND
        the total difference of the array (subtraction).
        Example input:
        5
        20 15 0 3 -1
        Example output:
        Sum: 37
        Difference: 3
        */

        int size = scnr.nextInt();
        int[] a = new int[size];
        
        for(int i = 0; i < size; i++){
            a[i] = scnr.nextInt();
        }

        int sum = 0;
        int diff = a[0];

        for(int i = 0; i < size; i++){
            sum += a[i];
        }

        for(int i = 1; i < size; i++){
            diff -= a[i];
        }

        System.out.println("Sum: " + sum + "\nDifference: " + diff);

    }

    public static void reverseArray(Scanner scnr){
        /*
        Write a program with an array fixed to a size of an
        inputted integer. After inputting those values, print the
        reverse of the array. Make sure to end with a
        new line.
        Example Input:
        5
        10 20 30 40 50
        Example Output:
        50 40 30 20 10
        */

        int size = scnr.nextInt();
        int[] a = new int[size];
        
        for(int i = 0; i < size; i++){
            a[i] = scnr.nextInt();
        }

        for(int i = 0; i < size / 2; i++){
            int temp = a[i];
            a[i] = a[size - 1 - i];
            a[size - 1 - i] = temp;
        }

        for(int i = 0; i < size; i++){
            System.out.print(a[i] + " ");
        }

        System.out.println();
    }

}
