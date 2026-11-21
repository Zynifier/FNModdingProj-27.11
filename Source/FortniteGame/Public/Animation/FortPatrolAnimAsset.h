// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Animation/AnimInputs/FortAnimInput_PatrolAnimSet.h"
#include "FortCombatTypes.h"
#include "FortPatrolAnimAsset.generated.h"

class UFortPatrolAnimAsset;

USTRUCT(BlueprintType)
struct FFortPatrolAnimSetWeaponPair
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
	TEnumAsByte<EFortWeaponCoreAnimation::Type> WeaponType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Default")
	TObjectPtr<UFortPatrolAnimAsset> DataAsset;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortPatrolAnimAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AnimSet")
	FFortAnimInput_PatrolAnimSet AnimSet;

};

