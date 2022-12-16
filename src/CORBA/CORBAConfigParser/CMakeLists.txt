#cmake_minimum_required (VERSION 2.6)




add_library(CORBAConfigParser  SHARED
  CorbaConfigReader.cpp 
  ParameterConfig.cpp 
)
target_link_libraries(CORBAConfigParser CORBACommons   xerces-c XMLUtility
    )
#    pcre ssl crypto z event 

##StatsIDL CorbaObjectRefIDL ProcessControlIDL 
#    Generics ACE Logger Sync String

#    TAO TAO_AnyTypeCode  TAO_CodecFactory TAO_CosEvent TAO_CosNaming TAO_CosNotification TAO_DynamicAny TAO_EndpointPolicy TAO_FaultTolerance
#    TAO_FT_ClientORB TAO_FT_ServerORB TAO_FTORB_Utils TAO_IORManip TAO_IORTable 
#    TAO_Messaging TAO_PI TAO_PI_Server TAO_PortableGroup TAO_PortableServer TAO_Security TAO_SSLIOP TAO_TC TAO_TC_IIOP TAO_Valuetype ACE_SSL 
