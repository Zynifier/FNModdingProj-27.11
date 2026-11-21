// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CollectionBook/FortCollectionBookGenericRewardWidget.h"
#include "FortCollectionBookSectionCompletionRewardWidget.generated.h"

class UCommonActivatablePanelLegacy;
class UCommonButtonLegacy;
class UFortCollectionBookRewardModalWidget;
class UFortCollectionBookSection;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortCollectionBookSectionCompletionRewardWidget : public UFortCollectionBookGenericRewardWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="Collection Book", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> RewardDetailsButton;

	UPROPERTY(EditAnywhere, Category="Reward Modal")
	TSoftClassPtr<UFortCollectionBookRewardModalWidget> RewardDetailsModalWidgetClass;

	UPROPERTY(EditAnywhere, Category="Reward Modal")
	FText ModalTitle;

private:
	UFUNCTION()
	void HandleRewardDetailsModalWidgetDeactivated(UCommonActivatablePanelLegacy* DeactivatedPanel);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortCollectionBookRewardModalWidget> RewardDetailsModalWidget;

	UPROPERTY(Transient)
	TObjectPtr<UFortCollectionBookSection> Section;

};

