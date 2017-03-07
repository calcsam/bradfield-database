# this is basically a reduce function
class Aggregate:
    def __init__(self, executor, **kwargs):
        self.executor = executor
        self.kwargs = kwargs
        self.operators = kwargs['operators']
        self.values = {}
        for operator in self.operators:
            self.values[operator.name] = {}
            for i, field in enumerate(operator.fields):
                self.values[operator.name][field] = operator.default_values[i]

    def reduce(self):
        row = self.executor.next()
        while (row):
            for operator in self.operators:
                for i, field in enumerate(operator.fields):
                    self.values[operator.name][field] = operator.reduce(self.values[operator.name][field], row.get_column_value(field))
            row = self.executor.next()
        return self.values


class Operator:
    def __init__(self, **kwargs):
        for key in kwargs:
            setattr(self, key, kwargs[key])

    def acc(self, row, val):
        raise NotImplementedError


class Sum(Operator):
    name = 'sum'

    def reduce(self, acc, val):
        return int(acc) + (int(val) if isinstance(val, int) else 0)


class Count(Operator):
    name = 'count'

    def reduce(self, acc, val):
        return acc + 1
