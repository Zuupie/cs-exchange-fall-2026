import java.util.Scanner;

public class Own_practice {
    public static void main(String[] args){
        int[] numbers = new int[20];
        Scanner scnr = new Scanner(System.in);

        int temp = scnr.nextInt();
        int size = 0;

        // Read all Input values until the first negative one
        // and store it into an array
        while(temp >= 0){
            numbers[size] = temp;
            size++;
            temp = scnr.nextInt();
        }

        scnr.close();

        int min, max;

        reverseArray(numbers, size);

        System.out.print("Reversed: ");
        printArray(numbers, size);

        min = findMin(numbers, size);
        max = findMax(numbers, size);

        System.out.println("\nMin: " + min + "\nMax: " + max);

        printChart(numbers, size);
    }

    // Printing all elements of the given array
    private static void printArray(int[] array, int size){
        for(int i = 0; i < size; i++){
            System.out.print(array[i] + " ");
        }
    }

    // Reverse the elements of given array 
    private static void reverseArray(int[] array, int size){
        int temp = 0;
        for(int i = 0; i < size / 2; i++){
            temp = array[i];
            array[i] = array[size - 1 - i];
            array[size - 1 - i] = temp;
        }
    }

    // Find the minimum value in the given array
    private static int findMin(int[] array, int size){
        int localMin = array[0];
        for(int i = 1; i < size; i++){
            if(localMin >= array[i]){
                localMin = array[i];
            }
        }
        return localMin;
    }

    // Find the maximum value in the given array
    private static int findMax(int[] array, int size){
        int localMax = array[0];
        for(int i = 1; i < size; i++){
            if(localMax <= array[i]){
                localMax = array[i];
            }
        }
        return localMax;
    }

    // Print as many stars as the value of each element
    private static void printChart(int[] array, int size){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < array[i]; j++){
                System.out.print("*");
            }
            System.out.println();
        }
    }
}