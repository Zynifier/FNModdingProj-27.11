// Copyright Epic Games, Inc. All Rights Reserved.

#include "FrontEnd/FrontendAnimInstance.h"

void UFrontendAnimInstance::AnimNotify_PlayFireFX(const UAnimNotify* Notify)
{
}

EFortDisplayGender::Type UFrontendAnimInstance::GetGender()
{
	return EFortDisplayGender::Type();
}

bool UFrontendAnimInstance::IsInLobby()
{
	return false;
}

void UFrontendAnimInstance::PlayIntro()
{
}

void UFrontendAnimInstance::PlayOutro()
{
}

void UFrontendAnimInstance::PlaySelected()
{
}

bool UFrontendAnimInstance::ShouldHidePropsDuringBlend(UAnimMontage* Montage) const
{
	return false;
}
