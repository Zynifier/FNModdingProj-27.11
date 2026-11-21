// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "AthenaMapMarkerItemDefinition.generated.h"

class AFortMapMarkerTopperActor;

UCLASS(BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaMapMarkerItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Visual")
	TSoftClassPtr<AFortMapMarkerTopperActor> TopperActorClass;

};

