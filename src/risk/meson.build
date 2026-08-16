# *******************************
# *** Autor: Reymon Dev       ***# *** Datum: 08. Mai. 2026    ***
# *** Aktua: 12. Juni. 2026   ***
# *** Lizenz: AGPL-3-or-later ***
# *******************************

subdir('inventory')
subdir('microprice')
subdir('stoikov')

RDCRisk = static_library(
	'pzhmm_risk',

	files_risk_inventory,
	files_risk_microprice,
	files_risk_stoikov,

	dependencies: dependencies,
	include_directories: inc,

	install: true,
	name_suffix: meson.project_version()
)