//
//  JPANCSNotificationSource.h
//  Mac ANCS
//
//  Created by Jamie Pinkham on 9/20/13.
//  Copyright (c) 2013 Jamie Pinkham. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, ANCSEventNotificationType)
{
	ANCSEventNotificationTypeAdded = 0,
	ANCSEventNotificationTypeModified = 1,
	ANCSEventNotificationTypeRemoved = 2,
	ANCSEventNotificationTypeReserved,
};

typedef NS_OPTIONS(NSUInteger, ANCSEventFlag)
{
	ANCSEventFlagSilent = (1 << 0),
	ANCSEventFlagImportant = ( 1 << 1),
    ANCSEventFlagPreExisting  = ( 1 << 2),
    ANCSEventFlagPositiveAction  = ( 1 << 3),
    ANCSEventFlagNegativeAction = ( 1 << 4),
};

typedef NS_ENUM(NSInteger, ANCSCategory)
{
	ANCSCategoryOther,
	ANCSCategoryIncomingCall,
	ANCSCategoryMissedCall,
	ANCSCategoryVoicemail,
	ANCSCategorySocial,
	ANCSCategorySchedule,
	ANCSCategoryEmail,
	ANCSCategoryNews,
	ANCSCategoryHealthAndFitness,
	ANCSCategoryBusinessAndFinance,
	ANCSCategoryLocation,
	ANCSCategoryEntertainment,
};

typedef NS_ENUM(uint16_t, ANCSCommandId)
{
    ANCSCommandIDGetNotificationAttributes = 0,
    ANCSCommandIDGetAppAttributes = 1,
    ANCSCommandIDPerformNotificationAction  = 2,
};

@interface ANCSNotification : NSObject

- (instancetype)initWithData:(NSData *)data;

@property (nonatomic, readonly) NSUInteger notificationUid;
@property (nonatomic, readonly) NSUInteger categoryCount;
@property (nonatomic, readonly) ANCSEventNotificationType notificationType;
@property (nonatomic, readonly) ANCSEventFlag eventFlags;
@property (nonatomic, readonly) ANCSCategory category;

@end
