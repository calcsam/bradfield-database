FILE_NAMES = [
	"cia-crest-files-cia-crest-archive-metadata/2_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/3_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/4_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/5_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/6_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/7_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/8_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/9_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/10_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/11_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/12_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/13_export.csv",
	"cia-crest-files-cia-crest-archive-metadata/14_export.csv",
]

COL_NAMES = [
	'collection',
	'content_type',
	'document_creation_date',
	'document_number',
	'document_page_count',
	'document_release_date',
	'document_type',
	'file',
	'more1_link',
	'more1_title',
	'more2_link',
	'more2_title',
	'more3_link',
	'more3_title',
	'more4_link',
	'more4_title',
	'more5_link',
	'more5_title',
	'publication_date',
	'release_decision',
	'sequence_number',
	'title',
	'url'
]


class _EOF:
	def __init__(self):
		pass

	def __nonzero__(self):
		return False

	def __str__(self):
		return "EOF"

EOF = _EOF()


class _BOF:
	def __init__(self):
		pass

	def __str__(self):
		return "BOF"

BOF = _BOF()