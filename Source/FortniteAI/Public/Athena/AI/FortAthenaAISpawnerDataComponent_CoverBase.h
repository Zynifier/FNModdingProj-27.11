// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent.h"
#include "FortAthenaAISpawnerDataComponent_CoverBase.generated.h"

class UNavigationQueryFilter;

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_CoverBase : public UFortAthenaAISpawnerDataComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAISpawnerDataComponent_CoverBase", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UNavigationQueryFilter> CoverPositionFilterClass;

	UPROPERTY(EditDefaultsOnly, Category="Retreat", meta=(AllowPrivateAccess="true"))
	FVector CoverBoxExtent;

	UPROPERTY(EditDefaultsOnly, Category="Retreat", meta=(AllowPrivateAccess="true"))
	float CoverOffset;

};

