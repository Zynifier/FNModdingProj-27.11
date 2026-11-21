// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MVVMViewModelBase.h"
#include "Creative/FortCreativeLoadedLinkData.h"
#include "Online/FortSocialParty.h"
#include "FortActivityViewModel.generated.h"

class UFortGameActivity;
class UTexture2DDynamic;
class UTexture;
enum class EActivityImageLoadingState : uint8;
enum class EFortActivityIsLockedReason : uint8;
enum class ERatingsBoard : uint8;

UENUM(BlueprintType)
enum class EActivityImageLoadingState : uint8
{
	/** Image is unset */
	Unset = 0 UMETA(DisplayName="Unset"),
	/** Image is loading */
	Loading = 1 UMETA(DisplayName="Loading"),
	/** Image is loaded */
	Loaded = 2 UMETA(DisplayName="Loaded"),
	/** Error loading image */
	Error = 3 UMETA(DisplayName="Error"),
	Max = 4 UMETA(Hidden),
};

UCLASS(Config=Game, MinimalAPI, meta=(DisplayName="Discover Activity View Model"))
class UFortActivityViewModel : public UMVVMViewModelBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Discover Activity")
	bool DoesActivityRequirePurchase() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	EFortActivityIsLockedReason GetActivityLockedReason() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	const FText GetAgeRatingShortText() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	const FText GetAgeRatingText() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	UTexture2DDynamic* GetAgeRatingTexture() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	int32 GetCCUCount() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	FText GetDescription() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	FText GetDisplayName() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	FText GetDisplaySubName() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	EActivityImageLoadingState GetImageLoadingState() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	UTexture* GetImageTexture() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	FString GetIslandCreatorName() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	int32 GetMaxPlayersRangeMax() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	int32 GetMaxPlayersRangeMin() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	int32 GetMaxTeamSize() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	int32 GetNumFriendsPlaying() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	ERatingsBoard GetRatingBoard() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	const TArray<FText> GetRatingDescriptors() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	const TArray<FText> GetRatingInteractiveElements() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	FName GetReferencePanelName() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	FName GetReferenceSurfaceName() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	int32 GetTeamSizeRangeMax() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	int32 GetTeamSizeRangeMin() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	const bool HasAgeRating() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	bool IsActivityLocked() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	bool IsAgeRatingTextureRectangular() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	bool IsEpicCreated() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	bool IsEpicLabsCreated() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	bool IsEpicOriginalCreated() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	bool IsFavorite() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	const bool IsRatingNotApplicable() const;

	UFUNCTION(BlueprintPure, Category="Discover Activity")
	const bool IsRatingRefused() const;

	UFUNCTION(BlueprintCallable)
	void ResetAnalytics();

	UFUNCTION(BlueprintCallable)
	void StartActiveImpression();

	UFUNCTION(BlueprintCallable)
	void StartVisibilityImpression();

	UFUNCTION(BlueprintCallable)
	void StopActiveImpression();

	UFUNCTION(BlueprintCallable)
	void StopVisibilityImpression();

	UPROPERTY(BlueprintReadOnly, Category="Discover Activity", meta=(AllowPrivateAccess))
	bool bIsLeader;

	UPROPERTY(BlueprintReadOnly, Category="Discover Activity", meta=(AllowPrivateAccess))
	int32 PartySize;

	UPROPERTY(BlueprintReadOnly, Category="Discover Activity", meta=(AllowPrivateAccess))
	bool bIsCurrentActivity;

	UPROPERTY(BlueprintReadOnly, Category="Discover Activity", meta=(AllowPrivateAccess))
	EFortInvalidActivityReason InvalidActivityReason;

	UPROPERTY(BlueprintReadOnly, Category="Discover Activity", meta=(AllowPrivateAccess))
	bool bShouldShowIARCRating;

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortGameActivity> AssignedGameActivity;

	UPROPERTY(Config)
	TMap<uint32, ECreativeLinkPreviewSize> MinColumnSizeToImageSize;

};

