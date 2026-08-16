###############################
### Autor: Reymon Dev       ###
### Datum: 15. August. 2026 ###
### Aktua: 15. August. 2026 ###
### Lizenz: AGPL-3-or-later ###
###############################

project(
	'RDC Market Maker',
	'c',
	version : '0.0.3',
	meson_version : '>=1.10.0',
	default_options : [
		'c_std=gnu23',
		'warning_level=3',
		'buildtype=debug',
		'optimization=g',
		'strip=true'
  	]
)

#############################
### Environment Variables ###
#############################

system    = host_machine.system()
buildtype = get_option('buildtype')

############################
### Modules and Programs ###
############################

cmake = import('cmake')
gdb   = find_program('gdb')

################################
### Local Libraries Versions ###
################################

RDCKraken_version = '0.1.0'
RDCKraken_soversion = '0.1.0'

###############
### Options ###
###############

build_kraken  = get_option('build_kraken')
build_binance = get_option('build_binance')

###########################
### Subprojects Options ###
###########################

lws_options    = cmake.subproject_options()
yyjson_options = cmake.subproject_options()

##########################
### Subproject Options ###
##########################

lws_options.add_cmake_defines({
	'LWS_ROLE_WS': 1,
	'LWS_WITH_SECURE_STREAMS': 1,
	'LWS_WITHOUT_EXTENSIONS': 0,
	'LWS_WITHOUT_TESTAPPS': 1,
	'CMAKE_BUILD_TYPE': 'Release',
	'CMAKE_POSITION_INDEPENDENT_CODE': 'ON'
})

yyjson_options.add_cmake_defines({
	'CMAKE_BUILD_TYPE': 'Release',
	'CMAKE_POSITION_INDEPENDENT_CODE': 'ON'
})

###################
### Subprojects ###
###################

lws_subproject   = cmake.subproject('libwebsockets', options: lws_options)
yyjson_subroject = cmake.subproject('yyjson', options: yyjson_options)

########################
### Global Arguments ###
########################

add_project_arguments(
	'-Wno-switch',
	'-Wno-unused-parameter',
	'-Wno-unused-function',
	'-Dbuildtype=' + buildtype,
	language: 'c'
)

add_project_link_arguments(
	'-lm',
	'-lpthread',
	language: 'c'
)

####################
### Dependencies ###
####################

lws     = lws_subproject.dependency('websockets')
curl    = dependency('libcurl')
json    = yyjson_subroject.dependency('yyjson')
crypto  = dependency('libcrypto')
openssl = dependency('openssl')

dependencies = [ lws, curl, json, crypto, openssl ]

###################
### Directories ###
###################

inc = include_directories(
	'include'
)

#############
### Files ###
#############

source_files_kern = files(
	'src/kern.c'
)

######################
### Subdirectories ###
######################

link_with = []

subdir('src/utils')
subdir('src/risk')
subdir('src/exchanges')

###################
### Executables ###
###################

rdcmm = executable(
	'rdcmm',
	
	source_files_kern,

	link_with: libraries,
	dependencies: dependencies,
	include_directories: inc,

	install_rpath: '$ORIGIN:$ORIGIN/lib:$ORIGIN/../lib:/usr/local/lib:/usr/lib',

	subdir: 'bin',
	install: true
)

###################
### Run Targets ###
###################

run_target('run-debug',   command: [ gdb, rdcmm ])
run_target('run-release', command: [ rdcmm ])