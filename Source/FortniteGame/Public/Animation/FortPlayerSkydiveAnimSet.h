// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Animation/AnimInputs/FortAnimInput_PlayerSkydiveAnimAsset.h"
#include "FortPlayerSkydiveAnimSet.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortPlayerSkydiveAnimSet : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="AnimSet")
	FFortAnimInput_PlayerSkydiveAnimAsset AnimAsset;

};

