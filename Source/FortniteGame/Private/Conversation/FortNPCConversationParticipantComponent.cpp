// Copyright Epic Games, Inc. All Rights Reserved.

#include "Conversation/FortNPCConversationParticipantComponent.h"
#include "Net/UnrealNetwork.h"

UFortTandemCharacterData* UFortNPCConversationParticipantComponent::GetCharacterData() const
{
	return nullptr;
}

void UFortNPCConversationParticipantComponent::OnBotControllerAlertLevelChanged(AFortAthenaAIBotController* BotController, EAlertLevel OldAlertLevel, EAlertLevel NewAlertLevel)
{
}

void UFortNPCConversationParticipantComponent::OnBotControllerDBNOStatusChanged(AFortAthenaAIBotController* BotController, bool bIsDBNO)
{
}

void UFortNPCConversationParticipantComponent::OnPlayerPawnOwnerDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum)
{
}

void UFortNPCConversationParticipantComponent::OnRep_CanStartConversation()
{
}

void UFortNPCConversationParticipantComponent::OnRep_ConversationModeActive()
{
}

void UFortNPCConversationParticipantComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortNPCConversationParticipantComponent, bCanStartConversation);
	DOREPLIFETIME(UFortNPCConversationParticipantComponent, bConversationModeActive);
	DOREPLIFETIME(UFortNPCConversationParticipantComponent, ConversationInteractionCollisionProfile);
	DOREPLIFETIME(UFortNPCConversationParticipantComponent, ConversationInteractionBoxExtent);
	DOREPLIFETIME(UFortNPCConversationParticipantComponent, ConversationInteractionBoxOffset);
	DOREPLIFETIME(UFortNPCConversationParticipantComponent, CharacterData);
	DOREPLIFETIME(UFortNPCConversationParticipantComponent, bCanConverseWhenConverted);
}
