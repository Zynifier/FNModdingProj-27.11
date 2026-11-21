// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortCollectionBookProgressionRewardsPreviewWidget.generated.h"

class UFortCollectionBookProgressionRewardWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCollectionBookProgressionRewardsPreviewWidget : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCollectionBookProgressionRewardsPreviewWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCollectionBookProgressionRewardWidget> NextRewardWidget;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCollectionBookProgressionRewardsPreviewWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortCollectionBookProgressionRewardWidget> NextMajorRewardWidget;

};

