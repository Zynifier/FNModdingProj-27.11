// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Sound/FortFootstepBank.h"
#include "FortSurfaceTypeToSurfaceTypeTag.generated.h"

USTRUCT()
struct FFortSurfaceTypeToSurfaceTypeTag
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="SurfaceType")
	TEnumAsByte<EFortFootstepSurfaceType::Type> FootSurfaceType;

	UPROPERTY(EditAnywhere, Category="SurfaceType")
	TEnumAsByte<EPhysicalSurface> SurfaceType;

	UPROPERTY(EditAnywhere, Category="SurfaceType", meta=(Categories="Fort.SurfaceType"))
	FGameplayTag SurfaceTypeTag;

	UPROPERTY(EditAnywhere, Category="SurfaceType")
	bool bAllowsSurfaceRetriggerOfEvents;

};

UCLASS()
class UFortSurfaceTypeToSurfaceTypeTagMapping : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="SurfaceType")
	TArray<FFortSurfaceTypeToSurfaceTypeTag> TypeToTagMapping;

};

