// Copyright Epic Games, Inc. All Rights Reserved.

#include "Creative/DAD/DAD_CosmeticItemUserOptions.h"

const TArray<FDAD_CosmeticItemUserOption>& UDAD_CosmeticItemUserOptions::GetCosmetics() const
{
	static TArray<FDAD_CosmeticItemUserOption> Dummy;
	return Dummy;
}

TSoftObjectPtr<UAnimSequenceBase> UDAD_GenderAnimationUserOptionAsset::GetAnimationForGender(const EFortCustomGender::Type Gender) const
{
	return TSoftObjectPtr<UAnimSequenceBase>();
}
