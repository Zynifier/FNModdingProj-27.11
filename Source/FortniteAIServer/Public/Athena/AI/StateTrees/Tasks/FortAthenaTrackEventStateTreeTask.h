// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateTreeTaskBase.h"
#include "FortAthenaTrackEventStateTreeTask.generated.h"

USTRUCT(meta=(Category="Fortnite|Smart Object", DisplayName="Track StateTree Events"))
struct FFortAthenaTrackEventStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagQuery EventTagQuery;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTag StateTreeEventTag;

};

USTRUCT()
struct FFortAthenaTrackEventStateTreeTaskStateTreeParameter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	bool bHasReceivedTrackedEvent;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTag ReceivedEventTag;

};

USTRUCT()
struct FFortAthenaTrackEventStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Output")
	FFortAthenaTrackEventStateTreeTaskStateTreeParameter OutParameter;

};

