def mean(nums):
	sums = 0
	count = len(nums)
	for number in nums:
		sums += number
	sums = sums/count
	
def median(nums):
	count = len(nums)
	check = count % 2
	if check == 0:
		count/2