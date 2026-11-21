// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortGliderSpawnComponent.generated.h"

class AFortPlayerParachute;
class UAthenaGliderItemDefinition;

UCLASS(Transient, MinimalAPI)
class UFortGliderSpawnComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UAthenaGliderItemDefinition> GliderDef;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerParachute> Parachute;

};

