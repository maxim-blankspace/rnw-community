/*

 Copyright 2022 Fiserv, Inc and/or its affiliates

 Redistribution and use in source and binary forms, with or without
 modification, is permitted provided that adherence to the following
 conditions is maintained. If you do not agree with these terms,
 please do not use, install, modify or redistribute this software.

 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY FISERV,INC AND/OR ITS AFFILIATES "AS IS" AND ANY
 EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 IN NO EVENT SHALL FISERV,INC AND/OR ITS AFFILIATES OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */

#import "BMSTextFieldDelegateProxy.h"

#import "BMSCardFunctions.h"

@class BMSCardInfo;

/**
 A UITextFieldDelegate class that will auto format its text field with a masked card number.

 This class internally contains the card number set in the text field. When the text is changed, this value is updated
 and a masked value is set to the text field. The masking can be changed using [BMSCardFormatterDelegate maskFormat]
 and [BMSCardFormatterDelegate maskCharacter].

 You can check if the card is valid using [BMSCardFormatterDelegate validCard].

 To retrieve the card number, use [BMSCardFormatterDelegate setCardNumberOnCardInfo:] to set it onto your
 BMSCardInfo object.

 To clear the card number and text field use [BMSTextFieldDelegateProxy clearTextField].
 */
@interface BMSCardFormatterDelegate : BMSTextFieldDelegateProxy

/**
 The mask format used for the card number.

 The default setting is BMSCardMaskFormatMaskWithLastFour.
 */
@property (nonatomic) BMSCardMaskFormat maskFormat;

/**
 The mask character used for the card number.

 The default value is '*'.
 */
@property (nonatomic) unichar maskCharacter;

/**
 The spacing used for the card number.

 The default value is BMSCardMaskSpacingNone.
 */
@property (nonatomic, assign) BMSCardMaskSpacing maskSpacing;

/**
 Can be used to check if the card number is valid.
 */
@property (nonatomic, getter=isValidCard) BOOL validCard;

/**
 Should be used to set the card number on a BMSCardInfo object.

 This is the only way to retrieve the unmasked card number from the text field.

 @param cardInfo The BMSCardInfo object you want to assign the card number to.

 @see BMSCardInfo
 */
- (void)setCardNumberOnCardInfo:(BMSCardInfo*)cardInfo;

@end
