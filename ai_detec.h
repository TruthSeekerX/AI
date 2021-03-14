/********************************************************************************************************************************************
* This is header file for ai_detec() function  
* Language: C
* Author:Siyuan e2002077
* Version: v0.1
* 10.03.2021 (dd.mm.yyy)
*********************************************************************************************************************************************/

int ui_get_ans(char *ptr_ans);
int ui_opt(uint8_t *ptr_opt);
void ai_detec(double rgb[], double snptc_wghts[],uint8_t *ptr_flg);
int ai_analys_man(double snptc_wghts[]);
int ai_analys_rand(double snptc_wghts[]);

