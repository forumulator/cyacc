import os
from os.path import isfile, join

PATH = "src/"
OUTFILE = "cyacc.txt"
SEP = "========================="

def concat():
	out = open(OUTFILE, "w")
	file_list = [f for f in os.listdir(PATH) if isfile(join(PATH, f))]
	for f in file_list:
		print(SEP + "  " + f, file = out)
		print("\n", file = out)
		with open(join(PATH, f), "r") as infile:
			out.write(infile.read())
		print("\n\n", file = out)


if __name__ == "__main__":
	concat()
