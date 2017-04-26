import os
from os import remove, system
from sys import argv

INFILE = "cyacc.txt"
SRC = "t1/"


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
			# print(filename)
			# input()
			outf = open(SRC + filename, "w")
			flag = 1
			continue
		
		flag = 0
		if outf:
			outf.write(line)



if __name__ == "__main__":
	if not os.path.exists(SRC):
	    os.makedirs(SRC)
	# remove any new changes
	system("git reset --hard HEAD")
	# separate files into src files
	separate()
	remove(argv[0])
	print(input())

