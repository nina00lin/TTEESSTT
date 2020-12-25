/*
PTLF token structure
2620 000D 02EC都算是USER-DATA的HEADER。
其中2620是固定的，000D是內含TOKEN的數量(此例為13)，02EC是USER-DATA總長度。
2120 4334是TOKEN HEADER，2120是固定的，4334是TOKEN-ID(此例為"C4")。
000C是TOKEN資料長度，不含TOKEN HEADER。


*/
#include <stdio.h>  nolist
#include <stdarg.h> nolist
#include <ctype.h>  nolist
/* #include <cextdecs> nolist */
#include <string.h> nolist
#include <stdlib.h> nolist
#include <math.h>   nolist
#include <tal.h>    nolist
#include <time.h>    nolist

#include "xlibc"
#include "usrdecs"
#ifdef _GUARDIAN_HOST
#include "$system.zsysdefs.zsysc" nolist
#include <cextdecs> nolist
#endif

#ifdef _OSS_HOST
#include "/G/system/zsysdefs/zsysc" nolist
#include <cextdecs.h> nolist
#endif

#ifdef _WIN32_HOST
#include "zsysc.h" nolist
#include <cextdecs.h> nolist
#endif

#define USEREXIT_VPROC T9999D40_cuserexit_11Mar2008
#define USEREXIT_VPROC_TEXT "T9999D40_cuserexit_11Mar2008"

/* static global variables that persist between calls  */
typedef struct USEREXIT_GLOBALS_DEF
{
   short fnum;
   char msg[256];
} USEREXIT_GLOBALS_DEF;

static USEREXIT_GLOBALS_DEF g;

/* define user records */
short access1 = 1, cont_file_ctl = -1, error, cont_file = -1;
char cont_file_ctl_str[36], cont_file_str[36];


typedef struct _journal_struct
{
   int sis_tbl_ver; /*   4    bytes */      /* offset 0    */
   char pan[28]; /* 28   bytes */           /* offset 4    */
   long long onl_key_amt; /* 8    bytes */  /* offset 32   */
   char seq_num_char[12]; /* 12   bytes */  /* offset 40   */
   short discrim; /* 2    bytes */          /* offset 52   */
   short num_jrnl_rec; /* 2    bytes */     /* offset 54   */
   char iss_inst_id[20]; /* 20   bytes */   /* offset 56   */
   char acct_num[28]; /* 28   bytes */      /* offset 76   */
   char tran_dat_tim[16]; /* 16   bytes */  /* offset 104  */
   char acq_inst_id[20]; /* 20   bytes */   /* offset 120  */
   char chan_id[16]; /* 16   bytes */       /* offset 140  */
   char tran_dat_tim2[16]; /* 16   bytes */ /* offset 156  */
   char chan_id2[16]; /* 16   bytes */      /* offset 172  */
   char rec_frmt; /* 1    bytes */          /* offset 188  */
   char mrch_id[15]; /* 15   bytes */       /* offset 189  */
   char clerk_id[6]; /* 6    bytes */       /* offset 204  */
   char tran_dat_tim3[16]; /* 16   bytes */ /* offset 210  */
   char acq_inst_id2[20]; /* 20   bytes */  /* offset 226  */
   char bus_lvl1[10]; /* 10   bytes */      /* offset 246  */
   char bus_lvl2[10]; /* 10   bytes */      /* offset 256  */
   char bus_lvl3[10]; /* 10   bytes */      /* offset 266  */
   char bus_lvl4[10]; /* 10   bytes */      /* offset 276  */
   char bus_lvl5[10]; /* 10   bytes */      /* offset 286  */
   char mrch_id2[15]; /* 15   bytes */      /* offset 296  */
   char chan_id3[16]; /* 16   bytes */      /* offset 311  */
   char shift_num[2]; /* 2    bytes */      /* offset 327  */
   char btch_num[2]; /* 2    bytes */       /* offset 329  */
   char tran_dat_tim4[16]; /* 16   bytes */ /* offset 331  */
   char iss_inst_id2[20]; /* 20   bytes */  /* offset 347  */
   char pan2[28]; /* 28   bytes */          /* offset 367  */
   char tran_dat_tim5[16]; /* 16   bytes */ /* offset 395  */
   char fm_ts[8]; /* 8    bytes */          /* offset 411  */
   char dual_site_ind; /* 1    bytes */     /* offset 419  */
   char jrnl_body[7000]; /* 3650 bytes */   /* offset 420  */
} journal_struct;
/* journal_struct journal_rec; */

typedef struct _journal_output_body_struct
{
   char SEQ_ID[10]; /* 10   bytes */                  /* offset 0    */
   char TDE2104_PAN[28]; /* 28   bytes */             /* offset 10   */
   char FILTER1[2]; /* 2    bytes */                   /* offset 38   */ /* filter */
   long TDE2107_WS_AUTH_TYP; /* 4    bytes */         /* offset 38   */

   char TDE2111_F5_CRD_FIID[20]; /* 20   bytes */     /* offset 42   */
   char TDE2166_Track2_Data[37]; /* 37   bytes */     /* offset 62   */
   char TDE2177_Track2_Exp_Date[6]; /* 6    bytes */  /* offset 99   */
   char OGG_TDE2183_F30_RETL_SIC_CDE[4]; /*4    bytes */ /* offset 105  */ /* long TDE2183_F30_RETL_SIC_CDE;*/
   char TDE2242_F38_TERM_LN[16]; /* 16   bytes */     /* offset 109  */
   char OGG_TDE2359_WK_PRODUCT_IND[2]; /* 2    bytes */   /* offset 125  */
   char TDE2921_PAN_TKN_DATA[100]; /* 100  bytes */   /* offset 127  */
   char TDE2921_TKN_REQ_ID[100]; /* 100  bytes */     /* offset 227  */
   char TDE2921_TKN_STATUS; /* 1    bytes */          /* offset 327  */
   char TDE2921_TLV_DATA[400]; /* 400   bytes */      /* offset 328  */
} journal_output_body_struct; /* Total 528 Bytes */
/* journal_output_body_struct journal_output_body_rec; */


typedef struct _journal_output_struct
{
   int sis_tbl_ver; /*   4    bytes */      /* offset 0    */
   char pan[28]; /* 28   bytes */           /* offset 4    */
   long long onl_key_amt; /* 8    bytes */  /* offset 32   */
   char seq_num_char[12]; /* 12   bytes */  /* offset 40   */
   short discrim; /* 2    bytes */          /* offset 52   */
   short num_jrnl_rec; /* 2    bytes */     /* offset 54   */
   char iss_inst_id[20]; /* 20   bytes */   /* offset 56   */
   char acct_num[28]; /* 28   bytes */      /* offset 76   */
   char tran_dat_tim[16]; /* 16   bytes */  /* offset 104  */
   char acq_inst_id[20]; /* 20   bytes */   /* offset 120  */
   char chan_id[16]; /* 16   bytes */       /* offset 140  */
   char tran_dat_tim2[16]; /* 16   bytes */ /* offset 156  */
   char chan_id2[16]; /* 16   bytes */      /* offset 172  */
   char rec_frmt; /* 1    bytes */          /* offset 188  */
   char mrch_id[15]; /* 15   bytes */       /* offset 189  */
   char clerk_id[6]; /* 6    bytes */       /* offset 204  */
   char tran_dat_tim3[16]; /* 16   bytes */ /* offset 210  */
   char acq_inst_id2[20]; /* 20   bytes */  /* offset 226  */
   char bus_lvl1[10]; /* 10   bytes */      /* offset 246  */
   char bus_lvl2[10]; /* 10   bytes */      /* offset 256  */
   char bus_lvl3[10]; /* 10   bytes */      /* offset 266  */
   char bus_lvl4[10]; /* 10   bytes */      /* offset 276  */
   char bus_lvl5[10]; /* 10   bytes */      /* offset 286  */
   char mrch_id2[15]; /* 15   bytes */      /* offset 296  */
   char chan_id3[16]; /* 16   bytes */      /* offset 311  */
   char shift_num[2]; /* 2    bytes */      /* offset 327  */
   char btch_num[2]; /* 2    bytes */       /* offset 329  */
   char tran_dat_tim4[16]; /* 16   bytes */ /* offset 331  */
   char iss_inst_id2[20]; /* 20   bytes */  /* offset 347  */
   char pan2[28]; /* 28   bytes */          /* offset 367  */
   char tran_dat_tim5[16]; /* 16   bytes */ /* offset 395  */
   char fm_ts[8]; /* 8    bytes */          /* offset 411  */
   char dual_site_ind; /* 1    bytes */     /* offset 419  */
   journal_output_body_struct jrnl_body; /* 522 bytes */ /* offset 420  */
} journal_output_struct;
/* journal_output_struct journal_output_rec; */

typedef struct _journal_continuation_struct
{
   int sis_tbl_ver; /*   4    bytes */     /* offset 0    */
   char pan[28]; /* 28   bytes */          /* offset 4    */
   long long onl_key_amt; /* 8    bytes */ /* offset 32   */
   char seq_num_char[12]; /* 12   bytes */ /* offset 40   */
   short discrim; /* 2    bytes */         /* offset 52   */
   char rec_num[3]; /* 3    bytes */       /* offset 54   */
   /*short num_jrnl_rec;*/ /* 2    bytes */    /* offset 57   */
   char num_jrnl_rec[2]; /* 2    bytes */    /* offset 57   */
   char fm_ts[8]; /* 8    bytes */         /* offset 59   */
   char dual_site_ind; /* 1    bytes */    /* offset 67  */
   char jrnl_body[3650]; /* 3650 bytes */  /* offset 68  */
} journal_continuation_struct;
/* journal_continuation_struct journal_continuation_rec; */

#pragma section ptlf_in_rec
/* Record PTLF-IN-REC created on 02/17/2020 at 11:42 */

typedef struct __ptlf_in_rec
{
   /*   long long                       syskey; */
   struct
   {
      long long dat_tim;
      char rec_typ[2];
      struct
      {
         char crd_ln[4];
         char crd_fiid[4];
         struct
         {
            char card_num[19];
            char card_mbr[3];
         } crd_card;
      } crd;
      struct
      {
         char retl_ln[4];
         char retl_fiid[4];
         char retl_grp[4];
         char retl_regn[4];
         char retl_id[19];
         char term_id[16];
         char shift_num[3];
         char batch_num[3];
      } retl;
      struct
      {
         char term_ln[4];
         char term_fiid[4];
         char term_id[16];
         char term_tim[8];
      } term;
      struct
      {
         char term_id[16];
         struct
         {
            char rec_frmt;
            char retailer_id[19];
            char clerk_id[6];
         } rkey;
      } tkey;
      char dat_flg;
   } head;
   union {
      struct
      {
         char auth_typ[4];
         char auth_rte_stat[2];
         char auth_originator;
         char auth_responder;
         char auth_iss_code[2];
         long long auth_entry_tim;
         long long auth_exit_tim;
         long long auth_re_entry_tim;
         struct
         {
            char auth_tran_y[2];
            char auth_tran_m[2];
            char auth_tran_d[2];
         } auth_tran_dat;
         struct
         {
            char auth_tran_hh[2];
            char auth_tran_mm[2];
            char auth_tran_ss[2];
            char auth_tran_tt[2];
         } auth_tran_tim;
         char auth_post_dat[6];
         char auth_acq_ichg_setl_dat[6];
         char auth_iss_ichg_setl_dat[6];
         char auth_seq_num[12];
         char auth_term_name_loc[25];
         char auth_term_owner_name[22];
         char auth_term_city[13];
         char auth_term_st[3];
         char auth_term_cntry_cde[2];
         char auth_brch_id[4];
         char auth_user_fld2[3];
         short auth_term_tim_ofst;
         char auth_acq_inst_id_num[11];
         char auth_rcv_inst_id_num[11];
         char auth_term_typ[2];
         char auth_clerk_id[6];
         struct
         {
            char auth_crt_auth_grp[4];
            char auth_crt_auth_user_id[8];
         } auth_crt_auth;
         char auth_retl_sic_code[4];
         char auth_orig[4];
         char auth_dest[4];
         struct
         {
            char auth_tran_code_tc[2];
            char filler_0[4];
         } auth_tran_code;
         char auth_crd_typ[2];
         char auth_acct_num[19];
         char auth_resp_code[3];
         unsigned long long auth_amt_1;
         unsigned long long auth_amt_2;
         char auth_exp_dat[4];
         struct
         {
            char filler_1;
            char track2_card_num[16];
            char filler_2;
            char track2_exp_date[4];
            char filler_3[18];
         } auth_track2;
         char auth_pin_ofst[16];
         char auth_pre_auth_seq_num[12];
         char auth_invoice_num[10];
         char auth_orig_invoice_num[10];
         char auth_authorizer[16];
         char auth_auth_ind;
         char auth_shift_num[3];
         char auth_batch_seq_num[3];
         struct
         {
            char auth_apprv_code_6[6];
            char filler_4;
            char auth_apprv_code_resp;
         } auth_apprv_code_8;
         char auth_apprv_code_lgth;
         char auth_ichg_resp[8];
         char auth_pseduo_term_id[4];
         char auth_rfrl_phone[20];
         char auth_dft_capture_flg;
         char auth_setl_flg;
         char auth_rvrl_code[2];
         char auth_rea_for_chrgbk[2];
         char auth_num_of_chrgbk;
         char auth_pt_srv_cond_code[2];
         struct
         {
            char entry_code1[2];
            char entry_code2;
         } auth_pt_srv_entry_code;
         char auth_auth_ind2;
         char auth_orig_crncy_code[3];
         char auth_user_fld4[30];
         char auth_refr[6];
         char auth_adj_stl_impact_flg;
         char auth_refr_ind[4];
         char auth_frwd_inst_id_num[11];
         char auth_crd_accpt_id_num[11];
         char auth_crd_iss_id_num[11];
         char auth_orig_msg_typ[4];
         char auth_orig_tran_tim[8];
         char auth_orig_tran_dat[4];
         char auth_orig_seq_num[12];
         char auth_orig_b24_post_dat[4];
         char auth_excp_rsn_code[3];
         char auth_ovrrde_flg;
         char auth_addr[20];
         char auth_zip_code[9];
         char auth_addr_vrfy_stat;
         char auth_pin_ind;
         char tt2[49];
      } auth;
      struct
      {
         struct
         {
            char stl_typ[4];
            char stl_post_dat[6];
            char stl_prod_id[2];
            char stl_rel_num[2];
            char stl_dpc_num[4];
            short term_tim_ofst;
            char stl_term_id[8];
            char filler_5[6];
            struct
            {
               char stl_retl_rttn[11];
               char stl_retl_id[10];
               char filler_6[9];
               char filler_7[41];
            } stl_retl;
            char stl_setl_typ;
            char stl_bal_flg;
            char filler_8;
            char stl_tran_dat[6];
            char stl_tran_tim[6];
            char stl_ob_flg;
            char stl_ach_comp_id[10];
            char stl_billing_info[10];
            char filler_9[22];
         } stl_rec_1;
         char filler_10;
         struct
         {
            struct
            {
               short dc_db_cnt;
               long long dc_db;
               short dc_cr_cnt;
               long long dc_cr;
               short dc_adj_cnt;
               long long dc_adj;
            } stl_dc_tot;
            struct
            {
               short db_cnt_a;
               long long db_a;
               short cr_cnt_a;
               long long cr_a;
               short adj_cnt_a;
               long long adj_a;
            } stl_tot;
            struct
            {
               short cn_db_cnt;
               long long cn_db;
               short cn_cr_cnt;
               long long cn_cr;
               short cn_adj_cnt;
               long long cn_adj;
            } stl_cn_dc_tot;
            struct
            {
               short db_cnt_c;
               long long db_c;
               short cr_cnt_c;
               long long cr_c;
               short adj_cnt_c;
               long long adj_c;
            } stl_cn_tot;
         } stl_rec_2;
         char filler_11[257];
      } stl_rec;
   } u_auth;
   struct
   {
      char tt3[24];
      char optn_retl_id[10];
      char optn_store_id[6];
      char optn_edc_tc[2];
      char filler_12[11];
      char goods_id[6];
      char personal_id[10];
      char tms_download_flag;
      char hk_ind;
      char filler_13;
      char cup_crd_flg;
      char ec_flag;
      char settle_flag[2];
      char cup_setl_date[4];
      char org_tran_date[4];
      char org_tran_time[6];
      char ref_code[12];
      char tt1[2490];
   } user_data;
} ptlf_in_rec_def;
#define ptlf_in_rec_def_Size 3378
#pragma section ptlf_out_rec
/* Record PTLF-OUT-REC created on 02/17/2020 at 15:11 */

typedef struct __ptlf_out_rec
{
   struct
   {
      char f1_log_yy[4];
      char f2_log_mm[2];
      char f3_log_dd[2];
      char f4_log_seq[12];
      char f5_crd_fiid[4];
      union {
         char f6_tran_date[8];
         struct
         {
            char f6_tran_yy[4];
            char f6_tran_mm[2];
            char f6_tran_dd[2];
         } f6_tran_date_r;
      } u_f6_tran_date;
      char f7_crd_num[19];
      char f8_retl_id[17];
      char f9_term_id[8];
      char f10_batch_num[3];
      char f11_rec_typ[2];
      char f12_shift_num[3];
   } out_head;
   union {
      struct
      {
         char f13_seq_num[3];
         union {
            char f14_tran_tim[8];
            struct
            {
               char f14_tran_hh[2];
               char f14_tran_mm[2];
               char f14_tran_ss[2];
               char f14_tran_mss[2];
            } f14_tran_tim_r;
         } u_f14_tran_tim;
         char f15_apprv_cde_8[8];
         char f16_dft_cap_flg;
         char f17_tc[2];
         char f18_crd_typ[2];
         char f19_amt_1[19];
         char f20_amt_2[19];
         char f21_auth_typ[4];
         char f22_originator;
         char f23_responder;
         struct
         {
            char entry_yy[4];
            char entry_mon[2];
            char entry_dd[2];
            char entry_hh[2];
            char entry_mm[2];
            char entry_ss[2];
            char entry_ms[3];
            char entry_mms;
         } f24_entry_tim;
         struct
         {
            char exit_yy[4];
            char exit_mon[2];
            char exit_dd[2];
            char exit_hh[2];
            char exit_mm[2];
            char exit_ss[2];
            char exit_ms[3];
            char exit_mms;
         } f25_exit_tim;
         struct
         {
            char rentry_yy[4];
            char rentry_mon[2];
            char rentry_dd[2];
            char rentry_hh[2];
            char rentry_mm[2];
            char rentry_ss[2];
            char rentry_ms[3];
            char rentry_mms;
         } f26_re_entry_tim;
         char f27_term_cntry_cde[2];
         char f28_grp[4];
         char f29_user_id[8];
         char f30_retl_sic_cde[4];
         char f31_orig[4];
         char f32_resp_cde[3];
         char f33_track2_fmt1[40];
         char f34_pt_srv_entry_mde[3];
         char f35_optn_retl_id[10];
         char f36_optn_edc_tc[2];
         char f37_card_ln[4];
         char f38_term_ln[4];
         char f39_pt_srv_cond_mde[2];
         char f40_track2_exp_date[4];
         union {
            char f41_gmt_dat[8];
            struct
            {
               char f41_gmt_yy[4];
               char f41_gmt_mm[2];
               char f41_gmt_dd[2];
            } f41_gmt_dat_r;
         } u_f41_gmt_dat;
         union {
            char f42_gmt_tim[8];
            struct
            {
               char f42_gmt_hh[2];
               char f42_gmt_mm[2];
               char f42_gmt_ss[2];
               char f42_gmt_mss[2];
            } f42_gmt_tim_r;
         } u_f42_gmt_tim;
         char f43_dow;
         char f44_tx_indr;
         char f45_tx_resp_cde[2];
         char f46_redemption_pt[8];
         char f47_sign_bal_pt;
         char f48_balance_pt[8];
         char f49_pay_amt[10];
         char f50_period_num[2];
         char f51_amt_1st[8];
         char f52_amt_each[8];
         char f53_amt_fee[6];
         char f54_tkc0_moto_flag;
         char f55_cavv_resp_cde[2];
         char f56_cavv_sec_cde[2];
         char f57_cavv_indr[2];
         char f58_cavv_vlue[4];
         char f59_unpred_num[4];
         char f60_auth_track_num[16];
         char f61_term_name_loc[25];
         char f62_term_owner_name[22];
         char f63_term_city[13];
         char f64_term_st[3];
         char f65_extrn_resp[3];
         char f66_goods_id[6];
         char f67_acs_identifier[2];
         char f68_auth_method;
         char f69_ucaf_aav[3];
         char f70_ucaf_authn_coll_ind;
         char f71_settle_flag[2];
         char f72_auth_pin_ind;
         char f73_cup_setl_date[4];
         char f74_org_tran_date[4];
         char f75_org_tran_time[6];
         char f76_trace_num[6];
         char f77_ref_code[12];
         char f78_hk_ind;
         char f79_cup_crd_flg;
         char f80_term_attend_ind;
         char f81_ch_present_ind;
         char f82_ch_actvt_ind;
         char f83_term_input_cap_ind;
         char f84_tran_id[15];
         char f85_prod_id[2];
         char f86_acct_num_ind;
         char f87_virtual_card_num[19];
         char f88_vcn_exp[4];
         char f88_1_ac_very_rslt[2];
         char f88_2_fraud_chk_rslt[2];
         char s8_filler[2];
         char f89_on_behalf_service[2];
         char f90_on_behalf_result;
         char f91_card_prod_iden_info[32];
         char f92_id_flag;
         char f93_txn_chnl_typ[2];
         char f94_txn_init_mthd;
         char f95_chn_cust_id_typ[2];
         char f96_chn_cust_id[20];
         char f97_txn_ind;
         char f98_txn_relv_tag[2];
         char f99_acct_ord_num[40];
         char f100_crd_stat[3];
         char f101_mob_phone_nbr[20];
         char f102_e_com_ind[2];
         char f103_scnd_mrch_id[15];
         char f104_scnd_mrch_nam_addr[40];
         char f105_user_id_cat[2];
         char f106_user_id_pmnt_item[40];
         char f107_rgn_cde[4];
         char f108_addl_rgn_cde[4];
         char f109_pmnt_mthd_tag;
         char f110_mthd_typ[2];
         char f111_pmnt_mthd_num[40];
         char f112_time_span[3];
         char f113_max_mntd_amt[12];
         char f114_min_mntd_amt[12];
         char f115_pmnt_per[17];
         char f116_stip_orig_mti[4];
         char f117_stip_orig_txn_cde[6];
         char f118_stip_orig_pt_svc_cde[2];
         char f119_stip_vip_ind;
         char f120_stip_fail_rsn[2];
         char f121_stip_iin[11];
         char f122_orig_crncy_code[3];
         char f123_num_active_token[2];
         char f124_acva[2];
         char f125_pan_source[2];
         char f126_ac[8];
         char f127_ac_exp_datetime[12];
         char f128_wallet_sp_rc[30];
         char f129_msg_type[2];
         char f130_avr;
         char f131_aa_mv_cr[2];
         char f132_cvmt[186];
         char f133_token_al[2];
         char f134_token_req_id[11];
         char f135_token_type[2];
         char f136_token_status;
         char f137_additional_data[15];
         char f138_dev_type[2];
         char f139_msg_rsn_cde[4];
         char f140_pf_id[11];
         char f141_net_ref_id[15];
         char f142_pos_data[12];
         char f143_id_chk_head;
         char f144_merchant_pan[19];
         char f145_coupon_info[19];
         char f146_discount_amt[12];
         char f147_preferential_amt[12];
         char f148_token_qr_tag11[25];
         char f149_pmnt_typ_ind[3];
         char tmp_filler[23];
      } out_auth;
      struct
      {
         char f13_setl_typ;
         char f14_bal_flg;
         union {
            char f15_tran_tim[6];
            struct
            {
               char f15_tran_hh[2];
               char f15_tran_mm[2];
               char f15_tran_ss[2];
            } f15_tran_tim_r;
         } u_f15_tran_tim;
         char f16_ob_flg;
         char f17_db_cnt[5];
         char f18_db[19];
         char f19_cr_cnt[5];
         char f20_cr[19];
         char f21_adj_cnt[5];
         char f22_adj[19];
      } out_settle;
   } u_out_auth;
   struct
   {
      char icc5_b2_bit_map[16];
      char icc6_crypto_info_data[8];
      char icc6_crypto_info_data_h[2];
      char icc7_tvr[40];
      char icc7_tvr_h[10];
      char icc8_arqc[16];
      char icc9_amt_auth[12];
      char icc10_amt_other[12];
      char icc11_aip[16];
      char icc11_aip_h[4];
      char icc12_atc[5];
      char icc12_atc_h[4];
      char icc13_ic_term_cntry_cde[3];
      char icc14_tran_crncy_cde[3];
      char icc15_ic_tran_dat[6];
      char icc16_tran_type[2];
      char icc17_unpredict_num[8];
      char icc18_iss_appl_data_lgth[4];
      char icc19_deriv_key_index[2];
      char icc20_crypto_ver_num[2];
      char icc21_crd_verif_rslts[48];
      char icc21_crd_verif_rslts_h[12];
      char icc22_dac[4];
      char icc23_b3_bit_map[16];
      char icc24_term_ser_num[8];
      char icc25_term_cap[24];
      char icc25_term_cap_h[6];
      char icc26_b3_user_fld1[4];
      char icc27_b3_user_fld2[8];
      char icc28_emv_term_type[2];
      char icc29_appl_ver_num[4];
      struct
      {
         char icc30_cvm_rslts_1[8];
         char icc30_cvm_rslts_2[2];
         char icc30_cvm_rslts_3[2];
      } icc30_cvm_rslts;
      char icc31_df_name_lgth[4];
      char icc32_df_name[32];
      char icc33_icpt_srv_entry_mde[3];
      char icc34_term_entry_cap;
      char icc35_last_icc_stat;
      char icc36_data_suspect;
      char icc37_appl_pan_seq_num[2];
      char icc38_dev_info[6];
      char icc39_rsn_on_line_cde[4];
      char icc40_arqc_verify;
      char icc41_b4_user_fld1;
      char icc42_iss_auth_arpc[16];
      char icc43_iss_auth_addl_data[16];
      char icc44_iss_resp_cde[2];
      char icc45_iss_auth_info[12];
      char icc46_send_crd_blk;
      char icc47_send_put_data;
      char icc48_off_tvr[10];
      char icc49_off_cvr[8];
      char icc50_chip_cond_cde;
      char icc51_chip_rec;
      char icc52_off_resp_cde[2];
      char icc53_cryptogram[16];
      char icc54_crd_seq[3];
      char icc55_term_cap_pro[6];
      char icc56_iss_script_data[256];
      char icc57_offline_ind;
      char icc58_auth_resp_cde[2];
      char icc59_tran_stat_info[4];
      char icc60_iss_script_rslts[50];
      char icc61_visa_chip_cond_cde;
      char icc62_mc_iss_auth_data[32];
      char icc63_mc_iss_script_tplt_1_2[256];
      char icc64_mc_tran_seq_cntr[8];
      char icc65_jcb_appl_usage_ctrl[4];
      char icc66_jcb_icc_appl_ver[4];
      char icc67_cvd;
      char icc68_isr_data[80];
      char icc69_cntr[16];
      char icc69_iad[64];
      char icc70_visa_ffi[10];
      char icc_filler[84];
   } out_icc_auth;
} ptlf_out_rec_def;
#define ptlf_out_rec_def_Size 2702
/*---------------------------------------------------------------------------*
 * Extract/Replicat callbacks for common error reporting                     *
 *---------------------------------------------------------------------------*/
#define MSG_INFO 1     /* normal EMS message */
#define MSG_CRITICAL 2 /* EMS message with emphasis on */
#define MSG_FATAL 3    /* abends the process after writing the message */

#ifdef __cplusplus
extern "C"
{      /* dont allow C++ name mangling on the entrypoint */
#endif /* or VPROC                                       */

   void USEREXIT_VPROC(void);

   void cuserexit(exit_call_type_def exit_call_type,
                  exit_result_def *exit_call_result,
                  exit_params_def *exit_params,
                  exit_rec_buf_def exit_rec_buf);

#ifdef __cplusplus
}
#endif

/*---------------------------------------------------------------------------*
 *                                                                           *
 *---------------------------------------------------------------------------*/
void USEREXIT_VPROC(void)
{
}

/*---------------------------------------------------------------------------*
 *                                                                           *
 *---------------------------------------------------------------------------*/
short USEREXIT_start(exit_params_def *rq)
{
   sprintf(g.msg, "USEREXIT Initialization %s", USEREXIT_VPROC_TEXT);
   GGS_REPORTMESSAGE(g.msg);
   GGS_EMSMESSAGE(17000, g.msg, MSG_INFO);

   return (EXIT_OK_VAL);
} /* USEREXIT_start */

/*---------------------------------------------------------------------------*
 *                                                                           *
 *---------------------------------------------------------------------------*/
short USEREXIT_begintrans(exit_params_def *rq)
{
   return (EXIT_OK_VAL);
} /* USEREXIT_begintrans */

/*---------------------------------------------------------------------------*
 *                                                                           *
 *---------------------------------------------------------------------------*/
short USEREXIT_endtrans(exit_params_def *rq)
{
   return (EXIT_OK_VAL);
} /* USEREXIT_endtrans */

/*---------------------------------------------------------------------------*
 *                                                                           *
 *---------------------------------------------------------------------------*/
short USEREXIT_processrecord(exit_params_def *rq, char *recbuf)
{
   struct FieldPase_
   {
      unsigned long
          primary_key1; /* 4 bytes */
      unsigned long
          primary_key2; /* 4 bytes */
      unsigned long
          primary_key3; /* 4 bytes */
      unsigned long
          primary_key4; /* 4 bytes */
      unsigned long
          primary_key5; /* 4 bytes */
      char
          other_data[260];
   } FieldPase;
   memcpy((char *)&FieldPase.primary_key1, recbuf, rq->record_len);

   return (EXIT_OK_VAL);
} /* USEREXIT_processrecord */

/*---------------------------------------------------------------------------*
 *                                                                           *
 *---------------------------------------------------------------------------*/
short AUTH_processrecord(exit_params_def *rq, char *recbuf)
{
   struct __ptlf_in_rec ptlf_in_record;

   short result = -1;
   short syskeylen = -1;
   short source_or_target = EXIT_FN_SOURCE_VAL;

   result = GET_SYSKEY_LENGTH(&syskeylen, source_or_target);
   if (result != 0)
   {
      sprintf(g.msg, "GET_SYSKEY_LENGTH error %d", result);
   }
   if (syskeylen > 0)
   {
      memcpy((char *)&ptlf_in_record.head.dat_tim, &recbuf[0 + syskeylen], (rq->record_len - syskeylen));
   }
   else
      memcpy((char *)&ptlf_in_record.head.dat_tim, &recbuf[0], (rq->record_len));
   return (EXIT_OK_VAL);
} /* USEREXIT_processrecord */

/*---------------------------------------------------------------------------*
 *                                                                           *
 *---------------------------------------------------------------------------*/
short JRNL_processrecord(exit_params_def *rq, char *recbuf)
{
   /*struct _journal_struct jrnl_in_record;
   struct _journal_continuation_struct jrnl_continuation_in_record;*/

   /*  struct __jrnl_out_rec jrnl_out_record; */

   journal_struct journal_rec = { 0 };
   journal_continuation_struct journal_continuation_rec = { 0 };
   journal_output_struct journal_output_rec = { 0 };



   short result = -1;
   short syskeylen = -1;
   short source_or_target = EXIT_FN_SOURCE_VAL;

   char temp_ctn_rec[3718] = { 0 };
   char jrnltab_rec[56] = { 0 };
   char jrnltab_tmp[56] = { 0 };
   char temp_recbuf[1000] = { 0 };
   char temp_recbuf2[1000] = {0};

   /*
   char temp_char_timestamp[8]= { 0 };
   long long temp_timestamp = 0; */

   /* add 2020/03/04 _ Scott */
   long tde_identifer = -1;
   long version = -1;
   long length = -1;
   char TDE_data[3640];
   char *tde_point;
   char *TDE_pnt;

   char SEQ_ID[10] = { 0 };
   char PAN[29] = { 0 };
   long WS_AUTH_TYP = -1;
   char F5_CRD_FIID[21] = { 0 };
   char TDE2166_Track2_Data[38] = { 0 };
   char TDE2177_Track2_Exp_Date[7] = { 0 };
   long F30_RETL_SIC_CDE = 0;
   char char_F30_RETL_SIC_CDE[4] = { 0 };
   char F38_TERM_LN[17] = {0};
   char WK_PRODUCT_IND[2] = { 0 };
   char TKN_STATUS = { 0 };

   long TDE2166_Track2_Flag = 0;

   char F40_TRACK2_EXP_DATE[5] = { 0 };

   char *PAN_TKN_DATA;
   char *TKN_REQ_ID;

   char *TDE2921_TLV_DATA;
   /* add 2020/04/30 _ Randolph */
   char chk_pan[28+1];           /* 28   bytes */  
   long long chk_onl_key_amt;    /* 8    bytes */  
   char chk_seq_num_char[12+1];  /* 12   bytes */  
   short chk_discrim;            /* 2    bytes */  
   char chk_tran_dat_tim[16+1];  /* 16   bytes */  



   short read_count = -1;
   unsigned short Total_body_len = 0, read_tde_length = 0, index = 0;

   short i = -1;
   long Temp_length = -1;
   int flag_find = 0;

       result = GET_SYSKEY_LENGTH(&syskeylen, source_or_target);
   if (result != 0)
   {
      sprintf(g.msg, "GET_SYSKEY_LENGTH error %d", result);
      GGS_REPORTMESSAGE(g.msg);
      return (EXIT_ABEND_VAL);
   }
   /*
      memcpy(temp_char_timestamp, (char *)rq->audit_timestamp, 8);
      memcpy(&temp_timestamp, temp_char_timestamp, 8);
      */
   if (syskeylen > 0)
   {

      if(rq->record_len <= syskeylen)
        return (EXIT_IGNORE_VAL);
      memcpy((char *)&journal_rec.sis_tbl_ver, &recbuf[0 + syskeylen], (rq->record_len - syskeylen));
      memcpy((char *)&journal_output_rec.sis_tbl_ver, &recbuf[0 + syskeylen], 420);
      Total_body_len = rq->record_len - syskeylen - 420;
      if(Total_body_len > 3650){
         flag_find = 1;
      }
      if (journal_rec.num_jrnl_rec > 1)
      {
         memset(jrnltab_tmp, 0x00, 56);
         OLDFILENAME_TO_FILENAME_((short *)&rq->source_file.volume[0], &jrnltab_tmp[0],
                                  (short)sizeof(jrnltab_tmp), &read_count);
         memset(jrnltab_rec, 0x20, 56);
         memcpy(jrnltab_rec, strstr(jrnltab_tmp, "$"), strlen(strstr(jrnltab_tmp, "$")));
         /*
   sprintf(jrnltab_rec,"$%s.%s.%s",rq->source_file.volume[2],rq->source_file.subvol,rq->source_file.file_part);
   */
         error = FILE_SETKEY_(cont_file_ctl, jrnltab_rec, 28, ,2, , 0);
         READX(cont_file_ctl, (char *)&jrnltab_rec[0], 56, (unsigned short *)&read_count);
         FILE_GETINFO_(cont_file_ctl, &error);
         if (error != 0)
         {
            /* skip record */
            sprintf(g.msg, "Can't find continuation file");
            GGS_REPORTMESSAGE(g.msg);
            return (EXIT_ABEND_VAL);
         }
         else
         {
            memset(jrnltab_tmp, 0x00, 56);
            memset((char *)&journal_continuation_rec.sis_tbl_ver, 0x00, sizeof(journal_continuation_rec));
            memcpy(&jrnltab_tmp[0], &jrnltab_rec[28], 28);
            memset(strstr(&jrnltab_tmp[0], " "), 0x00, 1);
            if (strncmp(&jrnltab_tmp[0], &cont_file_str[0], strlen(&jrnltab_tmp[0])) != 0)
            {
               memset(cont_file_str, 0x00, 36);
               memcpy(cont_file_str, &jrnltab_tmp[0], strlen(&jrnltab_tmp[0]));
               if(cont_file>0){
                 FILE_CLOSE_(cont_file);
               }
               error = FILE_OPEN_(cont_file_str, (short)strlen(cont_file_str), &cont_file, access1);
            }
            memcpy(&journal_continuation_rec.pan[0], &journal_rec.pan[0], sizeof(journal_rec.pan));
            journal_continuation_rec.onl_key_amt = journal_rec.onl_key_amt;
            memcpy(&journal_continuation_rec.seq_num_char[0], &journal_rec.seq_num_char[0], sizeof(journal_rec.seq_num_char));
            journal_continuation_rec.discrim = journal_rec.discrim;
            memcpy(&journal_continuation_rec.rec_num[0], "002", 3);

            error = FILE_SETKEY_(cont_file, &journal_continuation_rec.pan[0], 53, ,2, , 0);
            /*error = READX(cont_file, (char *)&journal_continuation_rec.sis_tbl_ver, 4048, &read_count); */
            READX(cont_file, temp_ctn_rec, 4048, (unsigned short *)&read_count);
            FILE_GETINFO_(cont_file, &error);
            if (error != 0)
            {
              /* skip record */
              sprintf(g.msg, "Can't find continuation record");
              GGS_REPORTMESSAGE(g.msg);
              memset(chk_pan,0,sizeof(chk_pan));
              chk_onl_key_amt=journal_rec.onl_key_amt;
              memset(chk_seq_num_char,0,sizeof(chk_seq_num_char));
              chk_discrim=journal_rec.discrim;
              memset(chk_tran_dat_tim,0,sizeof(chk_tran_dat_tim));
              memcpy(&chk_pan[0],&journal_rec.pan[0],28);
              memcpy(&chk_seq_num_char[0],&journal_rec.seq_num_char[0],12);
              memcpy(&chk_tran_dat_tim[0],&journal_rec.tran_dat_tim[0],16);
              sprintf(g.msg, "pan=%s",chk_pan);
              GGS_REPORTMESSAGE(g.msg);
              sprintf(g.msg, "onl_key_amt=%ld",chk_onl_key_amt);
              GGS_REPORTMESSAGE(g.msg);
              sprintf(g.msg, "seq_num_char=%s",chk_seq_num_char);
              GGS_REPORTMESSAGE(g.msg);
              sprintf(g.msg, "discrim=%d",chk_discrim);
              GGS_REPORTMESSAGE(g.msg);
              sprintf(g.msg, "tran_dat_tim=%s",chk_tran_dat_tim);
              GGS_REPORTMESSAGE(g.msg);
              return (EXIT_IGNORE_VAL);
            }

            memcpy((char *)&journal_continuation_rec.sis_tbl_ver, temp_ctn_rec, (read_count));

            /* memcpy((char *)&journal_continuation_rec.sis_tbl_ver, &temp_ctn_rec[0], 57);
            memcpy((char *)&journal_continuation_rec.num_jrnl_rec, &temp_ctn_rec[57], 2);
            memcpy(&journal_continuation_rec.fm_ts, &temp_ctn_rec[59], 9);
            memcpy(&journal_continuation_rec.jrnl_body, &temp_ctn_rec[68], (read_count - 68)); */

            memcpy(&journal_rec.jrnl_body[Total_body_len], &journal_continuation_rec.jrnl_body, (read_count - 68));
            Total_body_len += (read_count-68);
            /* TDE_Parse(&journal_rec.jrnl_body, sizeof(journal_continuation_rec.jrnl_body)); */


         }
      }
      index = 0;

      while (1)
      {
         if (journal_rec.jrnl_body[index + 2] == 0x00 && journal_rec.jrnl_body[index + 3] == 0x00)
         {
            if (read_tde_length >= Total_body_len){
               memset(SEQ_ID, 0, sizeof(SEQ_ID));
               if(F30_RETL_SIC_CDE == 6011 && WK_PRODUCT_IND == "02"){
                  sprintf(&SEQ_ID[0], "T ");
               }
               else{
                  sprintf(&SEQ_ID[0], "P ");
               }
               memcpy(&SEQ_ID[2], &rq->audit_timestamp, 8);
               memcpy(&journal_output_rec.jrnl_body.SEQ_ID[0], &SEQ_ID[0], sizeof(SEQ_ID));
               memset(temp_recbuf, 0, sizeof(temp_recbuf));
               memset(temp_recbuf2, 0, sizeof(temp_recbuf2));

               memcpy(recbuf + 8, (char *)&journal_output_rec.sis_tbl_ver, sizeof(journal_output_rec));
               memcpy(temp_recbuf, (char *)&journal_output_rec.sis_tbl_ver, sizeof(journal_output_rec));
               /*memcpy(temp_recbuf2, (char *)&journal_output_rec.sis_tbl_ver, 948);*/
               memmove(temp_recbuf2, (char *)&journal_output_rec.sis_tbl_ver, 948);



               memcpy(&rq->source_file.volume[2], "GGS   ", 6);
               memcpy(&rq->source_file.subvol[0], "AUTHLOG ", 8);
               memcpy(&rq->source_file.file_part[0], "JRYYMMDD", 8);
               /* rq->record_len = syskeylen + 942; */
               rq->record_len = syskeylen + 950;
               break;
            }
            else{
               return (EXIT_IGNORE_VAL);
            }
         }



         tde_point = journal_rec.jrnl_body;
         read_tde_length = 0;

            while (read_tde_length < Total_body_len)
            {

               memcpy((char *)&tde_identifer, tde_point, 4);
               tde_point = tde_point + 4;
               read_tde_length = read_tde_length + 4;
               if (read_tde_length >= Total_body_len)
               {
                  return (EXIT_ABEND_VAL);
               }

               memcpy((char *)&version, tde_point, 4);
               tde_point = tde_point + 4;
               read_tde_length = read_tde_length + 4;
               if (read_tde_length >= Total_body_len)
               {
                  return (EXIT_ABEND_VAL);
               }

               memcpy((char *)&length, tde_point, 4);
               if(length > 7000){
               	  memset(chk_pan,0,sizeof(chk_pan));
               	  chk_onl_key_amt=journal_rec.onl_key_amt;
               	  memset(chk_seq_num_char,0,sizeof(chk_seq_num_char));
               	  chk_discrim=journal_rec.discrim;
               	  memset(chk_tran_dat_tim,0,sizeof(chk_tran_dat_tim));
                  memcpy(&chk_pan[0],&journal_rec.pan[0],28);
                  memcpy(&chk_seq_num_char[0],&journal_rec.seq_num_char[0],12);
                  memcpy(&chk_tran_dat_tim[0],&journal_rec.tran_dat_tim[0],16);
                  sprintf(g.msg, "Parse TDE length error, skip this record");
                  GGS_REPORTMESSAGE(g.msg);
                  sprintf(g.msg, "pan=%s",chk_pan);
                  GGS_REPORTMESSAGE(g.msg);
                  sprintf(g.msg, "onl_key_amt=%ld",chk_onl_key_amt);
                  GGS_REPORTMESSAGE(g.msg);
                  sprintf(g.msg, "seq_num_char=%s",chk_seq_num_char);
                  GGS_REPORTMESSAGE(g.msg);
                  sprintf(g.msg, "discrim=%d",chk_discrim);
                  GGS_REPORTMESSAGE(g.msg);
                  sprintf(g.msg, "tran_dat_tim=%s",chk_tran_dat_tim);
                  GGS_REPORTMESSAGE(g.msg);
                  return (EXIT_IGNORE_VAL);

               }
               tde_point = tde_point + 4;
               read_tde_length = read_tde_length + 4;
               if (read_tde_length >= Total_body_len)
               {
                  return (EXIT_ABEND_VAL);
               }

               if ((length % 2) != 0)
                  length++;

               memcpy(TDE_data, tde_point, (length - 12));
               for (i = 0; i < (length - 12); i++)
               {
                  tde_point++;
                  read_tde_length++;
               }
               TDE_pnt = TDE_data;



               switch (tde_identifer)
               {

               case 2104:

                  memset(PAN, 0, sizeof(PAN));
                  memcpy(PAN, TDE_pnt, 28);

                  memcpy(journal_output_rec.jrnl_body.TDE2104_PAN, TDE_pnt, 28);

                  break;

               case 2107:

                  memset(&WS_AUTH_TYP, 0, sizeof(WS_AUTH_TYP));
                  memcpy(&WS_AUTH_TYP, TDE_pnt, 4);
                  memcpy(&journal_output_rec.jrnl_body.TDE2107_WS_AUTH_TYP, TDE_pnt, 4);

                  break;

               case 2111:

                  memset(F5_CRD_FIID, 0, sizeof(F5_CRD_FIID));
                  memcpy(F5_CRD_FIID, TDE_pnt, 20);
                  memcpy(journal_output_rec.jrnl_body.TDE2111_F5_CRD_FIID, TDE_pnt, 20);

                  break;

               case 2166:

                  TDE2166_Track2_Flag = 1;
                  memset(TDE2166_Track2_Data, 0, sizeof(TDE2166_Track2_Data));
                  memcpy(&Temp_length, TDE_pnt, 4);
                  if(Temp_length>(sizeof(journal_output_rec.jrnl_body.TDE2166_Track2_Data)+4)){
                    memcpy(TDE2166_Track2_Data, TDE_pnt + 4, sizeof(journal_output_rec.jrnl_body.TDE2166_Track2_Data));
                    memcpy(journal_output_rec.jrnl_body.TDE2166_Track2_Data, TDE_pnt + 4, sizeof(journal_output_rec.jrnl_body.TDE2166_Track2_Data));
                  }
                  else{
                    memcpy(TDE2166_Track2_Data, TDE_pnt + 4, Temp_length - 4);
                    memcpy(journal_output_rec.jrnl_body.TDE2166_Track2_Data, TDE_pnt + 4, Temp_length - 4);
                  }

                  for (i = 0; i < Temp_length; i++)
                  {
                     if (TDE2166_Track2_Data[i] == 'D' || TDE2166_Track2_Data[i] == '=')
                     {
                        memcpy(F40_TRACK2_EXP_DATE, &TDE2166_Track2_Data[i + 1], sizeof(F40_TRACK2_EXP_DATE) - 1);

                        break;
                     }
                  }

                  break;

               case 2177:

                  memset(TDE2177_Track2_Exp_Date, 0, sizeof(TDE2177_Track2_Exp_Date));
                  memcpy(TDE2177_Track2_Exp_Date, TDE_pnt, 6);
                  memcpy(journal_output_rec.jrnl_body.TDE2177_Track2_Exp_Date, TDE_pnt, 6);

                  if (TDE2166_Track2_Flag != 1)
                  {
                     memcpy(F40_TRACK2_EXP_DATE, TDE2177_Track2_Exp_Date, sizeof(F40_TRACK2_EXP_DATE) - 1);

                  }
                  break;

               case 2183:
                  memset(&F30_RETL_SIC_CDE, 0, sizeof(F30_RETL_SIC_CDE));
                  memset(char_F30_RETL_SIC_CDE, 0, sizeof(char_F30_RETL_SIC_CDE));
                  memcpy(&F30_RETL_SIC_CDE, TDE_pnt, 4);
                  memcpy(char_F30_RETL_SIC_CDE, TDE_pnt, 4);
                  memcpy(journal_output_rec.jrnl_body.OGG_TDE2183_F30_RETL_SIC_CDE, TDE_pnt, 4);
                  break;

               case 2242:

                  memset(F38_TERM_LN, 0, sizeof(F38_TERM_LN));
                  memcpy(F38_TERM_LN, TDE_pnt, 16);
                  memcpy(journal_output_rec.jrnl_body.TDE2242_F38_TERM_LN, TDE_pnt, 16);

                  break;

               case 2359:
                  memset(WK_PRODUCT_IND, 0, sizeof(WK_PRODUCT_IND));
                  memcpy(WK_PRODUCT_IND, TDE_pnt + 7, 2);
                  memcpy(journal_output_rec.jrnl_body.OGG_TDE2359_WK_PRODUCT_IND, TDE_pnt + 7, 2);
                  break;

               case 2921:
               {

                  /* i: TDE Context Data Length */
                  i = 0;

                  /* Account Status */
                  i += (TDE_pnt[i] != 0x00) ? 2 : 1;

                  /* Network Generated Token Issuer ID */
                  i += (TDE_pnt[i] != 0x00) ? 3 : 1;

                  /* PAN Account Range */
                  if (TDE_pnt[i] != 0x00)
                  {
                     memcpy(&Temp_length, &TDE_pnt[i + 1], 4);
                     i += (Temp_length + 5);
                  }
                  else
                  {
                     i += 1;
                  }

                  /* Last 4 digits of PAN */
                  i += (TDE_pnt[i] != 0x00) ? 5 : 1;

                  /* Token Data */
                  if (TDE_pnt[i] != 0x00)
                  {
                     memcpy(&Temp_length, &TDE_pnt[i + 1], 4);
                     PAN_TKN_DATA = (char *)realloc(PAN_TKN_DATA, (Temp_length + 1) * sizeof(char));
                     memcpy(PAN_TKN_DATA, &TDE_pnt[i + 5], Temp_length);
                     if (Temp_length> sizeof(journal_output_rec.jrnl_body.TDE2921_PAN_TKN_DATA))
                       memcpy(journal_output_rec.jrnl_body.TDE2921_PAN_TKN_DATA, &TDE_pnt[i + 5], sizeof(journal_output_rec.jrnl_body.TDE2921_PAN_TKN_DATA));
                     else
                       memcpy(journal_output_rec.jrnl_body.TDE2921_PAN_TKN_DATA, &TDE_pnt[i + 5], Temp_length);

                     i += (Temp_length + 5);
                  }
                  else
                  {
                     i += 1;
                  }

                  /* Token Assurance Leve */
                  if (TDE_pnt[i] != 0x00)
                  {
                     memcpy(&Temp_length, &TDE_pnt[i + 1], 4);
                     i += (Temp_length + 5);
                  }
                  else
                  {
                     i += 1;
                  }

                  /* Token Requester */
                  if (TDE_pnt[i] != 0x00)
                  {
                     memcpy(&Temp_length, &TDE_pnt[i + 1], 4);
                     TKN_REQ_ID = (char *)realloc(TKN_REQ_ID, (Temp_length + 1) * sizeof(char));
                     memcpy(TKN_REQ_ID, &TDE_pnt[i + 5], Temp_length);
                     if(Temp_length> sizeof(journal_output_rec.jrnl_body.TDE2921_TKN_REQ_ID))
                       memcpy(journal_output_rec.jrnl_body.TDE2921_TKN_REQ_ID, & TDE_pnt[i + 5], sizeof(journal_output_rec.jrnl_body.TDE2921_TKN_REQ_ID));
                     else
                       memcpy(journal_output_rec.jrnl_body.TDE2921_TKN_REQ_ID, & TDE_pnt[i + 5], Temp_length);
                     i += (Temp_length + 5);
                  }
                  else
                  {
                     i += 1;
                  }

                  /* Action Indicator */
                  i += (TDE_pnt[i] != 0x00) ? 2 : 1;

                  /* Replacement PAN Expiration Date */
                  i += (TDE_pnt[i] != 0x00) ? 5 : 1;

                  /* Token Status */
                  if (TDE_pnt[i] != 0x00)
                  {
                     memset(&TKN_STATUS, 0, sizeof(TKN_STATUS));
                     memcpy(&TKN_STATUS, &TDE_pnt[i + 1], 1);
                     memcpy(&journal_output_rec.jrnl_body.TDE2921_TKN_STATUS, &TDE_pnt[i + 2], 1);
                     i += 2;
                  }
                  else
                  {
                     i += 1;
                  }

                  /* TLV Data */
                  /*while(i < length){
                     memcpy(&Temp_length, &TDE_pnt[i + 1], 4);
                  }*/
                  if (i < length - 12)
                  {
                     memcpy(&Temp_length, &TDE_pnt[i], 4);
                     TDE2921_TLV_DATA = (char *)realloc(TDE2921_TLV_DATA, (Temp_length + 1) * sizeof(char));
                     memcpy(TDE2921_TLV_DATA, &TDE_pnt[i + 4], Temp_length);
                     if(Temp_length>sizeof(journal_output_rec.jrnl_body.TDE2921_TLV_DATA))
                       memcpy(journal_output_rec.jrnl_body.TDE2921_TLV_DATA, &TDE_pnt[i + 4], sizeof(journal_output_rec.jrnl_body.TDE2921_TLV_DATA));
                     else
                       memcpy(journal_output_rec.jrnl_body.TDE2921_TLV_DATA, &TDE_pnt[i + 4], Temp_length);
                  }
               }
               break;

            default:
               break;
            }
            index = read_tde_length;

            /*index += (12 + read_tde_length); error_version*/
         }
      }
   }else
   {
      memcpy((char *)&journal_rec.sis_tbl_ver, &recbuf[0], (rq->record_len));
   }
         return (EXIT_OK_VAL);
} /* USEREXIT_processrecord */

/*---------------------------------------------------------------------------*
 *                                                                           *
 *---------------------------------------------------------------------------*/
short USEREXIT_discardrecord(exit_params_def *rq, exit_rec_buf_def recbuf)
{
   return (EXIT_OK_VAL);
} /* USEREXIT_discardrecord */

/*---------------------------------------------------------------------------*
 *                                                                           *
 *---------------------------------------------------------------------------*/
short USEREXIT_fileclose(exit_params_def *rq)
{
   return (EXIT_OK_VAL);
} /* USEREXIT_fileclose */

/*---------------------------------------------------------------------------*
 *                                                                           *
 *---------------------------------------------------------------------------*/
short USEREXIT_stop(exit_params_def *rq)
{
   /* close files open by the user exit */

   /* release any malloc'd buffers      */

   sprintf(g.msg, "USEREXIT Termination");
   GGS_REPORTMESSAGE(g.msg);
   GGS_EMSMESSAGE(17000, g.msg, MSG_INFO);

   return (EXIT_OK_VAL);
} /* USEREXIT_stop */

/*---------------------------------------------------------------------------*
 * Called before extract/replicat dynamically unload a userexit DLL          *
 *---------------------------------------------------------------------------*/
short USEREXIT_dllunload(exit_params_def *rq)
{
   /* close files open by the user exit */

   /* release any malloc'd buffers      */

   /* if the user exit cannot be unloaded then return IGNORE */
   /* and replicat/extract will fail the DLL unload          */
   /* return(EXIT_IGNORE_VAL);                               */

   return (EXIT_OK_VAL);
} /* UUSEREXIT_dllunload */

/*---------------------------------------------------------------------------*
 *                                                                           *
 *---------------------------------------------------------------------------*/
void cuserexit(exit_call_type_def exit_call_type,
               exit_result_def *exit_call_result,
               exit_params_def *exit_params,
               exit_rec_buf_def exit_rec_buf)
{
   short erc;

   switch (exit_call_type)
   {
   case EXIT_CALL_START: /* 1 */
      erc = USEREXIT_start(exit_params);
      break;

   case EXIT_CALL_BEGIN_TRANS: /* 2 */
      erc = USEREXIT_begintrans(exit_params);
      break;

   case EXIT_CALL_PROCESS_RECORD: /* 3 */
      if (!memcmp(&exit_params->function_param[0], "AU", 2))
      {
         erc = AUTH_processrecord(exit_params, exit_rec_buf);
      }
      else if (!memcmp(&exit_params->function_param[0], "JRNL", 4))
      {
         strcpy(cont_file_ctl_str, &exit_params->function_param[5]);
         if (cont_file_ctl == -1)
         {
            error = FILE_OPEN_(cont_file_ctl_str, (short)strlen(cont_file_ctl_str), &cont_file_ctl, access1);
            if (error != 0){
               exit(1);
            }

         }
         erc = JRNL_processrecord(exit_params, exit_rec_buf);
      }
      else
      {
         erc = USEREXIT_processrecord(exit_params, exit_rec_buf);
      }
      break;

   case EXIT_CALL_DISCARD_RECORD: /* 4 */
      erc = USEREXIT_discardrecord(exit_params, exit_rec_buf);
      break;

   case EXIT_CALL_END_TRANS: /* 5 */
      erc = USEREXIT_endtrans(exit_params);
      break;

   case EXIT_CALL_STOP: /* 6 */
      erc = USEREXIT_stop(exit_params);
      break;

   case EXIT_CALL_FILE_CLOSE: /* 7 */
      erc = USEREXIT_fileclose(exit_params);
      break;

   case EXIT_CALL_DLL_UNLOAD: /* 8 */
      erc = USEREXIT_dllunload(exit_params);
      break;

   default:
      erc = EXIT_OK_VAL;
      USEREXIT_VPROC();
      break;
   } /* switch */

   *exit_call_result = erc;
   return;
} /* cuserexit */
