if (${KMC_INSTALL_PACKAGE})
	configure_package_config_file (
		CMakeConfigs/KMCConfig.cmake.in CMakeConfigs/KMCConfig.cmake
		INSTALL_DESTINATION ${INSTALL_PACKAGE_DIR}
		PATH_VARS INSTALL_INCLUDE_DIR)
	install (TARGETS KMC
		DESTINATION ${CMAKE_INSTALL_LIBDIR}
		EXPORT KMCTargets)
	install (EXPORT KMCTargets
		FILE KMCTargets.cmake
		NAMESPACE KMC::
		DESTINATION ${INSTALL_PACKAGE_DIR})
	install (FILES "${CMAKE_CURRENT_BINARY_DIR}/CMakeConfigs/KMCConfig.cmake"
		DESTINATION ${INSTALL_PACKAGE_DIR})
endif (${KMC_INSTALL_PACKAGE})
