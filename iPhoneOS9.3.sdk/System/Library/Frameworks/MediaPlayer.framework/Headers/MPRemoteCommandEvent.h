//
//  MPRemoteCommandEvent.h
//  MediaPlayer
//
//  Copyright (c) 2013 Apple, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MediaPlayer/MediaPlayerDefines.h>
#import <MediaPlayer/MPNowPlayingInfoLanguageOption.h>


NS_ASSUME_NONNULL_BEGIN

@class MPRemoteCommand;

MP_EXTERN_CLASS_AVAILABLE(7_1)
@interface MPRemoteCommandEvent : NSObject

/// The command that sent the event.
@property (nonatomic, readonly) MPRemoteCommand *command;

/// The time when the event occurred.
@property (nonatomic, readonly) NSTimeInterval timestamp;

@end

MP_EXTERN_CLASS_AVAILABLE(7_1)
@interface MPSkipIntervalCommandEvent : MPRemoteCommandEvent

/// The chosen interval for this skip command event.
@property (nonatomic, readonly) NSTimeInterval interval;

@end

typedef NS_ENUM(NSUInteger, MPSeekCommandEventType) {
    MPSeekCommandEventTypeBeginSeeking,
    MPSeekCommandEventTypeEndSeeking
} NS_ENUM_AVAILABLE_IOS(7_1);

MP_EXTERN_CLASS_AVAILABLE(7_1)
@interface MPSeekCommandEvent : MPRemoteCommandEvent

/// The type of seek command event, which specifies whether an external player
/// began or ended seeking.
@property (nonatomic, readonly) MPSeekCommandEventType type;

@end

MP_EXTERN_CLASS_AVAILABLE(7_1)
@interface MPRatingCommandEvent : MPRemoteCommandEvent

/// The chosen rating for this command event. This value will be within the
/// minimumRating and maximumRating values set for the MPRatingCommand object.
@property (nonatomic, readonly) float rating;

@end

MP_EXTERN_CLASS_AVAILABLE(7_1)
@interface MPChangePlaybackRateCommandEvent : MPRemoteCommandEvent

/// The chosen playback rate for this command event. This value will be equal
/// to one of the values specified in the supportedPlaybackRates array for the
/// MPChangePlaybackRateCommand object.
@property (nonatomic, readonly) float playbackRate;

@end

MP_EXTERN_CLASS_AVAILABLE(7_1)
@interface MPFeedbackCommandEvent : MPRemoteCommandEvent

/// Whether the command event is a negative operation. For example, the command
/// might ask that the app remove a bookmark for a particular track, rather than
/// add it. In this case, the handler for the bookmark command should check this
/// flag and remove the bookmark if it is set to YES.
///
/// For like/dislike, a "negative like" might be treated differently from a
/// dislike command. The app might want to remove the "like" flag from the
/// current track, but not blacklist and skip to the next track as it would for
/// a dislike command.
@property (nonatomic, readonly, getter = isNegative) BOOL negative;

@end

MP_EXTERN_CLASS_AVAILABLE(9_0)
@interface MPChangeLanguageOptionCommandEvent : MPRemoteCommandEvent

/// The requested language option to change.
/// The supplied language option may be the Automatic Legible Language Option
/// which would mean that best legible language option based on user preferences
/// is being requested. See MPNowPlayingInfoLanguageOption isAutomaticLegibleLanguageOption
@property (nonatomic, readonly) MPNowPlayingInfoLanguageOption *languageOption;

@end

MP_EXTERN_CLASS_AVAILABLE(8_0)
@interface MPChangePlaybackPositionCommandEvent : MPRemoteCommandEvent

/// The desired playback position to use when setting the current time of the player.
@property (nonatomic, readonly) NSTimeInterval positionTime;

@end

NS_ASSUME_NONNULL_END
