// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/NavAreas/FortNavArea.h"
#include "FortNavArea_SmashableJump.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortNavArea_SmashableJump : public UFortNavArea
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="NavArea")
	int32 Strength;

};

