void main() {
  asm{

  bsf status, RP0 // go to bank1
  movlw 0x00
  movwf TRISB // set port B as output
  bcf status, RP0 // Bank 0
  clrf PORTB // clear port B


  
  main:
       movwf PORTB
       call Delay
       goto main
  

  Delay:
        movlw 0xFA
        movwf 0x25
        loop_1:
               movlw 0xFA
               movwf 0x26
               loop_2:
                      NOP
                      NOP
                      NOP
                      NOP
                      NOP
                      DECFSZ 0x26,1
                      goto loop_2
               DECFSZ 0x25,1
               goto loop_1
               comf PORTB , 0
               return main
  
  
  }
}
