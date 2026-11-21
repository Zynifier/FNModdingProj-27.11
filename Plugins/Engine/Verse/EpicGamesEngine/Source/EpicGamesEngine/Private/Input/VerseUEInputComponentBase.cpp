// Copyright Epic Games, Inc. All Rights Reserved.

#include "Input/VerseUEInputComponentBase.h"
#include "Net/UnrealNetwork.h"

void UVerseUEInputComponentBase::ServerTriggerAction_Implementation(const FName& ActionName, EInputEvent InputEvent)
{
}
bool UVerseUEInputComponentBase::ServerTriggerAction_Validate(const FName& ActionName, EInputEvent InputEvent)
{
	return true;
}

void UVerseUEInputComponentBase::ServerTriggerAxis_Implementation(const FName& AxisName, float Value)
{
}
bool UVerseUEInputComponentBase::ServerTriggerAxis_Validate(const FName& AxisName, float Value)
{
	return true;
}

void UVerseUEInputComponentBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UVerseUEInputComponentBase, ReplicatedActionMappingArray);
	DOREPLIFETIME(UVerseUEInputComponentBase, ReplicatedAxisMappingArray);
	DOREPLIFETIME(UVerseUEInputComponentBase, ReplicatedInputBindingArray);
}
