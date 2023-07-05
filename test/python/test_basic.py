import os
import os.path as osp
import subprocess

path = '../../out/build/x64-Debug/'
my_env = {**os.environ, 'PATH': '/usr/sbin:/sbin:' + os.environ['PATH']}

def compile_program(source):
    proc = subprocess.run([osp.join(path, 'bin/miniclang.exe'), source],
                          capture_output=True,
                          timeout=10)
    assert proc.returncode == 0, proc.stderr
    ir = proc.stdout.decode('utf-8')
    return ir

def save_compiled(ir, out_filename):
    with open(out_filename, 'w') as f:
        f.write(ir + '\n')

def validate_compiled(filename, expected):
    proc = subprocess.run(['clang', filename, '-o', 'tmp.out'])
    assert proc.returncode == 0, proc.stderr
    proc = subprocess.run(['tmp.out'])
    assert proc.returncode == expected

def test_wellformed(source, expected):
    ir = compile_program(source)
    save_compiled(ir, 'tmp.ll')
    validate_compiled('tmp.ll', expected)

proc = subprocess.run(['clang', '-v'], env=my_env)
assert proc.returncode == 0
test_wellformed('42+5', 47)
test_wellformed(' 5 + 3 - 1', 7)
