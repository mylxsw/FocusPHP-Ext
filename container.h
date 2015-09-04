#ifndef EXT_FOCUSPHP_CONTAINER_H_
#define EXT_FOCUSPHP_CONTAINER_H_

extern zend_class_entry *focusphp_container_ce;

zval* focus_container_instance();
zval* focus_container_get(zval *this_ptr, char *name, int len);

FOCUS_STARTUP_FUNCTION(container);

#endif