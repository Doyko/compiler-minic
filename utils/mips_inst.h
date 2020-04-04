#ifndef _MIPS_INST_H_
#define _MIPS_INST_H_

#define data_start 0x1001

typedef enum _codop_type
{
    CODOP_NONE,
    CODOP_DATA_SEC,
    CODOP_TEXT_SEC,
    CODOP_WORD,
    CODOP_ASCIIZ,
    CODOP_LABEL,
    CODOP_LABEL_STR,
    CODOP_LUI,
    CODOP_ADDU,
    CODOP_ADDIU,
    CODOP_SUBU,
    CODOP_MULT,
    CODOP_DIV,
    CODOP_SLLV,
    CODOP_SRAV,
    CODOP_SRLV,
    CODOP_AND,
    CODOP_ANDI,
    CODOP_OR,
    CODOP_NOR,
    CODOP_ORI,
    CODOP_XOR,
    CODOP_XORI,
    CODOP_SLT,
    CODOP_SLTU,
    CODOP_SLTI,
    CODOP_SLTIU,
    CODOP_LW,
    CODOP_SW,
    CODOP_BEQ,
    CODOP_BNE,
    CODOP_MFLO,
    CODOP_MFHI,
    CODOP_J,
    CODOP_TEQ,
    CODOP_SYSCALL,
} codop_type;


typedef struct _mips_inst_s
{
    struct _mips_inst_s* next;
    codop_type codop;
    int32_t r_dest;
    int32_t r_src_1;
    int32_t r_src_2;
    int32_t imm;

    int32_t label; // Destination label for jumps and branches
    char* label_str; // label itself for elements with codop = CODOP_LABEL
    char* str; // for litteral strings

} mips_inst_s;

typedef mips_inst_s* mips_inst_t;

typedef struct _program_s
{
    mips_inst_t start_inst;
    mips_inst_t last_inst;
} program_s;

typedef program_s* program_t;

const char* inst_codop2string(codop_type codop);
const char* inst_codop2string_lc(codop_type codop);

void create_data_sec_inst();
void create_text_sec_inst();
void create_word_inst(char* label, int32_t init_value);
void create_asciiz_inst(char* label_str, char* str);
void create_label_inst(int32_t label);
void create_label_str_inst(char* label);
void create_lui_inst(int32_t r_dest, int32_t imm);
void create_addu_inst(int32_t r_dest, int32_t r_src_1, int32_t r_src_2);
void create_subu_inst(int32_t r_dest, int32_t r_src_1, int32_t r_src_2);
void create_slt_inst(int32_t r_dest, int32_t r_src_1, int32_t r_src_2);
void create_sltu_inst(int32_t r_dest, int32_t r_src_1, int32_t r_src_2);
void create_and_inst(int32_t r_dest, int32_t r_src_1, int32_t r_src_2);
void create_or_inst(int32_t r_dest, int32_t r_src_1, int32_t r_src_2);
void create_xor_inst(int32_t r_dest, int32_t r_src_1, int32_t r_src_2);
void create_nor_inst(int32_t r_dest, int32_t r_src_1, int32_t r_src_2);
void create_mult_inst(int32_t r_src_1, int32_t r_src_2);
void create_div_inst(int32_t r_src_1, int32_t r_src_2);
void create_sllv_inst(int32_t r_dest, int32_t r_src_1, int32_t r_src_2);
void create_srav_inst(int32_t r_dest, int32_t r_src_1, int32_t r_src_2);
void create_srlv_inst(int32_t r_dest, int32_t r_src_1, int32_t r_src_2);
void create_addiu_inst(int32_t r_dest, int32_t r_src_1, int32_t imm);
void create_andi_inst(int32_t r_dest, int32_t r_src_1, int32_t imm);
void create_ori_inst(int32_t r_dest, int32_t r_src_1, int32_t imm);
void create_xori_inst(int32_t r_dest, int32_t r_src_1, int32_t imm);
void create_slti_inst(int32_t r_dest, int32_t r_src_1, int32_t imm);
void create_sltiu_inst(int32_t r_dest, int32_t r_src_1, int32_t imm);
void create_lw_inst(int32_t r_dest, int32_t r_src_1, int32_t imm);
void create_sw_inst(int32_t r_src_1, int32_t r_src_2, int32_t imm);
void create_beq_inst(int32_t r_src_1, int32_t r_src_2, int32_t label);
void create_bne_inst(int32_t r_src_1, int32_t r_src_2, int32_t label);
void create_mflo_inst(int32_t r_dest);
void create_mfhi_inst(int32_t r_dest);
void create_j_inst(int32_t label);
void create_teq_inst(int32_t r_src_1, int32_t r_src_2);
void create_syscall_inst();

void create_program();
void free_program();
void dump_mips_program(char* filename);

#endif
