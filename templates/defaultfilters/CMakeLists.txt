project(grantlee_defaultfilters)

grantlee_add_plugin(grantlee_defaultfilters
  defaultfilters

  FILTERS
    datetime
    integers
    lists
    logic
    misc
    stringfilters
)

qt5_use_modules(grantlee_defaultfilters Core)

install(TARGETS grantlee_defaultfilters
         LIBRARY DESTINATION ${PLUGIN_INSTALL_DIR} COMPONENT Templates
)
