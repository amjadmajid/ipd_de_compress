from __future__ import print_function
for line in open("dump.hex"):
	line = line.split(" ")
	print ("".join( [line[1], line[2], line[3], line[4], line[5], line[6], line[7], line[8]]  ), end="")
