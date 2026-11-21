// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EntityActorComponent.h"
#include "PointLightComponentBase.generated.h"

class UVerseLightPropertiesBase;

UCLASS(Abstract)
class UPointLightComponentBase : public UEntityActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Replicated)
	TObjectPtr<UVerseLightPropertiesBase> ReplicatedLightProperties;

};

