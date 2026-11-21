// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortItem.h"
#include "FortPlaysetPropItem.generated.h"

class UFortPlaysetPropItemDefinition;

UCLASS()
class UFortPlaysetPropItem : public UFortItem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UFortPlaysetPropItemDefinition> ItemDefinition;

};

