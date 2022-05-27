void main() {
  asm{

  bsf status, RP0 // go to bank1
  movlw 0x00
  movwf TRISB // set port B as output
  bcf status, RP0 // Bank 0
  clrf PORTB // clear port B



  main:
       movlw 0x00
       movwf PORTB
       call Delay
           movlw 0b00000001
       movwf PORTB
       call Delay
              movlw 0b00000010
       movwf PORTB
       call Delay
              movlw 0b00000100
       movwf PORTB
       call Delay
              movlw 0b00001000
       movwf PORTB
       call Delay
               movlw 0b00010000
       movwf PORTB
       call Delay
               movlw 0b00100000
       movwf PORTB
       call Delay
              movlw 0b01000000
       movwf PORTB
       call Delay
                     movlw 0b10000000
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
               return


  }
}
