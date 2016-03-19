from Media import Media

class Film(Media):

	def __init__(self,callNo,title,subjects,director,notes,year):
		self.callNo = callNo
		self.title = title
		self.subjects = subjects
		self.director = director
		self.notes = notes
		self.year = year
		super(Film,self).__init__(self.callNo,self.title,self.subjects,self.notes)


	
	def compare_Other(self,other):
		if other in self.director:
			return True
		elif other in self.year:
			return True
		elif other in self.notes:
			return True
		else:
			return False




	def display(self):
		super(Film,self).display()
		print ("Director: %s" % (self.director))
		print ("Year: %s" % (self.year))
		
		
