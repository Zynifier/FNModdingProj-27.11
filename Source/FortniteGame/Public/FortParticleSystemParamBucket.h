// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Particles/ParticleSystemComponent.h"
#include "FortParticleSystemParamBucket.generated.h"

USTRUCT()
struct FFortParticleSystemParamBucket
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Particles")
	TArray<FParticleSysParam> Parameters;

};

