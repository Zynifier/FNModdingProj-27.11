// Copyright Epic Games, Inc. All Rights Reserved.

#include "WeakPoints/FortWeakPoint.h"
#include "Net/UnrealNetwork.h"

UShapeComponent* AFortWeakPoint::GetAimAssistTargetComponent_Implementation()
{
	return nullptr;
}

FName AFortWeakPoint::GetWeakPointAttachmentSocketName() const
{
	return FName();
}

EFortWeakPointState AFortWeakPoint::GetWeakPointState() const
{
	return EFortWeakPointState();
}

void AFortWeakPoint::OnRep_WeakPointState()
{
}

void AFortWeakPoint::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AFortWeakPoint, WeakPointState);
	DOREPLIFETIME(AFortWeakPoint, WeakPointAttachmentSocketName);
}
