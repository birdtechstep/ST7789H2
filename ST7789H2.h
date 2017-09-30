/******************************************************************
  This is our library for the Adafruit ILI9341 Breakout and Shield
  ----> http://www.adafruit.com/products/1651

  Check out the links above for our tutorials and wiring diagrams
  These displays use SPI to communicate, 4 or 5 pins are required
  to interface (RST is optional)
  Adafruit invests time and resources providing this open source
  code, please support Adafruit and open-source hardware by
  purchasing products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 *******************************************************************/

#ifndef _ST7789H2_H_
#define _ST7789H2_H_

#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif
#define PROGMEM

//#include "SD.h"

typedef struct { // Data stored PER GLYPH
	uint16_t bitmapOffset;     // Pointer into GFXfont->bitmap
	uint8_t  width, height;    // Bitmap dimensions in pixels
	uint8_t  xAdvance;         // Distance to advance cursor (x axis)
	int8_t   xOffset, yOffset; // Dist from cursor pos to UL corner
} GFXglyph;

typedef struct { // Data stored for FONT AS A WHOLE:
	uint8_t  *bitmap;      // Glyph bitmaps, concatenated
	GFXglyph *glyph;       // Glyph array
	uint8_t   first, last; // ASCII extents
	uint8_t   yAdvance;    // Newline distance (y axis)
} GFXfont;


#include <SPI.h>
//#include <utility/Config.h>

// ST7789H2
#define ST7789H2_TFTWIDTH   240
#define ST7789H2_TFTHEIGHT  204

#define ST7789H2_NOP        0x00
#define ST7789H2_SWRESET    0x01
#define ST7789H2_RDDID      0x04
#define ST7789H2_RDDST      0x09

#define ST7789H2_SLPIN      0x10
#define ST7789H2_SLPOUT     0x11
#define ST7789H2_PTLON      0x12
#define ST7789H2_NORON      0x13

#define ST7789H2_RDMODE     0x0A
#define ST7789H2_RDMADCTL   0x0B
#define ST7789H2_RDPIXFMT   0x0C
#define ST7789H2_RDIMGFMT   0x0D
#define ST7789H2_RDSELFDIAG 0x0F

#define ST7789H2_INVOFF     0x20
#define ST7789H2_INVON      0x21
#define ST7789H2_GAMMASET   0x26
#define ST7789H2_DISPOFF    0x28
#define ST7789H2_DISPON     0x29

#define ST7789H2_CASET      0x2A
#define ST7789H2_PASET      0x2B
#define ST7789H2_RAMWR      0x2C
#define ST7789H2_RAMRD      0x2E

#define ST7789H2_PTLAR      0x30
#define ST7789H2_MADCTL     0x36
#define ST7789H2_VSCRSADD   0x37
#define ST7789H2_PIXFMT     0x3A

#define ST7789H2_FRMCTR1    0xB1
#define ST7789H2_FRMCTR2    0xB2
#define ST7789H2_FRMCTR3    0xB3
#define ST7789H2_INVCTR     0xB4
#define ST7789H2_DFUNCTR    0xB6

#define ST7789H2_PWCTR1     0xC0
#define ST7789H2_PWCTR2     0xC1
#define ST7789H2_PWCTR3     0xC2
#define ST7789H2_PWCTR4     0xC3
#define ST7789H2_PWCTR5     0xC4
#define ST7789H2_VMCTR1     0xC5
#define ST7789H2_VMCTR2     0xC7

#define ST7789H2_RDID1      0xDA
#define ST7789H2_RDID2      0xDB
#define ST7789H2_RDID3      0xDC
#define ST7789H2_RDID4      0xDD

#define ST7789H2_GMCTRP1    0xE0
#define ST7789H2_GMCTRN1    0xE1
/*
#define ST7789H2_PWCTR6     0xFC
*/

// Color definitions
#define ST7789H2_BLACK       0x0000      /*   0,   0,   0 */
#define ST7789H2_NAVY        0x000F      /*   0,   0, 128 */
#define ST7789H2_DARKGREEN   0x03E0      /*   0, 128,   0 */
#define ST7789H2_DARKCYAN    0x03EF      /*   0, 128, 128 */
#define ST7789H2_MAROON      0x7800      /* 128,   0,   0 */
#define ST7789H2_PURPLE      0x780F      /* 128,   0, 128 */
#define ST7789H2_OLIVE       0x7BE0      /* 128, 128,   0 */
#define ST7789H2_LIGHTGREY   0xC618      /* 192, 192, 192 */
#define ST7789H2_DARKGREY    0x7BEF      /* 128, 128, 128 */
#define ST7789H2_BLUE        0x001F      /*   0,   0, 255 */
#define ST7789H2_GREEN       0x07E0      /*   0, 255,   0 */
#define ST7789H2_CYAN        0x07FF      /*   0, 255, 255 */
#define ST7789H2_RED         0xF800      /* 255,   0,   0 */
#define ST7789H2_MAGENTA     0xF81F      /* 255,   0, 255 */
#define ST7789H2_YELLOW      0xFFE0      /* 255, 255,   0 */
#define ST7789H2_WHITE       0xFFFF      /* 255, 255, 255 */
#define ST7789H2_ORANGE      0xFD20      /* 255, 165,   0 */
#define ST7789H2_GREENYELLOW 0xAFE5      /* 173, 255,  47 */
#define ST7789H2_PINK        0xF81F

#define BLACK               0x0000      /*   0,   0,   0 */
#define NAVY                0x000F      /*   0,   0, 128 */
#define DARKGREEN           0x03E0      /*   0, 128,   0 */
#define DARKCYAN            0x03EF      /*   0, 128, 128 */
#define MAROON              0x7800      /* 128,   0,   0 */
#define PURPLE              0x780F      /* 128,   0, 128 */
#define OLIVE               0x7BE0      /* 128, 128,   0 */
#define LIGHTGREY           0xC618      /* 192, 192, 192 */
#define DARKGREY            0x7BEF      /* 128, 128, 128 */
#define BLUE                0x001F      /*   0,   0, 255 */
#define GREEN               0x07E0      /*   0, 255,   0 */
#define CYAN                0x07FF      /*   0, 255, 255 */
#define RED                 0xF800      /* 255,   0,   0 */
#define MAGENTA             0xF81F      /* 255,   0, 255 */
#define YELLOW              0xFFE0      /* 255, 255,   0 */
#define WHITE               0xFFFF      /* 255, 255, 255 */
#define ORANGE              0xFD20      /* 255, 165,   0 */
#define GREENYELLOW         0xAFE5      /* 173, 255,  47 */
#define PINK                0xF81F

#if defined(ESP8266) || defined (ESP32)
#define USE_FAST_PINIO
#endif

class ST7789H2 : public Print{
    protected:
        void
        charBounds(char c, int16_t *x, int16_t *y,
        int16_t *minx, int16_t *miny, int16_t *maxx, int16_t *maxy);
        const int16_t
        WIDTH, HEIGHT;   // This is the 'raw' display w/h - never changes
        int16_t
        _width, _height, // Display w/h as modified by current rotation
        cursor_x, cursor_y;
        uint16_t
        textcolor, textbgcolor;
        uint8_t
        textsize,
        rotation;
        boolean
        wrap,   // If set, 'wrap' text at right edge of display
        _cp437; // If set, use correct CP437 charset (default is off)
        GFXfont
        *gfxFont;

    public:
        ST7789H2(int8_t _CS, int8_t _DC, int8_t _LED, int8_t _RST = -1);

#ifndef ESP32
        void      begin(uint32_t freq = 0);
#else
        void      begin(uint32_t freq = 0, SPIClass &spi=SPI);
#endif
        void      setRotation(uint8_t r);
        void      invertDisplay(boolean i);
        void      scrollTo(uint16_t y);

        // Required Non-Transaction
        void      drawPixel(int16_t x, int16_t y, uint16_t color);
        void      drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);


        // Transaction API
        void      startWrite(void);
        void      endWrite(void);
        void      writePixel(int16_t x, int16_t y, uint16_t color);
        void      writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
        void      writeFillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
        void      writeFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
        void      writeFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);

        // Transaction API not used by GFX
        void      setAddrWindow(uint16_t x, uint16_t y, uint16_t w, uint16_t h);
        void      writePixel(uint16_t color);
        void      writePixels(uint16_t * colors, uint32_t len);
        void      writeColor(uint16_t color, uint32_t len);
	    void      pushColor(uint16_t color);

        // Recommended Non-Transaction
        void      drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
        void      drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
        void      fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
        void      drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
        void      fillScreen(uint16_t color);
        void      drawBitmap(int16_t x, int16_t y, int16_t w, int16_t h, const uint16_t *pcolors);
        void      drawBitmap(int16_t x, int16_t y, int16_t w, int16_t h, const uint8_t *pcolors);

        uint8_t   readcommand8(uint8_t reg, uint8_t index = 0);

        uint16_t  color565(uint8_t r, uint8_t g, uint8_t b);

    // via Charles Bailey on stackoverflow:
    // "Functions in derived classes which don't override functions in base
    // classes but which have the same name will hide other functions of the
    // same name in the base class.
    // "It is generally considered bad practice to have have functions in
    // derived classes which have the same name as functions in the base
    // class which aren't intended to override the base class functions as
    // what you are seeing is not usually desirable behaviour. It is usually
    // preferable to give different functions different names."
    // i.e. this function in ST7789H2 should not have been called this; it's
    // fundamentally different from GFX's drawBitmap().  But here we are,
    // painted into the proverbial corner.  C++11 has the 'using' keyword
    // to allow access to base class functions.  This'll band-aid the issue
    // for now but might be inadequate for "vintage" complier variants that
    // some board support packages might possibly be using, dunno.
        // using Adafruit_GFX::drawBitmap;
        void    progressBar(int x, int y, int w, int h, uint8_t val);
        void    setBrightness(uint8_t brightness);
        void    putChar(int x, int y, char ch);
        void    putStr(int x, int y, String str);
        void    bmpDraw(char *filename, uint8_t x, uint16_t y);
//------------------------------
  // These exist only with Adafruit_GFX (no subclass overrides)
  // CONTROL API
  // These MAY be overridden by the subclass to provide device-specific
  // optimized code.  Otherwise 'generic' versions are used.
        // void    setRotation(uint8_t r);
        // void    invertDisplay(boolean i);

  void
    drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color),
    drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
      uint16_t color),
    fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color),
    fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,
      int16_t delta, uint16_t color),
    drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
      int16_t x2, int16_t y2, uint16_t color),
    fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1,
      int16_t x2, int16_t y2, uint16_t color),
    drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
      int16_t radius, uint16_t color),
    fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h,
      int16_t radius, uint16_t color),
    drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[],
      int16_t w, int16_t h, uint16_t color),
    drawBitmap(int16_t x, int16_t y, const uint8_t bitmap[],
      int16_t w, int16_t h, uint16_t color, uint16_t bg),
    drawBitmap(int16_t x, int16_t y, uint8_t *bitmap,
      int16_t w, int16_t h, uint16_t color),
    drawBitmap(int16_t x, int16_t y, uint8_t *bitmap,
      int16_t w, int16_t h, uint16_t color, uint16_t bg),
    drawXBitmap(int16_t x, int16_t y, const uint8_t bitmap[],
      int16_t w, int16_t h, uint16_t color),
    drawGrayscaleBitmap(int16_t x, int16_t y, const uint8_t bitmap[],
      int16_t w, int16_t h),
    drawGrayscaleBitmap(int16_t x, int16_t y, uint8_t *bitmap,
      int16_t w, int16_t h),
    drawGrayscaleBitmap(int16_t x, int16_t y,
      const uint8_t bitmap[], const uint8_t mask[],
      int16_t w, int16_t h),
    drawGrayscaleBitmap(int16_t x, int16_t y,
      uint8_t *bitmap, uint8_t *mask, int16_t w, int16_t h),
    drawRGBBitmap(int16_t x, int16_t y, const uint16_t bitmap[],
      int16_t w, int16_t h),
    drawRGBBitmap(int16_t x, int16_t y, uint16_t *bitmap,
      int16_t w, int16_t h),
    drawRGBBitmap(int16_t x, int16_t y,
      const uint16_t bitmap[], const uint8_t mask[],
      int16_t w, int16_t h),
    drawRGBBitmap(int16_t x, int16_t y,
      uint16_t *bitmap, uint8_t *mask, int16_t w, int16_t h),
    drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color,
      uint16_t bg, uint8_t size),
    setCursor(int16_t x, int16_t y),
    setTextColor(uint16_t c),
    setTextColor(uint16_t c, uint16_t bg),
    setTextSize(uint8_t s),
    setTextWrap(boolean w),
    cp437(boolean x=true),
    setFont(const GFXfont *f = NULL),
    getTextBounds(char *string, int16_t x, int16_t y,
      int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h),
    getTextBounds(const __FlashStringHelper *s, int16_t x, int16_t y,
      int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h);

#if ARDUINO >= 100
  virtual size_t write(uint8_t);
#else
  virtual void   write(uint8_t);
#endif

  int16_t height(void) const;
  int16_t width(void) const;

  uint8_t getRotation(void) const;

  // get current cursor position (get rotation safe maximum values, using: width() for x, height() for y)
  int16_t getCursorX(void) const;
  int16_t getCursorY(void) const;

    private:
        SPIClass _spi;
        uint32_t _freq;
#if defined (__AVR__) || defined(TEENSYDUINO)
        int8_t  _cs, _dc, _rst, _sclk, _mosi, _miso;
#ifdef USE_FAST_PINIO
        volatile uint8_t *mosiport, *misoport, *clkport, *dcport, *csport;
        uint8_t  mosipinmask, misopinmask, clkpinmask, cspinmask, dcpinmask;
#endif
#elif defined (__arm__)
        int32_t  _cs, _dc, _rst, _sclk, _mosi, _miso;
#ifdef USE_FAST_PINIO
        volatile RwReg *mosiport, *misoport, *clkport, *dcport, *csport;
        uint32_t  mosipinmask, misopinmask, clkpinmask, cspinmask, dcpinmask;
#endif
#elif defined (ESP8266) || defined (ESP32)
        int8_t   _cs, _dc, _rst, _sclk, _mosi, _miso, _led;
#ifdef USE_FAST_PINIO
        volatile uint32_t *mosiport, *misoport, *clkport, *dcport, *csport;
        uint32_t  mosipinmask, misopinmask, clkpinmask, cspinmask, dcpinmask;
#endif
#else
        int8_t      _cs, _dc, _rst, _sclk, _mosi, _miso, _led;
#endif

        void        writeCommand(uint8_t cmd);
        void        spiWrite(uint8_t v);
        uint8_t     spiRead(void);
};

#endif
