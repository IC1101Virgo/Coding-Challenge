# Largest Permutation
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a permutation of first <strong>n</strong> natural numbers as an array and an integer k. Print the lexicographically largest permutation after at most k swaps.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>n=5
k=3
arr[] = {4, 5, 2, 1, 3}
<strong>Output:</strong> 5 4 3 2 1
<strong>Explanation</strong>: Swap 1<sup>st</sup> and 2<sup>nd</sup> elements: 5 4 2 1 3 
             Swap 3<sup>rd</sup> and 5<sup>th</sup> elements: 5 4 3 1 2 
             Swap 4<sup>th</sup> and 5<sup>th</sup> elements: 5 4 3 2 1 </span></pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>n=3
k=1
arr[] = {2, 1, 3}
<strong>Output:</strong> 3 1 2
<strong>Explanation</strong>: Swap 1<sup>st</sup> and 3<sup>re</sup> elements: 3 1 2 </span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
Since, this is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the function <strong>KswapPermutation</strong>() that takes <strong>array arr, integer n</strong> <strong>and integer k</strong> as parameters and modifies the array arr and does not return anything.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(n).<br>
<strong>Expected Auxiliary Space:</strong> O(n).</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
2 ≤ n ≤ 10<sup>6</sup></span></p>

<p>&nbsp;</p>
 <p></p>
            </div>