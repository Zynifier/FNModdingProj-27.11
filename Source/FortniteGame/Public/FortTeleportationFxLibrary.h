// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/Guid.h"
#include "FortTeleportationFxLibrary.generated.h"

class AFortPlayerPawn;
class AFortPlayerPawnAthena;
class UMaterialInstanceDynamic;
class UMaterialInterface;
class UObject;
class UPointLightComponent;
class USkeletalMeshComponent;

UCLASS(meta=(ScriptName="TeleportationFxLibrary"))
class UTeleportationFxLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Teleportation FX", meta=(WorldContext="WorldContextObject"))
	static void CleanupDissolveFX(UObject* WorldContextObject, UMaterialInterface* DissolveMat, UPARAM(ref) TArray<UMaterialInstanceDynamic*>& DissolveMIDs);

	UFUNCTION(BlueprintCallable, Category="Teleportation FX", meta=(WorldContext="Pawn"))
	static void CleanupResOutFX(AFortPlayerPawnAthena* Pawn, const float PawnLifespan, UPARAM(ref) UPointLightComponent*& TeleportationPointLight, UMaterialInterface* DissolveMat, UPARAM(ref) TArray<UMaterialInstanceDynamic*>& DissolveMIDs);

	UFUNCTION(BlueprintCallable, Category="Teleportation FX")
	static void PreDissolveGlowUpdate(const TArray<UMaterialInstanceDynamic*>& Materials, float Glow);

	UFUNCTION(BlueprintCallable, Category="Teleportation FX")
	static bool SetupDissolveFx(UMaterialInterface* MatCharacterDissolve, const TArray<USkeletalMeshComponent*>& SkeletalMeshes, UPARAM(ref) TArray<UMaterialInstanceDynamic*>& DissolveMIDs);

	UFUNCTION(BlueprintCallable, Category="Teleportation FX")
	static void UpdateDissolveFx(float Transition, float ZHeight, float LightIntensity, float MaxLightIntensity, const FName& SocketMeshTop, const FName& SocketMeshBottom, const USkeletalMeshComponent* SkeletalMeshComponent, UPointLightComponent* TeleportationPointLight, const TArray<UMaterialInstanceDynamic*>& DissolveMIDs, AFortPlayerPawn* Pawn, FGuid MaterialOverrideId);

};

