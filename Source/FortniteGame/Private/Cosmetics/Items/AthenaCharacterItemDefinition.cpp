// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cosmetics/Items/AthenaCharacterItemDefinition.h"

bool UAthenaCharacterItemDefinition::FindBodyType_BP(const TArray<FMcpVariantChannelInfo>& InCharacterVariantChannels, TEnumAsByte<EFortCustomBodyType::Type>& OutBodyType) const
{
	return false;
}

EFortCustomGender::Type UAthenaCharacterItemDefinition::GetCharacterGender_BP(const FFortAthenaLoadout& Loadout) const
{
	return EFortCustomGender::Type();
}

#if WITH_EDITOR
void UAthenaCharacterItemDefinition::MigratePartsFromHID()
{
}
#endif

void UAthenaCharacterItemDefinition::GetPreviewSkeletalMeshes(TArray<USkeletalMesh*>& OutList, TArray<TSubclassOf<UAnimInstance>>& OutAnimBP) const
{
}
