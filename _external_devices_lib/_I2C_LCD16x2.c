/*
 * _I2C_LCD16x2.c
 *
 *  Created on: 12 de mar de 2017
 *      Author: maike_rodrigo
 */
#include "_I2C_LCD16x2.h"
static unsigned char pcf_byte;
void lcd_send_command(unsigned char command, char operation){
    if (operation == 0){
        //PORTB &= ~(1<<RS);
        twi_write(_I2C_LCD_ADDR, (pcf_byte & ~(1<<RS)));
    }
    else{
        //PORTB |= (1<<RS);
        twi_write(_I2C_LCD_ADDR, (pcf_byte | (1<<RS)));
    }
    //4 MSB
    pcf_byte = (0b11110000 & command) | (0x0F & operation<<RS);
    twi_write(_I2C_LCD_ADDR, pcf_byte);
    lcd_pulse_enable();
    //4 LSB
    pcf_byte =((command << 4) & 0b11110000) | (0x0F & operation<<RS) ;
    twi_write(_I2C_LCD_ADDR, pcf_byte);
    lcd_pulse_enable();
    if((operation == 0) && (command<4))
    _delay_ms(2);
}

void lcd_start(){
    _delay_ms(20);

    pcf_byte = 0x00;
    twi_write(_I2C_LCD_ADDR, pcf_byte & ~(1<<RS));
    lcd_pulse_enable();

    pcf_byte = 0x03<<4;
    twi_write(_I2C_LCD_ADDR, pcf_byte);
    lcd_pulse_enable();
    _delay_ms(5);
    lcd_pulse_enable();
    _delay_us(150);
    lcd_pulse_enable();
    pcf_byte = 0x02<<4;
    twi_write(_I2C_LCD_ADDR, pcf_byte);
    lcd_pulse_enable();
    lcd_send_command(0x28, 0);
    lcd_send_command(0x08, 0);
    lcd_send_command(0x01, 0);
    lcd_send_command(0x0C, 0);
    lcd_send_command(0x80, 0);
}
void lcd_write(char *c){
    for (; *c !=0; c++) lcd_send_command(*c, 1 );
}
void lcd_write_flash(const char *c){
    for(; pgm_read_byte(&(*c))!= 0; c++) lcd_send_command(pgm_read_byte(&(*c)), 1);
}
void lcd_pulse_enable(){
    _delay_us(1);
    twi_write(_I2C_LCD_ADDR, pcf_byte | (1<<EN) );
    _delay_us(1);
    twi_write(_I2C_LCD_ADDR, pcf_byte & ~(1<<EN) ) ;
    _delay_us(45);
}
void lcd_set_cursor(unsigned char line, unsigned char colun){
    if (line == 0 && colun >= 0 && colun <=16)
    {
        lcd_send_command(0x80+colun, 0);
        }else{
        lcd_send_command(0xC0+colun, 0);
    }
}
void lcd_move_text(unsigned char direction){
    if (direction == 0){
        lcd_send_command(0x18, 0);
        }else{
        lcd_send_command(0x1C, 0);
    }
}
void lcd_enable_cursor(){
    lcd_send_command(0x0E, 0);
}
void lcd_disable_cursor(){
    lcd_send_command(0x0C, 0);
}
void lcd_return_cursor(){
    lcd_send_command(0x02, 0);
}
void lcd_cursor_mv_left(){
    lcd_send_command(0x10, 0);
}
void lcd_cursor_mv_right(){
    lcd_send_command(0x14, 0);
}
void lcd_cursor_set_type(unsigned char type){
    if (type == 0){
        lcd_send_command(0x0D, 0); // Cursor piscante
        }else{
        lcd_send_command(0x0F, 0);	// Cursor com altern���ncia
    }
}
void lcd_clear(){
    lcd_send_command(0x01, 0);
}
void identificar_numeros(unsigned int value, unsigned char *disp){
    unsigned char n;
    for (n=0; n<5;n++)
    disp[n] = 0+48;

    do
    {
        *disp = (value%10) + 48;
        value /= 10;
        disp++;
    } while (value !=0);
}



