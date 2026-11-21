// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Field/FieldSystemActor.h"
#include "TornadoRadialForceActor.generated.h"

class UOperatorField;
class URadialFalloff;
class URadialVector;

UCLASS(BlueprintType, Blueprintable)
class ATornadoRadialForce : public AFieldSystemActor
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="TornadoRadialForce", meta=(ExposeOnSpawn="TRUE"))
	float Radius;

	UPROPERTY(BlueprintReadWrite, Category="TornadoRadialForce", meta=(ExposeOnSpawn="TRUE"))
	float Strength;

	UPROPERTY(BlueprintReadOnly, Category="TornadoRadialForce")
	float StartTime;

	UPROPERTY(BlueprintReadWrite, Category="TornadoRadialForce", meta=(ExposeOnSpawn="TRUE"))
	float StopTime;

	UPROPERTY(BlueprintReadWrite, Category="TornadoRadialForce", meta=(ExposeOnSpawn="TRUE"))
	float IncomingDuration;

	UPROPERTY(BlueprintReadWrite, Category="TornadoRadialForce", meta=(ExposeOnSpawn="TRUE"))
	float OutgoingDuration;

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<URadialVector> RadialVector;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<URadialFalloff> RadialFalloff;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UOperatorField> OperatorField;

};

