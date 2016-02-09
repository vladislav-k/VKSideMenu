//
//  VKSideMenu.h
//
//  Created by Vladislav Kovalyov on 2/7/16.
//  Copyright © 2016 WOOPSS.com (http://woopss.com/)
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <UIKit/UIKit.h>

/*!
 @enum      VKSideMenuDirection
 @abstract  An enum that defines the direction of <code>VKSideMenu</code>
 
 @constant  VKSideMenuDirectionLeftToRight
                Menu appears from left to right of parent view
 @constant  VKAdBannerViewRotationTypeRandom
                Menu appears from right to left of parent view
 */
typedef NS_ENUM(NSInteger, VKSideMenuDirection)
{
    VKSideMenuDirectionLeftToRight,
    VKSideMenuDirectionRightToLeft
};

/*!
 @protocol  VKSideMenuDataSource
 @abstract  This protocol represents the data model object
 @note      It's almost the same to UITableViewDataSource
 */

@class VKSideMenu, VKSideMenuItem;
@protocol VKSideMenuDataSource <NSObject>

@required
-(NSInteger)numberOfSectionsInSideMenu:(VKSideMenu *)sideMenu;
-(NSInteger)sideMenu:(VKSideMenu *)sideMenu numberOfRowsInSection:(NSInteger)section;
-(VKSideMenuItem *)sideMenu:(VKSideMenu *)sideMenu itemForRowAtIndexPath:(NSIndexPath *)indexPath;

@end

/*!
 @protocol  VKSideMenuDelegate
 @abstract  This protocol represents the behaviour of the <code>VKSideMenu</code>.
 */

@class VKSideMenu, VKSideMenuItem;
@protocol VKSideMenuDelegate <NSObject>

@optional
/*!
 @abstract  These methods called when <code>VKSideMenu</code> changes it's appearance
 @param     sideMenu 
                <code>VKSideMenu</code> called which delegate is called
 */
-(void)sideMenuDidShow:(VKSideMenu *)sideMenu;
-(void)sideMenuDidHide:(VKSideMenu *)sideMenu;

/*!
 @method    sideMenu:didSelectRowAtIndexPath:
 @abstract  Called when user did select some item
 @param     sideMenu
                <code>VKSideMenu</code> called which delegate is called
 @param     indexPath
                <code>NSIndexPath</code> of the selected item
 */
-(void)sideMenu:(VKSideMenu *)sideMenu didSelectRowAtIndexPath:(NSIndexPath *)indexPath;

/*!
 @method    sideMenu:didSelectRowAtIndexPath:
 @abstract  Called when user did select some item
 @param     sideMenu
                <code>VKSideMenu</code> called which delegate is called
 @param     section
                Index of section which asking for title
 */
-(NSString *)sideMenu:(VKSideMenu *)sideMenu titleForHeaderInSection:(NSInteger)section;

@end

/// -------------------------------------------------------------------
/// @class     VKSideMenuItem
/// @abstract  <code>VKSideMenuItem</code> represents menu item's data
/// -------------------------------------------------------------------
@interface VKSideMenuItem : NSObject

/*!
 @property  icon
 @abstract  Icon image for item
 */
@property (nonatomic, strong) UIImage  *icon;

/*!
 @property  title
 @abstract  Title for item
 */
@property (nonatomic, strong) NSString *title;

/*!
 @property  tag
 @abstract  Tag for item
 @note      Used just for convenience
 */
@property (nonatomic, assign) NSInteger *tag;

@end

/// -------------------------------------------------------------------
/// @class  VKSideMenu
/// -------------------------------------------------------------------

@interface VKSideMenu : NSObject

/*!
 @method    initWithWidth:andDirection:
 @abstract  Used for initialization of <code>VKSideMenu</code> with specified width and direction
 @param     width
                Specified width of the side menu
 @param     direction
                Specified direction of the side menu
 @see       <code>VKSideMenuDirection</code>
 @return    <code>VKSideMenu</code> instance
 */
-(instancetype)initWithWidth:(CGFloat)width andDirection:(VKSideMenuDirection)direction;

/*!
 @property  delegate
 @abstract  <code>VKSideMenu</code> delegate object
 @see       VKSideMenuDelegate
 */
@property (nonatomic, strong) id <VKSideMenuDelegate> delegate;

/*!
 @property  dataSource
 @abstract  <code>VKSideMenu</code> data source object
 @see       VKSideMenuDataSource
 */
@property (nonatomic, strong) id <VKSideMenuDataSource> dataSource;

/*!
 @property  direction
 @abstract  Direction of the <code>VKSideMenu</code> 
 @note      Default is VKSideMenuDirectionLeftToRight
 @see       VKSideMenuDirection enum
 */
@property (nonatomic, assign) VKSideMenuDirection direction;

/*!
 @property  width
 @abstract  Specified width of <code>VKSideMenu</code>
 @note      Default is 240
 */
@property (nonatomic, assign) CGFloat width;

/*!
 @property  view
 @abstract  View of the <code>VKSideMenu</code>
 @note      If iOS version is 8.0 or later it will be initialized as UIVisualEffectView
 */
@property (nonatomic, strong) UIView *view;

/*!
 @property  blurEffectStyle
 @abstract  UIBlurEffectStyle for <code>VKSideMenu</code> view
 @note      Use if iOS version is 8.0 or later. Default is UIBlurEffectStyleExtraLight
 */
@property (nonatomic, assign) UIBlurEffectStyle blurEffectStyle NS_AVAILABLE_IOS(8_0);

/*!
 @property  tableView
 @abstract  UITableView object used for data representation
 */
@property (nonatomic, strong) UITableView *tableView;

/*!
 @property  enableOverlay
 @abstract  Determines if dimmed overlay must be showed
 @note      Default value is YES
 */
@property (nonatomic, assign) BOOL enableOverlay;

/*!
 @property  enableOverlay
 @abstract  Determines if <code>VKSideMenu</code> should be closed after user tapped outside the menu view
 @note      Default value is YES
 */
@property (nonatomic, assign) BOOL automaticallyDeselectRow;

/*!
 @property  enableOverlay
 @abstract  Determines if <code>VKSideMenu</code> should be closed after user selected any item
 @note      Default value is YES
 */
@property (nonatomic, assign) BOOL hideOnSelection;

/*!
 @method    show
 @abstract  Shows <code>VKSideMenu</code> view
 */
-(void)show;

/*!
 @method    show
 @abstract  Shows <code>VKSideMenu</code> with specified width
 @param     width
                Specified width for <code>VKSideMenu</code>
 */
-(void)showWithWidth:(CGFloat)width;

/*!
 @method    show
 @abstract  Hides <code>VKSideMenu</code> view
 */
-(void)hide;

/*!
 @property   backgroundColor
 @abstract   Color of selection for <code>tableView</code> rows
 @note       Default is colorWithWhite:1. alpha:.8
 @discussion Use only with iOS 7
 */
@property (nonatomic, strong) UIColor *backgroundColor NS_DEPRECATED_IOS(7_0, 8_0);

/*!
 @property  selectionColor
 @abstract  Color of selection for <code>tableView</code> rows
 @note      Default is colorWithWhite:1. alpha:.5
 */
@property (nonatomic, strong) UIColor *selectionColor;

/*!
 @property  selectionColor
 @abstract  Color of title for <code>tableView</code> rows
 @note      Default is #252525
 */
@property (nonatomic, strong) UIColor *textColor;

/*!
 @property  sectionTitleFont
 @abstract  Font for item's title of <code>tableView</code> sections
 @note      Default is systemFont with size 15.0
 */
@property (nonatomic, strong) UIFont *sectionTitleFont;

/*!
 @property  sectionTitleColor
 @abstract  Color of section's title for <code>tableView</code> rows
 @note      Default is #8f8f8f
 */
@property (nonatomic, strong) UIColor *sectionTitleColor;

/*!
 @property  iconsColor
 @abstract  Color of section's icons for <code>tableView</code> rows
 @note      Default is #8f8f8f. Set nil if you don't want to override icon color
 */
@property (nonatomic, strong) UIColor *iconsColor;

@end
