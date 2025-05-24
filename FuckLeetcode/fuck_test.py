# 命令行指定文件作为输入
# 通过反射进行测试
import sys
import os
import importlib
from IPython import embed
import inspect
import traceback
import time

# author: 4o
def import_module_from_path(relative_path, module_name):
    # 获取当前文件的绝对路径
    current_dir = os.path.dirname(__file__)
    # 将相对路径转换为绝对路径
    absolute_path = os.path.join(current_dir, relative_path)

    # 使用importlib.util.spec_from_file_location来加载模块
    spec = importlib.util.spec_from_file_location(module_name, absolute_path)
    module = importlib.util.module_from_spec(spec)
    sys.modules[module_name] = module
    spec.loader.exec_module(module)
    return module


# author: 4o
def global_exception_hook(exc_type, exc_value, exc_traceback):
    # 打印异常信息

    # 打印堆栈信息
    traceback.print_tb(exc_traceback)

    # 遍历堆栈帧
    tb = exc_traceback
    while tb is not None:
        frame = tb.tb_frame
        local_vars = frame.f_locals
        print(f"\nIn file: {frame.f_code.co_filename}, line: {tb.tb_lineno}, in {frame.f_code.co_name}")
        print("Local variables:")
        for var_name, var_value in local_vars.items():
            print(f"    {var_name} = {var_value}")
        tb = tb.tb_next
    print("Unhandled exception caught!")
    print("Exception type:", exc_type)
    print("Exception value:", exc_value)

# 设置全局异常钩子
sys.excepthook = global_exception_hook


if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Usage: python fuck_test.py [code file] [func name]?")
        exit(-1)
    file_name = sys.argv[1]
    print(file_name)
    current_dir = os.path.dirname(__file__)

    module = import_module_from_path(file_name, current_dir)
    
    sIns = module.Solution()
    funcs = inspect.getmembers(sIns, predicate=inspect.ismethod)
    # embed()
    if len(funcs) != 1 and len(sys.argv) < 3:
        print(f"Specify function name plz. in {funcs}")
        exit(-2)
    print(funcs)
    func = funcs[0] if len(funcs) == 1 else [sys.argv[2], getattr(sIns, sys.argv[2], None)]
    if not func:
        print(f"func name not in {funcs}")
        exit(-3)
    
    if not getattr(module, 'INPUT', None):
        print("Specify INPUT in module plz.")
        exit(-4)
    
    for i in module.INPUT:
        timeBeg = time.time()
        r = func[1](*i)
        timeEnd = time.time()
        print(f"{func[0]}{i} ==> {r}, cost: {timeEnd-timeBeg:.4f}")
    
    # embed()
    pass