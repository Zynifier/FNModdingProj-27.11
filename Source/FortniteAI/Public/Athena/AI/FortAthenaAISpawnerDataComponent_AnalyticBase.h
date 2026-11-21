// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AI/FortAthenaAIRuntimeParametersComponent.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent.h"
#include "FortAthenaAISpawnerDataComponent_AnalyticBase.generated.h"

UCLASS(MinimalAPI)
class UFortAthenaAIRuntimeParameters_Analytic : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FGameplayTagContainer OnDeathGameplayTags;

};

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_AnalyticBase : public UFortAthenaAISpawnerDataComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Common", meta=(AllowPrivateAccess="true"))
	FGameplayTagContainer OnDeathGameplayTags;

};

