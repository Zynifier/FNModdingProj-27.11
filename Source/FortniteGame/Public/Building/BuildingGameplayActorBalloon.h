// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingGameplayActor.h"
#include "BuildingGameplayActorBalloon.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActorBalloon : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Replicated, Category="Balloons", meta=(ExposeOnSpawn))
	int32 BalloonLocationSelection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Balloons")
	float BalloonNoAim;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="Balloons")
	FVector CharVelZ;

};

