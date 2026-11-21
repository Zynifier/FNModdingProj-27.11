// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTabListWidgetBase.h"
#include "ItemPicker/FortItemPicker.h"
#include "FortHeroLoadoutHeroPicker.generated.h"

class UCommonButtonBase;
class UFortCampaignHeroLoadoutItem;
class UFortTabListWidgetBase_Legacy;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortHeroLoadoutHeroPicker : public UFortItemPickerBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AssociateFilterTabList(const UFortTabListWidgetBase_Legacy* ExternalFilterTabList);

	UFUNCTION(BlueprintCallable)
	FName GetCurrentlySelectedTab();

	UFUNCTION(BlueprintCallable)
	void SetTargetLoadoutSlot(const UFortCampaignHeroLoadoutItem* LoadoutItem, const FName& SlotName);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleDifferentTargetLoadoutSetBP();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleFilterTabSelectedBP(FName TabId);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortHeroLoadoutHeroPicker", meta=(EditInline="true"))
	TObjectPtr<UFortTabListWidgetBase_Legacy> ExternalFilterTabList;

	UPROPERTY(BlueprintReadOnly, Category="FortHeroLoadoutHeroPicker")
	TWeakObjectPtr<UFortCampaignHeroLoadoutItem> TargetLoadoutItem;

	UPROPERTY(BlueprintReadOnly, Category="FortHeroLoadoutHeroPicker")
	FName TargetSlotName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHeroLoadoutHeroPicker")
	TSubclassOf<UCommonButtonBase> FilterTabButtonType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, EditFixedSize, Category="FortHeroLoadoutHeroPicker")
	TMap<FName, FFortTabButtonLabelInfo> TabButtonLabelInfoMap;

private:
	UFUNCTION()
	void HandleFilterTabSelected(FName TabId);

	UFUNCTION(BlueprintCallable)
	void UpdateFilterTabList(FName PreviouslySelectedTab);

};

