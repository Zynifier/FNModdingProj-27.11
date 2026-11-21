// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ReplicatedMontagePair.generated.h"

class UAnimMontage;

USTRUCT()
struct FReplicatedMontagePair
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UAnimMontage> Montage1;

	UPROPERTY()
	TObjectPtr<UAnimMontage> Montage2;

	UPROPERTY()
	FName Section1;

	UPROPERTY()
	FName Section2;

	UPROPERTY()
	int8 RepIndex;

};

