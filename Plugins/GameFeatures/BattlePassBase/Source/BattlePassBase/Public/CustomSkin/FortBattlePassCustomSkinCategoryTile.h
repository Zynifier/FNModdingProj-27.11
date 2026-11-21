// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortBattlePassCustomSkinCategoryTile.generated.h"

class UFortBattlePassTile;
class UFortDynamicEntryBox;
class UProgressBar;
class URichTextBlock;

UCLASS(Abstract)
class UFortBattlePassCustomSkinCategoryTile : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortBattlePassCustomSkinCategoryTile(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable)
	void FocusTile(const int32 Index);

	UFUNCTION(BlueprintCallable)
	void SetPreviewedTile(const int32 Index);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnLockedProgressUpdated(const int32 CurrentlyOwnedBeforeCategory, const int32 TotalRewardsBeforeCategory, const float LockedProgress);

	UFUNCTION(BlueprintImplementableEvent)
	void OnLockedStateChanged(const bool bCategoryLocked);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOwnedTilesUpdated(const int32 CurrentlyOwnedRewards, const int32 TotalRewards, const float CategoryProgress);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UProgressBar> ProgressBar;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> FortDynamicEntryBox_Items;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> Text_CategoryTitle;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortBattlePassTile> PreviewedTile;

	UPROPERTY(BlueprintReadOnly, Category="FortBattlePassCustomSkinCategoryTile")
	int32 OwnedRewards;

};

