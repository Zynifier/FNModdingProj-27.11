// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "FortCreativeOptionVariableBase.generated.h"

USTRUCT(BlueprintType)
struct FCreativeOptionVariableBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeOptionVariableBase")
	FGameplayTag VariableTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="CreativeOptionVariableBase")
	int32 Value;

};

