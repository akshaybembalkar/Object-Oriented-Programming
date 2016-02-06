# Author: Akshay S. Bembalkar
#
# A menu driven program to built library search engine.
#

from searchEngine import searchEngine

searchObj = searchEngine()
searchObj.fileProcessing()

resultList = []	#Declare resultList to hold search data


while True:

	print ("Selct your search type: ")
	print ("1.Search by Call number")
	print ("2.Search by Title")
	print ("3.Search by Subject")
	print ("4.Search Other")
	print ("5.Quit")

	choice = (input("\nEnter your choice: "))

	if choice == "1":
		resultList[:] = []
		print ("Searching by call no....")
		callno = input("Enter Call Number to search: ")
		resultList = searchObj.searchByCallno(callno)
		for obj in resultList:
			obj.display()
		print (len(resultList))


	elif choice == "2":
		print ("Searching by Title....")
		resultList[:] = []
		title = input("Enter Title to search: ")
		resultList = searchObj.searchByTitle(title)
		for obj in resultList:
			obj.display()
		print (len(resultList))

	elif choice == "3":
		print ("Searching by Subject....")
		resultList[:] = []
		subject = input("Enter Subject to search: ")
		resultList = searchObj.searchBySubject(subject)
		for obj in resultList:
			obj.display()
		print (len(resultList))

	elif choice == "4":
		print ("Searching String....")
		resultList[:] = []
		other = input("Enter string to search: ")
		resultList = searchObj.searchByOther(other)
		for obj in resultList:
			obj.display()
		print (len(resultList))


	elif choice=="5":
		resultList[:] = []
		break

	else:
		print ("Wrong Input....")
		continue

	ch = input("Do you want to continue[y/n]: ")
	if ch == 'y' or ch == 'Y':
		continue
	else:
		break;
	
