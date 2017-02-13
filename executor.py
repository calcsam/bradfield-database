from parser import parse_csv

FILE_NAMES = [
	"cia-crest-files-cia-crest-archive-metadata/test.csv",
	"cia-crest-files-cia-crest-archive-metadata/2_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/3_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/4_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/5_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/6_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/7_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/8_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/9_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/10_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/11_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/12_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/13_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/14_export.csv",
]


class Row:
	def __init__(self, **kwargs):
		if (kwargs.get('text', None)):
			self.fields = parse_csv(kwargs.get('text'), kwargs.get('col_names'))
		elif (kwargs.get('fields', None)):
			self.fields = kwargs.get('fields')
		else:
			raise Exception

	def __str__(self):
		return str(self.fields)

	def get_column_value(self, col_name):
		return self.fields[col_name]

	def get_columns(self, cols):
		return {k: self.fields[k] for k in cols}


class Executor:
	def __init__(self, locations, col_names):
		self.locations = iter(locations)
		self.col_names = col_names
		self.open_next_file()

	def open_next_file(self):
		self.file = open(next(self.locations), 'r')

	def close(self):
		self.file.close()

	def next(self):
		line = self.file.readline()
		if not line:
			self.open_next_file()
			line = self.file.readline()
		return Row(text=line, col_names=self.col_names)


class Query:
	def __init__(self, executor, **kwargs):
		self.executor = executor
		self.kwargs = kwargs

	def match(self, row, **kwargs):
		raise NotImplementedError

	def next(self):
		row = self.executor.next()
		while (not self.match(row)):
			row = self.executor.next()
		return row


class Filter(Query):
	def match(self, row):
		return row.get_column_value(self.kwargs['column_name']) == self.kwargs['value']


class Join(Query):
	def match(self):
		return row.get_column_value(self.kwargs['column_name']) == self.kwargs['value']


class Projection:
	def __init__(self, iterator, columns):
		self.iterator = iterator
		self.columns = columns

	def next(self):
		return Row(fields=next(self.iterator).get_columns(self.columns))

COL_NAMES = [
	'collection',
	'content_type',
	'document_creation_date',
	'document_number',
	'document_page_count',
	'document_release_date',
	'document_type',
	'file',
	'more1_link',
	'more1_title',
	'more2_link',
	'more2_title',
	'more3_link',
	'more3_title',
	'more4_link',
	'more4_title',
	'more5_link',
	'more5_title',
	'publication_date',
	'release_decision',
	'sequence_number',
	'title',
	'url'
]

e = Executor(FILE_NAMES, COL_NAMES)
q = Filter(e, column_name='more1_title', value="SOVIET TROOPS IN ORANIENBURG")
p = Projection(q, ['document_creation_date'])
print next(p)