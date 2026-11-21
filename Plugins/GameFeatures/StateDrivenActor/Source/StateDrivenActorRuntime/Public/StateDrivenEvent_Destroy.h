// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateDrivenEvent.h"
#include "StateDrivenTagQuery.h"
#include "StateDrivenEvent_Destroy.generated.h"

USTRUCT(meta=(DisplayName="Destroy"))
struct FStateDrivenEvent_Destroy : public FStateDrivenEvent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenEvent_Destroy")
	FStateDrivenTagQuery InstigatorTagQuery;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StateDrivenEvent_Destroy")
	FStateDrivenTagQuery DamageInstanceTagQuery;

};

