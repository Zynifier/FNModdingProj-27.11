// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortObjectArray.generated.h"

class UObject;

USTRUCT(BlueprintType)
struct FFortObjectArray
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	TArray<UObject*> Objects;

};

