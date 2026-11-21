// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Misc/DateTime.h"
#include "Misc/Timespan.h"
#include "Creative/FortCreativeLoadedLinkData.h"
#include "OnlineLinkId.h"
#include "FortPortalComponent.generated.h"

class AFortPlayerController;
class UTexture2DDynamic;
enum class EPortalLinkCodeLockStatus : uint8;

UENUM(BlueprintType)
enum class EPortalLinkCodeLockMode : uint8
{
	/** The link code is always unlocked with no cool-down period */
	NeverLocked = 0,
	/** Once set, the link code is locked for a time window determined by Portal.WindowLockExpirationSeconds (cvar) */
	WindowLocked = 1,
	/** Once set, The link code is always locked and cannot be changed */
	AlwaysLocked = 2,
};

UENUM(BlueprintType)
enum class EPortalLinkCodeLockStatus : uint8
{
	/** The link code is unlocked and has not yet been set */
	Unlocked_NotSet = 0,
	/** The link code is unlocked */
	Unlocked = 1,
	/** The link code is locked */
	Locked = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativeLinkDataError, FString, ErrorCode);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativeLinkDataLoaded, const FCreativeLoadedLinkData&, LinkData);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCreativeLinkThumbnailUpdated, bool, bSuccess);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnIslandModerationCheckComplete, bool, bValidIsland);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPortalLinkCodeLockStatusChanged, EPortalLinkCodeLockStatus, Status);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPortalLinkLockExpired, EPortalLinkCodeLockStatus, Status);

UCLASS(meta=(BlueprintSpawnableComponent))
class UFortPortalComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool CanSetLinkCode() const;

	UFUNCTION(BlueprintCallable)
	void CheckIslandModeration(const FCreativeLoadedLinkData& LinkData, const FOnIslandModerationCheckComplete& OnIslandModerationCheckComplete);

	UFUNCTION(BlueprintCallable)
	void ExpireLinkCodeLock();

	UFUNCTION(BlueprintPure)
	FString GetAccountIdOwnerOfIsland() const;

	UFUNCTION(BlueprintPure)
	FTimespan GetRemainingLockDuration() const;

	UFUNCTION(BlueprintPure)
	bool HasValidLinkData() const;

	UFUNCTION(BlueprintPure)
	bool IsPartyEligibleForMatchmaking() const;

	UFUNCTION(BlueprintPure)
	bool IsPlayerEligibleToBeginMatchmaking(const AFortPlayerController* FortPC) const;

	UFUNCTION(BlueprintPure)
	bool IsWellKnownNameSupported() const;

	UFUNCTION(BlueprintPure)
	bool LinkRequiresCreativeContent();

	UFUNCTION(BlueprintPure)
	FString MakeLinkCodeWithVersioning(const FString& LinkCode, int32 Version) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ServerSetLinkCode(const FOnlineLinkId& InLinkId, bool bIgnoreCanSetLinkCode = false, bool bFromDAD = false, bool bCalledByModerator = false);

	UFUNCTION(BlueprintCallable)
	void SetLinkDataLoaded(const FCreativeLoadedLinkData& InLinkData);

	UFUNCTION(BlueprintCallable)
	void SetLockExpirationSecondsToNotOverrideCVar();

	UFUNCTION(BlueprintCallable)
	void SetLockOverrideExpirationSeconds(int32 NewExpirationSeconds);

	UFUNCTION(BlueprintCallable)
	void SetResetCodeAfterCooldown(bool bNewResetCodeAfterCooldown);

	UPROPERTY(BlueprintAssignable)
	FOnCreativeLinkDataLoaded OnLinkDataLoaded;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeLinkDataError OnLinkDataError;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeLinkThumbnailUpdated OnLinkThumbnailUpdated;

	UPROPERTY(BlueprintAssignable)
	FOnPortalLinkCodeLockStatusChanged OnPortalLinkCodeLockStatusChanged;

	UPROPERTY(BlueprintAssignable)
	FOnPortalLinkLockExpired OnPortalLinkLockExpired;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_LoadedLinkData, Category="FortPortalComponent")
	FCreativeLoadedLinkData LoadedLinkData;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_LinkDataErrorStatus, Category="FortPortalComponent")
	FString LinkDataErrorStatus;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortPortalComponent")
	TObjectPtr<UTexture2DDynamic> ThumbnailTexture;

	UPROPERTY(BlueprintReadWrite, Replicated, Category="FortPortalComponent")
	EPortalLinkCodeLockMode LinkCodeLockMode;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_LinkCodeLockStatus, Category="FortPortalComponent")
	EPortalLinkCodeLockStatus LinkCodeLockStatus;

	UPROPERTY(EditDefaultsOnly, Category="FortPortalComponent")
	bool bWindowLockedStartsLocked;

private:
	UFUNCTION()
	void OnLinkCodeLockExpired();

	UFUNCTION()
	void OnLinkThumbnailDownloaded(bool bSuccess, UTexture2DDynamic* InThumbnailTexture);

	UFUNCTION()
	void OnMinigameStarted();

	UFUNCTION()
	void OnRep_LinkCodeLockStatus();

	UFUNCTION()
	void OnRep_LinkDataErrorStatus();

	UFUNCTION()
	void OnRep_LoadedLinkData();

	UFUNCTION()
	void ServerSetLinkCode_Complete(bool bSuccess, const FString& ErrorMessage, const FCreativeLoadedLinkData& InLinkData);

	UPROPERTY(Transient, Replicated)
	bool bHasValidLinkData;

	UPROPERTY(Transient, Replicated)
	bool bLinkRequiresCreativeContent;

	UPROPERTY(Transient, Replicated)
	FDateTime LinkCodeLockExpirationTime;

};

