from ..iterator import RowIterator


class Select(RowIterator):
	REQUIRED_KWARGS = ['column_name', 'value']

	def match(self):
		return self.currentRow.get_column_value(self.kwargs['column_name']) == self.kwargs['value']


class Limit(RowIterator):
	REQUIRED_KWARGS = ['limit']
	DEFAULT_VALUES = {'count': 0}

	def match(self):
		self.count += 1
		return True

	def stop(self):
		return self.count > self.kwargs['limit']


class Unique(RowIterator):
	REQUIRED_KWARGS = ['column_names']
	DEFAULT_VALUES = {'seen': set([])}

	def match(self):
		values = tuple(self.currentRow.get_column_tuples(self.kwargs['column_names']))

		if values in self.seen:
			return False

		self.seen.add(values)
		return True