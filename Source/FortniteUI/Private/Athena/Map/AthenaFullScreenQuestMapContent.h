// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaChallengeListEntryContextInterface.h"
#include "Athena/AthenaMapScreenAnalyticsInterface.h"
#include "Athena/Map/AthenaFullScreenMapBase.h"
#include "Components/FortControllerComponent_PinQuest.h"
#include "AthenaFullScreenQuestMapContent.generated.h"

class UAthenaFullScreenMapControlsWidget;
class UAthenaQuestListContent;
class UFortQuestItemDefinition;
class UImage;
class UScaleBox;
class UUserWidget;

UCLASS(Abstract, Config=Game, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaFullScreenQuestMapContent : public UAthenaFullScreenMapBase, public IAthenaMapScreenAnalyticsInterface, public IAthenaChallengeListEntryContextInterface
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnChallengeCategoryChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnQuestListGainedFocus();

	UFUNCTION(BlueprintImplementableEvent)
	void OnQuestListLostFocus();

private:
	UFUNCTION()
	void HandleControlsSortButtonClicked();

	UFUNCTION()
	void HandleInspectItemsButtonClicked();

	UFUNCTION()
	void HandlePinnedQuestsChanged(const FAthenaPinnedQuestData& PinnedQuestData);

	UFUNCTION()
	void HandlePinSelectedCategoryButtonClicked();

	UFUNCTION()
	void HandlePinSelectedQuestButtonClicked();

	UFUNCTION()
	void HandleSortTypeTextChanged(const FText& TypeText);

	UFUNCTION()
	void HandleViewPlaylistButtonClicked(const FString& IslandMnemonic, const FName PlaylistName);

	UFUNCTION()
	void OnListViewScrolled(float OffsetInItems, float DistanceRemaining);

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UAthenaFullScreenMapControlsWidget> ControlsPanel;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaFullScreenQuestMapContent", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UAthenaQuestListContent> QuestPanel;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_CustomMapBackground;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScaleBox> ScaleBox_CustomMapContent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUserWidget> CustomMapWidgetInstance;

	UPROPERTY()
	TObjectPtr<UFortQuestItemDefinition> CachedPinnedQuestDefinition;

	UPROPERTY(Config)
	bool bDisableDisplayMapInCreative;

};

