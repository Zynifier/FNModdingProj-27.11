// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Animation/AnimInputs/FortAnimInput_PlayerAnimAsset.h"
#include "FortFirstPersonAnimAsset.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(LoadBehavior="LazyOnDemand"))
class UFortFirstPersonAnimAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortFirstPersonAnimAsset")
	FFortAnimInput_PlayerAnimAsset AnimSet;

};

