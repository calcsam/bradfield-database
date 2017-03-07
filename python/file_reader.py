from constants import EOF
from row import Row


class Executor:
	def __init__(self, locations, col_names):
		self.all_locations = locations
		self.locations = iter(locations)
		self.col_names = col_names
		self.open_next_file()

	def open_next_file(self):
		try:
			self.file = open(next(self.locations), 'r')
		except StopIteration:
			self.file = None

	def close(self):
		self.file.close()

	def next(self):
		line = self.file.readline()
		if not line:
			self.open_next_file()
			if not self.file:
				return EOF
			line = self.file.readline()
		return Row(text=line, col_names=self.col_names)

	def clone(self):
		return Executor(self.all_locations, self.col_names)