//
//  KOTerminalFeeder.h
//  Welly
//
//  Created by K.O.ed on 08-8-11.
//  Copyright 2008 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "CommonType.h"

@class YLConnection, XIIntegerArray, YLTerminal;

@interface KOTerminalFeeder : NSObject {
@public
    unsigned int _row;
    unsigned int _column;
    unsigned int _cursorX;
    unsigned int _cursorY;
    unsigned int _offset;
	
    int _savedCursorX;
    int _savedCursorY;
	
    int _fgColor;
    int _bgColor;
    BOOL _bold;
    BOOL _underline;
    BOOL _blink;
    BOOL _reverse;
	
    cell **_grid;
	
    enum { TP_NORMAL, TP_ESCAPE, TP_CONTROL } _state;
	
    XIIntegerArray *_csBuf;
    XIIntegerArray *_csArg;
    unsigned int _csTemp;
	
    int _scrollBeginRow;
    int _scrollEndRow;
	
	YLTerminal *_terminal;
	YLConnection *_connection;
	
	BOOL _hasNewMessage;	// to determine if a growl notification is needed
}

- (id)init;
- (id)initWithConnection: (YLConnection *) connection;
- (void)dealloc;

/* Input Interface */
//- (void)feedData:(NSData *)data connection:(id)connection;
- (void)feedData:(NSData *)data connection:(id)connection;
- (void)feedBytes:(const void *)bytes length:(NSUInteger)len connection:(id)connection;

- (void)setTerminal:(YLTerminal *)terminal;

/* Clear */
- (void)clearRow:(int)r;
- (void)clearRow:(int)r fromStart:(int)s toEnd:(int)e;
- (void)clearAll;

- (cell *) cellsOfRow: (int) r;
@end