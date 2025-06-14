import subprocess
import glob

for OUT in glob.glob('*.a'):
    IN = OUT.replace(".a", "")
    NAME = IN
    if NAME[0] == '0':
        NAME = NAME[1:]
    subprocess.run(f'move {IN} {NAME}.in', shell=True) #change to mv on linux or mac
    subprocess.run(f'move {OUT} {NAME}.out', shell=True) #change to mv on linux or mac