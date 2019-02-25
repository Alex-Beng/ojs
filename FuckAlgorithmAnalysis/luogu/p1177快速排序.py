def quick_sort(num_list, left, right):
    if left < right:
        pivot = num_list[left] 
        i, j = left, right

        while i<j:
            while num_list[j] >= pivot and i < j:
                j -= 1
            num_list[i] = num_list[j]
            while num_list[i] <= pivot and i < j:
                i += 1
            num_list[j] = num_list[i]
        num_list[i] = pivot

        quick_sort(num_list, left, i-1)
        quick_sort(num_list, i+1, right)
        return num_list


input()
num_list = list(map(int, input().split()))
# quick_sort(num_list, 0, len(num_list)-1)
num_list.sort()
for i in num_list:
    print(i, end=" ")

