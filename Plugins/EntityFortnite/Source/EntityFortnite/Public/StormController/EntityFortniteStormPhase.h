// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "EntityFortniteStormPhase.generated.h"

USTRUCT(BlueprintType, meta=(IsBlueprintBase="true"))
struct ENTITYFORTNITE_API FEntityFortniteStormPhase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EntityFortniteStormPhase")
	float WaitTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EntityFortniteStormPhase")
	float ShrinkTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EntityFortniteStormPhase")
	float EndRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EntityFortniteStormPhase")
	float EndRadiusPercentage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EntityFortniteStormPhase")
	int32 DamageIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EntityFortniteStormPhase")
	bool bMoves;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EntityFortniteStormPhase")
	float MinMovementDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EntityFortniteStormPhase")
	float MaxMovementDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EntityFortniteStormPhase")
	float MinMovementDistancePercentage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EntityFortniteStormPhase")
	float MaxMovementDistancePercentage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="EntityFortniteStormPhase")
	FVector4 EndLocation;

};

