/**
 * @file    Errors.h
 * @author  Longwei Lai<lailongwei@126.com>
 * @date    2016/01/25
 * @version 1.0
 *
 * @brief
 */
#ifndef __CSLLBC_COM_ERRORS_H__
#define __CSLLBC_COM_ERRORS_H__

#include "csllbc/common/Macro.h"
#include "csllbc/common/LibHeader.h"

/**
 * Format last error.
 * @param[out] lastErrorLen - the last error length.
 * @return const char *     - the last error string representation.
 */
LLBC_EXTERN_C CSLLBC_EXPORT const char *csllbc_FormatLastError(int *lastErrorLen);

#endif // !__CSLLBC_COM_ERRORS_H__
