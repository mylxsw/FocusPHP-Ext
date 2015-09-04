#include "php.h"

#include "php_focusphp.h"
#include "container.h"

zend_class_entry *focusphp_container_ce;

PHP_METHOD(container, get)
{

}

PHP_METHOD(container, has)
{
	
}


const zend_function_entry focus_container_functions[] = {
	PHP_ME(container, get, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(container, has, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

FOCUS_STARTUP_FUNCTION(container)
{
	zend_class_entry temp_ce;
	INIT_CLASS_ENTRY(temp_ce, "Focus\\Container", focus_container_functions);

	focusphp_container_ce = zend_register_internal_class(&temp_ce TSRMLS_CC);

	return SUCCESS;
}