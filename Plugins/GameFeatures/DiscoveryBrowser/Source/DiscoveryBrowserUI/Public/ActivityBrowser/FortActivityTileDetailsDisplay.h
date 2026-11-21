// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Creative/FortCreativeLoadedLinkData.h"
#include "FortActivityTileDetailsDisplay.generated.h"

class UCommonButtonBase;
class UCommonTextBlock;
class UFortActivityBrowserAttributionsModal;
class UFortActivityBrowserTag;
class UFortActivityCreatorPageView;
class UFortActivityDetailsModal;
class UFortActivityVideoCycle;
class UFortCampaignPurchaseScreen;
class UFortGameActivity;
class UTextBlock;
class UTexture;
enum class EFortActivityIsLockedReason : uint8;
enum class EFortInvalidActivityReason : uint8;

UCLASS(Abstract, Config=Game, meta=(DisableNativeTick))
class UFortActivityTileDetailsDisplay : public UCommonButtonBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnActivitySelected);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnActivityUnSelected);

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void BroadcastOnActivityConfirmed() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnRespondToTileViewVisibilityChange(bool bIsVisible);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateColumnSize(int32 NewColumnSize);

	UFUNCTION(BlueprintCallable)
	void UpdateActivitySelector();

protected:
	UFUNCTION(BlueprintPure)
	bool DoesActivityRequirePurchase() const;

	UFUNCTION(BlueprintPure)
	FString GetActivityCreatorDisplayText() const;

	UFUNCTION(BlueprintPure)
	EFortInvalidActivityReason GetInvalidActivityReason() const;

	UFUNCTION(BlueprintPure)
	EFortActivityIsLockedReason GetIsActivityLockedReason() const;

	UFUNCTION(BlueprintPure)
	bool IsActivityFavorited() const;

	UFUNCTION(BlueprintPure)
	bool IsActivityLocked() const;

	UFUNCTION(BlueprintPure)
	bool IsModeSetActivity() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnDetailsUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	void OnFriendsPlayingChanged(int32 NumPlaying);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsFavoriteChanged(const bool bIsFavorite);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLocalPlayerDemoted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLocalPlayerPromotedToLeader();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLogoImageChanged(const bool bIsLoading, const UTexture* Texture);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPartySizeChanged(const int32 PartySize);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreviewImageChanged(const bool bIsLoading, const UTexture* Texture);

	UFUNCTION(BlueprintImplementableEvent)
	void OnRequiresPurchaseChanged(const bool bRequiresPurchase);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTileActiveSet(const bool bIsTileActive);

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	void ShouldPlayTileVideo(bool& bOutResult);

	UFUNCTION(BlueprintCallable)
	void StartTileVideo();

	UFUNCTION(BlueprintCallable)
	void StopTileVideo();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateCCU(const int32 CCUCount);

	UFUNCTION(BlueprintCallable)
	void UpdateFromFortActivityViewModel();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateSqueegeeWidgets(UFortGameActivity* GameActivity);

	UPROPERTY(BlueprintAssignable)
	FOnActivitySelected OnActivitySelectedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnActivityUnSelected OnActivityUnSelectedDelegate;

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category="Tile Details")
	bool bShowDetailsButton;

	UPROPERTY(EditAnywhere, Category="Tile Details")
	int32 DefaultColumnSize;

private:
	UFUNCTION()
	void HandleActivitySelected();

	UFUNCTION()
	void HandleShowActivityDetails();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityTileDetailsDisplay", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ActivityName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityTileDetailsDisplay", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlayerCount;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityTileDetailsDisplay", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Favorite;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityTileDetailsDisplay", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Details;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityTileDetailsDisplay", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortActivityBrowserTag> ActivityBrowserTag_EpicOriginal;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityTileDetailsDisplay", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UTextBlock> Text_DebugId;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityTileDetailsDisplay", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortActivityVideoCycle> ActivityVideoCycleWidget;

	UPROPERTY(Config)
	TMap<uint32, ECreativeLinkPreviewSize> MinColumnSizeToImageSize;

	UPROPERTY(Config)
	uint8 MaxMobileColumnSize;

	UPROPERTY(Config)
	uint8 MinMobileColumnSize;

	UPROPERTY(Config)
	bool bIsVideoEnabledForDynamicTileSizingV2;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityTileDetailsDisplay")
	TSubclassOf<UFortActivityDetailsModal> ActivityDetailsModalClass;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityTileDetailsDisplay")
	TSubclassOf<UFortActivityCreatorPageView> ActivityCreatorPageViewClass;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityTileDetailsDisplay")
	TSubclassOf<UFortCampaignPurchaseScreen> ActivityCampaignPurchaseScreenClass;

	UPROPERTY(EditDefaultsOnly, Category="FortActivityTileDetailsDisplay")
	TSubclassOf<UFortActivityBrowserAttributionsModal> ActivityAttributionsClass;

};

