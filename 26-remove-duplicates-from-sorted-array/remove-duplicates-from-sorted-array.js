/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let n=nums.length;
    let j=0;
    let mp=new Map();
    for(let i=0;i<n;i++){
        if(!mp.has(nums[i])){
            nums[j]=nums[i];
            j++;
            mp.set(nums[i],true);
        }
    }
    nums.splice(j,n-j);
    
};