# Daily Currency Converter 💱

A simple C program that calculates daily currency exchange rates across a 7-day period. 

## Features
* **Multi-Currency Support:** Convert between RON, EUR, GBP, and USD.
* **Daily Fluctuations:** Incorporates pre-defined matrices for buying and selling rates that change depending on the day of the week.
* **Cross-Currency Conversion:** If converting from one foreign currency to another (e.g., USD to EUR), the program automatically uses RON as a base bridge for the calculation.

## How It Works
The program runs in a loop, starting on Monday and allowing the user to progress through the week. For each calculation, the user inputs:
1. The amount to be exchanged.
2. The initial currency.
3. The target currency.

The calculations are handled by dedicated `buy`, `sell`, and `general` functions based on the user's target currency.

## Getting Started

### Prerequisites
You will need a C compiler installed on your system (such as `gcc`).

### Compilation & Execution
To compile and run the program from your terminal, use the following commands:

```bash
gcc main.c -o converter
./converter
