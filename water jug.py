def fill_first(x, y,end):
	x=first
	print x,y

	
	x=x-(second-y)
	y=second
	print x,y

	if x==end:
		return
	
	if x==0:
		if x==end or y==end:
				return
		fill_first(x,y,end)

	if y==second:
		y=0
		print x,y
		if (x<=second):
			x,y=y,x
			print x,y
			if x==end or y==end:
				return
			fill_first(x,y,end)

		if x>second:
			y=second
			x=x-second
			print x,y
			if x==end or y==end:
				return
			fill_first(x,y,end)



first = input("Enter capacity of first jug:	")
second = input("Enter capacity of second jug: ")
end = input("Enter the final measure of first jug: ")

fill_first(first,0,end)