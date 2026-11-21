// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OnlineAccount.h"
#include "OnlineAccountCommon.generated.h"

class UWaitingRoomState;

UENUM(BlueprintType)
enum class EConsoleAuthLinkState : uint8
{
	/** You aren't on a console why are you even asking, really? */
	NotOnConsole = 0,
	/** No Console auth available */
	ConsoleNotLoggedIn = 1,
	/** No Epic Auth is available yet, UI needs user to attempt linking then check again */
	EpicNotLoggedIn = 2,
	/** This epic account is already linked to this console auth */
	ThisEpicAccountLinked = 3,
	/** A different epic account is already linked to this console auth */
	OtherEpicAccountLinked = 4,
	/** No epic account is linked to this console auth yet */
	NoEpicAccountLinked = 5,
	/** This epic account is already linked to this console auth, but not the primary auth id */
	PrimaryIdNotLinked = 6,
	/** This epic account is already linked to this console auth, but not the secondary auth id */
	SecondaryIdNotLinked = 7,
};

UENUM(BlueprintType)
enum class ECreateAccountResult : uint8
{
	/** No account creation attempt was made */
	NotStarted = 0,
	/** Account creation pending */
	Pending = 1,
	/** Account creation succeeded and can login to new account */
	Success = 2,
	/** Could not login to console online account */
	Console_LoginFailed = 3,
	/** Can not use console account to associate auth due to already being associated with a different Epic account */
	Console_DuplicateAuthAssociation = 4,
	/** Account creation failed due to display name or email conflict */
	DuplicateAccount = 5,
	/** Account creation failed due another reason */
	GenericError = 6,
};

UENUM(BlueprintType)
enum class ELoginResult : uint8
{
	/** No login attempt was made */
	NotStarted = 0,
	/** Login is already pending */
	Pending = 1,
	/** Successfully logged in */
	Success = 2,
	/** Could not login to console online account */
	Console_LoginFailed = 3,
	/** Could not auth using console account */
	Console_AuthFailed = 4,
	/** Can not use console account to login due to missing auth */
	Console_MissingAuthAssociation = 5,
	/** Can not use console account to associate auth due to already being associated with a different Epic account */
	Console_DuplicateAuthAssociation = 6,
	/** Completed linking auth association from console to Epic account successfully */
	Console_AddedAuthAssociation = 7,
	/** Unknown error occured while attempting auth association */
	Console_AuthAssociationFailure = 8,
	/** Auth succeeded, but user is not entitled to play on this platform */
	Console_NotEntitled = 9,
	/** Failed to query console entitlements */
	Console_EntitlementCheckFailed = 10,
	/** Privilege Check failed for this user */
	Console_PrivilegeCheck = 11,
	/** User needs to patch their client or update their console */
	Console_PatchOrUpdateRequired = 12,
	/** Auth failed */
	AuthFailed = 13,
	/** refresh credentials used were no longer valid */
	AuthFailed_RefreshInvalid = 14,
	/** MFA verification failed */
	AuthFailed_InvalidMFA = 15,
	/** MFA verification required */
	AuthFailed_RequiresMFA = 16,
	/** Age Verification process must be completed */
	AuthFailed_AgeVerificationIncomplete = 17,
	/** User account has been locked out, eg. from too many failed logins */
	AuthFailed_LoginLockout = 18,
	/** Login credentials were reported invalid */
	AuthFailed_InvalidCredentials = 19,
	/** User needs to provide additional information or perform an additional corrective action to play */
	AuthFailed_CorrectiveActionRequired = 20,
	/** Parental controls */
	AuthParentalLock = 21,
	/** Auth succeeded but account is not allowed to play on this platform */
	PlatformNotAllowed = 22,
	/** Auth succeeded but user is not entitled to play */
	NotEntitled = 23,
	/** User is banned from this product */
	Banned = 24,
	/** EULA has not been accepted */
	EULACheckFailed = 25,
	/** Waiting room errored */
	WaitingRoomFailed = 26,
	/** Auth succeeded but service is currently unavailable for play */
	ServiceUnavailable = 27,
	/** Error occurred during login process */
	GenericError = 28,
	/** Error ocurred when secondary player can't join primary player's party */
	RegisterSecondaryPlayerInPrimaryPartyFailed = 29,
	/** Rejoin check failed */
	RejoinCheckFailure = 30,
	/** An HTTP request failed, possibly due to an uplink disconnect */
	ConnectionFailed = 31,
	/** A network connection is unavailable */
	NetworkConnectionUnavailable = 32,
	/** Login flow has been started when login was already in progress */
	AlreadyLoggingIn = 33,
	/** External auth association added to account */
	ExternalAuth_AddedAuthAssociation = 34,
	/** Failure communicating with external auth provider */
	ExternalAuth_ConnectionTimeout = 35,
	/** Failure to auth with external auth provider */
	ExternalAuth_AuthFailure = 36,
	/** Failed to associate external auth with backend */
	ExternalAuth_AssociationFailure = 37,
	/** Association between external auth and backend has not been made with these credentials */
	ExternalAuth_MissingAuthAssociation = 38,
	/** User canceled during external auth linking */
	ExternalAuth_Canceled = 39,
	/** Error creating our party */
	FailedToCreateParty = 40,
	/** Failed to download this user's profile */
	ProfileQueryFailed = 41,
	/** Failed to download the data encryption keychain*/
	QueryKeychainFailed = 42,
	/** Failed to download this user's saved settings */
	ClientSettingsDownloadFailed = 43,
	/** Failed to download this user's supervised settings */
	SupervisedSettingsDownloadFailed = 44,
	/** Failed to generate pin grant code */
	PinGrantFailure = 45,
	/** Account activation time out */
	PinGrantTimeout = 46,
	/** Pin code process canceled */
	PinGrantCanceled = 47,
	/** Timeout or hang during a login step. */
	LoginStepTimeout = 48,
};

USTRUCT()
struct FExchangeAccessParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString EntitlementId;

	UPROPERTY()
	FString ReceiptId;

	UPROPERTY()
	FString VendorReceipt;

	UPROPERTY()
	FString AppStore;

};

USTRUCT()
struct FGiftMessage
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString GiftCode;

	UPROPERTY()
	FString SenderName;

};

UCLASS(Config=Game)
class ACCOUNT_API UOnlineAccountCommon : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	FString AvailabilityServiceGameName;

	UPROPERTY(Config)
	bool bRequireLightswitchAtStartup;

	UPROPERTY(Config)
	FString EulaKey;

	UPROPERTY(Config)
	TArray<FString> EulaKeys;

	UPROPERTY(Config)
	TMap<FString, FString> EulaKeyMapping;

	UPROPERTY(Config)
	bool bEnableWaitingRoom;

	UPROPERTY(Config)
	TArray<FWebEnvUrl> WebCreateEpicAccountUrl;

	UPROPERTY(Config)
	bool bAllowLocalLogout;

	UPROPERTY(Config)
	FString RedeemAccessUrl;

	UPROPERTY(Config)
	FString RequestFreeAccessUrl;

	UPROPERTY(Config)
	FString RealGameAccessUrl;

	UPROPERTY(Config)
	float SkipRedeemOfflinePurchasesChance;

	UPROPERTY(Config)
	bool bUseFreeAccessInsteadOfGameAccess;

	UPROPERTY(Config)
	bool bShouldGrantFreeAccess;

	UPROPERTY(Config)
	bool bAllowHomeSharingAccess;

	UPROPERTY(Config)
	bool bRequireUGCPrivilege;

	UPROPERTY(Config)
	float AccessGrantDelaySeconds;

	UPROPERTY(Transient)
	TObjectPtr<UWaitingRoomState> WaitingRoomState;

private:
	UPROPERTY(Config)
	float DefaultLoginStepTimeout;

	UPROPERTY(Config)
	TMap<FName, float> CustomLoginStepTimeouts;

	UPROPERTY(Config)
	bool bEnableDevLoginStepTimeouts;

};

