/* Superfluous implementation file -- demonstrates conditional
 * complitation based on the Arduino model. */

/* An example of conditional compilation based on the device name:
 * Make the blink period twice as long when compiling on Megas.
 *
 * A more realistic use of this is with defining pins or choosing
 * SoftwareSerial over HardwareSerial, etc.
 */
#if defined(MEGA)
#define INITIAL_BLINK_PERIOD 100
#else
#define INITIAL_BLINK_PERIOD 500
#endif

extern const int blink_period = INITIAL_BLINK_PERIOD;

