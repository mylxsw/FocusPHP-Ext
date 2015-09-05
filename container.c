#include "php.h"

#include "php_focusphp.h"
#include "container/container.h"
#include "container.h"

zend_class_entry *focusphp_container_ce;

zval* focus_container_instance()
{
	zval *instance = zend_read_static_property(focusphp_container_ce, ZEND_STRL("_instance"), 1 TSRMLS_CC);
	if (Z_TYPE_P(instance) != IS_OBJECT || !instanceof_function(Z_OBJCE_P(instance), focusphp_container_ce TSRMLS_CC)) {
		MAKE_STD_ZVAL(instance);
		object_init_ex(instance, focusphp_container_ce);

		zend_update_static_property(focusphp_container_ce, ZEND_STRL("_instance"), instance TSRMLS_CC);
		zval_ptr_dtor(&instance);
	}

	return instance;
}

zval* focus_container_get(zval *this_ptr, char *name, int len)
{
	zval *result;
	ALLOC_ZVAL(result);
	ZVAL_STRING(result, name, 0);

	return result;
}

PHP_METHOD(container, instance)
{
	RETVAL_ZVAL(focus_container_instance(), 1, 0);
}

PHP_METHOD(container, get)
{
	char *name;
	int len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &len) == FAILURE) {
		RETURN_NULL();
	}

	RETURN_ZVAL(focus_container_get(getThis(), name, len), 1, 0);
}

PHP_METHOD(container, has)
{

}

ZEND_BEGIN_ARG_INFO_EX(container_get_args, 0, 0, 1)
    ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(container_has_args, 0, 0, 1)
    ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()


const zend_function_entry focus_container_functions[] = {
	PHP_ME(container, get, container_get_args, ZEND_ACC_PUBLIC)
	PHP_ME(container, has, container_has_args, ZEND_ACC_PUBLIC)
	PHP_ME(container, instance, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
	PHP_FE_END
};

FOCUS_STARTUP_FUNCTION(container)
{
	zend_class_entry temp_ce;
	INIT_CLASS_ENTRY(temp_ce, "Focus\\Container", focus_container_functions);

	focusphp_container_ce = zend_register_internal_class(&temp_ce TSRMLS_CC);
	zend_class_implements(focusphp_container_ce TSRMLS_CC, 1, container_interface_ce);

	zend_declare_property_null(focusphp_container_ce, ZEND_STRL("_instance"), ZEND_ACC_PROTECTED | ZEND_ACC_STATIC);

	return SUCCESS;
}
