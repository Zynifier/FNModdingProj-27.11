// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "CommonRotator.h"
#include "GameplayTagContainer.h"
#include "Types/SlateEnums.h"
#include "UObject/NoExportTypes.h"
#include "Building/SpatialGameplay/SpatialEnterExitContext.h"
#include "Building/SpatialGameplay/SpatialLoadingStateContext.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "FortMatchmakingKnobsSpinnerButton.generated.h"

class APlayerState;
class UCommonTextBlock;
class UFortCreativeOption;
class UFortEditableFilteredCountedTextBox;
class UFortUserPermissions;
class UMaterial;
class UObject;
class UPlaylistUserOptionBase;
class USizeBox;
class USocialUser;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHandleOptionWidgetGenerated, const UPlaylistUserOptionBase*, InPlaylistUserOption);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKnobDataInitialized, const UPlaylistUserOptionBase*, InPlaylistUserOption);

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortMatchmakingKnobsSpinnerButton : public UCommonRotator, public IUserObjectListEntry
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Matchmaking Knobs Button")
	FText GetDescription() const;

	UFUNCTION(BlueprintPure, Category="Matchmaking Knobs Button")
	FText GetTitleText() const;

	UFUNCTION(BlueprintPure)
	bool HasMatchingTags(FGameplayTagContainer Tags) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsUserOptionEnabledChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnLoadingStateChanged(bool bCurrentlyLoading);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNavigatedLeft();

	UFUNCTION(BlueprintImplementableEvent)
	void OnNavigatedRight();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSpinnerRotated(int32 Value, bool bUserInitiated);

	UFUNCTION(BlueprintImplementableEvent)
	void SetSpinnerOptionsVisiblity(bool bVisible);

	UPROPERTY(BlueprintAssignable)
	FOnKnobDataInitialized OnKnobDataInitialized;

	UPROPERTY(BlueprintAssignable)
	FOnHandleOptionWidgetGenerated OnHandleOptionWidgetGenerated;

protected:
	UFUNCTION()
	void OnLocalPlayerExperienceStateChanged(FEventMessageTag Channel, const FSpatialGameplayActorLoadingStateUpdatedPlayerContext& StateContext);

	UFUNCTION()
	void OnMinigameVolumeEntered(FEventMessageTag Channel, const FPlayerEnterSpatialActorContextLegacyMinigame& PlayerEnteredVolumeContext);

	UFUNCTION(BlueprintImplementableEvent)
	void ShouldHandleNavigation(bool& bOutShouldHandleNavigation, const EUINavigation NavigationType);

private:
	UPROPERTY()
	TObjectPtr<UObject> OptionDataObj;

	UPROPERTY()
	TObjectPtr<APlayerState> AssociatedPlayerState;

	UPROPERTY()
	TObjectPtr<UFortUserPermissions> RepresentedPlayer;

	UPROPERTY()
	TObjectPtr<UFortCreativeOption> CreativeOption;

	UPROPERTY()
	TObjectPtr<UMaterial> DisplayImageMaterial;

	UPROPERTY()
	TObjectPtr<USocialUser> SocialUser;

	UPROPERTY(EditDefaultsOnly, Category="FortMatchmakingKnobsSpinnerButton")
	bool bCanDisableFromUserOption;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMatchmakingKnobsSpinnerButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_TextEntry;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMatchmakingKnobsSpinnerButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortEditableFilteredCountedTextBox> FilteredTextEntry_Widget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMatchmakingKnobsSpinnerButton", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TextBlock_OptionDisplayName;

	UPROPERTY(BlueprintReadOnly, Category="FortMatchmakingKnobsSpinnerButton", meta=(AllowPrivateAccess))
	bool bIsUserOptionEnabled;

};

UCLASS()
class UFortUserPermissions : public UObject
{
	GENERATED_BODY()

};

