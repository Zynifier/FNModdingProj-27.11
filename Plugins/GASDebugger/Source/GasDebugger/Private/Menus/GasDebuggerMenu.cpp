// Copyright Epic Games, Inc. All Rights Reserved.

#include "Menus/GasDebuggerMenu.h"
#include "Net/UnrealNetwork.h"

void AGasDebuggerMenu::ClientReceiveCallStack_Implementation(FGasDebugReplicatableCallStack CallStack)
{
}

void AGasDebuggerMenu::ServerClose_Implementation()
{
}

void AGasDebuggerMenu::ServerRemoveEffect_Implementation(const FString& EffectUsefulName)
{
}

void AGasDebuggerMenu::ServerRemoveTag_Implementation(const FGameplayTag& Tag)
{
}

void AGasDebuggerMenu::ServerRequestCallStack_Implementation(uint16 Id)
{
}

void AGasDebuggerMenu::ServerSetAttribute_Implementation(const FString& AttributeName, float NewValue)
{
}

void AGasDebuggerMenu::ServerSetMonitoredActor_Implementation(AActor* ActorToMonitor)
{
}

void AGasDebuggerMenu::ServerTogglePause_Implementation()
{
}

void AGasDebuggerMenu::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AGasDebuggerMenu, MonitoredActor);
	DOREPLIFETIME(AGasDebuggerMenu, ServerGasDebugSnapshot);
}
