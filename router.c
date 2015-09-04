#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"

#include "php_focusphp.h"
#include "router.h"

zend_class_entry *focusphp_router_ce;

PHP_METHOD(router, add)
{

}

PHP_METHOD(router, parse)
{

}

PHP_METHOD(router, getPathInfo)
{

}


const zend_function_entry focus_router_functions[] = {
	PHP_ME(router, add, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(router, parse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(router, getPathInfo, NULL, ZEND_ACC_PUBLIC)

	PHP_FE_END
};


FOCUS_STARTUP_FUNCTION(router)
{
	zend_class_entry temp_ce;
	INIT_CLASS_ENTRY(temp_ce, "Focus\\Router", focus_router_functions);

	focusphp_router_ce = zend_register_internal_class(&temp_ce TSRMLS_CC);

	return SUCCESS;
}