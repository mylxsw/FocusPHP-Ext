#include "php.h"
#include "php_focusphp.h"
#include "server.h"

// zend_class_entry *focusphp_server_ce

const zend_function_entry server_functions[] = {

	PHP_FE_END
};


FOCUS_STARTUP_FUNCTION(server)
{
	zend_class_entry *temp_ce;
	INIT_CLASS_ENTRY(temp_ce, "Focus\\Server", server_functions);

	focusphp_server_ce = zend_register_internal_class(&temp_ce TSRMLS_CC);

	return SUCCESS;
}