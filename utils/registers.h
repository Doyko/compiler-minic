#ifndef _REGISTERS_H_
#define _REGISTERS_H_

#define stack_reg 29
#define r0 0

void push_temporary_virtual();
void pop_temporary_virtual();
void push_temporary(int32_t reg);
void pop_temporary(int32_t reg);
bool reg_available();
int32_t get_current_reg();
int32_t get_restore_reg();
void allocate_reg();
void release_reg();
int32_t get_new_label();
void set_temporary_start_offset(int32_t offset);
void set_max_registers(int32_t n);
void reset_temporary_max_offset();
int32_t get_temporary_max_offset();
int32_t get_temporary_curr_offset();


#endif
