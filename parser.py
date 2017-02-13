IN_QUOTES = 'in_quotes'
NORMAL = 'normal'
COMMA = 'comma'
STATES = [IN_QUOTES, NORMAL, COMMA]


def should_shift(state):
	return state == COMMA


def annotate(state, char, current_column, fields):
	if state == NORMAL:
		fields[current_column] = fields.get(current_column, "") + char
	elif state == IN_QUOTES:
		fields[current_column] = fields.get(current_column, "") + char

	return fields


def next_state(state, char):
	if state == NORMAL and char == '"':
		return IN_QUOTES
	elif state == NORMAL and char == ',':
		return COMMA
	elif state == NORMAL:
		return NORMAL
	elif state == COMMA and char == '"':
		return IN_QUOTES
	elif state == COMMA:
		return NORMAL
	elif state == IN_QUOTES and char == '"':
		return NORMAL
	elif state == IN_QUOTES:
		return IN_QUOTES


def parse_csv(text, COL_NAMES):
	fields = {}
	state = NORMAL
	columns = iter(COL_NAMES)
	current_column = columns.next()
	for char in text:
		state = next_state(state, char)
		fields = annotate(state, char, current_column, fields)
		if should_shift(state):
			current_column = columns.next()

	return fields