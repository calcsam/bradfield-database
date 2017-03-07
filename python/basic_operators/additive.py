from ..iterator import RowIterator
from ..constants import EOF


class Union(RowIterator):
	REQUIRED_KWARGS = ['column_name', 'value']

	def stop_e1(self):
		if hasattr(self, 'e1_eof'):
			return self.e1_eof
		return False

	def stop_e2(self):
		if hasattr(self, 'e2_eof'):
			return self.e2_eof
		return False

	def next(self):
		if not self.stop_e1():
			self.currentRow = self.e1.next()
			if self.currentRow == EOF:
				self.e1_eof = True
		elif not self.stop_e2():
			self.currentRow = self.e2.next()
			if self.currentRow == EOF:
				self.e2_eof = True
		else:
			return self.currentRow

