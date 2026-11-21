// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortPlayerControllerComponent_TacticalSprint.h"

UFortPlayerControllerComponent_TacticalSprint::UFortPlayerControllerComponent_TacticalSprint(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UFortPlayerControllerComponent_TacticalSprint::LogAndVisualLog(UObject* LoggingSource, ESprintLoggingVerbosityLevel Verbosity, const FString& LogString)
{
}

void UFortPlayerControllerComponent_TacticalSprint::OnAutoRunChanged(bool bAutoRunIsOn)
{
}

void UFortPlayerControllerComponent_TacticalSprint::OnMovementModeChanged(ACharacter* Character, EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
}

void UFortPlayerControllerComponent_TacticalSprint::OnMutatorUpdated()
{
}

void UFortPlayerControllerComponent_TacticalSprint::OnPawnChanged(AFortPawn* InPawn)
{
}

void UFortPlayerControllerComponent_TacticalSprint::OnPlayerStatePawnSet(APlayerState* Player, APawn* NewPawn, APawn* OldPawn)
{
}

void UFortPlayerControllerComponent_TacticalSprint::OnWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PreviousWeapon)
{
}

void UFortPlayerControllerComponent_TacticalSprint::PopCustomMovementModeExtensionClass()
{
}

void UFortPlayerControllerComponent_TacticalSprint::PushCustomMovementModeExtensionClass(TSubclassOf<UFortMovementMode_ELTacSprint> NewCustomMMExtensionClass)
{
}

void UFortPlayerControllerComponent_TacticalSprint::RegisterMutatorUpdatedDelegate()
{
}

void UFortPlayerControllerComponent_TacticalSprint::SetIsSprinting(bool bNewIsSprinting)
{
}
