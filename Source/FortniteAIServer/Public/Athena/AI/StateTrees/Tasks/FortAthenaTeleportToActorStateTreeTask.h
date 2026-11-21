// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "StateTreeTaskBase.h"
#include "FortAthenaTeleportToActorStateTreeTask.generated.h"

class AActor;

USTRUCT(meta=(DisplayName="(Fortnite) Teleport to Actor"))
struct FFortAthenaTeleportToActorStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortAthenaTeleportToActorStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> Actor;

	UPROPERTY(EditAnywhere, Category="Parameter")
	TObjectPtr<AActor> TargetActor;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FVector TeleportRelativeLocation;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FRotator TeleportRelativeRotation;

};

