// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OnlineAccountTexts.generated.h"

USTRUCT()
struct FOnlineAccountTexts_FailedLoginConsole
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts_FailedLoginConsole")
	FText AgeRestriction;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts_FailedLoginConsole")
	FText Generic;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts_FailedLoginConsole")
	FText MissingAuthAssociation;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts_FailedLoginConsole")
	FText NeedPremiumAccount;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts_FailedLoginConsole")
	FText OnlinePlayRestriction;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts_FailedLoginConsole")
	FText PatchAvailable;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts_FailedLoginConsole")
	FText PatchAvailableInstruction_Default;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts_FailedLoginConsole")
	FText PatchAvailableInstruction_Xbox;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts_FailedLoginConsole")
	FText PleaseSignIn;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts_FailedLoginConsole")
	FText SystemUpdateAvailable;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts_FailedLoginConsole")
	FText UI;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts_FailedLoginConsole")
	FText UnableToComplete;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts_FailedLoginConsole")
	FText UnableToSignIn;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts_FailedLoginConsole")
	FText UnableToStartPrivCheck;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts_FailedLoginConsole")
	FText UnexpectedError;

};

USTRUCT()
struct FOnlineAccountTexts
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText AllGiftCodesUsed;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText AssociateConsoleAuth;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText AutoLoginFailed;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText AutoLoginFailedMobile;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText BannedFromGame;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText CheckEntitledToPlay;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText CheckingRejoin;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText CheckServiceAvailability;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText ConsolePrivileges;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText CreateAccountCompleted;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText CreateAccountFailure;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText CreateHeadless;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText DoQosPingTests;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText DowntimeMinutesWarningText;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText DowntimeSecondsWarningText;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText DuplicateAuthAssociaton;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText EulaCheck;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText ExchangeConsoleGiftsForAccess;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText FailedAccountCreate;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText FailedEulaCheck_EulaAcceptanceFailed;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText FailedEulaCheck_MustAcceptEula;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText FailedLoginCredentialsMsg;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText FailedLoginAgeVerificationIncomplete;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText FailedLoginParentalLock;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText FailedLoginNoRealId;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText FailedLoginLockoutMsg;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText FailedLoginRequiresMFA;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText FailedLoginRequiresAuthAppMFA;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText FailedInvalidMFA;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText FailedLoginRequiresCorrectiveAction;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText FailedLoginMsg;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText FailedLoginMsg_InvalidRefreshToken;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText FailedStartLogin;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText FounderChatExitedText;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText FounderChatJoinedText;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText GameDisplayName;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText GeneralLoginFailure;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText GlobalChatExitedText;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText GlobalChatJoinedText;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText HeadlessAccountFailed;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText InMatchShutdownTimeWarningText;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText InvalidUser;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText LoggedOutofMCP;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText DisconnectedFromMCP;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText LoggedOutReturnedToTitle;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText LoggedOutSwitchedProfile;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText LoggingIn;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText LoggingInConsoleAuth;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText LoggingOut;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText LoginConsole;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText LoginFailure;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText Logout_Unlink;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText LogoutCompleted;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText LostConnection;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText LoginStepTimeout;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText MCPTimeout;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText LightswitchCheckNetworkFailureMsg;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText NetworkConnectionUnavailable;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText NoPlayEntitlement;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText NoServerAccess;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText PlayAccessRevoked;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText PremiumAccountName_Default;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText PremiumAccountName_Sony;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText PremiumAccountName_Switch;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText PremiumAccountName_XboxOne;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText RedeemOfflinePurchases;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText ServiceDowntime;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText SignInCompleting;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText SignIntoConsoleServices;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText TokenExpired;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText UnableToConnect;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText UnableToJoinWaitingRoomLoginQueue;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText UnexpectedConsoleAuthFailure;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText UnlinkConsoleFailed;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText UserLoginFailed;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText WaitingRoom;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText WaitingRoomError;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText WaitingRoomFailure;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText WaitingRoomWaiting;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FOnlineAccountTexts_FailedLoginConsole FailedLoginConsole;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText LoggingInExternalAuth;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText CreateDeviceAuth;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText ExtAuthCanceled;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText ExtAuthFailure;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText ExtAuthAssociationFailure;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText ExtAuthTimeout;

	UPROPERTY(EditAnywhere, Category="OnlineAccountTexts")
	FText ExtAuthMissingAuthAssociation;

	UPROPERTY(EditDefaultsOnly, Category="OnlineAccountTexts")
	FText UnableToQueryReceipts;

};

