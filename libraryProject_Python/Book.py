from Media import Media

class Book(Media):

	def __init__(self,callNo,title,subject,author,description,publisher,city,year,series,notes):
		self.callNo = callNo
		self.title = title
		self.subject = subject
		self.author = author
		self.description = description
		self.publisher = publisher
		self.city = city
		self.year = year
		self.series = series
		self.notes = notes
		super(Book,self).__init__(self.callNo,self.title,self.subject,self.notes)


	
	def compare_Other(self,other):
		if other in self.description:
			return True
		elif other in self.year:
			return True
		elif other in self.notes:
			return True
		else:
			return False




	def display(self):
		super(Book,self).display()
		print ("Author: %s" % (self.author))
		print ("Description: %s" % (self.description))
		print ("Publisher: %s" % (self.publisher))
		print ("City: %s" % (self.city))
		print ("Year: %s" % (self.year))
		print ("Series: %s\n\n" % (self.series))
	#	print "Notes: %s" % self.notes
		
