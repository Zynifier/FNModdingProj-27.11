// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cosmetics/Items/AthenaGliderItemDefinition.h"

#if WITH_EDITOR
void UAthenaGliderItemDefinition::CopyTransformFromGliderActor()
{
}
#endif

bool UAthenaGliderItemDefinition::GetAttachNiagaraEffectToPlayerPawn() const
{
	return false;
}

const TArray<FGliderBitsDefinition>& UAthenaGliderItemDefinition::GetBits() const
{
	static TArray<FGliderBitsDefinition> Dummy;
	return Dummy;
}

TSoftClassPtr<UAnimInstance> UAthenaGliderItemDefinition::GetOverrideAnimSetPtr() const
{
	return TSoftClassPtr<UAnimInstance>();
}

TSoftObjectPtr<USkeletalMesh> UAthenaGliderItemDefinition::GetOverrideSkelMeshPtr() const
{
	return TSoftObjectPtr<USkeletalMesh>();
}

TSubclassOf<AFortPlayerParachute> UAthenaGliderItemDefinition::GetParachutePrefabClass() const
{
	return TSubclassOf<AFortPlayerParachute>();
}

TSoftObjectPtr<UFortPlayerGliderAnimSet> UAthenaGliderItemDefinition::GetPlayerAnimSetPtr() const
{
	return TSoftObjectPtr<UFortPlayerGliderAnimSet>();
}

TSoftObjectPtr<UAnimSequence> UAthenaGliderItemDefinition::GetPoseAdditive() const
{
	return TSoftObjectPtr<UAnimSequence>();
}

const TArray<FGliderTrailParticleDefinition>& UAthenaGliderItemDefinition::GetTrailEffectDefinitions() const
{
	static TArray<FGliderTrailParticleDefinition> Dummy;
	return Dummy;
}

FName UAthenaGliderItemDefinition::GetUserSkeletonParameterName() const
{
	return FName();
}

void UAthenaGliderItemDefinition::MigrateGliderEffectDefinitions()
{
}
