// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Collections/AthenaCollectionScreenBase.h"
#include "AthenaCollectionScreenFishing.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaCollectionScreenFishing : public UAthenaCollectionScreenBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="AthenaCollectionScreenFishing")
	FText RequiresProFishingRodText;

};

