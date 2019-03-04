#include "SeqList.h"
#include "SingleLinkList.h"
#include "CircularLinkList.h"

int main(int argc, char const *argv[]) {
    int t = 233;
    CircularLinkList<int> cll;
    cll.input();
    cll.PushBack(666);
    cll.output();
    return 0;
}
