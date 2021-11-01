#
# @lc app=leetcode.cn id=1114 lang=python3
#
# [1114] 按序打印
#

# @lc code=start
class Foo:
    def __init__(self):
        self.status = 0

    def first(self, printFirst: 'Callable[[], None]') -> None:
        while True: 
            if self.status == 0:
                printFirst()
                self.status = 1
                return

    def second(self, printSecond: 'Callable[[], None]') -> None:
        while True:
            if self.status == 1:
                printSecond()
                self.status = 2
                return

    def third(self, printThird: 'Callable[[], None]') -> None:
        while True: 
            if self.status == 2:
                printThird()
                self.status = 0
                return
# @lc code=end
