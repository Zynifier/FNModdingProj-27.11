// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AI/BehaviorInjection/FortInjectedBehavior.h"
#include "FortItemInjectedBehaviorDataTable.generated.h"

class UFortItemDefinition;

USTRUCT()
struct FFortItemInjectedBehaviorsDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ItemBehavior")
	TSoftObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(EditAnywhere, Category="ItemBehavior")
	TArray<FFortInjectedBehaviorEntry> InjectedBehaviors;

};

