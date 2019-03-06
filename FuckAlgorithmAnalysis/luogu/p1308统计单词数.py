vocabulary = input()
vocabulary = vocabulary.lower()
paragragh = list(input().split())
paragragh = [i.lower() for i in paragragh]

vocabulary_indexs = [i for i in range(len(paragragh)) if paragragh[i] == vocabulary]

if (len(vocabulary_indexs)):
    print(len(vocabulary_indexs), ' ', vocabulary_indexs[0])
else:
    print(-1)