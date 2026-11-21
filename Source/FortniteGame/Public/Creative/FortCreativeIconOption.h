// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortCreativeIconOption.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FCreativeIconOption
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="CreativeIconOption")
	TSoftObjectPtr<UTexture2D> SmallIcon;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Category="CreativeIconOption")
	TSoftObjectPtr<UTexture2D> LargeIcon;

};

