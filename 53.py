def sumsubarray(nums):
    # divide and conquer approach

    for i in range(1, len(nums)):
        nums[i] = max(nums[i], nums[i] + nums[i - 1])

    return max(nums)

if __name__ == '__main__':

    nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]

    print(sumsubarray(nums))

    
