// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataProviders/AIDataProvider.h"
#include "Engine/EngineTypes.h"
#include "EnvironmentQuery/EnvQueryTest.h"
#include "FortQueryTest_ValidSurface.generated.h"

class AActor;
class UPhysicalMaterial;

UCLASS()
class UFortQueryTest_ValidSurface : public UEnvQueryTest
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Test|Ground Trace")
	FAIDataProviderFloatValue Radius;

	UPROPERTY(EditDefaultsOnly, Category="Test|Ground Trace")
	FAIDataProviderFloatValue TraceOffsetUp;

	UPROPERTY(EditDefaultsOnly, Category="Test|Ground Trace")
	FAIDataProviderFloatValue TraceOffsetDown;

	UPROPERTY(EditDefaultsOnly, Category="Test|Ground Trace")
	TEnumAsByte<ECollisionChannel> TraceCollisionChannel;

	UPROPERTY(EditDefaultsOnly, Category="Test|Flatness")
	FAIDataProviderFloatValue FlatSurfaceToleranceZ;

	UPROPERTY(EditDefaultsOnly, Category="Test|Physical Materials")
	TArray<TSoftObjectPtr<UPhysicalMaterial>> SurfaceMaterials;

	UPROPERTY(EditDefaultsOnly, Category="Test|Physical Materials")
	bool bAreSurfaceMaterialsValid;

	UPROPERTY(EditDefaultsOnly, Category="Test|Actor Classes", meta=(AllowAbstract="true"))
	TArray<TSoftClassPtr<AActor>> ValidHitActorClasses;

	UPROPERTY(EditDefaultsOnly, Category="Test|Actor Classes", meta=(AllowAbstract="true"))
	TArray<TSoftClassPtr<AActor>> InvalidHitActorClasses;

};

