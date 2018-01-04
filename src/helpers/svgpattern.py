from math import pi, cos, sin
def circual(radius, parts):
	rad = 2*pi/parts
	cr = 0.0
	ud = True
	path = ""
	while (cr < 2*pi):
			path += "0,0 "
			path += "%f,%f " % ( radius*cos(cr),radius*sin(cr))
			cr += rad
			path += "%f,%f " % ( radius*cos(cr),radius*sin(cr))
			cr += rad
	return "M %sZ" % path
	
if __name__ == "__main__":
	print circual(500,36)
