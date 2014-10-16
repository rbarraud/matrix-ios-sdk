/*
 Copyright 2014 OpenMarket Ltd
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#import <Foundation/Foundation.h>

#import <XCTest/XCTest.h>

#import "MXSession.h"

// The URL of your test home server
FOUNDATION_EXPORT NSString * const kMXTestsHomeServerURL;

@interface MatrixSDKTestsData : NSObject

+ (id)sharedData;

// Credentials for the user mxBob on the home server located at kMXTestsHomeServerURL
@property (nonatomic, readonly) MXLoginResponse *bobCredentials;

// Get credentials asynchronously
// The user will be created if needed
- (void)getBobCredentials:(void (^)())success;
- (void)getBobMXSession:(void (^)(MXSession *bobSession))success;

// Prepare a test with a MXSession for mxBob so that we can make test on it
- (void)doMXSessionTestWithBob:(XCTestCase*)testCase
                   readyToTest:(void (^)(MXSession *bobSession, XCTestExpectation *expectation))readyToTest;

// Prepare a test with a a MXSession for mxBob so that we can make test on it
- (void)doMXSessionTestWithBobAndARoom:(XCTestCase*)testCase
                           readyToTest:(void (^)(MXSession *bobSession, NSString* room_id, XCTestExpectation *expectation))readyToTest;

- (void)doMXSessionTestWithBobAndThePublicRoom:(XCTestCase*)testCase
                           readyToTest:(void (^)(MXSession *bobSession, NSString* room_id, XCTestExpectation *expectation))readyToTest;

- (void)doMXSessionTestInABobRoomAndANewTextMessage:(XCTestCase*)testCase
                                     newTextMessage:(NSString*)newTextMessage
                                      onReadyToTest:(void (^)(MXSession *bobSession, NSString* room_id, NSString* new_text_message_event_id, XCTestExpectation *expectation))readyToTest;

- (void)doMXSessionTestWithBobAndARoomWithMessages:(XCTestCase*)testCase
                                       readyToTest:(void (^)(MXSession *bobSession, NSString* room_id, XCTestExpectation *expectation))readyToTest;

- (void)doMXSessionTestWihBobAndSeveralRoomsAndMessages:(XCTestCase*)testCase
                                            readyToTest:(void (^)(MXSession *bobSession, XCTestExpectation *expectation))readyToTest;

//- (void)AliceCredentials:(void (^)())success;
//@property (nonatomic, readonly) MXLoginResponse *aliceCredentials;

//- (void)randomCredentials:(void (^)(MXLoginResponse *randomCredentials))success;

// Creates roomsCount rooms with messagesCount messages in the mxSession
- (void)for:(MXSession*)mxSession createRooms:(NSUInteger)roomsCount withMessages:(NSUInteger)messagesCount success:(void (^)())success;

// Posts messagesCount messages to the room
- (void)for:(MXSession *)mxSession andRoom:(NSString*)room_id postMessages:(NSUInteger)messagesCount success:(void (^)())success;

@end