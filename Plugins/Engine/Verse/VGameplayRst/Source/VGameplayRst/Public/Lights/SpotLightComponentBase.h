// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EntityActorComponent.h"
#include "SpotLightComponentBase.generated.h"

class UVerseLightPropertiesBase;

UCLASS(Abstract)
class USpotLightComponentBase : public UEntityActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Replicated)
	TObjectPtr<UVerseLightPropertiesBase> ReplicatedLightProperties;

};

