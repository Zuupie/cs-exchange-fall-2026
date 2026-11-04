import java.util.Scanner;
import java.util.ArrayList;

public class StudentScoreManager {
    public static void main(String[] args) {
        ArrayList<Integer> scores = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        // Step 1 - get scores from user
        for(int i = 0; i < 5; i++) {
            System.out.print("Enter score for student " + (i + 1) + ": ");
            int score = scanner.nextInt();
            scores.add(score);
        }

        // Step 2 - print the scores and the size of the list
        System.out.println(scores);
        System.out.println("Size of the list: " + scores.size());

        // Step 3 - add and remove scores
        scores.add(95);
        scores.set(2, 85);
        scores.remove(0);
        System.out.println(scores);

        // Step 4 - calculate the average score
        int sum = 0;
        for(int i = 0; i < scores.size(); i++){
            sum += scores.get(i);
        }
        System.out.println("Average score: " + sum / scores.size());

        // Part 2 - Recursion
        // 2.1 
        int totalSum = calculateSum(scores, 0);
        System.out.println("Total sum of scores: " + totalSum);

        // 2.2 
        int passingCount = countPassing(scores, 0);
        System.out.println("Number of passing scores: " + passingCount);

        // 2.3 
        int maxScore = findMaximum(scores, 0);
        System.out.println("Maximum score: " + maxScore);
        

    }

    // 2.1
    public static int calculateSum (ArrayList<Integer> scores, int index){
        if(index == scores.size()){
            return 0;
        }
        return scores.get(index) + calculateSum(scores, index + 1);
    }

    // 2.2
    public static int countPassing (ArrayList<Integer> scores, int index){
        if(index == scores.size()){
            return 0;
        }
        if(scores.get(index) >= 70){
            return 1 + countPassing(scores, index + 1);
        } else {
            return countPassing(scores, index + 1);
        }
    }

    //2.3
    public static int findMaximum (ArrayList<Integer> scores, int index){
        if(index == scores.size() - 1){
            return scores.get(index);
        }
        int maxInRest = findMaximum(scores, index + 1);
        if(scores.get(index) > maxInRest){
            return scores.get(index);
        } else {
            return maxInRest;
        }
    }
}
