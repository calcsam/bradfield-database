from ..iterator import RowIterator
from ..constants import EOF

class CrossProduct(TwoOperatorRowIterator):
	def __init__(self, e1, e2, *args):
		super(CrossProduct, self).__init__()
		self.e2_clone = self.e2.clone()
		self.e1_row = self.e1.next()
		self.e2_row = self.e2.next()

	def next_left_row(self):
		self.e2 = self.e2_clone
		self.e2_clone = self.e2_clone.clone()
		self.e2_row = self.e2.next()
		self.e1_row = self.e1.next()

	def get_match(self):
		self.e2_row = next(self.e2)
		if not self.e2_row:
			return EOF

		if (self.match_value()):
			return self.e2_row
		return None

	def join(self):
		return {
			'row1': self.e1_row.fields,
			'row2': self.e2_row.fields
		}

	def stop(self):
		return False

	def nested_loop_join(self):
		if not self.e1_row:
			return EOF

		ret_value = self.get_match()

		while not ret_value:
			# done w/ cols
			if ret_value == EOF:
				self.next_left_row()
			# done w/ rows
			if not self.e1_row:
				return EOF
			ret_value = self.get_match()

		return self.join()

	def next(self):
		return self.nested_loop_join()

	def match_value(self):
		return True


class Join(CrossProduct):
	def __init__(self, e1, e2, e1_field, e2_field):
		super(Join, self).__init__()
		self.e1_field = e1_field
		self.e2_field = e2_field

	def match_value(self):
		return self.e1_row.get_column_value(self.e1_field) ==  \
				self.e1_row.get_column_value(self.e2_field)