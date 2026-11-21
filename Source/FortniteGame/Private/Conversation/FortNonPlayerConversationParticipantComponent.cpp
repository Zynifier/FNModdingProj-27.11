// Copyright Epic Games, Inc. All Rights Reserved.

#include "Conversation/FortNonPlayerConversationParticipantComponent.h"
#include "Net/UnrealNetwork.h"

void UFortNonPlayerConversationParticipantComponent::AddHideUIIndicatorReason(const FName& Reason)
{
}

bool UFortNonPlayerConversationParticipantComponent::CanStartConversationWith(const AFortPlayerController* PlayerController) const
{
	return false;
}

void UFortNonPlayerConversationParticipantComponent::GiveItemsToPlayer(AFortPlayerController* RecipientPlayerController, const TArray<FNPCChosenItemData>& ItemsToGive)
{
}

bool UFortNonPlayerConversationParticipantComponent::HasHideUIIndicatorReasons() const
{
	return false;
}

void UFortNonPlayerConversationParticipantComponent::RemoveHideUIIndicatorReason(const FName& Reason)
{
}

void UFortNonPlayerConversationParticipantComponent::SelectItemsToGive(TArray<FNPCChosenItemData>& OutItemsSelectedData) const
{
}

void UFortNonPlayerConversationParticipantComponent::ShowMessage(const FText& Message)
{
}

void UFortNonPlayerConversationParticipantComponent::StartConversation(const FGameplayTag InConversationEntryTag, AActor* Instigator, AActor* Target) const
{
}

void UFortNonPlayerConversationParticipantComponent::TossItems(const TArray<FNPCChosenItemData>& ItemsToGive, const FVector& SpawnPickupLocation, const FVector& TossDirection, const float TossSpeed, const float TossAngleVarianceDegrees)
{
}

void UFortNonPlayerConversationParticipantComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortNonPlayerConversationParticipantComponent, ConversationEntryTag);
	DOREPLIFETIME(UFortNonPlayerConversationParticipantComponent, InteractorParticipantTag);
	DOREPLIFETIME(UFortNonPlayerConversationParticipantComponent, SelfParticipantTag);
	DOREPLIFETIME(UFortNonPlayerConversationParticipantComponent, ServiceProviderIDTag);
	DOREPLIFETIME(UFortNonPlayerConversationParticipantComponent, ConditionalBenefitsConfigIDTag);
	DOREPLIFETIME(UFortNonPlayerConversationParticipantComponent, bShowNameWhenInRange);
	DOREPLIFETIME(UFortNonPlayerConversationParticipantComponent, bShowIndicatorBubble);
	DOREPLIFETIME(UFortNonPlayerConversationParticipantComponent, bShowNameplateOnPreview);
	DOREPLIFETIME(UFortNonPlayerConversationParticipantComponent, bShowConversationText);
	DOREPLIFETIME(UFortNonPlayerConversationParticipantComponent, bOverrideParticipantDisplayName);
	DOREPLIFETIME(UFortNonPlayerConversationParticipantComponent, ParticipantDisplayNameOverride);
}
