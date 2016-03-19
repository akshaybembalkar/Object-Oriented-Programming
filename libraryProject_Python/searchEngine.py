from Book import Book
from Film import Film
from Periodic import Periodic
from Video import Video
from Media import Media

cardCatalog = []

class searchEngine():	

	def __init__(self):
		self.fileProcessing()

#fileProcessin() reads all files and inserts data into the list
	def fileProcessing(self):
		
		with open("book.txt" , 'r') as bookObj:
			for line in bookObj:
				fields = line.split('|')
				
				l0 = fields[0]
				l1 = fields[1]
				l2 = fields[2]
				l3 = fields[3]
				l4 = fields[4]
				l5 = fields[5]
				l6 = fields[6]
				l7 = fields[7]
				l8 = fields[8]
				l9 = fields[9]
				book = Book(l0,l1,l2,l3,l4,l5,l6,l7,l8,l9)
				book.__class__ = Book
				cardCatalog.append(book)
			
			#for obj in cardCatalog:
				#obj.display()
				#print len(cardCatalog)

		with open("periodic.txt" , 'r') as periodicObj:
			for line in periodicObj:
				fields = line.split('|')
				
				l0 = fields[0]
				l1 = fields[1]
				l2 = fields[2]
				l3 = fields[3]
				l4 = fields[4]
				l5 = fields[5]
				l6 = fields[6]
				l7 = fields[7]
				l8 = fields[8]
				l9 = fields[9]
				l10 = fields[10]
				l11 = fields[11]
				periodic = Periodic(l0,l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11)
				periodic.__class__ = Periodic
				cardCatalog.append(periodic)


		with open("video.txt" , 'r') as videoObj:
			for line in videoObj:
				fields = line.split('|')
				
				l0 = fields[0]
				l1 = fields[1]
				l2 = fields[2]
				l3 = fields[3]
				l4 = fields[4]
				l5 = fields[5]
				l6 = fields[6]
				l7 = fields[7]
				
				video = Video(l0,l1,l2,l3,l4,l5,l6,l7)
				video.__class__ = Video
				cardCatalog.append(video)



		with open("film.txt" , 'r') as filmObj:
			for line in filmObj:
				fields = line.split('|')
				
				l0 = fields[0]
				l1 = fields[1]
				l2 = fields[2]
				l3 = fields[3]
				l4 = fields[4]
				l5 = fields[5]
				film = Film(l0,l1,l2,l3,l4,l5)
				film.__class__ = Film
				cardCatalog.append(film)


#Search By call Number
	def searchByCallno(self,callNo):
		resultList = []
		for obj in cardCatalog:
			result = obj.compare_Callno(callNo)
			if result:
				resultList.append(obj)
			
		return resultList

#Search by Title
	def searchByTitle(self,title):
		resultList = []
		for obj in cardCatalog:
			result = obj.compare_Title(title)
			if result:
				resultList.append(obj)
			
		return resultList         #Return search result

#Search by Subject
	def searchBySubject(self,subject):
		resultList = []
		for obj in cardCatalog:
			result = obj.compare_Subject(subject)
			if result:
				resultList.append(obj)
			
		return resultList

#Search by Other String
	def searchByOther(self,other):
		resultList = []
		for obj in cardCatalog:
			result = obj.compare_Other(other)
			if result:
				resultList.append(obj)
			
		return resultList






