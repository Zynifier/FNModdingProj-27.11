// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Animation/AnimInputs/FortAnimInput_PlayerAnimAsset.h"
#include "FortWeaponAnimSet.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(LoadBehavior="LazyOnDemand"))
class UFortWeaponAnimSet : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AnimSet")
	float DelayBetweenFireAndFullBodySprint;

private:
	UPROPERTY(EditAnywhere, Category="AnimSet")
	FFortAnimInput_PlayerAnimAsset MaleAnimAsset;

	UPROPERTY(EditAnywhere, Category="AnimSet")
	FFortAnimInput_PlayerAnimAsset FemaleAnimAsset;

};

