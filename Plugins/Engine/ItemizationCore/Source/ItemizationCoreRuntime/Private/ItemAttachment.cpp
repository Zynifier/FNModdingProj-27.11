// Copyright Epic Games, Inc. All Rights Reserved.

#include "ItemAttachment.h"
#include "Net/UnrealNetwork.h"

void AItemAttachment::OnRep_AttachmentDataChanged()
{
}

void AItemAttachment::OnRep_ItemStateChanged()
{
}

void AItemAttachment::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AItemAttachment, AttachmentData);
	DOREPLIFETIME(AItemAttachment, ItemState);
}
