// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortItem.h"
#include "FortEmporiumItem.generated.h"

class UFortEmporiumItemDefinition;

UCLASS()
class UFortEmporiumItem : public UFortItem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UFortEmporiumItemDefinition> ItemDefinition;

};

