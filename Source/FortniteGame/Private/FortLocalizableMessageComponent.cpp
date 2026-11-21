// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortLocalizableMessageComponent.h"
#include "Net/UnrealNetwork.h"

void UFortLocalizableMessageComponent::LocalizeAndSetMessage(const FLocalizableMessage& MessageToLocalize, const FText& PropertyToAssignTo)
{
}

void UFortLocalizableMessageComponent::OnRep_MessageProperties(TArray<FLocalizableProperty> OldMessages)
{
}

void UFortLocalizableMessageComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortLocalizableMessageComponent, MessageProperties);
}
