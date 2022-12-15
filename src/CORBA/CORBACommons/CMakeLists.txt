#cmake_minimum_required (VERSION 2.6)
add_idl(StatsIDL Stats.idl)
add_idl(CorbaObjectRefIDL CorbaObjectRef.idl)
add_idl(ProcessControlIDL ProcessControl.idl)



add_library(CORBACommons  SHARED
  AceLogger.cpp 
  CorbaAdapters.cpp 
  CorbaClientAdapter.cpp 
  CorbaServerAdapter.cpp 
  ProcessControlImpl.cpp 
  Reactor.cpp 
  
#  StatsC.cpp
 # StatsS.cpp
#  CorbaObjectRefC.cpp
#  CorbaObjectRefS.cpp
#  ProcessControlC.cpp
#  ProcessControlS.cpp
)

#OPENDDS_TARGET_SOURCES(stats Stats.idl)
#target_link_libraries(stats
#  Qt5::Widgets
#  OpenDDS::Dcps
#  OpenDDS::Tcp
#  OpenDDS::Udp
#  OpenDDS::Multicast
#  OpenDDS::Rtps_Udp
#  OpenDDS::InfoRepoDiscovery
#)

#add_library(corbaCS STATIC
#  StatsC.cpp
#  StatsS.cpp
#  CorbaObjectRefC.cpp
#  CorbaObjectRefS.cpp
#  ProcessControlC.cpp
#  ProcessControlS.cpp
#
#)
#add_dependencies( corbaCS StatsIDL CorbaObjectRefIDL ProcessControlIDL)

#g++ -shared -L../../../lib -pthread -W -Wall -g -O3 -m64 -march=x86-64 -o libCORBACommons.so AceLogger.so.o CorbaAdapters.so.o CorbaClientAdapter.so.o CorbaServerAdapter.so.o ProcessControlImpl.so.o Reactor.so.o CorbaObjectRef.so.o ProcessControl.so.o Stats.so.o CorbaObjectRef_s.so.o ProcessControl_s.so.o Stats_s.so.o 
#-lLogger -lGenerics -lSync -lString -lpcre -lssl -lcrypto -lz -levent -l -l -l -l -l  -l -l -l -l -l -l -l -l
target_link_libraries(CORBACommons StatsIDL CorbaObjectRefIDL ProcessControlIDL 
    Generics ACE Logger Sync String 
    pcre ssl crypto z event 
    TAO TAO_AnyTypeCode  TAO_CodecFactory TAO_CosEvent TAO_CosNaming TAO_CosNotification TAO_DynamicAny TAO_EndpointPolicy TAO_FaultTolerance
    TAO_FT_ClientORB TAO_FT_ServerORB TAO_FTORB_Utils TAO_IORManip TAO_IORTable 
    TAO_Messaging TAO_PI TAO_PI_Server TAO_PortableGroup TAO_PortableServer TAO_Security TAO_SSLIOP TAO_TC TAO_TC_IIOP TAO_Valuetype ACE_SSL 
    )
