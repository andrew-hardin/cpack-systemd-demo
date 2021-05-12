# No idea what the minimum version is. This just happens to be
# what I had installed at the time.
cmake_minimum_required(VERSION 3.16)
project(HelloWorld VERSION 0.1)

# Just because our hello-world is using a few C++11 features...
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Setup and install the hello-world application.
add_executable(hello-world main.cc)
install(TARGETS hello-world RUNTIME DESTINATION bin)

# Configure the service file so that it knows where the
# binary was installed.
set(SERVICE_NAME hello-world.service)
set(EXE_PATH ${CMAKE_INSTALL_PREFIX}/bin/hello-world)
set(SERVICE_IN ${SERVICE_NAME}.in)
set(SERVICE_OUT ${CMAKE_CURRENT_BINARY_DIR}/${SERVICE_NAME})
configure_file(${SERVICE_IN} ${SERVICE_OUT} @ONLY)

# Install the service file in the share directory. The post
# install RPM script will handle placing the file where
# it's supposed to go.
install(FILES ${SERVICE_OUT} DESTINATION share)

# Configure the scripts that are executed by the RPM.
# This could be done without going through the rigmarole of
# using configures, but I don't want to hard-code the name
# of the service into each file.
#
# Each script has the option of performing verbose logging
# Switch this variable to TRUE to enable those logs.
# I found this helpful while troubeshooting package upgrades.
set(VERBOSE_LOGGING FALSE)
set(POST_IN ${CMAKE_CURRENT_LIST_DIR}/post.sh.in)
set(POST_OUT ${CMAKE_CURRENT_BINARY_DIR}/post.sh)
configure_file(${POST_IN} ${POST_OUT} @ONLY)
set(POSTUN_IN ${CMAKE_CURRENT_LIST_DIR}/postun.sh.in)
set(POSTUN_OUT ${CMAKE_CURRENT_BINARY_DIR}/postun.sh)
configure_file(${POSTUN_IN} ${POSTUN_OUT} @ONLY)
set(PREUN_IN ${CMAKE_CURRENT_LIST_DIR}/preun.sh.in)
set(PREUN_OUT ${CMAKE_CURRENT_BINARY_DIR}/preun.sh)
configure_file(${PREUN_IN} ${PREUN_OUT} @ONLY)


set(CPACK_PACKAGE_VERSION ${CMAKE_PROJECT_VERSION})
set(CPACK_GENERATOR "RPM")
set(CPACK_PACKAGE_NAME "hello-world")
set(CPACK_PACKAGE_RELEASE 1)
set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
set(CPACK_RPM_POST_INSTALL_SCRIPT_FILE ${POST_OUT})
set(CPACK_RPM_POST_UNINSTALL_SCRIPT_FILE ${POSTUN_OUT})
set(CPACK_RPM_PRE_UNINSTALL_SCRIPT_FILE ${PREUN_OUT})
set(CPACK_RPM_PACKAGE_REQUIRES_POSTUN "systemd")
set(CPACK_RPM_PACKAGE_REQUIRES_PREUN "systemd")
set(CPACK_RPM_PACKAGE_REQUIRES_POST "systemd")
include(CPack)
