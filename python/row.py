from parser import parse_csv

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

	def get_column_value(self, col_name, DEFAULT_VALUE=0):
		return self.fields.get(col_name, DEFAULT_VALUE)

	def get_column_tuples(self, cols):
		return [self.fields.get(k, None) for k in cols]

	def get_columns(self, cols):
		return {k: self.fields.get(k, None) for k in cols}