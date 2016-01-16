//
//  ALMessageDBService.h
//  ChatApp
//
//  Created by Devashish on 21/09/15.
//  Copyright © 2015 AppLogic. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "DB_FileMetaInfo.h"
#import "DB_Message.h"
#import "ALMessage.h"
#import "ALFileMetaInfo.h"


@protocol ALMessagesDelegate <NSObject>

-(void)getMessagesArray:(NSMutableArray*)messagesArray;

-(void) updateMessageList:(NSMutableArray*)messagesArray;

@end

@interface ALMessageDBService : NSObject
- (NSArray *)getUnreadMessages:(NSString *) contactId;
//Add Message APIS
-(NSMutableArray *)addMessageList:(NSMutableArray*) messageList;
-(DB_Message*)addMessage:(ALMessage*) message;
-(void)getMessages;
-(void)fetchAndRefreshFromServer;
-(void)fetchAndRefreshFromServerForPush;
-(void)fetchAndRefreshQuickConversation;

-(NSManagedObject *)getMeesageById:(NSManagedObjectID *)objectID
                             error:(NSError **)error;
- (NSManagedObject *)getMessageByKey:(NSString *) key value:(NSString*) value;
-(NSMutableArray *)getMessageListForContactWithCreatedAt:(NSString *)contactId withCreatedAt:(NSNumber*)createdAt andChannelKey:(NSNumber *)channelKey;
-(NSMutableArray *)getPendingMessages;


-(NSUInteger)markConversationAsRead:(NSString *) contactId orChannelKey:(NSNumber *)key;



//update Message APIS
-(void)updateMessageDeliveryReport:(NSString*) messageKeyString;
-(void)updateDeliveryReportForContact: (NSString *) contactId;
-(void)updateMessageSyncStatus:(NSString*) keyString;
-(void)updateFileMetaInfo:(ALMessage *) almessage;

//Delete Message APIS

-(void) deleteMessage;
-(void) deleteMessageByKey:(NSString*) keyString;
-(void) deleteAllMessagesByContact: (NSString*) contactId orChannelKey:(NSNumber *)key;

//Generic APIS
-(BOOL) isMessageTableEmpty;
-(void)deleteAllObjectsInCoreData;

-(DB_Message *) createMessageEntityForDBInsertionWithMessage:(ALMessage *) theMessage;
-(DB_FileMetaInfo *) createFileMetaInfoEntityForDBInsertionWithMessage:(ALFileMetaInfo *) fileInfo;
-(ALMessage *) createMessageEntity:(DB_Message *) theEntity;


@property(nonatomic,weak) id <ALMessagesDelegate>delegate;

@end
