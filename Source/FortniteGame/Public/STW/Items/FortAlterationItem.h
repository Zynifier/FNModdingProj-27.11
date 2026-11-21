// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "FortAlterationItem.generated.h"

class UFortAlterationItemDefinition;

UCLASS()
class UFortAlterationItem : public UFortAccountItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Alteration", meta=(DisplayName="GetAlterationDefinition"))
	UFortAlterationItemDefinition* GetAlterationDefinitionBP() const;

};

