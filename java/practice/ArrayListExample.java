import java.util.ArrayList;

class ArrayListExample {
    public static void main(String[] args){

        ArrayList<Integer> arr = new ArrayList<>();
        arr.add(10);
        arr.add(20);
        arr.add(30);
        arr.add(40);
        arr.add(50);
        arr.remove(2);
        arr.add(2, 25);

        int sum = 0;

        for(int i = 0; i < arr.size(); i++){
            sum += arr.get(i);
        }

        System.out.println("Sum: " + sum);
        System.out.println("All elements: \n" + arr);

        
    }
}
