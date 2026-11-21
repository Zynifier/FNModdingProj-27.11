// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "StateTreeTypes.h"
#include "FortAthenaHandleSoftDisableGuardStateTreeTask.generated.h"

class AActor;

USTRUCT(meta=(Category="Fortnite|Smart Object", DisplayName="Handle Soft Disable Guard"))
struct FFortAthenaHandleSoftDisableGuardStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortAthenaHandleSoftDisableGuardStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter", meta=(BaseStruct="/Script/FortniteAIServer.FortAthenaSoftDisableStateTreeParameter"))
	FStateTreeStructRef SoftDisableStateReference;

	UPROPERTY(EditAnywhere, Category="Parameter")
	TArray<TObjectPtr<AActor>> ActorsToTeleportOnFailure;

};

