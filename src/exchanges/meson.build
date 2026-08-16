###############################
### Autor: Reymon Dev       ###
### Datum: 08. Mai. 2026    ###
### Aktua: 12. Juni. 2026   ###
### Lizenz: AGPL-3-or-later ###
###############################

######################
### Subdirectories ###
######################

subdir('kraken')
subdir('binance')

#################
### Libraries ###
#################

RDCExchange = static_library(
	'RDCExchange',

	files( 'RDConnection.c' ),

	dependencies: dependencies,
	include_directories: inc,

	build_subdir: 'lib',
	install: false
)

RDCKraken = shared_library(
	'RDCKraken',

	source_files_exchange_kraken,

	link_with: [ RDCRisk, RDCUtils ],

	dependencies: dependencies,
	include_directories: inc,

	version:   RDCKraken_version,
	soversion: RDCKraken_soversion,

	build_subdir: 'lib',
	install: true
)

RDCBinance = shared_library(
	'RDCBinance',

	source_files_exchange_binance,

	link_with: [ RDCRisk, RDCUtils ],

	dependencies: dependencies,
	include_directories: inc,

	version:   RDCBinance_version,
	soversion: RDCBinance_soversion,

	build_subdir: 'lib',
	install: true
)