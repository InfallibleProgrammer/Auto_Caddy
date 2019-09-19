#pragma once

#include "function_types.h"

/**
 * @file
 * This file provides API to turn on peripheral power, and their interrupts
 * Turning off power and disabling interrupts is a YAGNI so do not be suprised of the omission
 */

/**
 * These enum values map to the interrupt vector table
 * Check UM10562.pdf, Chapter 5: NVIC
 *
 * @note If you add more peripherals here, you will have to modify lpc_peripherals.c too
 *
 * @warning these need to map to the same values as lpc40xx.h 'IRQn_Type'; we duplicate it
 *          here to avoid including lpc40xx.h and make unit-testing and mocking easier.
 */
typedef enum {
  LPC_PERIPHERAL__TIMER0 = 1,
  LPC_PERIPHERAL__TIMER1 = 2,
  LPC_PERIPHERAL__TIMER2 = 3,
  LPC_PERIPHERAL__TIMER3 = 4,

  LPC_PERIPHERAL__UART0 = 5,
  LPC_PERIPHERAL__UART1 = 6,
  LPC_PERIPHERAL__UART2 = 7,
  LPC_PERIPHERAL__UART3 = 8,

  LPC_PERIPHERAL__ADC = 22,
} lpc_peripheral_e;

void lpc_peripheral__turn_on_power_to(lpc_peripheral_e peripheral);

void lpc_peripheral__enable_interrupt(lpc_peripheral_e peripheral, function__void_f isr_callback);