// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortPersistableItemDefinition.h"
#include "FortProfileItemDefinition.generated.h"

UCLASS(Abstract, BlueprintType)
class UFortProfileItemDefinition : public UFortPersistableItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	uint8 bCanBeFavorite : 1;

	UPROPERTY()
	uint8 bCanBeMarkedSeen : 1;

	UPROPERTY()
	FString GrantToProfileType;

};

