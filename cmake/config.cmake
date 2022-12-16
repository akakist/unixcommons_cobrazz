# Contains configuration variables for the FindOpenDDS cmake module based on
# detected defaults and/or user-supplied switches. Feel free to edit them as
# necessary, but keep in mind that they will be moved to config.cmake.bak.*
# the next time the $DDS_ROOT/configure script is executed.
#
# THIS FILE WAS AUTO-GENERATED BY: ./configure 

set(OPENDDS_MPC "/home/alexander_belyalov/OpenDDS/ACE_wrappers/MPC")
set(OPENDDS_ACE "/home/alexander_belyalov/OpenDDS/ACE_wrappers")
set(OPENDDS_TAO "/home/alexander_belyalov/OpenDDS/ACE_wrappers/TAO")

# Based on MPC features
set(OPENDDS_CXX11 ON)
set(OPENDDS_WCHAR OFF)
set(OPENDDS_IPV6 OFF)
set(OPENDDS_SAFETY_PROFILE OFF)
set(OPENDDS_VERSIONED_NAMESPACE OFF)
set(OPENDDS_SUPPRESS_ANYS ON)
set(OPENDDS_COVERAGE OFF)

# Based on configure script options
set(OPENDDS_BUILT_IN_TOPICS ON)
set(OPENDDS_COMPILER "g++")
set(OPENDDS_CONTENT_FILTERED_TOPIC ON)
set(OPENDDS_CONTENT_SUBSCRIPTION ON)
set(OPENDDS_DEBUG ON)
set(OPENDDS_FEATURES "no_cxx11=0")
set(OPENDDS_GTEST "")
set(OPENDDS_INLINE ON)
set(OPENDDS_JAVA "")
set(OPENDDS_MPCOPTS "")
set(OPENDDS_MULTI_TOPIC ON)
set(OPENDDS_OBJECT_MODEL_PROFILE ON)
set(OPENDDS_OPENSSL "")
set(OPENDDS_OWNERSHIP_KIND_EXCLUSIVE ON)
set(OPENDDS_OWNERSHIP_PROFILE ON)
set(OPENDDS_PERSISTENCE_PROFILE ON)
set(OPENDDS_QT "")
set(OPENDDS_QUERY_CONDITION ON)
set(OPENDDS_RAPIDJSON "/usr")
set(OPENDDS_SECURITY OFF)
set(OPENDDS_STATIC OFF)
set(OPENDDS_STD "gnu++14")
set(OPENDDS_XERCES3 "")

# Sanitizers
set(OPENDDS_ASAN OFF)
set(OPENDDS_TSAN OFF)
set(OPENDDS_UBSAN OFF)