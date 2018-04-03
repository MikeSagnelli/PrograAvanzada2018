# Partial 2: Problem Reverse: Reverse Sentences

You are given an integer N, followed by N lines of input (1 <= N <= 100). Each line of input contains one or several words separated with single spaces. Each word is a sequence of letters of English alphabet containing between 1 and 10 characters, inclusive. The total number of words in the input is between 1 and 100, inclusive.

Your task is to reverse the order of words in each line of input, while preserving the words themselves. The lines of your output should not have any trailing or leading spaces.

## Example

### Input

- 3
- Hello World
- Bye World
- Useless World

### Output

- World Hello
- World Bye
- Useless World

## Solution

1. Count words by counting the number of spaces plus 1.
2. Store each line as a whole string in an array of strings.
3. Make a temporal array of strings.
4. Scan the sentences and store words in the array.
5. Traverse array backwards and print the concatenated strings.

Complexity is O(n * l) where n is the number of words in a string, and l is the number of lines in the input. This falls into a O(n)

![alttext](https://github.com/MikeSagnelli/PrograAvanzada2018/blob/master/examenes/parcial2/parcial2_1.JPG)