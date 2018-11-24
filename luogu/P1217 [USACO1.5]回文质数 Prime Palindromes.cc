#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
bool is_prime[100000001];
int prime_nums[100000001];

bool Is_Prime(int num, int flag) {
    if (num==0 || num==1) {
        return false;
    }
    if (flag == 0) { // 普通弱智判素数
        for (int i=2; i*i<num; i++) {
            if (num%i == 0) {
                return false;
            }
        }
        return true;
    }
    else if (flag == 1) { // 埃式筛
        // bool is_prime[num+1] = {true};
        for (int i=2; i<=num; i++) {
            if (!is_prime[i]) {
                for (int j=i*i; j<=num; j+=i) {
                    is_prime[j] = true;
                }
            }
        }
        return is_prime[num];
    }
    else {
        // std::vector<int> prime_nums;
        int prime_nums_count = 0;
        for (int i=2; i<=num; i++) {
            if (!is_prime[i]) {
                // prime_nums.push_back(i);
                prime_nums[prime_nums_count++] = i;
            }
            // for (size_t j=0; j<prime_nums.size() && i*prime_nums[j]<=num; j++) {
            for (size_t j=0; j<prime_nums_count && i*prime_nums[j]<=num; j++) {
                is_prime[i*prime_nums[j]] = true;
                if (i%prime_nums[j] == 0) {
                    break;
                }
            }
        }
        return is_prime[num];
    }
}

bool is_revers_num(int num) {
    
    int ans = 0;
    int raw_num = num;
    while (num > 0) {
        ans *= 10;
        ans += num%10;
        num /= 10;
    }
    if (ans == raw_num) {
        return true;
    }
    else {
        return false;
    }
}

int main(int argc, char const *argv[]) {
    // memset(is_prime, true, sizeof(is_prime));

    // Is_Prime(100000000, 1); // 0.35s
    Is_Prime(10000000, 2); // 1.13s

    int a, b;
    cin>>a>>b;
    if (b > 10000000) {
        b = 10000000;
    }
    for (int i=a; i<=b; i++) {
        if (is_revers_num(i) && !is_prime[i]) {
            cout<<i<<endl;  
        }
    }
    return 0;
}
