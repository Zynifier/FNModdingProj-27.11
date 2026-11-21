// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_GravityMultiplier.generated.h"

class UFortSharedGravityMovementData;

USTRUCT(BlueprintType)
struct FGravityMovementData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="GravityMultiplier")
	float GravityZScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="GravityMultiplier")
	float VehicleGravityZScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="GravityMultiplier")
	float JumpZVelocityOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="GravityMultiplier")
	float JumpHorizontalAccelerationOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="GravityMultiplier")
	float JumpHorizontalVelocityOverride;

};

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_GravityMultiplier : public AFortAthenaMutator
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="GravityMultiplier")
	int32 GravityOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="GravityMultiplier")
	TObjectPtr<UFortSharedGravityMovementData> GravityPresets;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="GravityMultiplier")
	TArray<FGravityMovementData> CustomGravityData;

};

UCLASS()
class UFortSharedGravityMovementData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortSharedGravityMovementData")
	TArray<FGravityMovementData> GravityData;

};

