//
//	BPFormula.h
//	Cakebrew – The Homebrew GUI App for OS X 
//
//	Created by Bruno Philipe on 4/3/14.
//	Copyright (c) 2014 Bruno Philipe. All rights reserved.
//
//	This program is free software: you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation, either version 3 of the License, or
//	(at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#import <Foundation/Foundation.h>

@interface BPFormula : NSObject <NSCoding, NSCopying>

@property (strong, readonly) NSString *name;
@property (strong, readonly) NSString *version;
@property (strong, readonly) NSString *latestVersion;
@property (strong, readonly) NSString *installPath;
@property (strong, readonly) NSString *dependencies;
@property (strong, readonly) NSString *conflicts;
@property (strong, readonly) NSString *shortDescription;
@property (strong, readonly) NSURL    *website;
@property (strong, readonly) NSArray  *options;

+ (BPFormula*)formulaWithName:(NSString*)name version:(NSString*)version andLatestVersion:(NSString*)latestVersion;
+ (BPFormula*)formulaWithName:(NSString*)name andVersion:(NSString*)version;
+ (BPFormula*)formulaWithName:(NSString*)name;

/**
 *  The short name for the formula. Useful for taps. Returns the remaining substring after the last slash character.
 *
 *  @return The last substring after the last slash character.
 */
- (NSString*)installedName;

/**
 *  Retrieves and updates the formula info with the information from the 'brew info' command.
 *
 *  @return `YES` if the process succeeded, or `NO` otherwise.
 */
- (BOOL)getInformation;

/**
 *  @return `YES` if the formula is installed, or `NO` otherwise.
 */
- (BOOL)isInstalled;

/**
 *  @return `YES` if the formula is installed and outdated, or `NO` otherwise.
 */
- (BOOL)isOutdated;

@end
