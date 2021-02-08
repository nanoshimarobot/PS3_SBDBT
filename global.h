#ifndef __global_h
#define	__global_h
#include <stdlib.h>
#include "GenericTypeDefs.h"
#include "HardwareProfile.h"
#include "usb_config.h"
#include "USB/usb.h"
#include "USB/usb_host_bluetooth.h"
#include "user.h"
//#include "timer.h"
//#include "TimeDelay.h"
#include "xprintf.h"

#define PIN_CODE_DEFAULT		"0000"
#define BOARD_SBDBT				     1		//SBDBT�p�r���h
#define BOARD_SBXBT				     0		//SBXBT�p�r���h
#define	BOARD_SBGRBT				 0		//SBGRBT�p�r���h

#define	FORMAT_RCB3					 1		//RCB3
#define FORMAT_RCB4					 0		//RCB4HV(RCB3HV?)
#define	FORMAT_RPU					 0		//RPU Controller Protocol

#define	USE_SPP_SERVER				 1		//SPP�T�[�o�[�Ƃ��Ă����s���ē��삳���邩
#define	USE_USB_HID_CONTROLLER		 1		//USB�ڑ��̃R���g���[���[���g��
#define	USE_WRITE_STORED_LINK_KEY	 0		//SPP�ڑ��̃����N�L�[�� 0:PIC��FLASH�ɕۑ� 1:Bluetooth�A�_�v�^�ɕۑ�
#define	DELETE_STORED_LINK_KEY		 1
#define STANDALONE_PAIRING           1		//PS3�R���g���[���ƃy�A�����O����@�\��L���� 0:���Ȃ� 1:����
#define	USE_DUALSHOCK3_RUMBLE		 1		//PS3�R���g���[���̐U���@�\��L���ɂ���('1'��M:�E���U�� '2'��M:�����U��)

// Define the baud rate constants UART1
#if	FORMAT_RCB3
	#define	UARTPARAM1			UARTPARAM_N81	//data=8bit parity=none stopbit=1bit
	#define BAUDRATE1			    115200		//UART1�{�[���[�g
	#define	FORMAT_DATALEN			   8		//�d������
#elif	FORMAT_RCB4
	#define	UARTPARAM1			UARTPARAM_E81	//data=8bit parity=Even stopbit=1bit
	#define BAUDRATE1				115200		//UART1�{�[���[�g
	#define	FORMAT_DATALEN			  13		//�d������
#elif	FORMAT_RPU
	#define	UARTPARAM1			UARTPARAM_N81	//data=8bit parity=none stopbit=1bit
	#define BAUDRATE1				115200		//UART1�{�[���[�g
	#define	FORMAT_DATALEN			   9		//�d������
#endif

#define BRG_DIV1				     4
#define BRGH1					     1

#define	UART1_HW_FLOW			     0		//UART1�n�[�h�E�F�A�t���[���� (0:�Ȃ� 1:����)
#define	UART1_TX_POLARITY			 0		//���M�M���ɐ� 0:�ʏ� 1:���]
#define	UART1_RX_POLARITY			 0		//��M�M���ɐ� 0:�ʏ� 1:���]

#define	SEND_ON_DIFFERENT_DATA		 0		//���M�^�C�~���O 0:�A�����M 1:�O��̃f�[�^�ƍ����������Ƃ��̂ݑ��M
#define	NEUTRAL_DATA_SUPPRESS		 1		//�A�����M�� �j���[�g�����ʒu�̃f�[�^�� 0:�A�����M  1:�A�����M��}������

#define	UART1_MINIMUM_INTERVAL		20		//�d���̎����ɐ���������ꍇ(SEND_ON_DIFFERENT_DATA=0�̏ꍇ) 0:�Ȃ� 1�ȏ�:1�d��������̍Œ᎞��(ms)
#define	NEUTRAL_ADDITIONAL_PACKETS	 0		//�j���[�g�����ʒu�̃f�[�^�̂ݒǉ��ő��M����p�P�b�g�� 0:�ǉ��Ȃ� 1�ȏ�:�ǉ��p�P�b�g��

#define	USE_STICK_FOR_DIGITAL		 0		//�X�e�B�b�N���͂� 0:�A�i���O�I�Ɉ���  1:�f�W�^���I�Ɉ���
#define	STICK_DEADZONE				15 
//���S����v���}�C�����܂ł��j���[�g�����Ƃ��Ĉ������̂������l
#define STICK_RESOLUTION			 0		//�L���͈́F2-64,0:�����s,1:�Ӗ��Ȃ�
#define STICK_MINIMUM_VALUE			 0		//�X�e�B�b�N�̍ŏ��l�F(0:���g�p) 1-:�l��0�ɂȂ����ꍇ�̌듮���������?
//#define STICK_MAXIMUM_VALUE		   127		//�X�e�B�b�N�̍ő�l:�ő�l���N���b�v / �f�W�^���I�Ɉ����ꍇ�̒l
#define STICK_MAXIMUM_VALUE		   255		//�X�e�B�b�N�̍ő�l:�ő�l���N���b�v / �f�W�^���I�Ɉ����ꍇ�̒l
//#define STICK_NUTRAL_VALUE			64		//�X�e�B�b�N�̒����l
#define STICK_NUTRAL_VALUE		   128		//�X�e�B�b�N�̒����l

// Define the baud rate constants UART2 (Debug)
#define BAUDRATE2				115200		//UART2�{�[���[�g(�f�o�b�O�p)
#define BRG_DIV2				     4
#define BRGH2       		         1

// Define LED1 communication indicator on time(ms)
#define	LED1_ON_COUNT				10			//�ԐFLED�_������(ms)

//#define	USB_ACL_MINIMUM_INTERVAL   250
#define	USB_ACL_MINIMUM_INTERVAL     0

#if	BOARD_SBDBT
#define LOCAL_NAME				"SBDBT"		//Bluetooth���������O(SBDBT�̏ꍇ)
#define	ICSDEF					ICS_PGx1
#endif

#if BOARD_SBXBT
#define LOCAL_NAME				"SBXBT"		//Bluetooth���������O(SBXBT�̏ꍇ)
#define	ICSDEF					ICS_PGx1	//SBXBC���g�p���f�o�b�O�ݒ�
#endif

#if	BOARD_SBGRBT
#define LOCAL_NAME				"SBGRBT"	//Bluetooth���������O(SBGRBT�̏ꍇ)
#define	ICSDEF					ICS_PGx1
#endif

#ifdef	__DEBUG
//disable watchdog timer
#define	FWDTENDEF				FWDTEN_OFF
#define	RestartWatchdog()
#define STO_SERIAL				1   //0:STO as I/O  1:STO as serial output
#else
//enable watchdog timer
#define	FWDTENDEF				FWDTEN_ON
#define	RestartWatchdog()		ClrWdt()
#define STO_SERIAL			0   //0:STO as I/O  1:STO as serial output
#endif


#if	BOARD_SBDBT
//
//for SBDBT board
//
// Configure LED1 - put on pin 14 (RB14)
#define	led1_setup()		(TRISBbits.TRISB14=0)
#define	led1_on()			(LATBbits.LATB14=0)	//ON
#define	led1_off()			(LATBbits.LATB14=1)	//OFF

// Configure LED2 - put on pin 15 (RB15)
#define	led2_setup()		(TRISBbits.TRISB15=0)
#define	led2_on()			(LATBbits.LATB15=0)	//ON
#define	led2_off()			(LATBbits.LATB15=1)	//OFF

// Configure U1RX - put on pin 3 (RP23)
#define	u1rx_setup()		(RPINR18bits.U1RXR = 23)
// Configure U1TX - put on pin 2 (RP22)
#define u1tx_setup()		(RPOR11bits.RP22R = 3)
// Configure U1CTS - put on pin 4 (RP24)
#define	u1cts_setup()		(RPINR18bits.U1CTSR = 24)
// Configure U1RTS - put on pin 5 (RC9)
// U1RTS has software control
#define	u1rts_setup()		(TRISCbits.TRISC9=0)
#define	u1rts_on()			(LATCbits.LATC9=0)	//ON:rx ready
#define	u1rts_off()			(LATCbits.LATC9=1)	//OFF:rx not ready

#if	STO_SERIAL
// Configure console OUT(U2TX) - put on pin 1 (RP9)
#define	sto_setup()			(RPOR4bits.RP9R = 5)
#define	sto_l()
#define	sto_h()
#else
// Configure Status OUT - put on pin 1 (RB9)
#define	sto_setup()		(TRISBbits.TRISB9=0)
#define	sto_l()			(LATBbits.LATB9=0)
#define	sto_h()			(LATBbits.LATB9=1)
#endif

// no association out on this board
#define	assoc_setup()
#define	assoc_l()
#define	assoc_h()

// no on out on this board
#define	on_setup()
#define	pairen_setup()
#define	get_pairen()		(1)

#elif BOARD_SBXBT
//
// for SBXBT board
//
// Configure LED1 - put on pin 14 (RB14)
#define	led1_setup()			(TRISBbits.TRISB15=0)
#define	led1_on()				(LATBbits.LATB15=0)	//ON
#define	led1_off()				(LATBbits.LATB15=1)	//OFF

// Configure LED2 - put on pin 15 (RB15)
#define	led2_setup()			(TRISBbits.TRISB14=0)
#define	led2_on()				(LATBbits.LATB14=0)	//ON
#define	led2_off()				(LATBbits.LATB14=1)	//OFF

// Configure U1RX - put on pin 3 (RP23)
#define	u1rx_setup()		(RPINR18bits.U1RXR = 23)
// Configure U1TX - put on pin 2 (RP22)
#define u1tx_setup()		(RPOR11bits.RP22R = 3)
// Configure U1CTS - put on pin 4 (RP24)
#define	u1cts_setup()		(RPINR18bits.U1CTSR = 24)
// Configure U1RTS - put on pin 5 (RC9)
// U1RTS has software control
#define	u1rts_setup()		(TRISCbits.TRISC9=0)
#define	u1rts_on()			(LATCbits.LATC9=0)	//ON:rx ready
#define	u1rts_off()			(LATCbits.LATC9=1)	//OFF:rx not ready

#if	STO_SERIAL
// Configure console OUT(U2TX) - put on pin 37 (RP20)
#define	sto_setup()			(RPOR10bits.RP20R = 5)
#define	sto_l()
#define	sto_h()
#else
// Configure RSSI(status) OUT - put on pin 37 (RC4)
#define	sto_setup()			(TRISCbits.TRISC4=0)
#define	sto_l()				(LATCbits.LATC4=0)
#define	sto_h()				(LATCbits.LATC4=1)
#endif

// Configure Association OUT - put on pin 20 (RA1)
#define	assoc_setup()		(TRISAbits.TRISA1=0)
#define	assoc_l()			(LATAbits.LATA1=0)
#define	assoc_h()			(LATAbits.LATA1=1)

// Configure ON OUT - put on pin 44 (RB8)
#define	on_setup()			{TRISBbits.TRISB8=0; LATBbits.LATB8=1;}
#define	pairen_setup()
#define	get_pairen()		(1)

#else

//
//for SBGRBT board
//
// Configure LED1 - put on pin 14 (RB14)
#define	led1_setup()		(TRISBbits.TRISB14=0)
#define	led1_on()			(LATBbits.LATB14=0)	//ON
#define	led1_off()			(LATBbits.LATB14=1)	//OFF

// Configure LED2 - put on pin 15 (RB15)
#define	led2_setup()		(TRISBbits.TRISB15=0)
#define	led2_on()			(LATBbits.LATB15=0)	//ON
#define	led2_off()			(LATBbits.LATB15=1)	//OFF

// Configure U1RX - put on pin 3 (RP23)
#define	u1rx_setup()		(RPINR18bits.U1RXR = 23)
// Configure U1TX - put on pin 2 (RP22)
#define u1tx_setup()		(RPOR11bits.RP22R = 3)
// Configure U1CTS - put on pin 4 (RP24)
#define	u1cts_setup()		(RPINR18bits.U1CTSR = 24)
// Configure U1RTS - put on pin 5 (RC9)
// U1RTS has software control
#define	u1rts_setup()		(TRISCbits.TRISC9=0)
#define	u1rts_on()			(LATCbits.LATC9=0)	//ON:rx ready
#define	u1rts_off()			(LATCbits.LATC9=1)	//OFF:rx not ready

// no sto on this board
#define	sto_setup()
#define	sto_l()
#define	sto_h()

// no association out on this board
#define	assoc_setup()
#define	assoc_l()
#define	assoc_h()

// no on out on this board
#define	on_setup()

// Configure Pairing Enable Jumper - on pin 1 (RB9, CN21)
#define	pairen_setup()		{CNPU2bits.CN21PUE=1;}
#define	get_pairen()		(!PORTBbits.RB9)

#endif



/*
�o�͓d���t�H�[�}�b�g

RCB-3: 80
RCB-4: 0D 00 02 50 03 00: Checksum=0x62

��: 80 00 01 40 40 40 40 01
��: 80 00 02 40 40 40 40 02
��: 80 00 04 40 40 40 40 04
��: 80 00 08 40 40 40 40 08
��: 80 00 10 40 40 40 40 10
�~: 80 00 20 40 40 40 40 20
��: 80 00 40 40 40 40 40 40
��: 80 01 00 40 40 40 40 01
L1: 80 02 00 40 40 40 40 02
L2: 80 04 00 40 40 40 40 04
R1: 80 08 00 40 40 40 40 08
R2: 80 10 00 40 40 40 40 10

(Start): 80 00 03 40 40 40 40 03
(Select): 80 00 0C 40 40 40 40 0C

���A�i���O���E: 80 00 00 XX 40 40 40 XX
���A�i���O�㉺: 80 00 00 40 XX 40 40 XX
�E�A�i���O���E: 80 00 00 40 40 XX 40 XX
�E�A�i���O�㉺: 80 00 00 40 40 40 XX XX
*/

#if	FORMAT_RPU
#define	OUT_DIGITAL_TRIANGLE	0x0010
#define	OUT_DIGITAL_CIRCLE		0x0020
#define	OUT_DIGITAL_CROSS		0x0040
#define	OUT_DIGITAL_RECTANGLE	0x0080
#define	OUT_DIGITAL_R1			0x0008
#define	OUT_DIGITAL_R2			0x0002
#define	OUT_DIGITAL_R3			0x0400
#define	OUT_DIGITAL_L1			0x0004
#define	OUT_DIGITAL_L2			0x0001
#define	OUT_DIGITAL_L3			0x0200
#define	OUT_DIGITAL_SELECT		0x0100
#define	OUT_DIGITAL_START		0x0800
#define	OUT_DIGITAL_UP			0x1000
#define	OUT_DIGITAL_DOWN		0x4000
#define	OUT_DIGITAL_LEFT		0x8000
#define	OUT_DIGITAL_RIGHT		0x2000
#define	OUT_DIGITAL_PS			0x0000
#else
#define	PS3_OUT_DIGITAL_UP			0x01
#define	PS3_OUT_DIGITAL_LEFT		0x02
#define	PS3_OUT_DIGITAL_DOWN		0x04
#define	PS3_OUT_DIGITAL_RIGHT		0x08
#define	PS3_OUT_DIGITAL_L1      	0x10
#define	PS3_OUT_DIGITAL_SELECT		0x20
#define PS3_OUT_DIGITAL_L3          0x40

#define PS3_OUT_DIGITAL_TRIANGLE    0x01
#define PS3_OUT_DIGITAL_SQUARE      0x02
#define PS3_OUT_DIGITAL_CROSS       0x04
#define PS3_OUT_DIGITAL_CIRCLE      0x08
#define PS3_OUT_DIGITAL_R1          0x10
#define PS3_OUT_DIGITAL_START       0x20
#define PS3_OUT_DIGITAL_R3          0x40

/*unused*/
#define	OUT_DIGITAL_UP			0x01
#define	OUT_DIGITAL_LEFT		0x02
#define	OUT_DIGITAL_DOWN		0x04
#define	OUT_DIGITAL_RIGHT		0x08
#define	OUT_DIGITAL_L1      	0x10
#define	OUT_DIGITAL_SELECT		0x20
#define OUT_DIGITAL_TRIANGLE    0x01
#define OUT_DIGITAL_SQUARE      0x02
#define OUT_DIGITAL_CROSS       0x04
#define OUT_DIGITAL_CIRCLE      0x08
#define OUT_DIGITAL_R1          0x10
#define OUT_DIGITAL_START       0x20
#define OUT_DIGITAL_RECTANGLE   0x0100
#define OUT_DIGITAL_R2          0x1000
#define OUT_DIGITAL_L2          0x0400
#define	OUT_DIGITAL_L3			0x0000
#define	OUT_DIGITAL_R3			0x0000
#define	OUT_DIGITAL_PS			0x0000
/*------*/

#endif

#define HID_BUFFERSIZE              50 // size of the buffer for the Playstation Motion Controller
#define OUTPUT_REPORT_BUFFER_SIZE   48 //Size of the output report buffer for the controllers

extern const BYTE OUTPUT_REPORT_BUFFER[];

typedef unsigned clock_t;
#define Nop()    __builtin_nop()
#ifndef ClrWdt
#define ClrWdt() {__asm__ volatile ("clrwdt");}
#endif
#ifndef Sleep
#define Sleep()  {__asm__ volatile ("pwrsav #0");}
#endif
#ifndef Idle
#define Idle()   {__asm__ volatile ("pwrsav #1");}
#endif

typedef enum
{
    CONTROLLER_INITIALIZE = 0,
    CONTROLLER_STATE_GET_DATA,
    CONTROLLER_STATE_GET_DATA_WAIT,
    CONTROLLER_STATE_ERROR

} GENERAL_CONTROLLER_STATE;

#if STANDALONE_PAIRING
void save_local_bluetooth_address(BYTE address[6]);
BOOL read_local_bluetooth_address(BYTE address[6]);
BOOL Check_saved_local_bluetooth_address(BYTE address[6]);
#endif

extern WORD sixaxis_button_state;
extern BYTE sixaxis_button_state1;
extern BYTE sixaxis_button_state2;
extern BYTE sixaxis_lx;
extern BYTE sixaxis_ly;
extern BYTE sixaxis_rx;
extern BYTE sixaxis_ry;
extern BYTE sixaxis_l2;
extern BYTE sixaxis_r2;
extern BYTE deviceAddress;  // Address of the device on the USB
extern WORD	sixaxis_control_channel_id;
extern char	lineBuffer[];


extern void (*usb_tick_handler)(void);
void	event_bluetooth_rxEvent_done(WORD size);
void	event_bluetooth_rxAcl_done(WORD size);
clock_t clock(void);

void sixaxis_process_packet(BYTE *hid_report,WORD size);
void out_button_state(void);
void dev_elecom_u3312s(void);
void dev_elecom_u3412s(void);
void dev_dragonrise(void);
void dev_logicool_f510(void);
void dev_logicool_f710(void);
void dev_sony_ps3(void);
#endif
