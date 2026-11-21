// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortQuestMapCosmeticListWidget.generated.h"

class UFortItemDefinition;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortQuestMapCosmeticListWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Quest Map Cosmetic Widget")
	TArray<UFortItemDefinition*> GetDisplayItemDefs() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Quest Map Cosmetic Widget")
	void UpdateCosmeticListDisplay();

};

