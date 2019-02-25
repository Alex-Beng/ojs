/*
sample
00
00
11
11
11
11
11
11
11
11
11
11
output: 
0
*/
#include <algorithm>
#include <map>
#include <queue>
#include <iostream>
using namespace std;

struct node {
	node(int t=0) {
		hash_num = t;
	}
	int surface[6][4]; // 按输入顺序 上下左右前后
	int hash_num; // 把24个值都乘权重(2)然后加起来作为特征值..
};


node move_to(node t_status, int flag) {
	int t;
	int t2;
	switch(flag) {
	case 0: //R
		t = t_status.surface[3][0];
		t_status.surface[3][0] = t_status.surface[3][1];
		t_status.surface[3][1] = t_status.surface[3][3];
		t_status.surface[3][3] = t_status.surface[3][2];
		t_status.surface[3][2] = t;

		t  = t_status.surface[0][1];
		t2 = t_status.surface[0][3];
		t_status.surface[0][1] = t_status.surface[4][1];
		t_status.surface[0][3] = t_status.surface[4][3];
		t_status.surface[4][1] = t_status.surface[1][3];
		t_status.surface[4][3] = t_status.surface[1][1];
		t_status.surface[1][3] = t_status.surface[5][3];
		t_status.surface[1][1] = t_status.surface[5][1];
		t_status.surface[5][3] = t;
		t_status.surface[5][1] = t2;
		// t_status.surface[0][1] = t_status.surface[0][3];
		// t_status.surface[0][3] = t_status.surface[4][1];
		// t_status.surface[4][1] = t_status.surface[4][3];
		// t_status.surface[4][3] = t_status.surface[1][3];
		// t_status.surface[1][3] = t_status.surface[1][1];
		// t_status.surface[1][1] = t_status.surface[5][3];
		// t_status.surface[5][3] = t_status.surface[5][1];
		// t_status.surface[5][1] = t;
		return t_status;
	case 1: // U
		t = t_status.surface[0][0];
		t_status.surface[0][0] = t_status.surface[0][2];
		t_status.surface[0][2] = t_status.surface[0][3];
		t_status.surface[0][3] = t_status.surface[0][1];
		t_status.surface[0][1] = t;

		t  = t_status.surface[2][0];
		t2 = t_status.surface[2][1];
		t_status.surface[2][0] = t_status.surface[4][0];
		t_status.surface[2][1] = t_status.surface[4][1];
		t_status.surface[4][0] = t_status.surface[3][1];
		t_status.surface[4][1] = t_status.surface[3][0];
		t_status.surface[3][1] = t_status.surface[5][1];
		t_status.surface[3][0] = t_status.surface[5][0];
		t_status.surface[5][1] = t;
		t_status.surface[5][0] = t2;
		// t_status.surface[2][0] = t_status.surface[2][1];
		// t_status.surface[2][1] = t_status.surface[4][0];
		// t_status.surface[4][0] = t_status.surface[4][1];
		// t_status.surface[4][1] = t_status.surface[3][1];
		// t_status.surface[3][1] = t_status.surface[3][0];
		// t_status.surface[3][0] = t_status.surface[5][1];
		// t_status.surface[5][1] = t_status.surface[5][0];
		// t_status.surface[5][0] = t;
		return t_status;
	case 2: // F
		t = t_status.surface[4][0];
		t_status.surface[4][0] = t_status.surface[4][2];
		t_status.surface[4][2] = t_status.surface[4][3];
		t_status.surface[4][3] = t_status.surface[4][1];
		t_status.surface[4][1] = t;

		t  = t_status.surface[3][1];
		t2 = t_status.surface[3][3];
		t_status.surface[3][1] = t_status.surface[0][2];
		t_status.surface[3][3] = t_status.surface[0][3];
		t_status.surface[0][2] = t_status.surface[2][3];
		t_status.surface[0][3] = t_status.surface[2][1];
		t_status.surface[2][3] = t_status.surface[1][3];
		t_status.surface[2][1] = t_status.surface[1][2];
		t_status.surface[1][3] = t;
		t_status.surface[1][2] = t2;

		// t_status.surface[3][1] = t_status.surface[0][3];
		// t_status.surface[0][3] = t_status.surface[0][2];
		// t_status.surface[0][2] = t_status.surface[2][1];
		// t_status.surface[2][1] = t_status.surface[2][3];
		// t_status.surface[2][3] = t_status.surface[1][2];
		// t_status.surface[1][2] = t_status.surface[1][3];
		// t_status.surface[1][3] = t_status.surface[3][3];
		// t_status.surface[3][3] = t;
		return t_status;
	case 3: // R'
		return move_to(move_to(move_to(t_status,0),0),0);
	case 4: // U'
		return move_to(move_to(move_to(t_status,1),1),1);
	case 5: // F'
		return move_to(move_to(move_to(t_status,2),2),2);
	}
}

void get_hash(node &t_status) {
	t_status.hash_num = 0;
	for (int i=0; i<6; i++) {
		for (int j=0; j<4; j++) {
			t_status.hash_num = t_status.hash_num*2 + t_status.surface[i][j];
		}
	}
}

bool is_solved(node t_status) {
	int t_sum[6] = {0};
	for (int i=0; i<6; i++) {
		for (int j=0; j<4; j++) {
			t_sum[i] += t_status.surface[i][j];
		}
	}
	if (*min_element(t_sum,t_sum+6) == 0) {
		return true;
	}
	else {
		return false;
	}
}

void show_cube(node cube){
	for (int i=0; i<6; i++) {
		for (int j=0; j<2; j++) {
			cout<<cube.surface[i][2*j]<<' ';
			cout<<cube.surface[i][2*j+1]<<' ';
		}
		cout<<endl;
	}
	cout<<endl<<endl;
}


int main(int argc, char const *argv[]) {
	// node test;
	// for (int i=0; i<6; i++) {
	// 	for (int j=0; j<4; j++) {
	// 		cin>>test.surface[i][j];
	// 	}
	// }
	// show_cube(test);
	// test = move_to(test,0);//test R
	// show_cube(test);
	// return 0;

	node begin;
	int t_num;
	for (int i=0; i<6; i++) {
		for (int j=0; j<2; j++) {
			cin>>t_num;
			switch(t_num) {
			case 0:
				begin.surface[i][2*j] = 0;
				begin.surface[i][2*j+1] = 0;
				break;
			case 1:
				begin.surface[i][2*j] = 0;
				begin.surface[i][2*j+1] = 1;
				break;
			case 10:
				begin.surface[i][2*j] = 1;
				begin.surface[i][2*j+1] = 0;
				break;
			case 11:
				begin.surface[i][2*j] = 1;
				begin.surface[i][2*j+1] = 1;
				break;
			}
		}
	}
	// show_cube(begin);
	if (is_solved(begin)) {
		cout<<0<<endl;
		return 0;
	}


	std::queue<node> qrq;
	std::map<int, int> step;
	
	qrq.push(begin);
	while (!qrq.empty()) {
		node t_status = qrq.front();
		node t_next;
		qrq.pop();
		for (int i=0; i<6; i++) {
			t_next = move_to(t_status,i);
			get_hash(t_next);

			// cout<<t_next.hash_num<<endl;
			// show_cube(t_next);

			if (step[t_next.hash_num] == 0) { // 判重
				// show_cube(t_next);

				if (is_solved(t_next)) {
					cout<<step[t_status.hash_num]+1<<endl;
					// show_cube(t_next);
					return 0;
					
				}
				else {
					step[t_next.hash_num] = step[t_status.hash_num] + 1;
					qrq.push(t_next);
				}
			}
		}
	}
	return 0; 
}


/* abandoned version
#include <algorithm>
#include <map>
#include <queue>
#include <iostream>
using namespace std;
int cube [23][33];
int status[6]; // 通过六面的四个块给予权重代表该面..然后对六面也给予权重代表整个面...

void input() {
	int base_x;
	int base_y;

	base_x = 2;
	base_y = 0;
	for (int i=0; i<2; i++) {
		int t;
		cin>>t;
		status[0] += t;
		if (t == 0) {
			cube[base_y+i][base_x+0] = 0;
			cube[base_y+i][base_x+1] = 0;
		}
		else if(t == 1) {
			cube[base_y+i][base_x+0] = 0;
			cube[base_y+i][base_x+1] = 1;
		}
		else if(t == 10) {
			cube[base_y+i][base_x+0] = 1;
			cube[base_y+i][base_x+1] = 0;
		}
		else {
			cube[base_y+i][base_x+0] = 1;
			cube[base_y+i][base_x+1] = 1;
		}
	}
	//cout<<"here"<<endl;
	base_x = 2;
	base_y = 5;
	for (int i=0; i<2; i++) {
		int t;
		cin>>t;
		status[1] += t;
		if (t == 0) {
			cube[base_y-i][base_x+0] = 0;
			cube[base_y-i][base_x+1] = 0;
		}
		else if(t == 1) {
			cube[base_y-i][base_x+0] = 0;
			cube[base_y-i][base_x+1] = 1;
		}
		else if(t == 10) {
			cube[base_y-i][base_x+0] = 1;
			cube[base_y-i][base_x+1] = 0;
		}
		else {
			cube[base_y-i][base_x+0] = 1;
			cube[base_y-i][base_x+1] = 1;
		}
	}

	base_x = 0;
	base_y = 2;
	for (int i=0; i<2; i++) {
		int t;
		cin>>t;
		status[2] += t;
		if (t == 0) {
			cube[base_y+i][base_x+0] = 0;
			cube[base_y+i][base_x+1] = 0;
		}
		else if(t == 1) {
			cube[base_y+i][base_x+0] = 0;
			cube[base_y+i][base_x+1] = 1;
		}
		else if(t == 10) {
			cube[base_y+i][base_x+0] = 1;
			cube[base_y+i][base_x+1] = 0;
		}
		else {
			cube[base_y+i][base_x+0] = 1;
			cube[base_y+i][base_x+1] = 1;
		}
	}

	base_x = 5;
	base_y = 2;
	for (int i=0; i<2; i++) {
		int t;
		cin>>t;
		status[3] += t;
		if (t == 0) {
			cube[base_y+i][base_x-0] = 0;
			cube[base_y+i][base_x-1] = 0;
		}
		else if(t == 1) {
			cube[base_y+i][base_x+0] = 0;
			cube[base_y+i][base_x-1] = 1;
		}
		else if(t == 10) {
			cube[base_y+i][base_x+0] = 1;
			cube[base_y+i][base_x-1] = 0;
		}
		else {
			cube[base_y+i][base_x+0] = 1;
			cube[base_y+i][base_x-1] = 1;
		}
	}
	//cout<<"here"<<endl;
	base_x = 2;
	base_y = 2;
	for (int i=0; i<2; i++) {
		int t;
		cin>>t;
		status[4] += t;
		if (t == 0) {
			cube[base_y+i][base_x+0] = 0;
			cube[base_y+i][base_x+1] = 0;
		}
		else if(t == 1) {
			cube[base_y+i][base_x+0] = 0;
			cube[base_y+i][base_x+1] = 1;
		}
		else if(t == 10) {
			cube[base_y+i][base_x+0] = 1;
			cube[base_y+i][base_x+1] = 0;
		}
		else {
			cube[base_y+i][base_x+0] = 1;
			cube[base_y+i][base_x+1] = 1;
		}
	}
	//cout<<"here"<<endl;
	base_x = 7;
	base_y = 2;
	for (int i=0; i<2; i++) {
		int t;
		cin>>t;
		status[5] += t;
		if (t == 0) {
			cube[base_y+i][base_x+0] = 0;
			cube[base_y+i][base_x-1] = 0;
		}
		else if(t == 1) {
			cube[base_y+i][base_x+0] = 0;
			cube[base_y+i][base_x-1] = 1;
		}
		else if(t == 10) {
			cube[base_y+i][base_x+0] = 1;
			cube[base_y+i][base_x-1] = 0;
		}
		else {
			cube[base_y+i][base_x+0] = 1;
			cube[base_y+i][base_x-1] = 1;
		}
	}

}

int get_status() {
	int base_row;
	int base_col;

	base_row = 0;
	base_col = 2;
	status[0] = 0;
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			status[0] = status[0]*2 + cube[base_row+i][base_col+j];
		}
	}

	base_row = 2;
	base_col = 2;
	status[1] = 0;
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			status[1] = status[1]*2 + cube[base_row+i][base_col+j];
		}
	}

	base_row = 4;
	base_col = 2;
	status[2] = 0;
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			status[2] = status[2]*2 + cube[base_row+i][base_col+j];
		}
	}

	base_row = 2;
	base_col = 0;
	status[3] = 0;
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			status[3] = status[3]*2 + cube[base_row+i][base_col+j];
		}
	}

	base_row = 2;
	base_col = 5;
	status[4] = 0;
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			status[4] = status[4]*2 + cube[base_row+i][base_col+j];
		}
	}

	base_row = 2;
	base_col = 6;
	status[5] = 0;
	for (int i=0; i<2; i++) {
		for (int j=0; j<2; j++) {
			status[5] = status[5]*2 + cube[base_row+i][base_col+j];
		}
	}
}

void move_to(int flag) {
	int base_row;
	int base_col;
	int t;
	int t2;
	switch(flag) {
	case 0://D`
		base_row = 4;
		base_col = 2;
		t = cube[base_row][base_col];
		cube[base_row][base_col] = cube[base_row][base_col+1];
		cube[base_row][base_col+1] = cube[base_row+1][base_col+1];
		cube[base_row+1][base_col+1] = cube[base_row+1][base_col];
		cube[base_row+1][base_col] = t;

		base_row = 3;
		base_col = 0;
		t = cube[base_row][base_col];
		for (int i=0; i<=6; i++) {
			cube[base_row][base_col+i] = cube[base_row][base_col+i+1];
		}
		cube[base_row][base_col+7] = t;
		break;

	case 1://R`
		base_row = 2;
		base_col = 4;
		t = cube[base_row][base_col];
		cube[base_row][base_col] = cube[base_row][base_col+1];
		cube[base_row][base_col+1] = cube[base_row+1][base_col+1];
		cube[base_row+1][base_col+1] = cube[base_row+1][base_col];
		cube[base_row+1][base_col] = t;

		t = cube[2][6];
		t2 = cube[3][6];

		cube[2][6] = cube[5][3];
		cube[3][6] = cube[4][3];

		cube[5][3] = cube[3][3];
		cube[4][3] = cube[2][3];

		cube[3][3] = cube[1][3];
		cube[2][3] = cube[0][3];

		cube[1][3] = t;
		cube[0][3] = t2;

		break;
	case 2://F`
		base_row = 2;
		base_col = 2;
		t = cube[base_row][base_col];
		cube[base_row][base_col] = cube[base_row][base_col+1];
		cube[base_row][base_col+1] = cube[base_row+1][base_col+1];
		cube[base_row+1][base_col+1] = cube[base_row+1][base_col];
		cube[base_row+1][base_col] = t;

		t = cube[2][4];
		t2 = cube[3][4];

		cube[2][4] = cube[4][3];
		cube[3][4] = cube[4][2];

		cube[4][3] = cube[3][1];
		cube[4][2] = cube[2][1];

		cube[3][1] = cube[1][2];
		cube[2][1] = cube[1][3];

		cube[1][2] = t;
		cube[1][3] = t2;
		break;
	case 3://D
		for (int i=0; i<3; i++){
			move_to(0);
		}
	case 4://R
		for (int i=0; i<3; i++){
			move_to(1);
		}
	case 5://F
		for (int i=0; i<3; i++){
			move_to(2);
		}
	}
}

int main() {
	input();
	//move_to(0);move_to(1);

	// for (int i=0; i<6; i++) {
	// 	for (int j=0; j<8; j++) {
	// 		cout<<cube[i][j];
	// 	}
	// 	cout<<endl;
	// }

	if (*min_element(status,status+6) == 0) {
		cout<<0<<endl;
		return 0;
	}

	int begin_status = 0;
	for (int i=0; i<6; i++) {
		begin_status = begin_status*2 + status[i];
	}
	queue<int> qrq;
	map<int, int> step;
	qrq.push(begin_status);
	while (!qrq.empty()) {
		int t_status = qrq.front();
		int t_next = 0;
		qrq.pop();
		for (int i=0; i<6; i++) {
			move_to(i);
			get_status();
			for (int j=0; j<6; j++) {
				t_next = t_next*2 + status[i];
			}
			if (*min_element(status,status+6) == 0) { // 复原了？
				cout<<step[t_status] + 1<<endl;
			}
			if (step[t_next] == 0) {
				step[t_next] = step[t_status] + 1;
			}
			for (int k=0; k<3; k++) {
				move_to(i);
			}
		}
	}

	return 0;
}
*/