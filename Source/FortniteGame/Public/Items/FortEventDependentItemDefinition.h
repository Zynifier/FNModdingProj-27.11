// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortEventDependentItemDefinition.generated.h"

class UFortAccountItemDefinition;

UCLASS(HideCategories=("FrontendPreview", "AccountItem", "Sacrifice", "Conversion", "Level", "Display", "FortItemDefinition", "Functionality", "InventoryLimit", "OwnedTags", "Tooltips", "Rating", "Series"))
class UFortEventDependentItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="Event")
	FString CalendarChannelName;

	UPROPERTY(EditDefaultsOnly, Category="Event")
	FName RequiredEventTag;

	UPROPERTY(EditDefaultsOnly, Category="Event")
	TObjectPtr<UFortAccountItemDefinition> TargetReplacementItem;

};

