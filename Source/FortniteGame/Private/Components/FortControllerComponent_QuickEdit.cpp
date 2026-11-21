// Copyright Epic Games, Inc. All Rights Reserved.

#include "Components/FortControllerComponent_QuickEdit.h"
#include "Net/UnrealNetwork.h"

void UFortControllerComponent_QuickEdit::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortControllerComponent_QuickEdit, bEnabled);
}
