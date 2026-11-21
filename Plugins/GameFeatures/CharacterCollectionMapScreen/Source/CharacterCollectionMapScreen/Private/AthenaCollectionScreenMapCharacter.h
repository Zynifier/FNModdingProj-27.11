// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AthenaCollectionScreenMapBase.h"
#include "AthenaCollectionScreenMapCharacter.generated.h"

class UCollectionScreenServiceVisualData;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaCollectionScreenMapCharacter : public UAthenaCollectionScreenMapBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="AthenaCollectionScreenMapCharacter")
	TObjectPtr<UCollectionScreenServiceVisualData> SharedServiceVisualData;

};

