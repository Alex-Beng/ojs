#include <map>
#include <iostream>
using namespace std;

string idx2op[6] = {"FILL(1)","FILL(2)","DROP(1)","DROP(2)","POUR(1,2)","POUR(2,1)"};

struct status
{
    int cA;
    int cB;
    int prev;
    int op;
    status() {
        cA = cB = 0;
        prev = op = -1;
    }

    status(int A, int B, int pv=-1, int o=-1) {
        cA = A;
        cB = B;
        prev = pv;
        op = o;
    }

    // for map
    bool operator<(const status& that) const {
        //! 状态只与AB有关
        int this_key = cB*1000 + cA;
        int that_key = that.cB*1000 + that.cA;
        return this_key<that_key;
    }

    // for assign
    void operator=(const status &that){
        cA = that.cA;
        cB = that.cB;
        prev = that.prev;
        op = that.op;
    }

    // for debugging output
    friend ostream &operator<<( ostream &output, 
                                       const status &s )
    { 
        output << "A: " << s.cA << " B: " << s.cB << " prev: "<<s.prev << " op: "<<s.op;
        return output;            
    }
};

void out_res(status* st_qrq, int b_idx, int res) {
    if (b_idx == -1) {
        cout<<res<<endl;
    }
    else {
        int pv = st_qrq[b_idx].prev;
        out_res(st_qrq, pv, res);
        if (st_qrq[b_idx].op != -1)
            cout<<idx2op[st_qrq[b_idx].op]<<endl;
    }
}


int bfs(int A, int B, int C) {
    // 队列儿
    status st_qrq[23333];
    int qrq_head_idx = 0;
    int qrq_tail_idx = 0;
    std::map<status, int> cost;

    status t_s;
    st_qrq[qrq_tail_idx++] = t_s;
    cost[t_s] = 1;
    
    int t_idx = -1;
    int t_cost;
    while (qrq_head_idx != qrq_tail_idx) {
        t_s = st_qrq[qrq_head_idx];
        t_idx = qrq_head_idx;// for output res
        t_cost = cost[t_s];
        qrq_head_idx++;

        // cout<<t_s<<" cost: "<<t_cost<<endl;

        if (t_s.cA == C || t_s.cB == C) {
            out_res(st_qrq, t_idx, t_cost-1);
            return 1;
        }
        int t;
        // FILL(i)
        if (t_s.cA < A) {
            t = t_s.cA;
            t_s.cA = A;
            t_s.prev = t_idx;
            t_s.op = 0;
            if (!cost[t_s]) {
                cost[t_s] = t_cost + 1;
                st_qrq[qrq_tail_idx++] = t_s;
            }
            t_s.cA = t;
        }
        if (t_s.cB < B) {
            t = t_s.cB;
            t_s.cB = B;
            t_s.prev = t_idx;
            t_s.op = 1;
            if (!cost[t_s]) {
                cost[t_s] = t_cost + 1;
                st_qrq[qrq_tail_idx++] = t_s;
            }
            t_s.cB = t;
        }

        // DROP(i)
        if (t_s.cA > 0) {
            t = t_s.cA;
            t_s.cA = 0;
            t_s.prev = t_idx;
            t_s.op = 2;
            if (!cost[t_s]) {
                cost[t_s] = t_cost + 1;
                st_qrq[qrq_tail_idx++] = t_s;
            }
            t_s.cA = t;
        }
        if (t_s.cB > 0) {
            t = t_s.cB;
            t_s.cB = 0;
            t_s.prev = t_idx;
            t_s.op = 3;
            if (!cost[t_s]) {
                cost[t_s] = t_cost + 1;
                st_qrq[qrq_tail_idx++] = t_s;
            }
            t_s.cB = t;
        }

       // POUR(i,j)
        if (t_s.cA>0 && t_s.cB<B) {
            int t_water = min((B-t_s.cB), t_s.cA);
            t_s.cA -= t_water;
            t_s.cB += t_water;
            t_s.prev = t_idx;
            t_s.op = 4;
            if (!cost[t_s]) {
                cost[t_s] = t_cost + 1;
                st_qrq[qrq_tail_idx++] = t_s;
            }
            t_s.cA += t_water;
            t_s.cB -= t_water;
        }
        if (t_s.cB>0 && t_s.cA<A) {//!
            int t_water = min((A-t_s.cA), t_s.cB);//!
            t_s.cB -= t_water;
            t_s.cA += t_water;
            t_s.prev = t_idx;
            t_s.op = 5;
            if (!cost[t_s]) {
                cost[t_s] = t_cost + 1;
                st_qrq[qrq_tail_idx++] = t_s;
            }
            t_s.cB += t_water;
            t_s.cA -= t_water;
        }
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    int a, b, c;
    cin>>a>>b>>c;
    int t = bfs(a, b, c);
    if (!t) {
        cout<<"impossible"<<endl;
    }
    return 0;
}