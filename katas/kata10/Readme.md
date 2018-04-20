# Kata 10: 393. UTF-8 Validation

A character in UTF8 can be from **1 to 4 bytes** long, subjected to the following rules

1. For 1-byte character, the first bit is a 0, followed by its unicode code.
2. For n-bytes character, the first n-bits are all one's, the n+1 bit is 0, followed by n-1 bytes with most significant 2 bits being 10.

Given an array of integers representing the data, return whether it is a valid utf-8 encoding.

**Note:**
The input is an array of integers. Only the **least significant 8 bits** of each integer is used to store the data. This means each integer represents only 1 byte of data.

**Example 1:**

data = [197, 130, 1], which represents the octet sequence: **11000101 10000010 00000001**.    Return **true**.  It is a valid utf-8 encoding for a 2-bytes character followed by a 1-byte character.

**Example 2:**

data = [235, 140, 4], which represented the octet sequence: **11101011 10001100 00000100**.    Return **false**.  The first 3 bits are all one's and the 4th bit is 0 means it is a 3-bytes character.  The next byte is a continuation byte which starts with 10 and that's correct.  But the second continuation byte does not start with 10, so it is invalid.

## Solution

![alt text](https://github.com/MikeSagnelli/PrograAvanzada2018/blob/master/katas/kata10/kata10_1.JPG)
![alt text](https://github.com/MikeSagnelli/PrograAvanzada2018/blob/master/katas/kata10/kata10_2.JPG)