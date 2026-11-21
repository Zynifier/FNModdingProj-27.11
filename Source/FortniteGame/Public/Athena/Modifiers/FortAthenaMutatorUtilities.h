// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "FortAthenaMutatorUtilities.generated.h"

class AActor;
class AFortPlayerStateAthena;
class UFortActorOptionsComponent;
class UMaterialInstanceDynamic;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMutatorListUpdateDelegates);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE(FSimpleDynamicDelegate);

UCLASS(MinimalAPI)
class UFortAthenaMutatorUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void AdjustRespawnLocationForGroundHeight(UPARAM(ref) FVector& InOutRespawnLocation, float MinRespawnHeightAboveGround, const AActor* WorldContextActor);

	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
	static void ApplyActorOptionsComponentToDataRegistry(const UObject* WorldContextObject, const UFortActorOptionsComponent* FortActorOptionsComponent);

	UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
	static void RemoveDataRegistryOptionsForContextObject(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category="Hero Portraits")
	static void SetPlayerPortraitInMaterial(const AFortPlayerStateAthena* Player, UMaterialInstanceDynamic* Material, FName MaterialParam);

	UFUNCTION(BlueprintCallable, Category="Skydive", meta=(DefaultToSelf="WorldContextObject", HidePin="WorldContextObject"))
	static bool SphereTraceForParachuteLandingGeometry(FHitResult& OutHit, const UObject* WorldContextObject, const FVector& InLocation, float TraceStartZ, float TraceEndZ, float TraceSphereRadius);

};

