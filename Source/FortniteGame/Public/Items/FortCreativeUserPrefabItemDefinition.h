// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortWorldItemDefinition.h"
#include "FortCreativeUserPrefabItemDefinition.generated.h"

UCLASS(MinimalAPI, BlueprintType)
class UFortCreativeUserPrefabItemDefinition : public UFortWorldItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="CreativeUserPrefab")
	FName UserSaveContentName;

};

