// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/Components/FortControllerComponent_UGCEdit.h"

void UFortControllerComponent_UGCEdit::ServerOptInForDeviceUpgrades_Implementation(AActor* ContextActor)
{
}
bool UFortControllerComponent_UGCEdit::ServerOptInForDeviceUpgrades_Validate(AActor* ContextActor)
{
	return true;
}

void UFortControllerComponent_UGCEdit::ServerOptInForMemorySystemUpgrades_Implementation(AActor* ContextActor)
{
}
bool UFortControllerComponent_UGCEdit::ServerOptInForMemorySystemUpgrades_Validate(AActor* ContextActor)
{
	return true;
}

void UFortControllerComponent_UGCEdit::ServerUpdateUserOptionValues_Implementation(UFortUserOptionContainerComponent* UserOptionContainerComponent, const TArray<FString>& OptionsKeys, const TArray<FString>& OptionsValues)
{
}
bool UFortControllerComponent_UGCEdit::ServerUpdateUserOptionValues_Validate(UFortUserOptionContainerComponent* UserOptionContainerComponent, const TArray<FString>& OptionsKeys, const TArray<FString>& OptionsValues)
{
	return true;
}
