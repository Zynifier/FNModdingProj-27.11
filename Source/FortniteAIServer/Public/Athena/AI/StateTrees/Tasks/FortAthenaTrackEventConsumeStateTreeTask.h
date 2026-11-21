// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "StateTreeTypes.h"
#include "FortAthenaTrackEventConsumeStateTreeTask.generated.h"

USTRUCT(meta=(Category="Fortnite|Smart Object", DisplayName="Track StateTree Events Consume"))
struct FFortAthenaTrackEventConsumeStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortAthenaTrackEventConsumeStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter", meta=(BaseStruct="/Script/FortniteAIServer.FortAthenaTrackEventStateTreeTaskStateTreeParameter"))
	FStateTreeStructRef ReferencedEvent;

};

