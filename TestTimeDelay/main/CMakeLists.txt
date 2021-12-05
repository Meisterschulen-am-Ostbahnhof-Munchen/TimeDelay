
if(CONFIG_EXAMPLE_AND)
    set(COMPONENT_SRCS  "examples/EXAMPLE_AND/main.cpp")
endif()

if(CONFIG_EXAMPLE_C_AND)
    set(COMPONENT_SRCS  "examples/EXAMPLE_C_AND/main.cpp")
endif()

if(CONFIG_EXAMPLE_OR)
    set(COMPONENT_SRCS  "examples/EXAMPLE_OR/main.cpp")
endif()

if(CONFIG_EXAMPLE_TON)
	set(COMPONENT_SRCS  "examples/EXAMPLE_TON/main.cpp")
endif()

if(CONFIG_EXAMPLE_TOF)
	set(COMPONENT_SRCS  "examples/EXAMPLE_TOF/main.cpp")
endif()

if(CONFIG_EXAMPLE_TRIG)
    set(COMPONENT_SRCS  "examples/EXAMPLE_TRIG/main.cpp")
endif()

if(CONFIG_EXAMPLE_BLINK)
    set(COMPONENT_SRCS  "examples/EXAMPLE_BLINK/main.cpp")
endif()

if(CONFIG_4_TON_SUPERTEST)
	set(COMPONENT_SRCS  "examples/4_TON_SUPERTEST/main.cpp")
endif()


if(CONFIG_FOUR_POSITION_TOF)
	set(COMPONENT_SRCS  "examples/FOUR_POSITION_TOF/main.cpp")
endif()





set(COMPONENT_ADD_INCLUDEDIRS "")
register_component()
