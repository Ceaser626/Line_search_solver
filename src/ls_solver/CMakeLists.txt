add_library(lssolverstatic STATIC
        line_search.cpp
        solver_api.cpp
)

target_include_directories(lssolverstatic PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/..
)

# 🔥 关键一步：把 Eigen 链进去
target_link_libraries(lssolverstatic PUBLIC Eigen3::Eigen)

#add_library(lssolverstatic STATIC
#        line_search.cpp
#        solver_api.cpp
#)
#
#set_property(TARGET lssolverstatic PROPERTY POSITION_INDEPENDENT_CODE ON)
#
#target_include_directories(lssolverstatic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/..)
#target_include_directories(lssolverstatic PUBLIC "D:\\Programming Pack\\vcpkg\\installed\\x64-mingw-dynamic")
#
#list( APPEND EMBEDDED_FILES
#        "${CMAKE_CURRENT_SOURCE_DIR}/line_search.cpp"
#        "${CMAKE_CURRENT_SOURCE_DIR}/line_search.hpp"
#        "${CMAKE_CURRENT_SOURCE_DIR}/solver_api.cpp"
#        "${CMAKE_CURRENT_SOURCE_DIR}/solver_api.hpp"
#        "${CMAKE_CURRENT_SOURCE_DIR}/types.hpp"
#        "${CMAKE_CURRENT_SOURCE_DIR}/solver_constants.hpp" )
#
#foreach( f ${EMBEDDED_FILES} )
#    get_filename_component( fname ${f} NAME )
#
#    set( dest_file "${EMBEDDED_BUILD_TINYMPC_DIR}/${fname}" )
#    list( APPEND EMBEDDED_BUILD_TINYMPC_FILES "${dest_file}" )
#
#    add_custom_command(OUTPUT ${dest_file}
#            COMMAND ${CMAKE_COMMAND} -E copy "${f}" "${dest_file}"
#            DEPENDS ${f}
#            COMMENT "Copying ${fname}")
#endforeach()
