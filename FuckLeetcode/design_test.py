import imp
import argparse
import importlib

parser = argparse.ArgumentParser()
parser.add_argument("file", help="file to test")
args = parser.parse_args()

md_name = '_'.join(args.file.split('.')[:-1])

print(f'loading {md_name}...')
module = imp.load_source(md_name, args.file)

try:
    ops = module.ops
    args = module.args
    exps = module.exps
except Exception as e:
    print(e)
    print("ERROR: There's no ops/args/exps in the file")
    exit(-1)
print(f'loaded: {md_name}, len(ops): {len(ops)}, len(args): {len(args)} len(exps): {len(exps)}\n')

n = len(ops)
solver = None
wrongs = []
for i in range(n):
    op = ops[i]
    arg = args[i]
    exp = exps[i]
    if i==0:
        if not hasattr(module, op):
            print(f"ERROR: There's no {op} in the file")
            exit(-1)
        solver = getattr(module, op)(*arg)
        print(f"Test [{i}]\n\tinput: {op}({','.join(map(str,arg))})\n\toutput: {solver}\n\n")
        continue
    if not hasattr(solver, op):
        print(f"ERROR: There's no {op} in the {solver}")
        exit(-1)
    r = getattr(solver, op)(*arg)
    print(f"Test [{i}]\n\tinput: {op}({','.join(map(str,arg))})\n\toutput: {r}\n\texp: {exp}\n\tcorrect: {r==exp}\n")
    if r!=exp:
        wrongs.append((i, op, arg, exp))

if len(wrongs)==0:
    exit(0)
print("Wrong Test cases:")
for i,op,arg,exp in wrongs:
    print(f"Test [{i}]\n\tinput: {op}({','.join(map(str,arg))})\n\texp: {exp}\n\toutput: {r}\n\n")