from Media import Media

class Video(Media):

	def __init__(self,callNo,title,subjects,description,distributor,notes,series,label):
		self.callNo = callNo
		self.title = title
		self.subjects = subjects
		self.description = description
		self.distributor = distributor
		self.notes = notes
		self.series = series
		self.label = label
		super(Video,self).__init__(self.callNo,self.title,self.subjects,self.notes)


	
	def compare_Other(self,other):
		if other in self.description:
			return True
		elif other in self.distributor:
			return True
		elif other in self.notes:
			return True
		else:
			return False




	def display(self):
		super(Video,self).display()
		print ("description: %s" % (self.description))
		print ("distributor: %s" % (self.distributor))
		print ("series: %s" % (self.series))
		print ("label: %s" % (self.label))
		
		
