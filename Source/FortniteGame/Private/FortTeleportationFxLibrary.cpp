// Copyright Epic Games, Inc. All Rights Reserved.

#include "FortTeleportationFxLibrary.h"

void UTeleportationFxLibrary::CleanupDissolveFX(UObject* WorldContextObject, UMaterialInterface* DissolveMat, TArray<UMaterialInstanceDynamic*>& DissolveMIDs)
{
}

void UTeleportationFxLibrary::CleanupResOutFX(AFortPlayerPawnAthena* Pawn, const float PawnLifespan, UPointLightComponent*& TeleportationPointLight, UMaterialInterface* DissolveMat, TArray<UMaterialInstanceDynamic*>& DissolveMIDs)
{
}

void UTeleportationFxLibrary::PreDissolveGlowUpdate(const TArray<UMaterialInstanceDynamic*>& Materials, float Glow)
{
}

bool UTeleportationFxLibrary::SetupDissolveFx(UMaterialInterface* MatCharacterDissolve, const TArray<USkeletalMeshComponent*>& SkeletalMeshes, TArray<UMaterialInstanceDynamic*>& DissolveMIDs)
{
	return false;
}

void UTeleportationFxLibrary::UpdateDissolveFx(float Transition, float ZHeight, float LightIntensity, float MaxLightIntensity, const FName& SocketMeshTop, const FName& SocketMeshBottom, const USkeletalMeshComponent* SkeletalMeshComponent, UPointLightComponent* TeleportationPointLight, const TArray<UMaterialInstanceDynamic*>& DissolveMIDs, AFortPlayerPawn* Pawn, FGuid MaterialOverrideId)
{
}
