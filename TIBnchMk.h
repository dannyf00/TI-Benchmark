#ifndef BENCHMARK_TI_H_INCLUDED
#define BENCHMARK_TI_H_INCLUDED

#include "dspic33duino.h"								//we use ticks

//reference / source:
//  TI MSP430 competitive benchmark - http://www.ti.com/lit/an/slaa205c/slaa205c.pdf

//configuration
#define TIBnchMk_LOOPS	1000						//number of iterations to run

//TIBnchMki() / TIBnchMkf(): ticks / 1K iterations
//  W801: 		17.8MM / 20.6MM ticks
//  dsPIC33: 	10.8MM /119.4MM ticks
//  PY32F0:		13.0MM / 56.7MM ticks
//  STM32G0:	12.6MM / 68.7MM ticks
//  STM32F1:	13.7MM / 51.0MM ticks
//  STM32F0:	11.3MM / 57.3MM ticks
//  PIC24F:		10.8MM /119.4MM ticks
//  PIC32MX:	10.0MM / 48.4MM ticks
//end configuration

//global defines
#define iLOOPS			(TIBnchMk_LOOPS)		//number of loops to run the integer portion of the benchmark: 17.8MM ticks / 1K cycles
#define fLOOPS			(TIBnchMk_LOOPS)		//number of loops to run the FP portion of the benchmark: 20.6MM ticks / 1K cycles
//as designed, this weight heavily favors floating point processes: suitable only for FP-heavy applications

//general guidance:
//1. adjust loops for equal cycles of 8/16/32-bit operations
//2. run benchmark at least 10 seconds -> total cycles >= 10* F_CPU
#define iLOOPS_8		(iLOOPS*4)				//loops for 8-bit interger benchmark: 1.5MM ticks / 1K cycles
#define iLOOPS_16		(iLOOPS)				//loops for 16-bit integer benchmark: 5.3MM ticks / 1K cycles
#define iLOOPS_32		(iLOOPS*2)				//loops for 32-bit integer benchmark: 3.2MM ticks / 1K cycles

//global defines
#if !defined(clock)
#define clock()			ticks()					//use ticks() if clock() isn't available
#endif

//global variables

//user API:
unsigned long TIBnchMki(void);					//return ticks over benchmark
unsigned long TIBnchMkf(void);					//return ticks over benchmark


//TI MSP430 competitive benchmark - http://www.ti.com/lit/an/slaa205c/slaa205c.pdf
/*******************************************************************************
*
* Name : 8-bit Math
* Purpose : Benchmark 8-bit math functions.
*
*******************************************************************************/

void main_8(void);

/*******************************************************************************
*
* Name : 8-bit 2-dim Matrix
* Purpose : Benchmark copying 8-bit values.
*
*******************************************************************************/
void main_8m (void);

/*******************************************************************************
*
* Name : 8-bit Switch Case
* Purpose : Benchmark accessing switch statement using 8-bit value.
*
*******************************************************************************/
void main_8sw(void);

/*******************************************************************************
*
* Name : 16-bit Math
* Purpose : Benchmark 16-bit math functions.
*
*******************************************************************************/
void main_16(void);

/*******************************************************************************
*
* Name : 16-bit 2-dim Matrix
* Purpose : Benchmark copying 16-bit values.
*
*******************************************************************************/
void main_16m(void);

/*******************************************************************************
*
* Name : 16-bit Switch Case
* Purpose : Benchmark accessing switch statement using 16-bit value.
*
*******************************************************************************/
void main_16sw(void);

/*******************************************************************************
*
* Name : 32-bit Math
* Purpose : Benchmark 32-bit math functions.
*
*******************************************************************************/
void main_32(void);

/*******************************************************************************
*
* Name : Matrix Multiplication
* Purpose : Benchmark multiplying a 3x4 matrix by a 4x5 matrix.
* Matrix contains 16-bit values.
*
*******************************************************************************/
void main_mmlt16(void);
void main_mmlt32(void);

/*******************************************************************************
*
* Name : Floating-point Math
* Purpose : Benchmark floating-point math functions.
*
*******************************************************************************/
void main_f(void);

/*******************************************************************************
*
* Name : FIR Filter
* Purpose : Benchmark an FIR filter. The input values for the filter
* is an array of 51 16-bit values. The order of the filter is
* 17.
*
*******************************************************************************/
void main_fir(void);

#endif // BENCHMARK_TI_H_INCLUDED
