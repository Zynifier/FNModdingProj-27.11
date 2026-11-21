// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CosmeticModifierTypes.generated.h"

class UObject;

USTRUCT()
struct FSoftModifierClassPtr
{
	GENERATED_BODY()

public:
	UPROPERTY(meta=(MustImplement="/Script/CosmeticFrameworkModifiers/CosmeticModifierInterface"))
	TSoftClassPtr<UObject> SoftClass;

};

