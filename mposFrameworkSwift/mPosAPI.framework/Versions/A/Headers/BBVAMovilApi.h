//
//  BBVAMovilApi.h
//  BancomerMovil
//
//  Created by Ricardo Zertuche on 8/10/14.
//  Copyright (c) 2014 Ricardo Zertuche. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EmvSwipeController.h"
#import "WisePadController.h"
#import "AFNetworking.h"
#import "AFHTTPSessionManager.h"

@protocol BBVADelegate <NSObject>
@optional
- (void) processText: (NSString*)text;
- (void) didFinishPaymentCorrectly: (BOOL)success withTransactin:(NSString*)transaction;
- (void) didSendSignature: (BOOL)success;
- (void) loginSucceded: (BOOL)success andToken:(NSString*)token andDictionary:(NSDictionary*)info;
// Returns an Array with Dictionaries of each transaction
- (void) loadedTransactionsReturn:(NSArray*)transactions;
- (void) didCancel: (BOOL)success andMessage:(NSString*)message;
- (void) didConnectDevice: (BOOL)yes;
- (void) didStartOnlineTransaction;
- (void) lowBaterryMessage:(NSString*)message;
- (void) searchResult:(NSArray*)result withSucces:(BOOL)success;
@end

@interface BBVAMovilApi : NSObject <EmvSwipeControllerDelegate, WisePadControllerDelegate, UIAlertViewDelegate, UITextFieldDelegate>
{
    BOOL isBadSwiped;
    BOOL isCheckingCardPresent;
    
    NSString *ksn;
    NSString *entrack1;
    NSString *entrack2;
    
    NSString *transactionID;
    NSString *authCode;
    NSString *test;
    
    UIAlertView *av;
    
    NSString *serverTlvResponse;
    int fallbackCounter;
    BOOL fallback;
    
    NSString *batteryWlaker;
    
    id <BBVADelegate> delegate;
}
@property (retain) id delegate;

@property (nonatomic, assign) id<EmvSwipeControllerDelegate> EmvSwipeControllerDelegate;
@property (nonatomic, assign) id<WisePadControllerDelegate> WisePadControllerDelegate;

@property (nonatomic) NSString *concepto;
@property (nonatomic) NSString *monto;
@property (nonatomic) NSString *mail;
@property (nonatomic) NSString *order;
@property (nonatomic) NSString *servicio;
@property (nonatomic) NSString *token;
@property (nonatomic) NSString *msi;
@property (nonatomic) NSString *env;
@property (nonatomic) NSString *cvv;
@property (nonatomic) NSString *latitude;
@property (nonatomic) NSString *longitud;

-(void) initBBVA;
-(BOOL) devicePluggedBBVA;
-(void) checkCardStatus;
-(void) checkCard;

- (void)loginWithUsername:(NSString *)username andPassword:(NSString*)password andEnv:(NSString*)env;
- (void)loadTransactions;
- (void)cancelTransactionWithOrder:(NSString*)order andToken:(NSString*)token;

- (void)sendAmount:(NSString*)amount andConcept:(NSString*)concept andEmail:(NSString*)email andToken:(NSString*)token andService:(NSString*)service andOrderID:(NSString*)orderID andPeriod:(NSString*)period andEnv:(NSString*)env andLat:(NSString*)lati andLong:(NSString*)longi;

- (void)sendSignatureData:(NSData*)signData;
- (void)searchTransactionWithAuthCode:(NSString*)auth_code andToken:(NSString *)token andEnv:(NSString*)env;
- (void)searchTransactionWithOrder:(NSString*)order_s andToken:(NSString *)token andEnv:(NSString*)env;

@end
