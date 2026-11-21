// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent_PinQuest.h"
#include "FortHUDElementWidget.h"
#include "AthenaPinnedQuestInfo.generated.h"

class UFortLazyImage;
class UFortQuestObjectiveInfo;
enum class EFortRarity : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaPinnedQuestInfo : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnSetPinnedQuestInfo(const int32 Achieved, const int32 Required, const EFortRarity Rarity, const FText& Description);

private:
	UFUNCTION()
	void HandleCurrentQuestsChanged();

	UFUNCTION()
	void HandlePinnedQuestChanged(const FAthenaPinnedQuestData& PinnedQuestData);

	UFUNCTION()
	void HandleQuestUpdate(const UFortQuestObjectiveInfo* QuestObjective, bool bDisplayStatusUpdate, bool bDisplayAnnouncementUpdate);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLazyImage> LazyImage_PinColor;

	UPROPERTY(EditAnywhere, Category="AthenaPinnedQuestInfo")
	int32 NumAllowedQuestDescCharacters;

};

