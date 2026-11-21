// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/MovementComponent.h"
#include "MovementComp_Tracer.generated.h"

UCLASS()
class UMovementComp_Tracer : public UMovementComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement")
	float Speed;

};

