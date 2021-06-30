#include "SEGGER_RTT.h"
#include "SEGGER_RTT_Conf.h"

#define BUFFER_INDEX 0

/*!
* @brief 封装 RTT 打印接口，执行条件：无
* @retval: 无
* 自定义RTT日志输出函数SEGGER_RTT_printf
* 依据重写的 SEGGER_RTT_printf 函数。
* 省略形参：缓存索引。修改返回值：int为void
*/
void RTT_printf(const char * sFormat, ...) {
  va_list ParamList;
  va_start(ParamList, sFormat);
	SEGGER_RTT_printf(BUFFER_INDEX,"\n");
  SEGGER_RTT_vprintf(BUFFER_INDEX, sFormat, &ParamList);
  va_end(ParamList);
}

/*!
* @brief 封装 RTT 打印接口，执行条件：无
* @retval: 无
*/
void print_log(const char * sFormat, ...)
{	
	va_list ParamList;
	va_start(ParamList, sFormat);
	SEGGER_RTT_vprintf(BUFFER_INDEX, sFormat, &ParamList);
	va_end(ParamList);
}

/*!
* @brief 初始化 RTT 打印接口，执行条件：无
* @retval: 无
 * 使用：
 * 1.在main中调用：RTT_Init("RTT Init...");
 * 2.在需要打印日志的位置：print_log(“日志内容.”);
*/
void RTT_Init(char * str)
{
	SEGGER_RTT_Init();
	print_log(str);//封装接口，无需填写 BUFFER_INDEX
}
