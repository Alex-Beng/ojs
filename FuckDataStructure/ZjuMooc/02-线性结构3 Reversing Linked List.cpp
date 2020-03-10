/**
 * WA!!!!!!!!!
 * */

#include <cstdio>

#include <iostream>
using namespace std;

struct Node {
    int data;
    int next;
};

Node memory[100090];

int Reverse(int head, int end);
void Print(int head);

int main(int argc, char const *argv[]) {
    int head, n, k;
    cin>>head>>n>>k;

    for (int i=0; i<n; i++) {
        int t_pos;
        Node t_node;
        cin>>t_pos>>t_node.data>>t_node.next;
        memory[t_pos].data = t_node.data;
        memory[t_pos].next = t_node.next;

    }

    // find K
    int t_ptr = head;
    while (t_ptr != -1) {
        if (memory[t_ptr].data == k) {
            break;
        }
        t_ptr = memory[t_ptr].next;
    }
    
    head = Reverse(head, memory[t_ptr].next);

    Print(head);
}

int Reverse(int head, int end) {
    int curr_node = head;
    int curr_head = end;
    while (curr_node != end) {
        // cout<<curr_node<<' '<<memory[curr_node].data<<endl;

        int t_next = memory[curr_node].next;

        memory[curr_node].next = curr_head;
        curr_head = curr_node;
        curr_node = t_next;
    }
    return curr_head;
}

void Print(int head) {
    int t_ptr = head;
    while (t_ptr != -1) {
        if (memory[t_ptr].next != -1)
            printf("%05d %d %05d\n", t_ptr, memory[t_ptr].data, memory[t_ptr].next);
        else 
            printf("%05d %d %d\n", t_ptr, memory[t_ptr].data, memory[t_ptr].next);
        t_ptr = memory[t_ptr].next;
    }
}

/**
00100 1 4
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

 * */