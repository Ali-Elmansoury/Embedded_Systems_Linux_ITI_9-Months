ENTRY(_start) 

SECTIONS {
    
    . = 0x00080000;

    .text : {
        *(.text*)   
        *(.rodata*) 
    }
    .data : { *(.data*) }
     . = ALIGN(4);
     _bss_start = .;
     .bss : { *(.bss* COMMON) }
     . = ALIGN(4);
     _bss_end = .;

}