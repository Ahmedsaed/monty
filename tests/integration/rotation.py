import os
import sys
sys.path.append(os.path.abspath(os.path.join(__file__ ,"../..")))
from integration_helpers import run_manual_test


# Define filename
file = "13-0.m"
correct_output = """0
9
8
7
6
5
4
3
2
1
9
8
7
6
5
4
3
2
1
0"""
correct_error = ""
correct_exit_code = 0

run_manual_test(f"./tests/bytecodes/{file}", correct_output, correct_error, correct_exit_code)

# Define filename
file = "14-0.m"
correct_output = """0
9
8
7
6
5
4
3
2
1
1
0
9
8
7
6
5
4
3
2"""
correct_error = ""
correct_exit_code = 0

run_manual_test(f"./tests/bytecodes/{file}", correct_output, correct_error, correct_exit_code)
