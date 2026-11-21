// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "UObject/NoExportTypes.h"
#include "Creative/FortCreativeTypes.h"
#include "OnlineLinkId.h"
#include "FortGameActivity.generated.h"

class UFortGameActivity;
class UTexture2DDynamic;
enum class ECreativeLinkPreviewSize : uint8;
enum class EFortActivityIsLockedReason : uint8;
enum class ERatingsBoard : uint8;

UENUM(BlueprintType)
enum class EActivityCheckSolution : uint8
{
	None = 0,
	Purchase = 1,
	Install = 2,
	Settings = 3,
	LeavePartyAndPlayTutorial = 4,
};

UENUM(BlueprintType)
enum class EFortActivityIsLockedReason : uint8
{
	/** Content is not locked. */
	None = 0,
	/** User's rating is set below the content rating. */
	AgeRating = 1,
	/** User does not allow Creative on a Creative mode. */
	K3SAllowCreateSetting = 2,
	/** Additional K3S setting is blocking this mode */
	K3SOtherSetting = 3,
	/** Secondary player's rating is set below the content rating */
	SplitscreenRatingBlocked = 4,
	/** Secondary player does not allow Creative on a Creative mode */
	SplitscreenCreativeBlocked = 5,
	/** Secondary player is blocked by an additional K3S setting */
	SplitscreenOtherSetting = 6,
};

UENUM(BlueprintType)
enum class EFortActivityLockStatus : uint8
{
	Locked = 0,
	Unlocked = 1,
};

UENUM(BlueprintType)
enum class EFortActivityLockStatusReason : uint8
{
	None = 0,
	RatingThreshold = 1,
	Override = 2,
	Legacy = 3,
	Invalidated = 4,
	Unrated = 5,
};

UENUM(BlueprintType)
enum class EFortDiscoveryDisabledFeatures : uint8
{
	Undefined = 0,
	AllWrites = 1,
	Favorites = 2,
	PlayHistory = 3,
	Queues = 4,
	ForCabin = 5,
	DiscoverySurface = 6,
};

UENUM(BlueprintType)
enum class EFortDiscoveryOptionsOverride : uint8
{
	Undefined = 0,
	Privacy = 1,
	FillOnly = 2,
	OnlyFillSolo = 3,
};

UENUM(BlueprintType)
enum class EFortGameActivityType : uint8
{
	Undefined = 0,
	STW = 1,
	BR = 2,
	LTM = 3,
	CreativePublishedIsland = 4,
	CreativePersonalIsland = 5,
	Valkyrie = 6,
	ModeSet = 7,
	Reference = 8,
};

USTRUCT(BlueprintType)
struct FGameActivityCheck
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="GameActivityCheck")
	FText CheckText;

	UPROPERTY(BlueprintReadOnly, Category="GameActivityCheck")
	bool bPassedCheck;

	UPROPERTY(BlueprintReadOnly, Category="GameActivityCheck")
	EActivityCheckSolution Solution;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortGameActivity : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	TArray<FCreativeIslandDescriptionTag> GetActivityDescriptionTags() const;

	UFUNCTION(BlueprintPure)
	const FText GetAgeRatingShortText() const;

	UFUNCTION(BlueprintPure)
	const FText GetAgeRatingText() const;

	UFUNCTION(BlueprintPure)
	UTexture2DDynamic* GetAgeRatingTexture() const;

	UFUNCTION(BlueprintPure)
	bool GetIsFavorite() const;

	UFUNCTION(BlueprintPure)
	EFortActivityIsLockedReason GetIsLockedReason() const;

	UFUNCTION(BlueprintPure)
	const FString GetPreviewPath(const ECreativeLinkPreviewSize PreviewSize) const;

	UFUNCTION(BlueprintPure)
	const ERatingsBoard GetRatingBoard() const;

	UFUNCTION(BlueprintPure)
	const TArray<FText> GetRatingDescriptors() const;

	UFUNCTION(BlueprintPure)
	const TArray<FText> GetRatingInteractiveElements() const;

	UFUNCTION(BlueprintPure)
	const bool HasAgeRating() const;

	UFUNCTION(BlueprintPure)
	bool IsAgeRatingTextureRectangular() const;

	UFUNCTION(BlueprintPure)
	bool IsLocked() const;

	UFUNCTION(BlueprintPure)
	const bool IsRatingNotApplicable() const;

	UFUNCTION(BlueprintPure)
	const bool IsRatingRefused() const;

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortGameActivity")
	FOnlineLinkId LinkId;

	UPROPERTY(BlueprintReadOnly, Category="FortGameActivity")
	FString SupportCode;

	UPROPERTY(BlueprintReadOnly, Category="FortGameActivity")
	EFortGameActivityType Type;

	UPROPERTY(BlueprintReadOnly, Category="FortGameActivity")
	FString Title;

	UPROPERTY(BlueprintReadOnly, Category="FortGameActivity")
	FString Creator;

	UPROPERTY(BlueprintReadOnly, Category="FortGameActivity")
	FString CreatorAccountId;

	UPROPERTY(BlueprintReadOnly, Category="FortGameActivity")
	FString Tagline;

	UPROPERTY(BlueprintReadOnly, Category="FortGameActivity")
	FString Introduction;

	UPROPERTY(BlueprintReadOnly, Category="FortGameActivity")
	TArray<FString> DescriptionTags;

	UPROPERTY(BlueprintReadOnly, Category="FortGameActivity")
	FString StoreOfferId;

	UPROPERTY(BlueprintReadOnly, Category="FortGameActivity")
	FString OwnershipToken;

	UPROPERTY(BlueprintReadOnly, Category="FortGameActivity")
	int32 Matchmaking_MaximumNumberOfPlayers;

	UPROPERTY(BlueprintReadOnly, Category="FortGameActivity")
	int32 Matchmaking_PlayersPerTeam;

	UPROPERTY(BlueprintReadOnly, Category="FortGameActivity")
	int32 Matchmaking_MaximumSocialPartySize;

	UPROPERTY(BlueprintReadOnly, Category="FortGameActivity")
	bool bIsUsingMatchmakingV2Config;

	UPROPERTY(BlueprintReadOnly, Category="FortGameActivity")
	EMMSRulePreset Matchmaking_MMSType;

	UPROPERTY(BlueprintReadOnly, Category="FortGameActivity")
	EMMSPrivacy Matchmaking_MMSPrivacy;

	UPROPERTY(BlueprintReadOnly, Category="FortGameActivity")
	FDateTime SortDate;

	UPROPERTY(BlueprintReadOnly, Category="FortGameActivity")
	FDateTime LastVisited;

	UPROPERTY()
	FString VideoUID;

	UPROPERTY()
	TArray<FOnlineLinkId> ChildSetLinkIds;

	UPROPERTY()
	TArray<TObjectPtr<UFortGameActivity>> ChildActivitySet;

private:
	UPROPERTY()
	TArray<FString> PreviewPaths;

	UPROPERTY()
	TArray<FString> LogoPaths;

};

