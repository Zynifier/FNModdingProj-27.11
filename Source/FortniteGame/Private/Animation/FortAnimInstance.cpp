// Copyright Epic Games, Inc. All Rights Reserved.

#include "Animation/FortAnimInstance.h"

void UFortAnimInstance::AnimNotify_LeftFootStep(const UAnimNotify* Notify)
{
}

void UFortAnimInstance::AnimNotify_RightFootStep(const UAnimNotify* Notify)
{
}

EFortCardinalDirection UFortAnimInstance::GetCardinalDirectionFromAngle(float Angle, float DeadZoneAngle) const
{
	return EFortCardinalDirection();
}

void UFortAnimInstance::GetPreviousFrameAimPitchAndYaw(float& OutPitch, float& OutYaw) const
{
}

void UFortAnimInstance::StopMontageIncludingInactive(float InBlendOutTime, const UAnimMontage* Montage)
{
}

AFortAIPawn* UFortAnimInstance::TryGetFortAIPawn()
{
	return nullptr;
}
