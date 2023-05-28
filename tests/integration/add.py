import os
import sys
sys.path.append(os.path.abspath(os.path.join(__file__ ,"../..")))
from integration_helpers import run_test


# Define filename
file = "04-0.m"

run_test(f"./tests/bytecodes/{file}")
