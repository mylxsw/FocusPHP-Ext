#include "php.h"
#include "php_focusphp.h"
#include "container.h"

zend_class_entry *container_interface_ce;

ZEND_BEGIN_ARG_INFO_EX(container_get_args, 0, 0, 1)
    ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(container_has_args, 0, 0, 1)
    ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

const zend_function_entry container_functions[] = {
    PHP_ABSTRACT_ME(container, get, container_get_args)
    PHP_ABSTRACT_ME(container, has, container_has_args)
    PHP_FE_END
};

FOCUS_STARTUP_FUNCTION(container_container)
{
    zend_class_entry temp_ce;
    INIT_CLASS_ENTRY(temp_ce, "Interop\\Container", container_functions);

    container_interface_ce = zend_register_internal_class(&temp_ce TSRMLS_CC);
    container_interface_ce->ce_flags |= ZEND_ACC_INTERFACE;

    return SUCCESS;
}
