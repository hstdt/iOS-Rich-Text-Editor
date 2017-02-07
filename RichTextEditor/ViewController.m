//
//  ViewController.m
//  RichTextEdtor
//
//  Created by Aryan Gh on 7/21/13.
//  Copyright (c) 2013 Aryan Ghassemi. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@property (assign) IBOutlet RichTextEditor *richTextEditor;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
	
	
}

- (void)viewWillAppear:(BOOL)animated {
	[super viewWillAppear:animated];
	[self.richTextEditor scrollRangeToVisible:NSMakeRange(0, 0)];
}

- (void)viewDidAppear:(BOOL)animated {
	[super viewDidAppear:animated];
	self.richTextEditor.selectedRange = NSMakeRange(0, 0);
	[self.richTextEditor scrollRangeToVisible:NSMakeRange(0, 0)];
}

/*- (NSArray *)fontSizeSelectionForRichTextEditor:(RichTextEditor *)richTextEditor
{
	// pas an array of NSNumbers
	return @[@5, @20, @30];
}

- (RichTextEditorToolbarPresentationStyle)presentarionStyleForRichTextEditor:(RichTextEditor *)richTextEditor
{
	return RichTextEditorToolbarPresentationStyleModal;
}

- (UIModalPresentationStyle)modalPresentationStyleForRichTextEditor:(RichTextEditor *)richTextEditor
{
	return UIModalPresentationFormSheet;
}

- (UIModalTransitionStyle)modalTransitionStyleForRichTextEditor:(RichTextEditor *)richTextEditor
{
	return UIModalTransitionStyleFlipHorizontal;
}*/

- (RichTextEditorFeature)featuresEnabledForRichTextEditor:(RichTextEditor *)richTextEditor
{
	return RichTextEditorFeatureFontSize | RichTextEditorFeatureFont | RichTextEditorFeatureAll;
}

@end
