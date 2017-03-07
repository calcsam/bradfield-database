from parser import parse_csv

from constants import COL_NAMES, FILE_NAMES
from file_reader import Executor
from basic_operators.cross_product import Join
from basic_operators.select import Limit
from basic_operators.projection import Projection

#e = Executor(FILE_NAMES, COL_NAMES)
#q = Filter(e, column_name='more1_title', value="SOVIET TROOPS IN ORANIENBURG")
#p = Projection(q, ['document_creation_date'])

#p1 = Projection(e, ['release_decision'])
#p2 = Unique(p1, column_names=['release_decision'])

e = Executor(FILE_NAMES, COL_NAMES)
#q = Filter(e, column_name='more1_title', value="SOVIET TROOPS IN ORANIENBURG")
#p = Projection(q, ['document_creation_date'])

"""
p3 = Aggregate(
	e,
	operators=[
		Sum(fields=['sequence_number'], default_values=[0]),
		Count(fields=['title'], default_values=[0])
	]
)
"""
e = Executor(FILE_NAMES, COL_NAMES)
p1 = Projection(e, ['more1_title', 'release_decision'])
p2 = Limit(p1, limit=10)

e1 = Executor(FILE_NAMES, COL_NAMES)
p4 = Projection(e1, ['more1_title', 'publication_date'])
p5 = Limit(p4, limit=10)

j = Join(p2, p5, 'more1_title', 'more1_title')

for i in range(0, 100):
	print next(j)
