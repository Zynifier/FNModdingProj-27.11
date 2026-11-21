// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateDrivenEvent.h"
#include "StateDrivenTagQuery.h"
#include "StateDrivenEvent_DamageInstance.generated.h"

USTRUCT(meta=(DisplayName="DamageInstance"))
struct FStateDrivenEvent_DamageInstance : public FStateDrivenEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenEvent_DamageInstance")
	FStateDrivenTagQuery InstigatorTagQuery;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenEvent_DamageInstance")
	FStateDrivenTagQuery DamageInstanceTagQuery;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenEvent_DamageInstance")
	float MinimumInstanceDamage;

};

