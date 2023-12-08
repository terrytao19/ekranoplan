#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "physical_connection" , 14 , 8 } , {
"int64_T" , 15 , 8 } , { "uint64_T" , 16 , 8 } , { "hnn0xl5fkk" , 17 , 8 } ,
{ "p1ga5fgg1t" , 18 , 352 } , { "uint64_T" , 19 , 8 } , { "int64_T" , 20 , 8
} , { "uint_T" , 21 , 32 } , { "char_T" , 22 , 8 } , { "uchar_T" , 23 , 8 } ,
{ "time_T" , 24 , 8 } } ; static uint_T rtDataTypeSizes [ ] = { sizeof (
real_T ) , sizeof ( real32_T ) , sizeof ( int8_T ) , sizeof ( uint8_T ) ,
sizeof ( int16_T ) , sizeof ( uint16_T ) , sizeof ( int32_T ) , sizeof (
uint32_T ) , sizeof ( boolean_T ) , sizeof ( fcn_call_T ) , sizeof ( int_T )
, sizeof ( pointer_T ) , sizeof ( action_T ) , 2 * sizeof ( uint32_T ) ,
sizeof ( int32_T ) , sizeof ( int64_T ) , sizeof ( uint64_T ) , sizeof (
hnn0xl5fkk ) , sizeof ( p1ga5fgg1t ) , sizeof ( uint64_T ) , sizeof ( int64_T
) , sizeof ( uint_T ) , sizeof ( char_T ) , sizeof ( uchar_T ) , sizeof (
time_T ) } ; static const char_T * rtDataTypeNames [ ] = { "real_T" ,
"real32_T" , "int8_T" , "uint8_T" , "int16_T" , "uint16_T" , "int32_T" ,
"uint32_T" , "boolean_T" , "fcn_call_T" , "int_T" , "pointer_T" , "action_T"
, "timer_uint32_pair_T" , "physical_connection" , "int64_T" , "uint64_T" ,
"hnn0xl5fkk" , "p1ga5fgg1t" , "uint64_T" , "int64_T" , "uint_T" , "char_T" ,
"uchar_T" , "time_T" } ; static DataTypeTransition rtBTransitions [ ] = { { (
char_T * ) ( & rtB . ewh2czgzt2 [ 0 ] ) , 0 , 0 , 128 } , { ( char_T * ) ( &
rtDW . kjy5vllogw ) , 18 , 0 , 1 } , { ( char_T * ) ( & rtDW . blkvfyc1ut ) ,
0 , 0 , 10 } , { ( char_T * ) ( & rtDW . kqs40q3ion ) , 17 , 0 , 1 } , { (
char_T * ) ( & rtDW . ot01cjf44p . LoggedData ) , 11 , 0 , 29 } , { ( char_T
* ) ( & rtDW . j2zbeu35vc ) , 6 , 0 , 2 } , { ( char_T * ) ( & rtDW .
no2vyppbyo . Count ) , 10 , 0 , 5 } , { ( char_T * ) ( & rtDW . mhy0u4hbsx )
, 2 , 0 , 2 } , { ( char_T * ) ( & rtDW . lvfkgpske1 ) , 3 , 0 , 2 } , { (
char_T * ) ( & rtDW . mqsusrzct3 ) , 8 , 0 , 6 } } ; static
DataTypeTransitionTable rtBTransTable = { 10U , rtBTransitions } ; static
DataTypeTransition rtPTransitions [ ] = { { ( char_T * ) ( & rtP . Apolar ) ,
0 , 0 , 18268 } , { ( char_T * ) ( & rtP . ManualSwitch1_CurrentSetting ) , 3
, 0 , 1 } } ; static DataTypeTransitionTable rtPTransTable = { 2U ,
rtPTransitions } ;
