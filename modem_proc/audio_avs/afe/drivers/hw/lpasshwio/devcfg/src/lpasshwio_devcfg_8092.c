#include "lpasshwio_devcfg.h"

HwdLpassPropertyType lpass_prop ={0xFE04F000};
HwdAudioIfPropertyType audioif_prop = {0xFE140000, (128*1024), 0xFD922000, 
   (4*1024), 4, 5, 4, 9, {0,1,2,3,4,5,6,7,8}, {4,4,4,4,4,8,2,8,4}, {3,3,3,3,3,3,1,1,2}, 19, 2, 0x30040000, 0};
HwdAvtimerPropertyType avtimer_prop = {{0xFE0C9000, 0xFE0CB000, 0xFE0CF000}, {0x1000, 0x1000, 0x1000}, {19200000, 28224000, 28224000}, 50, 0x30040001};
HwdDmlitePropertyType dmlite_prop = {0xFE0B2000, 0x1000, 23, 0x30040000};
HwdResamplerPropertyType resampler_prop = {0xFE0D0000, 0x4000, 53, 0x30040000};
lpasshwio_vfr_prop_t vfr_prop = {0xFE03C000, 0x1000, 0x30040000, 0x1, {{51, 0x0, 0x1}, {0, 0x0, 0x0}, {0, 0x0, 0x0}, {0, 0x0, 0x0}}};
lpasshwio_prop_riva_struct_t afe_riva_prop = {0, 0, 0, 0, 0, 0, 0};
lpasshwio_prop_slimbus_struct_t afe_slimbus_prop = {1};
HwdMidiPropertyType midi_prop = {0,0, 0, 0, 0,0 };
lpasshwio_prop_spdif_struct_t spdiftx_prop = {0xFE133000, 0x1000, 0xFE0B7000, 0x1000, 122, 2, 0x10000000};
lpasshwio_prop_hdmi_input_struct_t hdmi_input_prop = {0xFE134000, 0x1000, 121, 0x10000000};
