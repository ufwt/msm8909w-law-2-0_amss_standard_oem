CLOCK_TEST_DICT = {

  0x10000: 'gcc_sys_noc_axi_clk',
  0x10000: 'gcc_tic_clk',
  0x10001: 'gcc_sys_noc_usb3_axi_clk',
  0x10002: 'gcc_sys_noc_qdss_stm_axi_clk',
  0x10003: 'gcc_sys_noc_apss_ahb_clk',
  0x10004: 'gcc_snoc_pcnoc_ahb_clk',
  0x10005: 'gcc_sys_noc_cats_clk',
  0x10006: 'gcc_sys_noc_at_clk',
  0x10007: 'gcc_sys_noc_ipa_axi_clk',
  0x10008: 'gcc_pcnoc_ahb_clk',
  0x10009: 'gcc_pcnoc_ddr_cfg_clk',
  0x1000A: 'gcc_pcnoc_rpm_ahb_clk',
  0x1000B: 'gcc_pcnoc_tic_clk',
  0x1000C: 'gcc_pcnoc_at_clk',
  0x10010: 'gcc_gp1_clk',
  0x10011: 'gcc_gp2_clk',
  0x10012: 'gcc_gp3_clk',
  0x10018: 'gcc_noc_conf_xpu_ahb_clk',
  0x10020: 'gcc_imem_axi_clk',
  0x10021: 'gcc_imem_cfg_ahb_clk',
  0x10030: 'gcc_mss_cfg_ahb_clk',
  0x10031: 'gcc_mss_q6_bimc_axi_clk',
  0x10032: 'mss_gcc_dbg_clk',
  0x10034: 'gcc_mss_mcdma_bimc_clk_src',
  0x10038: 'gcc_rpm_cfg_xpu_clk',
  0x10040: 'gcc_qdss_dap_ahb_clk',
  0x10041: 'gcc_qdss_cfg_ahb_clk',
  0x10042: 'gcc_qdss_at_clk',
  0x10043: 'gcc_qdss_etr_usb_clk',
  0x10044: 'gcc_qdss_stm_clk',
  0x10045: 'gcc_qdss_traceclkin_clk',
  0x10046: 'gcc_qdss_tsctr_div2_clk',
  0x10048: 'gcc_qdss_tsctr_div3_clk',
  0x10049: 'gcc_qdss_dap_clk',
  0x1004A: 'gcc_qdss_tsctr_div4_clk',
  0x1004B: 'gcc_qdss_tsctr_div8_clk',
  0x1004C: 'gcc_qdss_tsctr_div16_clk',
  0x10050: 'gcc_apss_tcu_clk',
  0x10055: 'gcc_mss_tbu_axi_clk',
  0x10057: 'gcc_mss_tbu_q6_axi_clk',
  0x10059: 'gcc_smmu_xpu_clk',
  0x1005B: 'gcc_smmu_cfg_clk',
  0x1005D: 'gcc_pcnoc_tbu_clk',
  0x1005F: 'gcc_smmu_cats64_clk',
  0x10068: 'gcc_sdcc1_apps_clk',
  0x10069: 'gcc_sdcc1_ahb_clk',
  0x10088: 'gcc_blsp1_ahb_clk',
  0x10089: 'gcc_blsp1_sleep_clk',
  0x1008A: 'gcc_blsp1_qup1_spi_apps_clk',
  0x1008B: 'gcc_blsp1_qup1_i2c_apps_clk',
  0x1008C: 'gcc_blsp1_uart1_apps_clk',
  0x1008D: 'gcc_blsp1_uart1_sim_clk',
  0x1008E: 'gcc_blsp1_qup2_spi_apps_clk',
  0x10090: 'gcc_blsp1_qup2_i2c_apps_clk',
  0x10091: 'gcc_blsp1_uart2_apps_clk',
  0x10092: 'gcc_blsp1_uart2_sim_clk',
  0x10093: 'gcc_blsp1_qup3_spi_apps_clk',
  0x10094: 'gcc_blsp1_qup3_i2c_apps_clk',
  0x10095: 'gcc_blsp1_uart3_apps_clk',
  0x10096: 'gcc_blsp1_uart3_sim_clk',
  0x10098: 'gcc_blsp1_qup4_spi_apps_clk',
  0x10099: 'gcc_blsp1_qup4_i2c_apps_clk',
  0x1009A: 'gcc_blsp1_uart4_apps_clk',
  0x1009B: 'gcc_blsp1_uart4_sim_clk',
  0x100C8: 'gcc_prng_xpu_cfg_ahb_clk',
  0x100C9: 'gcc_pcnoc_mpu_cfg_ahb_clk',
  0x100D0: 'gcc_pdm_ahb_clk',
  0x100D1: 'gcc_pdm_xo4_clk',
  0x100D2: 'gcc_pdm2_clk',
  0x100D8: 'gcc_prng_ahb_clk',
  0x100F0: 'gcc_tcsr_ahb_clk',
  0x100F8: 'gcc_boot_rom_ahb_clk',
  0x10100: 'gcc_msg_ram_ahb_clk',
  0x10108: 'gcc_tlmm_ahb_clk',
  0x10109: 'gcc_tlmm_clk',
  0x10110: 'gcc_mpm_ahb_clk',
  0x10118: 'gcc_rpm_proc_fclk',
  0x10119: 'gcc_rpm_proc_hclk',
  0x1011A: 'gcc_rpm_bus_ahb_clk',
  0x1011B: 'gcc_rpm_sleep_clk',
  0x1011C: 'gcc_rpm_timer_clk',
  0x10120: 'gcc_sec_ctrl_acc_clk',
  0x10121: 'gcc_sec_ctrl_ahb_clk',
  0x10122: 'gcc_sec_ctrl_clk',
  0x10123: 'gcc_sec_ctrl_sense_clk',
  0x10124: 'gcc_sec_ctrl_boot_rom_patch_clk',
  0x10128: 'gcc_spmi_ser_clk',
  0x10129: 'gcc_spmi_pcnoc_ahb_clk',
  0x1012A: 'gcc_spmi_ahb_clk',
  0x10130: 'gcc_spdm_cfg_ahb_clk',
  0x10131: 'gcc_spdm_mstr_ahb_clk',
  0x10132: 'gcc_spdm_ff_clk',
  0x10133: 'gcc_spdm_bimc_cy_clk',
  0x10134: 'gcc_spdm_snoc_cy_clk',
  0x10135: 'gcc_spdm_pcnoc_cy_clk',
  0x10136: 'gcc_spdm_rpm_cy_clk',
  0x10138: 'gcc_crypto_clk',
  0x10139: 'gcc_crypto_axi_clk',
  0x1013A: 'gcc_crypto_ahb_clk',
  0x10148: 'gcc_ahb_clk',
  0x10149: 'gcc_xo_clk',
  0x1014A: 'gcc_xo_div4_clk',
  0x1014B: 'gcc_im_sleep_clk',
  0x10150: 'gcc_bimc_xo_clk',
  0x10151: 'gcc_bimc_cfg_ahb_clk',
  0x10152: 'gcc_bimc_sleep_clk',
  0x10153: 'gcc_bimc_sysnoc_axi_clk',
  0x10154: 'gcc_bimc_clk',
  0x10155: 'gcc_bimc_apss_axi_clk',
  0x10158: 'gcc_ddr_dim_cfg_clk',
  0x1015B: 'gcc_ddr_dim_sleep_clk',
  0x1015C: 'gcc_bimc_mcdma_axi_clk',
  0x10162: 'gcc_ultaudio_pcnoc_mport_clk',
  0x10163: 'gcc_ultaudio_pcnoc_sway_clk',
  0x10168: 'gcc_apss_ahb_clk',
  0x10169: 'gcc_apss_axi_clk',
  0x1016A: 'apss_gcc_dbg_clk',
  0x10170: 'gcc_snoc_bus_timeout0_ahb_clk',
  0x10171: 'gcc_snoc_bus_timeout2_ahb_clk',
  0x10178: 'gcc_pcnoc_bus_timeout0_ahb_clk',
  0x10179: 'gcc_pcnoc_bus_timeout1_ahb_clk',
  0x1017A: 'gcc_pcnoc_bus_timeout2_ahb_clk',
  0x1017B: 'gcc_pcnoc_bus_timeout3_ahb_clk',
  0x1017C: 'gcc_pcnoc_bus_timeout4_ahb_clk',
  0x10180: 'gcc_pcnoc_bus_timeout5_ahb_clk',
  0x10181: 'gcc_pcnoc_bus_timeout6_ahb_clk',
  0x10182: 'gcc_pcnoc_bus_timeout7_ahb_clk',
  0x10183: 'gcc_pcnoc_bus_timeout8_ahb_clk',
  0x10184: 'gcc_pcnoc_bus_timeout9_ahb_clk',
  0x10188: 'gcc_dehr_clk',
  0x10190: 'gcc_rbcpr_clk',
  0x10191: 'gcc_rbcpr_ahb_clk',
  0x101A0: 'usb2_phy_gcc_atest_ulpi_0_clk',
  0x101A8: 'usb2_phy_gcc_atest_ulpi_1_clk',
  0x101B0: 'gcc_ultaudio_ahbfabric_ixfabric_clk',
  0x101B1: 'gcc_ultaudio_ahbfabric_ixfabric_lpm_clk',
  0x101B2: 'gcc_ultaudio_lpaif_pri_i2s_clk',
  0x101B3: 'gcc_ultaudio_lpaif_sec_i2s_clk',
  0x101B4: 'gcc_ultaudio_lpaif_aux_i2s_clk',
  0x101B5: 'gcc_ultaudio_lpaif_slimbus_bam_clk',
  0x101B6: 'gcc_ultaudio_lpaif_ext_i2s_clk',
  0x101B7: 'gcc_ultaudio_lpaif_slimbus_core_clk',
  0x101C8: 'mpm_gcc_temp_sensor_ringosc_clk',
  0x101D0: 'apss_gcc_ringosc_clk',
  0x101E0: 'gcc_dcd_xo_clk',
  0x10201: 'gcc_ipa_tbu_clk',
  0x10203: 'gcc_usb3_axi_tbu_clk',
  0x10204: 'gcc_pcie_axi_tbu_clk',
  0x10205: 'gcc_mss_tbu_mcdma_axi_clk',
  0x10208: 'pcie_pipe_clk',
  0x10210: 'usb3_phy_wrapper_gcc_usb3_pipe_clk',
  0x10218: 'gcc_ipa_clk',
  0x10219: 'gcc_ipa_ahb_clk',
  0x1021A: 'gcc_ipa_sleep_clk',
  0x10220: 'gcc_qpic_clk',
  0x10221: 'gcc_qpic_ahb_clk',
  0x10222: 'gcc_qpic_system_clk',
  0x10230: 'gcc_usb30_master_clk',
  0x10231: 'gcc_usb30_sleep_clk',
  0x10232: 'gcc_usb30_mock_utmi_clk',
  0x10233: 'gcc_usb_phy_cfg_ahb_clk',
  0x10234: 'gcc_usb3_pipe_clk',
  0x10235: 'gcc_usb3_aux_clk',
  0x10238: 'gcc_pcie_cfg_ahb_clk',
  0x10239: 'gcc_pcie_pipe_clk',
  0x1023A: 'gcc_pcie_axi_clk',
  0x1023B: 'gcc_pcie_sleep_clk',
  0x1023C: 'gcc_pcie_axi_mstr_clk',
  0x10240: 'gcc_rbcpr_mx_clk',
  0x10241: 'gcc_rbcpr_mx_ahb_clk',
  0x10248: 'usb_hspw_clk_480m_test',
  0x10250: 'usb2_phy_wrapper_gcc_usb30_utmi_clk',
  0x10260: 'gcc_ultaudio_lpaif_pcm_dataoe_clk',
  0x10261: 'gcc_ultaudio_lpaif_aux_pcm_dataoe_clk',
  0x10262: 'gcc_ultaudio_avsync_xo_clk',
  0x10263: 'gcc_ultaudio_ahbfabric_efabric_spdm_clk',
  0x10268: 'gcc_ddr_voltage_droop_gpll0_clk',
  0x30041: 'clk_src_bit_coxm_mnd',
  0x30042: 'clk_src_rbcpr_ref',
  0x30043: 'clk_bit_coxm',
  0x30044: 'clk_rbcpr_ref',
  0x30049: 'clk_bus_config',
  0x3004A: 'clk_bus_pll_outctrl',
  0x3004B: 'clk_bus_rbcpr',
  0x3004C: 'clk_bus_coxm',
  0x3004D: 'clk_bus_crypto',
  0x3004E: 'clk_bus_mgpi',
  0x3004F: 'clk_bus_mvc',
  0x30051: 'clk_bus_stmr',
  0x30052: 'clk_bus_slave_timeout',
  0x30053: 'clk_bus_uim0',
  0x30054: 'clk_bus_uim1',
  0x30055: 'clk_bus_uim2',
  0x30056: 'clk_bus_uim3',
  0x30057: 'clk_src_uim',
  0x3005A: 'clk_src_uim0_mnd',
  0x3005B: 'clk_src_uim1_mnd',
  0x3005C: 'clk_src_uim2_mnd',
  0x3005D: 'clk_src_uim3_mnd',
  0x3005E: 'clk_card_src_uim0',
  0x3005F: 'clk_card_src_uim1',
  0x30061: 'clk_card_src_uim2',
  0x30062: 'clk_card_src_uim3',
  0x30063: 'clk_uart_bit_uim0',
  0x30064: 'clk_uart_bit_uim1',
  0x30065: 'clk_uart_bit_uim2',
  0x30066: 'clk_uart_bit_uim3',
  0x30077: 'clk_bus_rfc',
  0x30100: 'clk_src_bus_mss_config',
  0x30140: 'clk_xo',
  0x30180: 'clk_bus_q6',
  0x301C0: 'clk_axi_mnoc',
  0x30240: 'clk_xo_mdm',
  0x30280: 'clk_axi_dbg',
  0x302C0: 'clk_bus_nav',
  0x30300: 'clk_axi_nav',
  0x30340: 'clk_xo_nav',

}

