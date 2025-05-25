import java.util.ArrayList;
import java.util.Collections;

public class ArrayListDemo {
    public static void main(String[] args) {
        // 1. Create an ArrayList
        ArrayList<String> fruits = new ArrayList<>();

        // 2. Add elements
        fruits.add("Apple");
        fruits.add("Banana");
        fruits.add("Mango");
        fruits.add("Orange");
        fruits.add("Apple");  // Added Apple again to demonstrate lastIndexOf
        fruits.add("Kiwi");

        // 3. Print the ArrayList
        System.out.println("Fruits: " + fruits); // [Apple, Banana, Mango, Orange, Apple, Kiwi]

        // 4. Access elements
        System.out.println("First fruit: " + fruits.get(0)); // Apple

        // 5. Modify an element
        fruits.set(1, "Blueberry");
        System.out.println("After modifying: " + fruits); // [Apple, Blueberry, Mango, Orange, Apple, Kiwi]

        // 6. Remove an element by index
        fruits.remove(2);
        System.out.println("After removing index 2: " + fruits); // [Apple, Blueberry, Orange, Apple, Kiwi]

        // 7. Remove an element by value
        fruits.remove("Apple");
        System.out.println("After removing 'Apple': " + fruits); // [Blueberry, Orange, Apple, Kiwi]

        // 8. Check if list contains an element
        System.out.println("Contains Orange? " + fruits.contains("Orange")); // true

        // 9. Find size
        System.out.println("Size of list: " + fruits.size()); // 4

        // 10. Sort the list
        Collections.sort(fruits);
        System.out.println("Sorted fruits: " + fruits); // [Apple, Blueberry, Kiwi, Orange]

        // 11. Add an element at a specific position (index)
        fruits.add(1, "Pineapple");
        System.out.println("After adding Pineapple at index 1: " + fruits); // [Apple, Pineapple, Blueberry, Kiwi, Orange]

        // 12. Get the index of a specific element (first occurrence)
        System.out.println("Index of 'Apple': " + fruits.indexOf("Apple")); // 0

        // 13. Get the index of a specific element (last occurrence)
        System.out.println("Last index of 'Apple': " + fruits.lastIndexOf("Apple")); // 0 (or 2 if more Apples exist)

        // 14. Clear the list
        fruits.clear();
        System.out.println("After clearing: " + fruits); // []

        // 15. Check if list is empty
        System.out.println("Is list empty? " + fruits.isEmpty()); // true

        // 16. Add all elements from another list
        ArrayList<String> moreFruits = new ArrayList<>();
        moreFruits.add("Mango");
        moreFruits.add("Papaya");
        fruits.addAll(moreFruits);
        System.out.println("After adding all: " + fruits); // [Mango, Papaya]

        // 17. Iterate using for-each loop
        System.out.println("Iterating:");
        for (String fruit : fruits) {
            System.out.println(fruit);
        }

        // 18. Create ArrayList with initial capacity (optimization)
        ArrayList<Integer> numbers = new ArrayList<>(20);
        numbers.add(10);
        numbers.add(20);
        System.out.println("Numbers: " + numbers); // [10, 20]
    }
}
