// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "StateTreeTaskBase.h"
#include "FortAthenaHandleSoftDisableStateTreeTask.generated.h"

class AActor;

USTRUCT(meta=(Category="Fortnite|Smart Object", DisplayName="Handle Soft Disable"))
struct FFortAthenaHandleSoftDisableStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTag StateTreeEventTag;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FVector TeleportOnNavmeshQueryBoxExtents;

	UPROPERTY(EditAnywhere, Category="Parameter")
	int32 MaxTeleportToTryPerActor;

};

USTRUCT()
struct FFortAthenaSoftDisableStateTreeParameter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	TArray<TObjectPtr<AActor>> ActorsToTeleportOnExit;

};

USTRUCT()
struct FFortAthenaHandleSoftDisableStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	TArray<TObjectPtr<AActor>> ActorsToCleanup;

	UPROPERTY(EditAnywhere, Category="Output")
	bool bHasReceivedSoftDisableEvent;

	UPROPERTY(EditAnywhere, Category="Output")
	FGameplayTag ReceivedSoftDisableEvent;

	UPROPERTY(EditAnywhere, Category="Output")
	FFortAthenaSoftDisableStateTreeParameter OutState;

};

