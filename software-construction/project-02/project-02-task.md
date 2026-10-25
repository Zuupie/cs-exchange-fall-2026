# Project 2 – When Life Gives You Credit Debt

**Course:** COMP 2710 (Software Construction) · Fall 2026
**Language:** C++ (compiled with g++ on the AU server)
**Topic:** Flow of control, loops, input validation

> Task description summarized in my own words. The original assignment sheet is the instructor's material and is not included here.

## Problem

Write a program that computes how many months it takes to pay off a loan with fixed monthly payments, and the total interest paid over the life of the loan.

Each month:

1. Interest = remaining balance × (annual rate / 12)
2. The payment covers the interest first; the rest reduces the balance (principal).
3. The final payment is usually smaller: it equals the remaining balance plus that month's interest.

**Example:** $1000 loan at 18% per year (1.5% per month) with $50 payments. Month 1: interest $15.00, principal $35.00, new balance $965.00.

## Input

- Loan amount
- Interest rate (% per year)
- Monthly payment

## Output

An amortization table with the columns:

| Month | Balance | Payment | Rate (monthly %) | Interest | Principal |
|-------|---------|---------|------------------|----------|-----------|

- Month 0 shows the starting balance and `N/A` for the other columns.
- Money values have 2 decimal places, and numeric columns are left-aligned.
- After the table, print the number of months and the total interest paid.

## Requirements & Edge Cases

- Use a loop and a counter to track months.
- Handle the smaller final payment correctly.
- Loan amount and monthly payment must be positive; the interest rate must be non-negative.
- The monthly payment must be larger than the first month's interest. Otherwise the balance grows forever, so the program must reject the input.
- Detect non-numeric input. On any invalid input, print a clear error and either re-prompt or exit.

## Test Cases

| # | Loan | Rate | Payment | Expected |
|---|------|------|---------|----------|
| – | 1000 | 18 | 50 | 24 months, $197.83 interest |
| – | 2000 | 12 | 80 | 29 months, $312.98 interest |
| 1 | 1000 | 12 | 11 | 241 months, $1650.85 |
| 2 | 1000 | 50 | 2000 | 1 month, $41.67 |
| 3 | 1000 | 0 | 10 | 100 months, $0 |
| 4 | 2000 | 50 | 80 | Error: insufficient payment |
| 5 | -1000 | | | Error: invalid loan |
| 6 | abc | | | Error: invalid input |
| 7 | 1000 | -18 | | Error: invalid rate |
| 8 | 1000 | abc | | Error: invalid input |
| 9 | 1000 | 18 | -50 | Error: invalid payment |
| 10 | 1000 | 18 | abc | Error: invalid input |

## Build & Run

```bash
g++ project2.cpp
./a.out
```