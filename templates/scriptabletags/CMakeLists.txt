project(grantlee_scriptabletags)

grantlee_add_plugin(grantlee_scriptabletags
  scriptablecontext
  scriptablefilterexpression
  scriptablenode
  scriptableparser
  scriptablesafestring
  scriptabletags
  scriptabletemplate
  scriptablevariable

  FILTERS
    scriptablefilter
)

qt5_use_modules(grantlee_loadertags Core Script)

install(TARGETS grantlee_scriptabletags
         LIBRARY DESTINATION ${PLUGIN_INSTALL_DIR}
)

