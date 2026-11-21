// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortPawnDamageData.generated.h"

class AActor;
class AController;
class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct FPawnDamageData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="PawnDamageData")
	TObjectPtr<AActor> DamagedActor;

	UPROPERTY(BlueprintReadOnly, Category="PawnDamageData")
	float Damage;

	UPROPERTY(BlueprintReadOnly, Category="PawnDamageData")
	TObjectPtr<AController> InstigatedBy;

	UPROPERTY(BlueprintReadOnly, Category="PawnDamageData")
	TObjectPtr<AActor> DamageCauser;

	UPROPERTY(BlueprintReadOnly, Category="PawnDamageData")
	FVector HitLocation;

	UPROPERTY(BlueprintReadOnly, Export, Category="PawnDamageData", meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> HitComponent;

	UPROPERTY(BlueprintReadOnly, Category="PawnDamageData")
	FName BoneName;

	UPROPERTY(BlueprintReadOnly, Category="PawnDamageData")
	FVector Momentum;

};

