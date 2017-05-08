import os
from subprocess import DEVNULL, STDOUT, check_call
from sys import argv

dINFILE = "cyacc.txt"
dSRC = "t1/"


def separate():
	inf = open(INFILE, "r")
	outf = None
	flag = 0
	for line in inf.readlines():
		# Skip all newlines after the name separator
		# and all lines at beg
		if (flag and line == '\n'):
			continue
		# New file name spearator
		if line[0:4] == "====":
			if outf: outf.close()
			filename = line.split("=")[-1].lstrip().rstrip()
			outf = open(SRC + filename, "w")
			flag = 1
			continue
		
		flag = 0
		if outf:
			outf.write(line)



if __name__ == "__main__":
	global SRC, INFILE
	SRC = INFILE = None
	if not SRC:
		SRC = dSRC
	if not INFILE:
		INFILE = dINFILE
	# make dir if it doesn't exist
	if not os.path.exists(SRC):
	    os.makedirs(SRC)
	# separate files into src files
	separate()

# function : {}
# Set-Alias -Name mv -Value : -Option AllScope