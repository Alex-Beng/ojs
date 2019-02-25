
#include <queue>
#include <iostream>
using namespace std;
int vec[4][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};
int walked[23][33][5][5]; // x, y, color, direction
struct coordinate {
	coordinate() {
		time = 0;
	}
	int x;
	int y;
	int color;
	int direction;
	int time;
};

int transf_direction(char raw) {
	switch (raw) {
	case 'N':
		return 0;
	case 'W':
		return 1;
	case 'S':
		return 2;
	case 'E':
		return 3;
	}
}

int transf_color(char raw) {
	switch (raw) {
	case 'R':
		return 0;
	case 'Y':
		return 1;
	case 'B':
		return 2;
	case 'W':
		return 3;
	case 'G':
		return 4;
	}
}

coordinate move_to(coordinate site, int flag) {
	coordinate t_site;
	switch(flag) {
	case 0: // straight
		t_site.x = site.x + vec[site.direction][0];
		t_site.y = site.y + vec[site.direction][1];
		t_site.color = (site.color+1)%5;
        t_site.direction = site.direction;
		t_site.time = site.time + 1;
        break;
	case 1:// right
		t_site.x = site.x;
		t_site.y = site.y;
        t_site.color = site.color;
		t_site.direction = (site.direction+1)%4;
		t_site.time = site.time+1;
        break;
	case 2:// left
		t_site.x = site.x;
		t_site.y = site.y;
        t_site.color = site.color;
		t_site.direction = (site.direction+3)%4;
		t_site.time = site.time+1;
        break;
	}
    return t_site;
}

int main(){
	char map[23][33];
	coordinate begin,end;
	char t_char_1,t_char_2;
	cin>>begin.x>>begin.y>>t_char_1>>t_char_2;
	begin.color = transf_color(t_char_1);
	begin.direction = transf_direction(t_char_2);
	cin>>end.x>>end.y>>t_char_1;
	end.color = transf_color(t_char_1);

	for(int i = 1; i <= 20; i++) {
        for(int j = 1; j <= 20; j++) {
            cin >> map[i][j];
        }
    }
    
    queue<coordinate> qrq;
    qrq.push(begin);
    while (!qrq.empty()) {
		coordinate t_next;
		coordinate t_site = qrq.front();
		qrq.pop();
		for (int i=0; i<3; i++) {
			t_next = move_to(t_site,i);
			if (t_next.x == end.x && t_next.y == end.y && t_next.color == end.color) {
				cout<<t_next.time<<endl;
				return 0;
			}

            if (t_next.x<0 || t_next.y<0 || t_next.x>20 || t_next.y>20
                || map[t_next.x][t_next.y] == 'X') {
                continue;
            }

            if (walked[t_next.x][t_next.y][t_next.color][t_next.direction] == 0) {
                walked[t_next.x][t_next.y][t_next.color][t_next.direction] = 1;
                qrq.push(t_next);
            }
		}
    }

	return 0;
}

/*
#include <queue>
#include <iostream>
using namespace std;
#define Red (0)
#define Yellow (1)
#define Blue (2)
#define White (3)
#define Green (4)

#define North (0)
#define West (1)
#define South (2)
#define East (3)

int transf_color(char);
int transf_direction(char);

struct coordinate {
    coordinate() {
        time = 0;
    }
    int row;
    int col;
    int time;
    int color;
    int direction;
    char road;
};
coordinate map[23][33];

bool can_move(coordinate site) {
    if (site.col<1||site.row<1||site.col>20||site.row>20) {
        return false;
    }
    if (map[site.row][site.col].road == 'X') {
        return false;
    }
    return true;
}

coordinate move_to(coordinate site, int flag) {
    coordinate t_site;
    switch(flag) {
        case 0:// 向前�?
            if (site.direction == transf_direction('N')) {
                t_site.col = site.col;
                t_site.row = site.row - 1;
                t_site.color = (site.color + 1)%5;
                t_site.direction = site.direction;
                t_site.time = site.time+1;
                return t_site;
            }
            else if (site.direction == transf_direction('W')) {
                t_site.col = site.col - 1;
                t_site.row = site.row;
                t_site.color = (site.color + 1)%5;
                t_site.direction = site.direction;
                t_site.time = site.time+1;
                return t_site;
            }
            else if (site.direction == transf_direction('S')) {
                t_site.col = site.col;
                t_site.row = site.row + 1;
                t_site.color = (site.color + 1)%5;
                t_site.direction = site.direction;
                t_site.time = site.time+1;
                return t_site;
            }
            else if (site.direction == transf_direction('E')) {
                t_site.col = site.col + 1;
                t_site.row = site.row ;
                t_site.color = (site.color + 1)%5;
                t_site.direction = site.direction;
                t_site.time = site.time+1;
                return t_site;
            }
            break;
        case 1: //左转
            if (site.direction == transf_direction('N')) {
                t_site.col = site.col;
                t_site.row = site.row;
                t_site.color = site.color;
                t_site.direction = transf_direction('W');
                t_site.time = site.time+1;
                return t_site;
            }
            else if (site.direction == transf_direction('W')) {
                t_site.col = site.col;
                t_site.row = site.row;
                t_site.color = site.color;
                t_site.direction = transf_direction('S');
                t_site.time = site.time+1;
                return t_site;
            }
            else if (site.direction == transf_direction('S')) {
                t_site.col = site.col;
                t_site.row = site.row;
                t_site.color = site.color;
                t_site.direction = transf_direction('E');
                t_site.time = site.time+1;
                return t_site;
            }
            else if (site.direction == transf_direction('E')) {
                t_site.col = site.col;
                t_site.row = site.row;
                t_site.color = site.color;
                t_site.direction = transf_direction('N');
                t_site.time = site.time+1;
                return t_site;
            }
        case 2: //右转
            if (site.direction == transf_direction('N')) {
                t_site.col = site.col;
                t_site.row = site.row;
                t_site.color = site.color;
                t_site.direction = transf_direction('E');
                t_site.time = site.time+1;
                return t_site;
            }
            else if (site.direction == transf_direction('W')) {
                t_site.col = site.col;
                t_site.row = site.row;
                t_site.color = site.color;
                t_site.direction = transf_direction('N');
                t_site.time = site.time+1;
                return t_site;
            }
            else if (site.direction == transf_direction('S')) {
                t_site.col = site.col;
                t_site.row = site.row;
                t_site.color = site.color;
                t_site.direction = transf_direction('W');
                t_site.time = site.time+1;
                return t_site;
            }
            else if (site.direction == transf_direction('E')) {
                t_site.col = site.col;
                t_site.row = site.row;
                t_site.color = site.color;
                t_site.direction = transf_direction('S');
                t_site.time = site.time+1;
                return t_site;
            }
    }
}
int transf_direction(char raw) {
	switch (raw) {
	case 'N':
		return 0;
	case 'W':
		return 1;
	case 'S':
		return 2;
	case 'E':
		return 3;
	}
}

int transf_color(char raw) {
	switch (raw) {
	case 'R':
		return 0;
	case 'Y':
		return 1;
	case 'B':
		return 2;
	case 'W':
		return 3;
	case 'G':
		return 4;
	}
}
int mark[23][33][5][5];
int main(int argc, char const *argv[]) {
    coordinate begin;
    coordinate end;
	char t_char_1,t_char_2;
    cin>>begin.row>>begin.col>>t_char_1>>t_char_2;
    begin.color = transf_color(t_char_1);
    begin.direction = transf_direction(t_char_2);

    cin>>end.row>>end.col>>t_char_1;
    end.color = transf_color(t_char_1);

    for (int i=1; i<=20; i++) {
        for (int j=0; j<=20; j++) {
            cin>>map[i][j].road;
        }
    }
    std::queue<coordinate> qrq;
    qrq.push(begin);
    while (!qrq.empty()) {
        coordinate t_next;
        coordinate t_site = qrq.front();
        qrq.pop();
        for (int i=0;  i<3; i++) { // front & turn left & turn right
            t_next = move_to(t_site,i);
            if (!can_move(t_next)) {
                continue;
            }
            if (t_next.row == end.row && t_next.col == end.col && t_next.color == end.color ) {
				cout<<t_site.time+1<<endl;
            }
            else if (mark[t_next.row][t_next.col][t_next.direction][t_next.color] == 0) {
				mark[t_next.row][t_next.col][t_next.direction][t_next.color] = 1;
				qrq.push(t_next);
            }

        }
    }
    return 0;
}
*/
