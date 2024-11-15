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

#import "BMSTypes.h"

@class BMSCardInfo;

/**
 A UITextFieldDelegate class that will auto format its text field with an expiration date in the format MM/yyyy.

 This class internally contains the expiration date entered into the text field. When text is changed the value is
 updated, formatted and set to the text field. The spacing character between months and years can be changed with
 [BMSExpirationDateFormatterDelegate separatorCharacter].

 You can check if the expiration date is valid using [BMSExpirationDateFormatterDelegate validExpirationDate].

 You can retrieve the expiration date using either [BMSExpirationDateFormatterDelegate expirationDate] or set it to your
 BMSCardInfo object using [BMSExpirationDateFormatterDelegate setExpirationDateOnCardInfo:].

 To clear the expiration date and text field use [BMSTextFieldDelegateProxy clearTextField].
 */
@interface BMSExpirationDateFormatterDelegate : BMSTextFieldDelegateProxy

/**
 The separator character used between month and year in the format.

 The default value is '/'.
 */
@property (nonatomic) unichar separatorCharacter;

/**
 The input count for expiration dates.

 This modifies how many digits will be used to generate the expiration date. Default is BMSExpirationDateInputFour.
 */
@property (nonatomic, assign) BMSExpirationDateInput inputCount;

/**
 Can be used to check if the expiration date is valid.
 */
@property (nonatomic, getter=isValidExpirationDate) BOOL validExpirationDate;

/**
 The NSDate value for the text field if it's a valid date.

 This should be a date in UTC. e.g. "2017-08-01 00:00:00 +0000" for an expiration date of 08/17.
 */
@property (nonatomic, readonly) NSDate *expirationDate;

/**
 Can be used to set the expiration date on a BMSCardInfo object.

 @param cardInfo The BMSCardInfo object you want to assign the expiration date to.

 @see BMSCardInfo
 */
- (void)setExpirationDateOnCardInfo:(BMSCardInfo*)cardInfo;

/**
 Used to create a new date formatter with an existing date.

 Use this for instances of editing an existing date. This should be a date in UTC. e.g. "2017-08-01 00:00:00 +0000"
 for an expiration date of 08/17.

 @param date The date to initialize the formatter with.

 @return An instance of BMSExpirationDateFormatterDelegate.
 */
- (instancetype)initWithDate:(NSDate*)date;

@end
