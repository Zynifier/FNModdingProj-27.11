// Copyright Epic Games, Inc. All Rights Reserved.

#include "Animation/FortPlayerAnimationInterface.h"

const FFortAnimInput_BowWeapon& UFortPlayerAnimationInterface::GetBowWeaponInput() const
{
	static FFortAnimInput_BowWeapon Dummy;
	return Dummy;
}

const FFortAnimInput_JackalVehicle& UFortPlayerAnimationInterface::GetJackalVehicleInput() const
{
	static FFortAnimInput_JackalVehicle Dummy;
	return Dummy;
}

float UFortPlayerAnimationInterface::GetMeleeTwistCurveValue() const
{
	return float();
}

const FFortAnimInput_Skydiving& UFortPlayerAnimationInterface::GetSkydivingInput() const
{
	static FFortAnimInput_Skydiving Dummy;
	return Dummy;
}

const FFortAnimInput_SpringGlider& UFortPlayerAnimationInterface::GetSpringGliderInput() const
{
	static FFortAnimInput_SpringGlider Dummy;
	return Dummy;
}

const FFortAnimInput_TurnInPlace& UFortPlayerAnimationInterface::GetTurnInPlaceInput() const
{
	static FFortAnimInput_TurnInPlace Dummy;
	return Dummy;
}

EFortWeaponCoreAnimation::Type UFortPlayerAnimationInterface::GetWeaponCoreAnim() const
{
	return EFortWeaponCoreAnimation::Type();
}

const FFortAnimInput_Zipline& UFortPlayerAnimationInterface::GetZiplineInput() const
{
	static FFortAnimInput_Zipline Dummy;
	return Dummy;
}

bool UFortPlayerAnimationInterface::IsOnGrindRails() const
{
	return false;
}

bool UFortPlayerAnimationInterface::IsOnGround() const
{
	return false;
}

bool UFortPlayerAnimationInterface::IsPlayingEmote() const
{
	return false;
}

bool UFortPlayerAnimationInterface::IsPlayingMeleeAnim() const
{
	return false;
}

bool UFortPlayerAnimationInterface::IsRiding() const
{
	return false;
}

void UFortPlayerAnimationInterface::OnAnimNotifyOpenGlider()
{
}

void UFortPlayerAnimationInterface::ResetWeaponCoreAnimAssetsOverride(EFortWeaponCoreAnimation::Type WeaponCoreAnim)
{
}

void UFortPlayerAnimationInterface::SetUseAltGliderCamera(bool bUseAltGliderCamera)
{
}

void UFortPlayerAnimationInterface::SetWeaponCoreAnimAssetsOverride(FFortPlayerAnimAssets PlayerAnimAssetsOverride, EFortWeaponCoreAnimation::Type WeaponCoreAnim)
{
}

void UFortPlayerAnimationInterface::SetWeaponFireBlendTimeOverride(float BlendTime)
{
}

bool UFortPlayerAnimationInterface::ShouldForceOpenGlider() const
{
	return false;
}
