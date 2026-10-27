# COMP 1210 – Midterm 2 Lab Exam (Coding) – Study Sheet

Sources: `COMP1210_Midterm2.pdf` (review slides) and `Practiceprograms_Test2.pdf` (22 practice programs).

## 1. Official exam topics

| Topic  | What to practice                          |
|--------|-------------------------------------------|
| Loops  | Nested loops, for-each, while             |
| Arrays | Traversing, finding min/max, reversing    |

The exam is zyLabs-style: read input with `Scanner`, print **exactly** the required output
(spaces, commas, newlines matter).  

---

## 2. Program skeleton (write this from memory)

```java
import java.util.Scanner;

public class LabProgram {
   public static void main(String[] args) {
      Scanner scnr = new Scanner(System.in);

      int n = scnr.nextInt();
      // ...
   }
}
```

### Scanner cheat sheet
| Call                | Reads                                       |
|---------------------|---------------------------------------------|
| `scnr.nextInt()`    | next integer                                |
| `scnr.nextDouble()` | next double                                 |
| `scnr.next()`       | next word (stops at whitespace)             |
| `scnr.next().charAt(0)` | a single character                      |
| `scnr.nextLine()`   | rest of the current line (incl. spaces)     |
| `scnr.hasNextInt()` | `true` if another int is available          |

**Pitfall:** after `nextInt()`, a following `nextLine()` returns the leftover `""`.
Call an extra `scnr.nextLine();` first to consume the newline.

### Output
- `System.out.print(x)` – no newline; `System.out.println(x)` – with newline.
- `System.out.printf("%.2f\n", avg);` – 2 decimal places.
- `"\t"` tab, `"\n"` newline.
- "Follow each value by a comma/space, even the last one" → just `print(x + ",")` inside the loop.

---

## 3. Loops

### for / while / do-while / for-each
```java
for (int i = 0; i < n; i++) { ... }          // known number of iterations
while (x > 0) { ... }                         // unknown number, condition-driven
for (int v : arr) { ... }                     // read every element (no index!)
```
- for-each **cannot** modify the array or tell you the index — use a normal `for` for that.

### Sentinel loop (read until negative / "done")
```java
int val = scnr.nextInt();
while (val >= 0) {
   // process val
   val = scnr.nextInt();
}
```
```java
String line = scnr.nextLine();
while (!line.equals("Done") && !line.equals("done") && !line.equals("d")) {
   // process line
   line = scnr.nextLine();
}
```

### Nested loops (patterns)
```java
// right triangle: row i has i stars
for (int i = 1; i <= h; i++) {
   for (int j = 1; j <= i; j++) {
      System.out.print("* ");
   }
   System.out.println();
}
// reversed (h stars first): for (int i = h; i >= 1; i--)
```

### Brute force with nested loops (practice #11)
```java
for (int x = -10; x <= 10; x++) {
   for (int y = -10; y <= 10; y++) {
      if (a * x + b * y == c && d * x + e * y == f) { ... }
   }
}
```

### Digit / number loops
- Reverse binary: `while (x > 0) { print(x % 2); x = x / 2; }`
- Multiples of x: `if (i % x == 0)`
- Even: `n % 2 == 0`, odd: `n % 2 != 0`
- Hailstone: `n = (n % 2 == 0) ? n / 2 : 3 * n + 1;` — count outputs, newline every 5.
- Step by 5: `for (int i = start; i <= end; i += 5)`
- Loan: `balance = balance * (1 + rate) - payment; count++;` while `balance > 0`.

---

## 4. Arrays

### Read a list (size given first)
```java
int n = scnr.nextInt();
int[] arr = new int[n];
for (int i = 0; i < arr.length; i++) {
   arr[i] = scnr.nextInt();
}
```

### Read until negative (size unknown, "fewer than 20")
```java
int[] arr = new int[20];
int size = 0;
int val = scnr.nextInt();
while (val >= 0) {
   arr[size] = val;
   size++;
   val = scnr.nextInt();
}
// use size, NOT arr.length, from now on
```

### Core algorithms
```java
// sum / average
int sum = 0;
for (int v : arr) sum += v;
double avg = (double) sum / arr.length;    // cast! otherwise integer division

// min / max  (start with the FIRST element, not 0)
int max = arr[0];
for (int i = 1; i < arr.length; i++) {
   if (arr[i] > max) max = arr[i];
}

// count matching elements
int count = 0;
for (int v : arr) if (v % 3 == 0 || v % 5 == 0) count++;

// sum of elements at odd indices
for (int i = 1; i < arr.length; i += 2) sum += arr[i];

// print in reverse
for (int i = arr.length - 1; i >= 0; i--) System.out.print(arr[i] + ",");

// reverse IN PLACE (swap ends, go to the middle) – note: <, not <=
for (int i = 0; i < arr.length / 2; i++) {
   int temp = arr[i];
   arr[i] = arr[arr.length - 1 - i];
   arr[arr.length - 1 - i] = temp;
}

// swap first and last
int temp = arr[0];
arr[0] = arr[arr.length - 1];
arr[arr.length - 1] = temp;

// rotate right by one (last element → first)
int last = arr[arr.length - 1];
for (int i = arr.length - 1; i > 0; i--) {   // go BACKWARDS
   arr[i] = arr[i - 1];
}
arr[0] = last;

// palindrome check on an array
boolean isPal = true;
for (int i = 0; i < arr.length / 2; i++) {
   if (arr[i] != arr[arr.length - 1 - i]) isPal = false;
}

// two smallest
int min1 = Math.min(arr[0], arr[1]), min2 = Math.max(arr[0], arr[1]);
for (int i = 2; i < arr.length; i++) {
   if (arr[i] < min1) { min2 = min1; min1 = arr[i]; }
   else if (arr[i] < min2) { min2 = arr[i]; }
}

// dot product of two arrays
for (int i = 0; i < n; i++) sum += a[i] * b[i];

// middle element (odd count)        arr[size / 2]
// Nth from the end                   arr[size - N]
// frequency of each word (nested loop):
for (int i = 0; i < n; i++) {
   int freq = 0;
   for (int j = 0; j < n; j++) {
      if (words[i].equals(words[j])) freq++;
   }
   System.out.println(words[i] + " " + freq);
}
```

---

## 5. Strings (show up in the practice set)
```java
s.length()                 s.charAt(i)
s.equals("done")           // NEVER == for Strings
s.equalsIgnoreCase("done")
s.toLowerCase()            s.replace(" ", "")
Character.isLetter(c)      Character.isDigit(c)
```
- Count a char: loop `i` over `s.length()`, `if (s.charAt(i) == c) count++`
  (chars **are** compared with `==`). Plural: `count == 1 ? "" : "'s"`.
- Remove non-letters: build a new string, `if (Character.isLetter(c)) result += c;`
- Reverse a string: `for (int i = s.length() - 1; i >= 0; i--) result += s.charAt(i);`
- Palindrome phrase: remove spaces first, then compare `s.charAt(i)` with `s.charAt(len - 1 - i)`.

---

## 6. Common mistakes checklist (from the slides – check before submitting!)
- [ ] Missing braces `{ }` (esp. on `if` inside loops)
- [ ] **Array index out of bounds**: last valid index is `arr.length - 1`, so loop with `i < arr.length`, not `<=`
- [ ] Wrong loop condition / wrong update direction (`i++` vs `i--`)
- [ ] `=` (assignment) instead of `==` (comparison)
- [ ] Forgetting to reset variables (e.g. `count = 0` inside an outer loop)
- [ ] Integer division: `sum / n` with ints drops decimals → cast to `double`
- [ ] Initialising max with `0` (fails for negative numbers) → use `arr[0]`
- [ ] Using `arr.length` when only `size` elements were filled
- [ ] Output format: exact spaces, commas, trailing newline

---

## 7. Logic review questions from the slides (with answers)

1. **Nested star loop (`i` 1..3, `j` 1..i)** → prints
   ```
   *
   **
   ***
   ```
   Reverse it: `for (int i = 3; i >= 1; i--)`.

2. **`nums = {3,5,2,5,3,3}`, count `nums[i] == nums[0]`** → counts how often the first
   element (3) occurs → prints `3`. Unique elements: for each `i`, check with an inner loop
   whether `nums[i]` appeared at an index `j < i`; if not, `count++`.

3. **`for (int i = 10; i > 0; i++)`** → `i` grows, condition never fails → (practically)
   infinite loop until int overflow. Fix: `i--`.

4. **CountEvens → divisible by 3 or 5**: `if (nums[i] % 3 == 0 || nums[i] % 5 == 0)` → `Count: 5`.

5. **ReverseArray with `i <= arr.length / 2`**: works for odd length (middle swaps with itself)
   but for **even** length it swaps the middle pair back → wrong. Use `i < arr.length / 2`.

6. **SumArray, odd indices only**: `for (int i = 1; i < data.length; i += 2)` → `4 + 8 = 12`.

7. **Example 1 – multiples of x between low and high exclusive** (`1 10 2` → `Multiples of 2: 2,4,6,8,`):
   ```java
   System.out.print("Multiples of " + x + ": ");
   for (int i = low + 1; i < high; i++) {
      if (i % x == 0) System.out.print(i + ",");
   }
   System.out.println();
   ```

8. **Example 2 – rotate right** (`6 / 2 4 6 8 10 12` → `12 2 4 6 8 10 `): see "rotate right by one" above.

---

## 8. Practice programs (Practiceprograms_Test2.pdf) grouped by pattern

Solve each one in a `LabProgram.java` without looking at notes. Time yourself (~10 min each).

| Pattern                          | Problems |
|----------------------------------|----------|
| while loop on a number (`% /`)   | 1 reverse binary, 9 hailstone, 12 loan payments |
| Sentinel loop (stop at negative) | 2 max + average, 7 largest so far, 17 Nth from end, 20 middle integer |
| String traversal                 | 3 count a char, 4 remove non-alpha, 6 reverse lines until "done", 10 palindrome phrase |
| Counted / stepped for loop       | 5 increments of 5, Example 1 multiples of x |
| Nested loops                     | 8 right triangle, 11 brute-force equations, 22 word frequencies |
| Array min/max                    | 13 two smallest |
| Array reversing / swapping       | 14 palindrome list, 15 swap first & last, 16 rotate right, 19 print in reverse, slide 14 reverse in place |
| Array traversal + condition      | 18 dot product of two lists, 21 values ≤ threshold (threshold is the value **after** the list) |

**Priority if short on time:** 16, 13, 19, reverse-in-place, 14, 2, 17, 8, 22.
