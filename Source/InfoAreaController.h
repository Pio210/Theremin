/*
 Copyright (C) 2006-2007  Patrik Weiskircher
 
 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 as published by the Free Software Foundation; either version 2
 of the License, or (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, 
 MA 02110-1301, USA.
 */

#import <Cocoa/Cocoa.h>
#import "Growl/GrowlApplicationBridge.h"

@class WindowController, Song, CoverArtView;

@interface InfoAreaController : NSObject <GrowlApplicationBridgeDelegate> {
	IBOutlet NSTextField *mTitle;
	IBOutlet NSTextField *mArtist;
	IBOutlet NSTextField *mAlbum;
	
	IBOutlet NSTextField *mElapsedTime;
	IBOutlet NSTextField *mRemainingTime;
	IBOutlet NSSlider *mSeekSlider;
	
	IBOutlet CoverArtView *mCoverArtView;
	
	IBOutlet NSProgressIndicator *mProgressIndicator;
	IBOutlet NSTextField *mProgressLabel;
	
	NSTimer *mProgressIndicatorStartTimer;	
	NSTimer *mInfoAreaUpdateTimer;

	NSPoint mOriginalOriginTitle;
	NSPoint mOriginalOriginArtist;
	NSPoint mOriginalOriginProgressLabel;
	
	Song *mCurrentSong;
	NSData *mLastNotifiedSongIdentifier;
	
	NSDictionary *mGrowlDictionary;
	NSTimer *mGrowlTimer;
	NSImage *mGrowlImage;
	
	int _total;
}
- (id) init;
- (void) dealloc;

- (NSDictionary *) registrationDictionaryForGrowl;

- (void) enableCoverArt:(BOOL)aValue;

- (void) scheduleUpdate;
- (void) update;

- (void) updateSeekBarWithTotalTime:(int)total;
- (void) updateSeekBarWithElapsedTime:(int)elapsed;
@end