
if(CONFIG_EXAMPLE_AND)
    set(COMPONENT_SRCS  "examples/EXAMPLE_AND/main.cpp")
endif()

if(CONFIG_EXAMPLE_C_AND)
    set(COMPONENT_SRCS  "examples/EXAMPLE_C_AND/main.cpp")
endif()

if(CONFIG_EXAMPLE_OR)
    set(COMPONENT_SRCS  "examples/EXAMPLE_OR/main.cpp")
endif()

if(CONFIG_EXAMPLE_XOR)
    set(COMPONENT_SRCS  "examples/EXAMPLE_XOR/main.cpp")
endif()

if(CONFIG_EXAMPLE_NOT)
    set(COMPONENT_SRCS  "examples/EXAMPLE_NOT/main.cpp")
endif()

if(CONFIG_EXAMPLE_TON)
	set(COMPONENT_SRCS  "examples/EXAMPLE_TON/main.cpp")
endif()

if(CONFIG_EXAMPLE_TOF)
	set(COMPONENT_SRCS  "examples/EXAMPLE_TOF/main.cpp")
endif()

if(CONFIG_EXAMPLE_TOF_R_TRIG_O)
    set(COMPONENT_SRCS  "examples/EXAMPLE_TOF_R_TRIG_O/main.cpp")
endif()

if(CONFIG_EXAMPLE_TRIG)
    set(COMPONENT_SRCS  "examples/EXAMPLE_TRIG/main.cpp")
endif()

if(CONFIG_EXAMPLE_BLINK)
    set(COMPONENT_SRCS  "examples/EXAMPLE_BLINK/main.cpp")
endif()

if(CONFIG_EXAMPLE_4_TON_SUPERTEST)
	set(COMPONENT_SRCS  "examples/EXAMPLE_4_TON_SUPERTEST/main.cpp")
endif()

if(CONFIG_EXAMPLE_THREE_POSITION_TOF)
    set(COMPONENT_SRCS  "examples/EXAMPLE_THREE_POSITION_TOF/main.cpp")
endif()

if(CONFIG_EXAMPLE_THREE_POSITION_TOF_O)
    set(COMPONENT_SRCS  "examples/EXAMPLE_THREE_POSITION_TOF_O/main.cpp")
endif()
            
if(CONFIG_EXAMPLE_THREE_POSITION_2TOF)
    set(COMPONENT_SRCS  "examples/EXAMPLE_THREE_POSITION_2TOF/main.cpp")
endif()
            
if(CONFIG_EXAMPLE_THREE_POSITION_2TOF_O  )
    set(COMPONENT_SRCS  "examples/EXAMPLE_THREE_POSITION_2TOF_O/main.cpp")
endif()
            
if(CONFIG_EXAMPLE_FOUR_POSITION_TOF)
    set(COMPONENT_SRCS  "examples/EXAMPLE_FOUR_POSITION_TOF/main.cpp")
endif()
            
if(CONFIG_EXAMPLE_FOUR_POSITION_TOF_O)
    set(COMPONENT_SRCS  "examples/EXAMPLE_FOUR_POSITION_TOF_O/main.cpp")
endif()
                            
if(CONFIG_EXAMPLE_FOUR_POSITION_3TOF)
    set(COMPONENT_SRCS  "examples/EXAMPLE_FOUR_POSITION_3TOF/main.cpp")
endif()
            
if(CONFIG_EXAMPLE_FOUR_POSITION_3TOF_O)
    set(COMPONENT_SRCS  "examples/EXAMPLE_FOUR_POSITION_3TOF_O/main.cpp")
endif()

set(COMPONENT_ADD_INCLUDEDIRS "")
register_component()
