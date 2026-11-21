// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortCharacterMovementMutator.h"
#include "Net/UnrealNetwork.h"

void AFortCharacterMovementMutator::OnFortPawnChanged(AFortPawn* NewPawn)
{
}

void UFortCharacterMovementMutatorComponent::OnMovementModeChanged(ACharacter* Character, EMovementMode PreviousMovementMode, uint8 PreviousCustomMode)
{
}

void UFortCharacterMovementMutatorComponent::OnRep_BuffetBubblesFollowActor()
{
}

void UFortCharacterMovementMutatorComponent::OnRep_BuffetFlyingRicochetReplicatedData()
{
}

void UFortCharacterMovementMutatorComponent::OverrideBuffetFlyingMaxSpeed(const float Value, const bool bAsMultiplier, const float InterpSpeed)
{
}

void UFortCharacterMovementMutatorComponent::OverrideBuffetFlyingVelocityDirectionInterpSpeed(const float Value, const bool bAsMultiplier)
{
}

void UFortCharacterMovementMutatorComponent::SetBuffetBubblesFollowActor(AActor* Actor)
{
}

void UFortCharacterMovementMutatorComponent::SetBuffetBubblesInitialFollowBoxOffsetPercent(const FVector BoxOffsetPercent)
{
}

void UFortCharacterMovementMutatorComponent::SetBuffetBubblesIntroTargetTransform(const FTransform& Transform)
{
}

void UFortCharacterMovementMutatorComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UFortCharacterMovementMutatorComponent, BuffetBubblesFollowActor);
	DOREPLIFETIME(UFortCharacterMovementMutatorComponent, BuffetBubblesInitialFollowBoxOffsetPercent);
	DOREPLIFETIME(UFortCharacterMovementMutatorComponent, BuffetBubblesReplicatedData);
	DOREPLIFETIME(UFortCharacterMovementMutatorComponent, BuffetBubblesIntroTargetTransform);
	DOREPLIFETIME(UFortCharacterMovementMutatorComponent, BuffetFlyingMaxSpeedOverride);
	DOREPLIFETIME(UFortCharacterMovementMutatorComponent, BuffetFlyingMaxSpeedInterpSpeed);
	DOREPLIFETIME(UFortCharacterMovementMutatorComponent, BuffetFlyingVelocityDirectionInterpSpeedOverride);
	DOREPLIFETIME(UFortCharacterMovementMutatorComponent, BuffetFlyingRicochetReplicatedData);
}
