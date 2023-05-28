import os
import sys
sys.path.append(os.path.abspath(os.path.join(__file__ ,"../..")))
from integration_helpers import run_test


# Define filename
files = ["04-0.m", "06-0.m", "07-0.m", "08-0.m", "09-0.m"]

for file in files:
    run_test(f"./tests/bytecodes/{file}")
