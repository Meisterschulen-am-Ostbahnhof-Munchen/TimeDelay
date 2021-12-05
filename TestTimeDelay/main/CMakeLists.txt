





if(CONFIG_4_TON_SUPERTEST)
	set(COMPONENT_SRCS  "examples/4_TON_SUPERTEST/main.cpp")
endif()


if(CONFIG_FOUR_POSITION_TOF)
	set(COMPONENT_SRCS  "examples/FOUR_POSITION_TOF/main.cpp")
endif()





set(COMPONENT_ADD_INCLUDEDIRS "")
register_component()
