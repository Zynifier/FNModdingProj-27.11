// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortDeathCauseEnum.h"
#include "FortDeathTypes.generated.h"

class AActor;

USTRUCT(BlueprintType)
struct FDeathInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="DeathInfo")
	TWeakObjectPtr<AActor> FinisherOrDowner;

	UPROPERTY(BlueprintReadOnly, NotReplicated, Category="DeathInfo")
	TWeakObjectPtr<AActor> Downer;

	UPROPERTY(BlueprintReadOnly, Category="DeathInfo")
	bool bDBNO;

	UPROPERTY(BlueprintReadOnly, Category="DeathInfo")
	EDeathCause DeathCause;

	UPROPERTY(BlueprintReadOnly, Category="DeathInfo")
	uint8 DeathClassSlot;

	UPROPERTY(BlueprintReadOnly, Category="DeathInfo")
	float Distance;

	UPROPERTY(BlueprintReadOnly, Category="DeathInfo")
	FVector DeathLocation;

	UPROPERTY(BlueprintReadOnly, Category="DeathInfo")
	bool bInitialized;

	UPROPERTY(BlueprintReadOnly, Category="DeathInfo")
	FGameplayTagContainer DeathTags;

	UPROPERTY(BlueprintReadOnly, Category="DeathInfo")
	FGameplayTagContainer FinisherOrDownerTags;

	UPROPERTY(BlueprintReadOnly, Category="DeathInfo")
	FGameplayTagContainer VictimTags;

};

