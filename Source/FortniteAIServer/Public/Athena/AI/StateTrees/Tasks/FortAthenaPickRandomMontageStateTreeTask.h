// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "StateTreeTaskBase.h"
#include "FortAthenaPickRandomMontageStateTreeTask.generated.h"

class UAnimMontage;

USTRUCT(BlueprintType)
struct FFortAthenaPickRandomMontageConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAthenaPickRandomMontageConfig")
	TObjectPtr<UAnimMontage> Montage;

	UPROPERTY(EditAnywhere, Category="FortAthenaPickRandomMontageConfig")
	int32 RandomWeight;

};

USTRUCT(meta=(DisplayName="(Fortnite) Pick random Montage"))
struct FFortAthenaPickRandomMontageStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FFortAthenaPickRandomMontageStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Parameter")
	TArray<FFortAthenaPickRandomMontageConfig> PossibleMontages;

	UPROPERTY(EditAnywhere, Category="Output")
	TObjectPtr<UAnimMontage> PickedMontage;

};

