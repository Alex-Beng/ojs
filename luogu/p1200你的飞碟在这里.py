star_name = input()
team_name = input()

star_num_list = [ord(i)-ord('A')+1 for i in list(star_name)]
team_num_list = [ord(i)-ord('A')+1 for i in list(team_name)]

star_score = 1
for i in star_num_list:
    star_score *= i

team_score = 1
for i in team_num_list:
    team_score *= i

if star_score%47 == team_score%47:
    print("GO")
else:
    print("STAY")
# print(star_num_list)