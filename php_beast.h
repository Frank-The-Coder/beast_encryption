#ifndef PHP_BEAST_H
#define PHP_BEAST_H

extern zend_module_entry beast_module_entry;
#define phpext_beast_ptr &beast_module_entry

#ifdef PHP_WIN32
#define PHP_BEAST_API __declspec(dllexport)
#else
#define PHP_BEAST_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(beast);
PHP_MSHUTDOWN_FUNCTION(beast);
PHP_RINIT_FUNCTION(beast);
PHP_RSHUTDOWN_FUNCTION(beast);
PHP_MINFO_FUNCTION(beast);

PHP_FUNCTION(beast_encode_file);
PHP_FUNCTION(beast_avail_cache);
PHP_FUNCTION(beast_support_filesize);
PHP_FUNCTION(beast_file_expire);
PHP_FUNCTION(beast_clean_cache);

// Define arginfo for each function
ZEND_BEGIN_ARG_INFO(arginfo_beast_encode_file, 0)
ZEND_ARG_INFO(0, input)
ZEND_ARG_INFO(0, output)
ZEND_ARG_INFO(0, expire)
ZEND_ARG_INFO(0, encrypt_type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_beast_avail_cache, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_beast_support_filesize, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_beast_file_expire, 0)
ZEND_ARG_INFO(0, file)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_beast_clean_cache, 0)
ZEND_END_ARG_INFO()

#endif /* PHP_BEAST_H */
