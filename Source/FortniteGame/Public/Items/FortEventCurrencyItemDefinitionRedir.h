// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortPersistentResourceItemDefinition.h"
#include "FortEventCurrencyItemDefinitionRedir.generated.h"

class UFortItemDefinition;

UCLASS()
class UFortEventCurrencyItemDefinitionRedir : public UFortPersistentResourceItemDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UFortItemDefinition> CurrentCurrencyItem;

};

