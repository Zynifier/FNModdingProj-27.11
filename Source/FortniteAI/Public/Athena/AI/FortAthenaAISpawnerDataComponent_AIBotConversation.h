// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAIRuntimeParametersComponent.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_ConversationBase.h"
#include "FortAthenaAISpawnerDataComponent_AIBotConversation.generated.h"

class UAthenaDanceItemDefinition;
class UAthenaSpecialActorComponent;
class UFortAthenaNPCLoopStateComponent;
class UFortAthenaSpawnerDataBase;
class UFortNPCConversationParticipantComponent;
class UFortTandemCharacterData;

UCLASS()
class UFortAthenaAIRuntimeParameters_AIBotLoopSettings : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	uint8 bSpawnOutsideTheLoop : 1;

	UPROPERTY(Transient)
	uint8 bRespawnOustideTheLoop : 1;

	UPROPERTY(Transient)
	uint8 bRespawnAtOriginalSpawnLocation : 1;

	UPROPERTY(Transient)
	uint8 bRemoveInvulnerabilityOutsideSafeZone : 1;

	UPROPERTY(Transient)
	uint8 bDisableSpecialActorComponentUntilRespawn : 1;

};

UCLASS(MinimalAPI, BlueprintType)
class UFortAthenaAIRuntimeParameters_Conversation : public UFortAthenaAIRuntimeParameters
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	uint8 bEnterBTTaskConversationIfPlayerAround : 1;

	UPROPERTY(Transient)
	uint8 bCanConverseWhenConverted : 1;

	UPROPERTY(Transient)
	float EnterBTTaskConversationIfPlayerAroundDistSqr;

	UPROPERTY(Transient)
	float WaitTimeWhileNotInConversationState;

	UPROPERTY(Transient)
	float SecondsToDenyActorToWaitForConversation;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaDanceItemDefinition>> GreetingEmotes;

	UPROPERTY(Transient)
	float GreetingEmoteMaxDuration;

	UPROPERTY(Transient)
	TObjectPtr<UFortTandemCharacterData> CharacterData;

};

UCLASS(MinimalAPI)
class UFortAthenaAISpawnerDataComponent_AIBotConversation : public UFortAthenaAISpawnerDataComponent_ConversationBase
{
	GENERATED_BODY()

protected:
#if WITH_EDITOR
	UFUNCTION(BlueprintCallable, Category="Editor Scripting | AI Spawner Data")
	void PropagateReleaseVersionToCharacterData(UFortAthenaSpawnerDataBase* SourceSpawnerData);
#endif

private:
	UPROPERTY(EditDefaultsOnly, Category="Conversation", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortNPCConversationParticipantComponent> ConversationComponentClass;

	UPROPERTY(EditDefaultsOnly, Category="Conversation", meta=(AllowPrivateAccess="true"))
	FGameplayTag ConversationEntryTag;

	UPROPERTY(EditDefaultsOnly, Category="Conversation", meta=(AllowPrivateAccess="true"))
	FGameplayTag InteractorParticipantTag;

	UPROPERTY(EditDefaultsOnly, Category="Conversation", meta=(AllowPrivateAccess="true"))
	FGameplayTag SelfParticipantTag;

	UPROPERTY(EditDefaultsOnly, Category="Conversation", meta=(AllowPrivateAccess="true"))
	FScalableFloat EnterBTTaskConversationIfPlayerAround;

	UPROPERTY(EditDefaultsOnly, Category="Conversation", meta=(AllowPrivateAccess="true"))
	FScalableFloat EnterBTTaskConversationIfPlayerAroundDist;

	UPROPERTY(EditDefaultsOnly, Category="Conversation", meta=(AllowPrivateAccess="true"))
	FScalableFloat WaitTimeWhileNotInConversationState;

	UPROPERTY(EditDefaultsOnly, Category="Conversation", meta=(AllowPrivateAccess="true"))
	FScalableFloat SecondsToDenyActorToWaitForConversation;

	UPROPERTY(EditAnywhere, Category="Conversation", meta=(AllowPrivateAccess="true"))
	TArray<TObjectPtr<UAthenaDanceItemDefinition>> GreetingEmotes;

	UPROPERTY(EditAnywhere, Category="Conversation", meta=(AllowPrivateAccess="true"))
	FScalableFloat GreetingEmoteMaxDuration;

	UPROPERTY(EditDefaultsOnly, Category="Conversation")
	TObjectPtr<UFortTandemCharacterData> CharacterData;

	UPROPERTY(EditDefaultsOnly, Category="Interaction", meta=(AllowPrivateAccess="true"))
	FName ConversationInteractionCollisionProfile;

	UPROPERTY(EditDefaultsOnly, Category="Interaction", meta=(AllowPrivateAccess="true"))
	FVector ConversationInteractionBoxExtent;

	UPROPERTY(EditDefaultsOnly, Category="Interaction", meta=(AllowPrivateAccess="true"))
	FVector ConversationInteractionBoxOffset;

	UPROPERTY(EditAnywhere, Category="LoopState", meta=(AllowPrivateAccess="true"))
	FScalableFloat SpawnOutOfTheLoop;

	UPROPERTY(EditAnywhere, Category="LoopState", meta=(AllowPrivateAccess="true"))
	FScalableFloat RespawnOutsideTheLoop;

	UPROPERTY(EditAnywhere, Category="LoopState", meta=(AllowPrivateAccess="true"))
	FScalableFloat RespawnAtOriginalSpawnLocation;

	UPROPERTY(EditAnywhere, Category="LoopState", meta=(AllowPrivateAccess="true"))
	FScalableFloat RemoveInvulnerabilityOutsideSafeZone;

	UPROPERTY(EditDefaultsOnly, Category="LoopState", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UFortAthenaNPCLoopStateComponent> NPCLoopStateComponentClass;

	UPROPERTY(EditAnywhere, Category="SpecialActor", meta=(AllowPrivateAccess="true"))
	FScalableFloat UseSpecialActorComponent;

	UPROPERTY(EditAnywhere, Category="SpecialActor", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UAthenaSpecialActorComponent> SpecialActorComponentClass;

	UPROPERTY(EditAnywhere, Category="SpecialActor", meta=(AllowPrivateAccess="true"))
	FScalableFloat BlockSpecialActorUntilOutsideTheLoop;

	UPROPERTY(EditAnywhere, Category="Conversation", meta=(AllowPrivateAccess))
	bool bCanConverseWhenConverted;

};

