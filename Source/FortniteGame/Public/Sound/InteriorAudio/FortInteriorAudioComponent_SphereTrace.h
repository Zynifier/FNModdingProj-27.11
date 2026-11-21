// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Math/MathFwd.h"
#include "Sound/InteriorAudio/FortInteriorAudioComponent.h"
#include "FortInteriorAudioComponent_SphereTrace.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UFortInteriorAudioComponent_SphereTrace : public UFortInteriorAudioComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Trace Config", meta=(ClampMin="4"))
	int32 NumPoints;

	UPROPERTY(EditAnywhere, Category="Trace Config", meta=(ClampMin="10.000000"))
	float TraceRadius;

	UPROPERTY(EditAnywhere, Category="Trace Config")
	FVector TraceOrigin;

	UPROPERTY(EditAnywhere, Category="Trace Config", meta=(ClampMax="10", ClampMin="1"))
	int32 NumTracesPerFrame;

	UPROPERTY(EditAnywhere, Category="Trace Config")
	TEnumAsByte<ECollisionChannel> TraceChannel;

};

