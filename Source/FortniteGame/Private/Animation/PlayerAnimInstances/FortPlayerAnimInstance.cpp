// Copyright Epic Games, Inc. All Rights Reserved.

#include "Animation/PlayerAnimInstances/FortPlayerAnimInstance.h"

void UFortPlayerAnimInstance::AnimNotify_PlayFireFX(const UAnimNotify* Notify)
{
}

void UFortPlayerAnimInstance::AnimNotify_PlaySecondaryFireFX(const UAnimNotify* Notify)
{
}

void UFortPlayerAnimInstance::AnimNotify_PlayWeaponInspect(const UAnimNotify* Notify)
{
}

void UFortPlayerAnimInstance::AnimNotify_SkydiveAdditiveEnd(const UAnimNotify* Notify)
{
}

void UFortPlayerAnimInstance::AnimNotify_StopFireFX(const UAnimNotify* Notify)
{
}

UAnimMontage* UFortPlayerAnimInstance::FindEmoteToPlay(AFortPlayerController* FortPlayerController, EFortCustomBodyType::Type InBodyType, EFortCustomGender::Type InGender)
{
	return nullptr;
}

float UFortPlayerAnimInstance::GetRelativeAngle(float MovementAngle, EFortCardinalDirection Direction, bool bMirrorBackside) const
{
	return float();
}

void UFortPlayerAnimInstance::SetIsPatrolling(bool NewValue)
{
}

void UFortPlayerAnimInstance::UpdateTacticalSprint()
{
}
