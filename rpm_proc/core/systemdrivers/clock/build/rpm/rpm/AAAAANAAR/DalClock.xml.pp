#line 1 "Z:\\b\\rpm_proc\\core\\systemdrivers\\clock\\config\\DalClock.xml"

<!-- NOTE: DAL config has trouble parsing multi-line comment, so please put -->
<!--       proper comment tags on each line                                 -->
<!--                                                                        -->
<!-- Clock Driver Properties file                                           -->
<!-- Note we depend on the include path for the following directories to be -->
<!-- available to the DAL config compiler:                                  -->
<!-- "${INC_ROOT}/core/systemdrivers/hal/clk/inc",                          -->
<!-- "${INC_ROOT}/core/systemdrivers/clock/src",                            -->
<!-- "${INC_ROOT}/core/systemdrivers/clock/config"                          -->
<!-- "${INC_ROOT}/core/systemdrivers/clock/config/${CHIPSET}"               -->


<driver name="Clock">



  <device id=DALDEVICEID_CLOCK>
#line 1 "Z:\\b\\rpm_proc\\core\\systemdrivers\\clock\\config\\msm8909/ClockChipset.xml"
<!-- Clock sources -->
<props name="ClockSources" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
  SourceConfig
</props>

<!-- RPM Clocks -->
<props name="gcc_rpm_proc_fclk" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
  RPMClockConfig
</props>

<!-- System NOC Clocks -->
<props name="gcc_sys_noc_axi_clk" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
  SystemNOCClockConfig
</props>

<!-- Peripheral Config NOC Clocks -->
<props name="gcc_pcnoc_ahb_clk" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
  PCNOClockConfig
</props>

<!-- BIMC Clocks -->
<props name="gcc_bimc_clk" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
  BIMCClockConfig
</props>

<!-- BIMC GPU Clock -->
<props name="gcc_bimc_gpu_clk" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
  BIMCGPUClockConfig
</props>

<!-- APSS_TCU_ASYNC Clock -->
<props name="gcc_apss_tcu_async_clk" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
  APSSTCUASYNCClockConfig
</props>

<!-- QDSS AT Clocks -->
<props name="gcc_qdss_at_clk" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
  QDSSATClockConfig
</props>

<!-- QDSS Trace Clocks -->
<props name="gcc_qdss_traceclkin_clk" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
  QDSSTraceClockConfig
</props>

<!-- QDSS STM Clocks -->
<props name="gcc_qdss_stm_clk" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
  QDSSSTMClockConfig
</props>

<!-- QDSS TSCTR Div2 Clocks -->
<props name="gcc_qdss_tsctr_div2_clk" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
  QDSSTSCTRDiv2ClockConfig
</props>

<!-- RBCPR Clocks -->
<props name="gcc_rbcpr_clk" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
  RBCPRClockConfig
</props>

<!-- SPMI AHB Clocks -->
<props name="gcc_spmi_ahb_clk" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
  SPMIAHBClockConfig
</props>

<!-- SPMI SER Clocks -->
<props name="gcc_spmi_ser_clk" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
  SPMISERClockConfig
</props>

<!-- QPIC Clocks -->
<props name="gcc_qpic_clk" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
  QPICClockConfig
</props>

<!-- Clock Log Defaults -->
<props name="ClockLogDefaults" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
  ClockLogDefaultConfig
</props>

<!-- Clock Vreg level railway level mapping -->
<props name="ClockVregRailMap" type=DALPROP_ATTR_TYPE_STRUCT_PTR>
  ClockVregRailMapConfig
</props>

#line 27 "Z:\\b\\rpm_proc\\core\\systemdrivers\\clock\\config\\DalClock.xml"
#line 36 "Z:\\b\\rpm_proc\\core\\systemdrivers\\clock\\config\\DalClock.xml"
  </device>
</driver>

