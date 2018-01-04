from math import cos,sin,pi

def fallingcos8(width=1024):
	values = list()
	fac = pi/(width-1)
	for i in range(width):
		values.append(int((0.5+cos(i*fac)/2.0)*255))
	print values
	print len(values)

if __name__ == "__main__":
	fallingcos8(100)
