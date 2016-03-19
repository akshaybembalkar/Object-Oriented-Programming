#Author: Akshay S. Bembalkar

class Media(object):

#Constructor to initialize attributes those are common to book, film, videos and periodic.
	def __init__(self,callNo,title,subject,notes):
		self.callNo = callNo
		self.title = title
		self.subject = subject
		self.notes = notes



#Comapare string with call number
	def compare_Callno(self,callNo):
		if callNo in self.callNo:     #If string is in Call number string,
			return True           #Return true
		else:
			return False


#Comapare string with Title
	def compare_Title(self,title):
		if title in self.title:
			return True
		else:
			return False
	
#Comapare string with Subject
	def compare_Subject(self,subject):
		if subject in self.subject:
			return True
		else:
			return False

	def display(self):
		print ("Call Number: %s" % (self.callNo))
		print ("Title: %s" % (self.title))
		print ("Subject: %s" % (self.subject))
		print ("Notes: %s" % (self.notes))
