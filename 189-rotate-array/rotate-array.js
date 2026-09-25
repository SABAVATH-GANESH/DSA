/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
    let n = nums.length;
    k = k % n;

    nums.reverse();

    let part = nums.splice(0, k).reverse();
    nums.splice(0, 0, ...part);

    let part2 = nums.splice(k, n).reverse();
    nums.splice(k, 0, ...part2);
};