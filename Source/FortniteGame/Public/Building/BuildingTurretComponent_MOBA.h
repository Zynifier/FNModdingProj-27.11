// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingTurretComponent.h"
#include "BuildingTurretComponent_MOBA.generated.h"

class AActor;

USTRUCT()
struct FMOBATurretPrioritySetting
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Priority", meta=(ClampMin="0", UIMin="0"))
	int32 AIPriority;

	UPROPERTY(EditDefaultsOnly, Category="Priority", meta=(ClampMin="0", UIMin="0"))
	int32 PlayerPriority;

	UPROPERTY(EditDefaultsOnly, Category="Priority", meta=(ClampMin="0", UIMin="0"))
	int32 BuildingPriority;

};

UCLASS(BlueprintType, meta=(BlueprintSpawnableComponent))
class UBuildingTurretComponent_MOBA : public UBuildingTurretComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="TurretComponent")
	virtual void OnAllyHarmed(AActor* InAllyActor, AActor* InHarmingActor);

protected:
	UPROPERTY(EditDefaultsOnly, Category="TargetingPriority")
	FMOBATurretPrioritySetting TargetingPriority;

};

