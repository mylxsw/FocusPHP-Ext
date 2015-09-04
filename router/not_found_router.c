#include "php.h"

#include "php_focusphp.h"
#include "not_found_router.h"

zend_class_entry *focusphp_router_not_found_router_ce;

PHP_METHOD(not_found_router, isMatched)
{

}

PHP_METHOD(not_found_router, execute)
{

}

PHP_METHOD(not_found_router, isContinue)
{
	
}

const zend_function_entry not_found_router_functions[] = {
	PHP_ME(not_found_router, isMatched, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(not_found_router, execute, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(not_found_router, isContinue, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

FOCUS_STARTUP_FUNCTION(not_found_router)
{

	zend_class_entry temp_ce;
	INIT_CLASS_ENTRY(temp_ce, "Focus\\Router\\NotFoundRouter", not_found_router_functions);

	focusphp_router_not_found_router_ce = zend_register_internal_class(&temp_ce TSRMLS_CC);

	return SUCCESS;
}