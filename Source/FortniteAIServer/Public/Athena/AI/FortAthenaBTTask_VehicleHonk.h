// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "FortAthenaBTTask_VehicleHonk.generated.h"

UCLASS()
class UFortAthenaBTTask_VehicleHonk : public UBTTaskNode
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Honk", meta=(AllowPrivateAccess="true", UIMin="0.0"))
	float MaxHonkTime;

	UPROPERTY(EditAnywhere, Category="Honk", meta=(AllowPrivateAccess="true", UIMin="0.0"))
	float MinHonkTime;

	UPROPERTY(EditAnywhere, Category="Honk", meta=(AllowPrivateAccess="true"))
	float MaxFlickerTime;

	UPROPERTY(EditAnywhere, Category="Honk", meta=(AllowPrivateAccess="true"))
	float MinFlickerTime;

};

