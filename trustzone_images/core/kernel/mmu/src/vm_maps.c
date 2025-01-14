#include "vm_mm.h"
#include "hyp_target.h"

// Static memory regions for virtual machines
VMMM_attr_t vm_0_mem_regions [] = 
{
    /* Till start RPM MSG RAM */
    {0x0000, 0x0000, 0x60000 - 0x0000, VMMM_PERM_RW,  
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1}, 

    /* Map "RPM_MSG_RAM". Permission RW */
    {0x60000, 0x60000, 0x61000 - 0x60000, VMMM_PERM_RW,  
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},
    
    /* Map "RPM_MSG_RAM". Permission RO */
    {0x61000, 0x61000, 0x66000 - 0x61000, VMMM_PERM_R,
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},
  
    /* End of RPM MSG RAM - Start of BIMC. Permission RW */
    {0x68000, 0x68000, 0x400000 - 0x68000, VMMM_PERM_RW,
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},
  
    /* Map "BIMC_MISC" TO "Start of BIMC_GLOBAL1". Permission RO */
    {0x400000, 0x400000, 0x401000 - 0x400000, VMMM_PERM_R,
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},

    /* Map "BIMC_GLOBAL1" TO "Start of BIMC_GLOBAL2". Permission RW */
    {0x401000, 0x401000, 0x402000 - 0x401000, VMMM_PERM_RW,
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},

    /* Map "BIMC_GLOBAL2" TO "Start of BIMC_M_APP_MPORT". Permission RO */
    {0x402000, 0x402000, 0x408000 - 0x402000, VMMM_PERM_R,
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},

    /* Map "BIMC_M_APP_MPORT and BIMC_M_APP_PROF". Permission RW */
    {0x408000, 0x408000, 0x40A000 - 0x408000, VMMM_PERM_RW,  
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},

    /* Map "BIMC_M_DSP_MPORT and BIMC_M_DSP_PROF". Permission RO */
    {0x40C000, 0x40C000, 0x40E000 - 0x40C000, VMMM_PERM_R,  
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},
  
   /* Map "BIMC_M_GPU_MPORT and BIMC_M_GPU_PROF". Permission RW */
    {0x410000, 0x410000, 0x412000 - 0x410000, VMMM_PERM_RW,  
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},

   /* Map "BIMC_M_SYS0_MPORT" TO "End of BIMC_M_SYS1_PROF". Permission RW */
    {0x414000, 0x414000, 0x41A000 - 0x414000, VMMM_PERM_RW,  
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},

    /* Map "BIMC_M_TCU0_MPORT" TO "End of BIMC_M_TCU1_PROF". Permission RW */
    {0x41C000, 0x41C000, 0x422000 - 0x41C000, VMMM_PERM_RW,  
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},

   /* Map "BIMC_S_DDR0_SCMO" TO "End of BIMC_S_DEFAULT_ARB". Permission RO */
   {0x448000, 0x448000, 0x462000 - 0x448000, VMMM_PERM_R,  
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},

    /* End of BIMC - Start of SMMU TCU. Permission RW  */
    {0x480000, 0x480000, 0x01E00000 - 0x480000, VMMM_PERM_RW,  
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},

    /* SMMU TCU */  
    {0x01E00000, 0x01E00000, 0x01E20000 - 0x01E00000, VMMM_PERM_R,  
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},
  
    {0x01E22000, 0x01E22000, 0x01E30000 - 0x01E22000, VMMM_PERM_RW,  
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},
  
    {0x01E38000, 0x01E38000, 0x01E40000 - 0x01E38000, VMMM_PERM_RW,  
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},
  
    {0x01EF2000, 0x01EF2000, 0x01EF3000 - 0x01EF2000, VMMM_PERM_RW,   
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},
      
    {0x01F00000, 0x01F00000, 0x01F08000 - 0x01F00000, VMMM_PERM_R,  
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},

    {0x01F09000, 0x01F09000, 0x01F0C000 - 0x01F09000, VMMM_PERM_RW,  
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},

    /* PMIC_ARB - Start of DDR. Permission RW */  
    {0x02000000, 0x02000000, 0x80000000 - 0x02000000, VMMM_PERM_RW,  
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},

    /* DDR start to HYP start */
    {0x80000000, 0x80000000, 0x86400000 - 0x80000000, VMMM_PERM_RWX,   
      VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1}, 
    /* HYP start + 2MB to ADDR Map top */
    {HYP_MEMORY_ADDR + 0x200000, HYP_MEMORY_ADDR + 0x200000, 0x100000000 - (HYP_MEMORY_ADDR + 0x200000), 
     VMMM_PERM_RWX, VMMM_CACHE_USE_STAGE1, VMMM_SHARE_USE_STAGE1},
};
   
VMMM_attr_t *vm_map_table[VMMM_MAX_CONTEXT_NUM] = 
{
   vm_0_mem_regions
};

// Number of static memory regions for virtual machines
unsigned int vm_map_table_length[VMMM_MAX_CONTEXT_NUM] = 
{
   sizeof(vm_0_mem_regions)/sizeof(vm_0_mem_regions[0]),
};
