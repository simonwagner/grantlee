project(grantlee_defaulttags)

grantlee_add_plugin ( grantlee_defaulttags
  defaulttags

  TAGS
    autoescape
    comment
    cycle
    debug
    filtertag
    firstof
    for
    if
    ifchanged
    ifequal
    load
    mediafinder
    now
    range
    regroup
    spaceless
    templatetag
    widthratio
    with
)

qt5_use_modules(grantlee_defaulttags Core)

install(TARGETS grantlee_defaulttags
        LIBRARY DESTINATION ${PLUGIN_INSTALL_DIR} COMPONENT Templates
)


