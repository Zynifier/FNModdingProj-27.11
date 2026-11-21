// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AI/FortAthenaAIBotEvaluator_Attack.h"
#include "FortAthenaAIBotEvaluator_TokenPosition.generated.h"

class UEnvQuery;
class UFortAICombatTokenConsumerComponent;
class UFortAICombatTokenProviderComponent;

USTRUCT()
struct FPositioningEQS
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="PositioningEQS")
	FGameplayTagQuery ItemTagQuery;

	UPROPERTY(EditDefaultsOnly, Category="PositioningEQS")
	TObjectPtr<UEnvQuery> QueryTemplate;

};

UCLASS(BlueprintType, Blueprintable)
class UFortAthenaAIBotEvaluator_TokenPosition : public UFortAthenaAIBotEvaluator_Attack
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotEvaluator_TokenPosition")
	TArray<FPositioningEQS> EQSs;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotEvaluator_TokenPosition")
	bool bAllowSamePositionSelection;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotEvaluator_TokenPosition")
	float TokenPositionCooldown;

	UPROPERTY(EditDefaultsOnly, Category="FortAthenaAIBotEvaluator_TokenPosition")
	float TokenPositionCooldownVariation;

	UPROPERTY(Transient)
	float NextPositionTimestamp;

	UPROPERTY(Transient)
	bool bHasCurrentDestination;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAICombatTokenConsumerComponent> CachedTokenConsumerComponent;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UFortAICombatTokenProviderComponent> CachedTokenProviderComponent;

	UPROPERTY(Transient)
	int32 RunningEQSRequestID;

};

