import os
import sys
sys.path.append(os.path.abspath(os.path.join(__file__ ,"../..")))
from integration_helpers import run_manual_test


# Define filename
file = "15-0.m"
corrcet_output = """1
2
3
6
5
4
1
2
3
11
4
1
2
3
15
1
2
3
11111"""
correct_error = ""
correct_exit_code = 0

run_manual_test(f"./tests/bytecodes/{file}", corrcet_output, correct_error, correct_exit_code)
