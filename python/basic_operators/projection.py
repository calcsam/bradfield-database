from ..row import Row


class Projection:
	def __init__(self, iterator, columns):
		self.iterator = iterator
		self.columns = columns

	def next(self):
		return Row(fields=next(self.iterator).get_columns(self.columns))

	def clone(self):
		return Projection(self.iterator.clone(), self.columns)