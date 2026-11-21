// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AttributeModifierInfo.generated.h"

class UGameplayEffect;

USTRUCT()
struct FAttributeModifierInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UGameplayEffect> InstantGEs;

};

