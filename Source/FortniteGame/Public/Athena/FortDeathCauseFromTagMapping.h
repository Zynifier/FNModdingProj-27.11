// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "FortDeathCauseEnum.h"
#include "FortDeathCauseFromTagMapping.generated.h"

USTRUCT()
struct FFortTagToDeathCause
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Death")
	FGameplayTag DeathTag;

	UPROPERTY(EditAnywhere, Category="Death")
	EDeathCause DBNOCause;

	UPROPERTY(EditAnywhere, Category="Death")
	EDeathCause DeathCause;

};

UCLASS()
class UFortDeathCauseFromTagMapping : public UDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Death", meta=(TitleProperty="Death Cause Tags - (Order dictates priority of returning cause)"))
	TArray<FFortTagToDeathCause> TagToDeathCauseArray;

};

