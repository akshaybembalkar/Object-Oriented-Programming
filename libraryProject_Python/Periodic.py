from Media import Media

class Periodic(Media):

	def __init__(self,callNo,title,subject,author,description,publisher,publishing_history,series,notes,related_titles,other_forms_of_title,gov_doc_number):
		self.callNo = callNo
		self.title = title
		self.subject = subject
		self.author = author
		self.description = description
		self.publisher = publisher
		self.publishing_history = publishing_history
		self.series = series
		self.notes = notes
		self.related_titles = related_titles
		self.other_forms_of_title = other_forms_of_title
		self.gov_doc_number = gov_doc_number
		super(Periodic,self).__init__(self.callNo,self.title,self.subject,self.notes)

#	Media.__init__(self,callNo,title,subject,notes)
#	def __repr__(self):
#		return "%s %s %s %s %s %s %s %s %s %s" %#(self.callNo,self.title,self.subject,self.author,self.description,self.publisher,self.city,self.year,self.series,self.notes)


	
	def compare_Other(self,other):
		if other in self.description:
			return True
		elif other in self.series:
			return True
		elif other in self.related_titles:
			return True
		elif other in self.notes:
			return True
		else:
			return False




	def display(self):
		super(Periodic,self).display()
		print ("Author: %s" % (self.author))
		print ("Description: %s" % (self.description))
		print ("Publisher: %s" % (self.publisher))
		print ("publishing_history: %s" % (self.publishing_history))
		print ("Series: %s " % (self.series))
		print ("related_titles: %s" % (self.related_titles))
		print ("other_forms_of_title: %s" % (self.other_forms_of_title))
		print ("gov_doc_number: %s\n\n" % (self.gov_doc_number))

		
