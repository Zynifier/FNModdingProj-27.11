// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUrgentQuestData.h"
#include "Quests/FortQuestItemDefinition_Athena.h"
#include "FortUrgentQuestItemDefinition.generated.h"

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "FortItemDefinition", "Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "FortItemDefinition"))
class UFortUrgentQuestItemDefinition : public UFortQuestItemDefinition_Athena
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const FUrgentQuestData& GetUrgentQuestData() const;

protected:
	UPROPERTY(EditAnywhere, Category="Transient")
	FUrgentQuestData UrgentQuestData;

};

