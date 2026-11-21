// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortItemDefinition.h"
#include "FortMetadataItemDefinition.generated.h"

UCLASS(NotBlueprintable)
class UFortMetadataItemDefinition : public UFortItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Level")
	int32 MinLevel;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Level")
	int32 MaxLevel;

};

