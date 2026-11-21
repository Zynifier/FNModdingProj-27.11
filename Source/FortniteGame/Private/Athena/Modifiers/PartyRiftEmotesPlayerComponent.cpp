// Copyright Epic Games, Inc. All Rights Reserved.

#include "Athena/Modifiers/PartyRiftEmotesPlayerComponent.h"
#include "Net/UnrealNetwork.h"

void UPartyRiftEmotesPlayerComponent::ClientSendSpawnAnalytics_Implementation(const FVector Location, const int32 DeploymentTime, const FString& Reason) const
{
}

void UPartyRiftEmotesPlayerComponent::HandlePrivacySettingsChanged(const FPartyPrivacySettings& NewPrivacySettings)
{
}

void UPartyRiftEmotesPlayerComponent::OnRep_MutatorPartyRiftEmotes()
{
}

void UPartyRiftEmotesPlayerComponent::Server_SetOwnerAsPartyLeader_Implementation(const bool bPartyLeader)
{
}
bool UPartyRiftEmotesPlayerComponent::Server_SetOwnerAsPartyLeader_Validate(const bool bPartyLeader)
{
	return true;
}

void UPartyRiftEmotesPlayerComponent::Server_SetOwnerAway_Implementation(const bool bNewValue)
{
}

void UPartyRiftEmotesPlayerComponent::Server_SetPartyFull_Implementation(const bool bNewValue)
{
}

void UPartyRiftEmotesPlayerComponent::Server_SetPartyPrivacy_Implementation(const EPartyType NewPartyPrivacy)
{
}

void UPartyRiftEmotesPlayerComponent::Server_SetRequestToJoinPrivateIntention_Implementation(const bool bNewIntention)
{
}

void UPartyRiftEmotesPlayerComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UPartyRiftEmotesPlayerComponent, MutatorPartyRiftEmotes);
	DOREPLIFETIME(UPartyRiftEmotesPlayerComponent, bIsOwnerPartyLeader);
}
