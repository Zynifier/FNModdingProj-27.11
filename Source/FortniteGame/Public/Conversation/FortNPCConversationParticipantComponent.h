// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Athena/AI/FortPlayerBotUtils.h"
#include "Conversation/FortNonPlayerConversationParticipantComponent.h"
#include "FortNPCConversationParticipantComponent.generated.h"

class AActor;
class AController;
class AFortAthenaAIBotController;
class AFortPlayerPawn;
class UAnimInstance;
class UBoxComponent;
class UFortAthenaAIRuntimeParameters_Conversation;
class UFortGameStateComponent_AffiliationManager;
class UFortTandemCharacterData;
class UPrimitiveComponent;
enum class EAlertLevel : uint8;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortNPCConversationParticipantComponent : public UFortNonPlayerConversationParticipantComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UFortTandemCharacterData* GetCharacterData() const;

protected:
	UFUNCTION()
	void OnBotControllerAlertLevelChanged(AFortAthenaAIBotController* BotController, EAlertLevel OldAlertLevel, EAlertLevel NewAlertLevel);

	UFUNCTION()
	void OnBotControllerDBNOStatusChanged(AFortAthenaAIBotController* BotController, bool bIsDBNO);

	UFUNCTION()
	void OnPlayerPawnOwnerDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnRep_CanStartConversation();

	UFUNCTION()
	void OnRep_ConversationModeActive();

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_CanStartConversation, Category="FortNPCConversationParticipantComponent")
	bool bCanStartConversation;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_ConversationModeActive, Category="FortNPCConversationParticipantComponent")
	bool bConversationModeActive;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerPawn> PlayerPawnOwner;

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaAIBotController> BotControllerOwner;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGameStateComponent_AffiliationManager> AffiliationManager;

	UPROPERTY(Transient)
	TObjectPtr<UFortAthenaAIRuntimeParameters_Conversation> ConversationRuntimeParameters;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Conversation Interaction")
	FName ConversationInteractionCollisionProfile;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Conversation Interaction")
	FVector ConversationInteractionBoxExtent;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Conversation Interaction")
	FVector ConversationInteractionBoxOffset;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UBoxComponent> InteractCollisionComponent;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Conversation")
	TObjectPtr<UFortTandemCharacterData> CharacterData;

	UPROPERTY(EditDefaultsOnly, Category="Conversation")
	TSubclassOf<UAnimInstance> NPCAnimLayer;

	UPROPERTY(EditDefaultsOnly, Category="Conversation")
	bool bTriggerGiftOnFirstConversationEnabled;

	UPROPERTY(EditDefaultsOnly, Replicated, Category="Conversation")
	bool bCanConverseWhenConverted;

	UPROPERTY(EditAnywhere, Category="Conversation")
	TArray<EAlertLevel> AcceptableAlertnessLevels;

};

