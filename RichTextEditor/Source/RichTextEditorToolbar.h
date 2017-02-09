//
//  RichTextEditorToolbar.h
//  RichTextEdtor
//
//  Created by Aryan Gh on 7/21/13.
//  Copyright (c) 2013 Aryan Ghassemi. All rights reserved.
//
// https://github.com/aryaxt/iOS-Rich-Text-Editor
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
#import "RichTextEditorColorPicker.h"
#import "RichTextEditorFontPicker.h"
#import "RichTextEditorFontSizePicker.h"

#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)

typedef NS_ENUM(NSUInteger, RichTextEditorToolbarPresentationStyle) {
	RichTextEditorToolbarPresentationStyleModal,
	RichTextEditorToolbarPresentationStylePopover
};

typedef NS_ENUM(NSUInteger, ParagraphIndentation) {
	ParagraphIndentationIncrease,
	ParagraphIndentationDecrease
};

typedef NS_OPTIONS(NSUInteger, RichTextEditorFeature) {
	RichTextEditorFeatureNone							= 1 << 0,
	RichTextEditorFeatureFont							= 1 << 1,
	RichTextEditorFeatureFontSize						= 1 << 2,
	RichTextEditorFeatureBold							= 1 << 3,
	RichTextEditorFeatureItalic							= 1 << 4,
	RichTextEditorFeatureUnderline						= 1 << 5,
	RichTextEditorFeatureStrikeThrough					= 1 << 6,
	RichTextEditorFeatureTextAlignmentLeft				= 1 << 7,
	RichTextEditorFeatureTextAlignmentCenter			= 1 << 8,
	RichTextEditorFeatureTextAlignmentRight				= 1 << 9,
	RichTextEditorFeatureTextAlignmentJustified			= 1 << 10,
	RichTextEditorFeatureTextBackgroundColor			= 1 << 11,
	RichTextEditorFeatureTextForegroundColor			= 1 << 12,
	RichTextEditorFeatureParagraphIndentation			= 1 << 13,
	RichTextEditorFeatureParagraphFirstLineIndentation	= 1 << 14,
	RichTextEditorFeatureBulletList						= 1 << 15,
	RichTextEditorTextAttachment						= 1 << 16,
	RichTextEditorFeatureUndoRedo						= 1 << 17,
	RichTextEditorFeatureDismissKeyboard				= 1 << 18,
	RichTextEditorFeatureAll							= 1 << 19,
};

@protocol RichTextEditorToolbarDelegate <UIScrollViewDelegate>
- (void)richTextEditorToolbarDidDismissViewController;
- (void)richTextEditorToolbarDidSelectBold;
- (void)richTextEditorToolbarDidSelectItalic;
- (void)richTextEditorToolbarDidSelectUnderline;
- (void)richTextEditorToolbarDidSelectStrikeThrough;
- (void)richTextEditorToolbarDidSelectBulletListWithCaller:(id)caller;
- (void)richTextEditorToolbarDidSelectTextAttachment:(UIImage *)textAttachment;
- (void)richTextEditorToolbarDidSelectParagraphFirstLineHeadIndent;
- (void)richTextEditorToolbarDidSelectParagraphIndentation:(ParagraphIndentation)paragraphIndentation;
- (void)richTextEditorToolbarDidSelectFontSize:(NSNumber *)fontSize;
- (void)richTextEditorToolbarDidSelectFontWithName:(NSString *)fontName;
- (void)richTextEditorToolbarDidSelectTextBackgroundColor:(UIColor *)color;
- (void)richTextEditorToolbarDidSelectTextForegroundColor:(UIColor *)color;
- (void)richTextEditorToolbarDidSelectTextAlignment:(NSTextAlignment)textAlignment;
- (void)richTextEditorToolbarDidSelectUndo;
- (void)richTextEditorToolbarDidSelectRedo;
- (void)richTextEditorToolbarDidSelectDismissKeyboard;
@end

@protocol RichTextEditorToolbarDataSource <NSObject>
- (NSArray *)fontSizeSelectionForRichTextEditorToolbar;
- (NSArray *)fontFamilySelectionForRichTextEditorToolbar;
- (RichTextEditorToolbarPresentationStyle)presentationStyleForRichTextEditorToolbar;
- (UIModalPresentationStyle)modalPresentationStyleForRichTextEditorToolbar;
- (UIModalTransitionStyle)modalTransitionStyleForRichTextEditorToolbar;
- (UIViewController *)firstAvailableViewControllerForRichTextEditorToolbar;
- (RichTextEditorFeature)featuresEnabledForRichTextEditorToolbar;
- (UIViewController <RichTextEditorColorPicker> *)colorPickerForRichTextEditorToolbarWithAction:(RichTextEditorColorPickerAction)action;
- (UIViewController <RichTextEditorFontPicker> *)fontPickerForRichTextEditorToolbar;
- (UIViewController <RichTextEditorFontSizePicker> *)fontSizePickerForRichTextEditorToolbar;
@end

@interface RichTextEditorToolbar : UIScrollView

@property (nonatomic, weak) id <RichTextEditorToolbarDelegate> toolbarDelegate;
@property (nonatomic, weak) id <RichTextEditorToolbarDataSource> dataSource;

- (id)initWithFrame:(CGRect)frame delegate:(id <RichTextEditorToolbarDelegate>)delegate dataSource:(id <RichTextEditorToolbarDataSource>)dataSource;
- (void)updateStateWithAttributes:(NSDictionary *)attributes;
- (void)redraw;

- (void)enableUndoButton:(BOOL)shouldEnable;
- (void)enableRedoButton:(BOOL)shouldEnable;

@end
