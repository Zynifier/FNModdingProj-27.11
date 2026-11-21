// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortDifficultyOptionCategory.generated.h"

UCLASS(Abstract, EditInlineNew, BlueprintType)
class UFortDifficultyOptionCategory : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="CategorySettings")
	bool bIsRequired;

	UPROPERTY(EditDefaultsOnly, Category="CategorySettings")
	bool bIsStatic;

	UPROPERTY(EditDefaultsOnly, Category="CategorySettings")
	bool bHasValueRange;

};

