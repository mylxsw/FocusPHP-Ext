#include "php.h"

#include "php_focusphp.h"
#include "container.h"
#include "basic_container.h"

zend_class_entry *container_basic_ce;

PHP_METHOD(basic_container, get)
{

}

PHP_METHOD(basic_container, has)
{

}

ZEND_BEGIN_ARG_INFO_EX(container_get_args, 0, 0, 1)
    ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(container_has_args, 0, 0, 1)
    ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

const zend_function_entry basic_container_functions[] = {
    PHP_ME(basic_container, get, container_get_args, ZEND_ACC_PUBLIC)
    PHP_ME(basic_container, has, container_has_args, ZEND_ACC_PUBLIC)
    PHP_FE_END
};

FOCUS_STARTUP_FUNCTION(container_basic)
{
    zend_class_entry temp_ce;
    INIT_CLASS_ENTRY(temp_ce, "Focus\\BasicContainer", basic_container_functions);

    container_basic_ce = zend_register_internal_class(&temp_ce TSRMLS_CC);
    zend_class_implements(container_basic_ce TSRMLS_CC, 1, container_interface_ce);

    return SUCCESS;
}
