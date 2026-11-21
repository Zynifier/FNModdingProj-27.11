// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "FortAthenaStateTreeCrouchTask.generated.h"

class AActor;

USTRUCT(meta=(DisplayName="(Fortnite) Crouch Task"))
struct FFortAthenaStateTreeCrouchTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortAthenaStateTreeCrouchTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> Actor;

};

