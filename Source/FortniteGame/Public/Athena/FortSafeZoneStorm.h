// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "GameFramework/Actor.h"
#include "FortSafeZoneStorm.generated.h"

UCLASS()
class AFortSafeZoneStorm : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="SafeZone")
	FComponentReference StormEffectsMeshRef;

};

