# *******************************
# *** Autor: Reymon Dev       ***# *** Datum: 08. Mai. 2026    ***
# *** Aktua: 12. Juni. 2026   ***
# *** Lizenz: AGPL-3-or-later ***
# *******************************

subdir('common')
subdir('json')
subdir('security')
subdir('string')

RDCUtils = static_library(
	'pzhmm_utils',

	files_utils_json,
	files_utils_security,
	files_utils_string,

	dependencies: dependencies,
	include_directories: inc,

	install: true,
	name_suffix: meson.project_version()
)