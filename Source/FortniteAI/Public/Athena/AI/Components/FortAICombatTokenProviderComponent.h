// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TimerHandle.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "FortAICombatTokenProviderComponent.generated.h"

class UEnvQuery;
class UFortAICombatTokenConsumerComponent;

USTRUCT()
struct FTokenProviderPositioningData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TokenProviderPositioningData")
	FGameplayTagContainer TagContainer;

	UPROPERTY(EditDefaultsOnly, Category="TokenProviderPositioningData")
	TObjectPtr<UEnvQuery> QueryTemplate;

	UPROPERTY(EditDefaultsOnly, Category="TokenProviderPositioningData")
	FScalableFloat QueryUpdateFrequency;

	UPROPERTY(EditDefaultsOnly, Category="TokenProviderPositioningData")
	FScalableFloat DistanceForResultsInvalidation;

	UPROPERTY(EditDefaultsOnly, Category="TokenProviderPositioningData")
	bool bOwnerRelativePositions;

	UPROPERTY(Transient)
	FTimerHandle RunQueryHandle;

	UPROPERTY(Transient)
	FVector LastQueryLocation;

};

USTRUCT()
struct FTokenType
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TokenType")
	FGameplayTagContainer TagContainer;

	UPROPERTY(EditDefaultsOnly, Category="TokenType")
	FScalableFloat NumberOfTokens;

	UPROPERTY(Transient, Export)
	TArray<TWeakObjectPtr<UFortAICombatTokenConsumerComponent>> Tokens;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class UFortAICombatTokenProviderComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="Token Provider", meta=(AllowPrivateAccess="true"))
	TArray<FTokenType> TokenTypes;

	UPROPERTY(EditDefaultsOnly, Category="Token Provider", meta=(AllowPrivateAccess="true"))
	TArray<FTokenProviderPositioningData> PositioningDatas;

};

