import os
import sys
sys.path.append(os.path.abspath(os.path.join(__file__ ,"../..")))
from integration_helpers import run_test


# Define filename
files = ["11-0.m", "11-1.m", "11-2.m"]

for file in files:
    run_test(f"./tests/bytecodes/{file}")
