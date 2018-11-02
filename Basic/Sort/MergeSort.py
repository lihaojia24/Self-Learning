def mergeSort(nums, left, right, temp):
	if left < right:
		mid = (right + left) // 2
		mergeSort(nums, left, mid, temp)
		mergeSort(nums, mid+1, right, temp)
		merge(nums, left, mid, right, temp)

def merge(nums, left, mid, right, temp):
	pt, p1, p2 = 0, left, mid+1
	while(p1 <= mid and p2 <=right):
		if(nums[p1] < nums[p2]):
			temp[pt] = nums[p1]
			p1 += 1
		else:
			temp[pt] = nums[p2]
			p2 += 1
		pt += 1
	#填充剩余nums
	while p1 <= mid:
		temp[pt] = nums[p1]
		p1 += 1
		pt += 1
	while p2 <= right:
		temp[pt] = nums[p2]
		p2 += 1
		pt += 1
	#复制回原数组
	pt = 0
	while left <= right:
		nums[left] =temp[pt]
		left += 1
		pt += 1

nums = [2,3,1,4,0,8,9,7,6,5]
mergeSort(nums, 0, len(nums)-1, [0]*len(nums))
print(nums)