// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "Math/MathFwd.h"
#include "FortQueryTest_PointInBuildingFoundation.generated.h"

class ABuildingFoundation;
class UEnvQueryContext;

UCLASS()
class UFortQueryTest_PointInBuildingFoundation : public UEnvQueryTest
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Volumes", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UEnvQueryContext> BuildingFoundationContext;

	UPROPERTY(EditAnywhere, Category="Volumes", meta=(AllowPrivateAccess="true"))
	TSubclassOf<ABuildingFoundation> BuildingFoundationClass;

	UPROPERTY(EditAnywhere, Category="Volumes", meta=(AllowPrivateAccess="true"))
	FVector BoundingBoxScale;

};

