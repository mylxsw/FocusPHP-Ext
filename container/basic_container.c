#include "php.h"

#include "php_focusphp.h"
#include "container.h"
#include "basic_container.h"

zend_class_entry *container_basic_ce;

PHP_METHOD(basic_container, __construct)
{

    zval *config_files;
    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &config_files) == FAILURE) {
        return ;
    }

    zval *_classes;
    MAKE_STD_ZVAL(_classes);
    array_init(_classes);
    add_property_zval_ex(getThis(), ZEND_STRL("_classes"), _classes TSRMLS_CC);

    zval *_lazy_classes;
    MAKE_STD_ZVAL(_lazy_classes);
    array_init(_lazy_classes);
    add_property_zval_ex(getThis(), ZEND_STRL("_lazy_classes"), _lazy_classes TSRMLS_CC);

}

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
    PHP_ME(basic_container, __construct, NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
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

    zend_declare_property_null(container_basic_ce, ZEND_STRL("_system_classes"), ZEND_ACC_PRIVATE | ZEND_ACC_STATIC);
    zend_declare_property_null(container_basic_ce, ZEND_STRL("_classes"), ZEND_ACC_PRIVATE TSRMLS_CC);
    zend_declare_property_null(container_basic_ce, ZEND_STRL("_lazy_classes"), ZEND_ACC_PRIVATE TSRMLS_CC);

    zval *_system_classes;
    MAKE_STD_ZVAL(_system_classes);
    array_init(_system_classes);

    add_assoc_string(_system_classes, "Focus\\Request\\Request", "Focus\\Request\\HttpRequest", 0);
    add_assoc_string(_system_classes, "Focus\\Response\\Response", "Focus\\Response\\HttpResponse", 0);
    add_assoc_string(_system_classes, "Focus\\Request\\Session", "Focus\\Request\\DefaultSession", 0);
    add_assoc_string(_system_classes, "Focus\\Uri\\Uri", "Focus\\Uri\\DefaultUri", 0);
    add_assoc_string(_system_classes, "Focus\\Router", "Focus\\Router", 0);
    add_assoc_string(_system_classes, "Psr\\Log\\LoggerInterface", "Focus\\Log\\Logger", 0);

    zval *config_default;
    MAKE_STD_ZVAL(config_default);
    array_init(config_default);
    add_next_index_string(config_default, "Focus\\Config\\ArrayConfig", 0);
    add_next_index_bool(config_default, 0);

    add_assoc_zval(_system_classes, "Focus\\Config\\Config", config_default);

    zend_update_static_property(container_basic_ce, ZEND_STRL("_system_classes"), _system_classes TSRMLS_CC);

    return SUCCESS;
}
