Two Pointers: Uses two indices moving towards each other or at different speeds, common in sorted arrays and pair-sum problems.

 Opposite Ends (Meet in the Middle)

1. Two Sum II  (Input Array Is Sorted) [Easy] – Find two numbers that add up to a target.
 
2. 3Sum [Medium] – Find all unique triplets that sum up to zero.
 
3. 4Sum [Medium] – Find four unique numbers that sum up to a target.
 
4. Container With Most Water [Medium] – Find two lines that trap the most water.
 
5. Valid Palindrome [Easy] – Check if a string reads the same forward and backward after cleanup.🏃
 
Fast & Slow Pointers (Tortoise and Hare)
1. Remove Duplicates from Sorted Array [Easy] – Remove duplicates in-place so unique elements appear first.
  
2. Move Zeroes [Easy] – Push all zeroes to the end while keeping the relative order of other elements.

3. Squares of a Sorted Array [Easy] – Return a sorted array of the squares of a sorted array containing negative numbers.



Prefix Sum: Precomputes cumulative sums to answer range-sum queries efficiently in \(O(1)\) time.

Range Queries & Hash Map Combos

1. Range Sum Query - Immutable [Easy] – Answer multiple queries for the sum of elements between indices L and R.

2. Subarray Sum Equals K [Medium] – Count the total number of subarrays whose sum equals K (Uses Prefix Sum + Hash Map).

3. Subarray Sums Divisible by K [Medium] – Count subarrays whose sum is divisible by K (Uses Prefix Sum + Modulo Arithmetic).

4. Contiguous Array (Binary Array) [Medium] – Find the maximum length of a contiguous subarray with an equal number of 0s and 1s (Treat 0 as -1).

5. Product of Array Except Self [Medium] – Construct an array where each element is the product of all others except itself using prefix and suffix products.





4. Kadane's Algorithm: Dynamically tracks running subarray sums to solve maximum contiguous subarray problems in \(O(n)\) time










Easy Problems

1. Two Sum: Find two indices in an array that add up to a target value using a hash map for \(O(n)\) time complexity.

2. Best Time to Buy and Sell Stock: Track the running minimum price to find the maximum single-transaction profit in \(O(n)\) time.

3. Move Zeroes: Shift all zero entries to the end of the array in-place using a two-pointer swap.

4. Contains Duplicate: Use a hash set to verify if any element appears more than once


Medium Problems

1. Product of Array Except Self: Compute prefix and suffix products to find the product for every element without using division.

2. Rotate Array: Shift array elements right by \(k\) steps in-place using a three-reversal method.

3. 3Sum: Sort the array and apply a two-pointer approach for every element to find unique triplets summing to zero.

4. Maximum Subarray: Apply Kadane's Algorithm to find the contiguous subarray with the largest sum



Hard Problems

1. Trapping Rain Water: Use two pointers or precomputed max-height arrays to calculate trapped water volume in \(O(n)\) time.

2. First Missing Positive: Use index placement or array negation to find the smallest missing positive integer in \(O(n)\) time and \(O(1)\) space.



Imp Question
1. Longest Common Prefix