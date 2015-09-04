
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"

#include "php_focusphp.h"
#include "server.h"

zend_class_entry *focusphp_server_ce;

ZEND_BEGIN_ARG_INFO_EX(server_construct_arginfo, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, container, Focus\\Container, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(server_init_arginfo, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, container, Focus\\Container, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(server_empty_arginfo, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(server_register_router_arginfo, 0, 0, 1)
	ZEND_ARG_INFO(0, router)
	ZEND_ARG_INFO(0, ...)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(server_register_exception_handler_arginfo, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handler, IS_CALLABLE, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(server_register_error_handler_arginfo, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handler, IS_CALLABLE, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(server_register_autoloader_arginfo, 0, 0, 2)
	ZEND_ARG_INFO(0, baseDir)
	ZEND_ARG_INFO(0, baseNs)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(server_set_not_found_router_arginfo, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, notFoundRouter, Focus\\Router\\NotFoundRouter, 1)
ZEND_END_ARG_INFO()

PHP_METHOD(server, __construct)
{

}

PHP_METHOD(server, init)
{

}

PHP_METHOD(server, run)
{

}

PHP_METHOD(server, registerRouter)
{

}

PHP_METHOD(server, registerExceptionHandler)
{

}

PHP_METHOD(server, registerErrorHandler)
{

}

PHP_METHOD(server, registerAutoloader)
{

}

PHP_METHOD(server, getRequest)
{

}

PHP_METHOD(server, getResponse)
{

}

PHP_METHOD(server, getUri)
{

}

PHP_METHOD(server, getNotFoundRouter)
{

}

PHP_METHOD(server, setNotFoundRouter)
{

}

PHP_METHOD(server, getLogger)
{

}

const zend_function_entry server_functions[] = {
	PHP_ME(server, __construct, server_construct_arginfo, ZEND_ACC_PRIVATE | ZEND_ACC_CTOR)
	PHP_ME(server, init, server_init_arginfo, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_ME(server, run, server_empty_arginfo, ZEND_ACC_PUBLIC)
	PHP_ME(server, registerRouter, server_register_router_arginfo, ZEND_ACC_PUBLIC)
	PHP_ME(server, registerErrorHandler, server_register_error_handler_arginfo, ZEND_ACC_PUBLIC)
	PHP_ME(server, registerExceptionHandler, server_register_exception_handler_arginfo, ZEND_ACC_PUBLIC)
	PHP_ME(server, registerAutoloader, server_register_autoloader_arginfo, ZEND_ACC_PUBLIC)
	PHP_ME(server, getRequest, server_empty_arginfo, ZEND_ACC_PUBLIC)
	PHP_ME(server, getResponse, server_empty_arginfo,ZEND_ACC_PUBLIC)
	PHP_ME(server, getUri, server_empty_arginfo, ZEND_ACC_PUBLIC)
	PHP_ME(server, getNotFoundRouter, server_empty_arginfo, ZEND_ACC_PUBLIC)
	PHP_ME(server, setNotFoundRouter, server_set_not_found_router_arginfo, ZEND_ACC_PUBLIC)
	PHP_ME(server, getLogger, server_empty_arginfo, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

FOCUS_STARTUP_FUNCTION(server)
{
	zend_class_entry temp_ce;
	INIT_CLASS_ENTRY(temp_ce, "Focus\\Server", server_functions);

	focusphp_server_ce = zend_register_internal_class(&temp_ce TSRMLS_CC);

	zend_declare_class_constant_string(focusphp_server_ce, ZEND_STRL("VERSION"), "1.0.0 DEV" TSRMLS_CC);
	zend_declare_property_null(focusphp_server_ce, ZEND_STRL("_instance"), ZEND_ACC_STATIC | ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(focusphp_server_ce, ZEND_STRL("_router"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(focusphp_server_ce, ZEND_STRL("_notFoundRouter"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(focusphp_server_ce, ZEND_STRL("_container"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}