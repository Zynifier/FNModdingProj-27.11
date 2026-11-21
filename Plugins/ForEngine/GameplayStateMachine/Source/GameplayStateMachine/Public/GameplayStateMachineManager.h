// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "GameplayStateMachineManager.generated.h"

class UGameplayStateMachine;
class UGameplayStateMachineManager;

USTRUCT(BlueprintType)
struct GAMEPLAYSTATEMACHINE_API FGameplayStateMachineItem : public FFastArraySerializerItem
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TObjectPtr<UGameplayStateMachine> StateMachine;

	UPROPERTY(Transient)
	float BeginStateDelay;

	UPROPERTY(Transient)
	float InitializationTime;

};

USTRUCT()
struct GAMEPLAYSTATEMACHINE_API FGameplayStateMachineArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, NotReplicated, Export, meta=(EditInline="true"))
	TObjectPtr<UGameplayStateMachineManager> StateMachineManager;

protected:
	UPROPERTY(Transient)
	TArray<FGameplayStateMachineItem> StateMachineItems;

};

UCLASS(BlueprintType, Blueprintable, meta=(BlueprintSpawnableComponent))
class GAMEPLAYSTATEMACHINE_API UGameplayStateMachineManager : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, Replicated)
	FGameplayStateMachineArray StateMachineList;

};

