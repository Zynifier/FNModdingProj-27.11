// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Math/MathFwd.h"
#include "FortPocketLevel.generated.h"

class UWorld;

UCLASS()
class UFortPocketLevel : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Streaming")
	TSoftObjectPtr<UWorld> Level;

	UPROPERTY(EditAnywhere, Category="Streaming")
	FVector Bounds;

};

