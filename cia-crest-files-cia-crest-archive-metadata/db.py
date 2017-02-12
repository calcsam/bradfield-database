import csv

titles = [str(i) + "_export.csv" for i in range(1,15)]

rows = []

for title in titles:
	with open(title, 'rb') as csvfile:
		open_file = csv.reader(csvfile, delimiter=',', quotechar='|')
		for row in open_file:
			rows.append(row)
