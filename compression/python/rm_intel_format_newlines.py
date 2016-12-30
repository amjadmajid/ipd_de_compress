from __future__ import print_function
import argparse

parser = argparse.ArgumentParser()
parser.add_argument("-n", help="r: remove the new lines charaters")
parser.add_argument("-i", help="r: remove intel formatting")
parser.add_argument("-w", default="../dataFiles/dump.hex", help="output file name")
parser.add_argument("-r", default="../dataFiles/run-wireless.hex", help="input file name")


def main():
	args = parser.parse_args()

	ofile = args.w
	ifile = args.r

	# remove intel formatting
	if args.i == 'r' and args.n == 'r':
		remove_intel_format_newline(ifile, ofile)
	elif args.i == 'r':
		remove_intel_format(ifile, ofile)
	elif args.n == 'r':
		remove_newline(ifile, ofile)


def remove_intel_format(ifile, ofile):
	in_file = open(ifile, 'r')
	out_file = open(ofile, 'w')
	for line in in_file:
		line = line[9:-3]
		print (line, file=out_file)

def remove_intel_format_newline(ifile, ofile):
	in_file = open(ifile, 'r')
	out_file = open(ofile, 'w')
	for line in in_file:
		line = line[9:-3]
		print (line, file=out_file, end="")

def remove_newline(ifile, ofile,):
	in_file = open(ifile, 'r')
	out_file = open(ofile, 'w')
	for line in in_file:
		line = line[:-1]
		print (line, file=out_file ,end="" )

if __name__=='__main__':
	main()
