class Solution(object):
    def twoSum(self, nums, target):
        listFin = []
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if (nums[i] + nums[j]) == target:
                    listFin.append(i), listFin.append(j)

        return listFin
