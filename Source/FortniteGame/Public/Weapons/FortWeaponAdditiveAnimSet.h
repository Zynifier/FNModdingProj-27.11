// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Animation/AnimInputs/FortAnimInput_WeaponAdditiveAnimAsset.h"
#include "FortWeaponAdditiveAnimSet.generated.h"

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortWeaponAdditiveAnimSet : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	FFortAnimInput_WeaponAdditiveAnimAsset MaleBodyType_AnimAsset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	FFortAnimInput_WeaponAdditiveAnimAsset FemaleBodyType_AnimAsset;

};

