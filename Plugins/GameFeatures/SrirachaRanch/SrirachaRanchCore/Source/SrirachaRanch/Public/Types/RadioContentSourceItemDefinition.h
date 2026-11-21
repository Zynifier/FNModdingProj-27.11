// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItemDefinition.h"
#include "RadioContentSourceItemDefinition.generated.h"

class UFortStreamMediaSource;

UENUM(BlueprintType)
enum class EOnlineRadioSourceType : uint8
{
	Epic = 0,
};

UCLASS(HideCategories=("AccountItem", "Sacrifice", "Conversion", "Level", "Functionality", "InventoryLimit", "Rating", "FrontendPreview"))
class URadioContentSourceItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RadioResource")
	FString ResourceID;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RadioResource")
	TObjectPtr<UFortStreamMediaSource> MediaSource;

};

