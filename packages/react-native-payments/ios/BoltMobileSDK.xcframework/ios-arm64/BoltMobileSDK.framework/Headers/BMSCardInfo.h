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

#import <Foundation/Foundation.h>

#import "BMSTypes.h"

/**
 An object used to store card information for token generation.

 This object should be populated with information for a card being tokenized. The cardNumber and CVV properties will not
 return an unmasked version of the value once set. Use the maskFormat and maskCharacter properties to alter the masking
 for these fields.
 */
@interface BMSCardInfo : NSObject <NSCopying>

/**
 The card number for the account.

 Reading this value will returned the number in a masked format defined by maskFormat and maskCharacter. You should set
 the cardNumber with the unmasked value from your input method.
 */
@property (nonatomic,copy) NSString *cardNumber;

/**
 The expiration date of the card.

 This should be a date in UTC. e.g. "2017-08-01 00:00:00 +0000" for an expiration date of 08/17.
 */
@property (nonatomic, copy) NSDate *expirationDate;

/**
 The CVV for the card.

 Reading this value will return the CVV in a masked format defined by maskCharacter. You should set the CVV with the
 unmasked value from your input method.
 */
@property (nonatomic, copy) NSString *CVV;

/**
 The postal code of the billing address for the card.
 */
@property (nonatomic, copy) NSString *postalCode;

/**
 The account type for the card.

 Returns BMSCardIssuerNone if the card number isn't set.
 */
@property (nonatomic, assign, readonly) BMSCardIssuer accountType;

/**
 The mask format for reading cardNumber.

 Defaults to BMSCardMaskFormatMaskWithLastFour.
 */
@property (nonatomic, assign) BMSCardMaskFormat maskFormat;

/**
 The mask character used when reading cardNumber and CVV.

 Defaults to '*'.
 */
@property (nonatomic, assign) unichar maskCharacter;

/**
 The spacing used when reading cardNumber.

 Defaults to BMSCardMaskSpacingNone.
 */
@property (nonatomic, assign) BMSCardMaskSpacing maskSpacing;

/**
 Returns if the card information is valid.

 Check this before calling `-[BMSAPI generateAccountForCard:completion:]`. If it returns `FALSE`, token generation will
 fail. This validates cardNumber, expirationDate and CVV.
 */
- (BOOL)isCardValid;

@end
