from constants import EOF, BOF

class RowIterator:
	REQUIRED_KWARGS = []
	DEFAULT_VALUES = {}

	def __init__(self, executor, *args, **kwargs):
		self.executor = executor
		self.kwargs = kwargs
		self.currentRow = BOF
		for kwarg in self.REQUIRED_KWARGS:
			if kwarg not in kwargs:
				raise Exception
		for var in self.DEFAULT_VALUES:
			setattr(self, var, self.DEFAULT_VALUES[var])

	def stop(self):
		return False

	def match(self, **kwargs):
		raise NotImplementedError

	def next(self):
		while not self.match() and not self.stop():
			self.currentRow = self.executor.next()
		if self.stop():
			return EOF
		else:
			return self.currentRow

	def clone(self):
		return self.__class__(self.executor.clone(), **self.kwargs)

class OneOperatorRowIterator(RowIterator):
	def __init__(self, executor, *args, **kwargs):
		self.executor = executor
		super(OneOperatorRowIterator, self).__init__()


class TwoOperatorRowIterator(RowIterator):
	def __init__(self, e1, e2, *args, **kwargs):
		self.e1 = e1
		self.e2 = e2
		super(TwoOperatorRowIterator, self).__init__()

	def stop_e1(self):
		return False

	def stop_e2(self):
		return False
