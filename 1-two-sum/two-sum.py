class Solution(object):
    def twoSum(self, nums, k):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        mp={}
        for i in range(len(nums)):
            if nums[i] not in mp:
                mp[nums[i]]=[]
            mp[nums[i]].append(i)
        nums.sort()
        j=0
        l=len(nums)-1
        ans=[]
        while j<l:
            if nums[j]+nums[l]==k:
                if nums[j]==nums[l]:
                    ans.append(mp[nums[j]][0])
                    ans.append(mp[nums[j]][1])
                    
                else:
                     ans.append(mp[nums[j]][0])
                     ans.append(mp[nums[l]][0])
                break
            elif nums[j]+nums[l]>k:
                l -=1
            else:
                j +=1
        return ans

        