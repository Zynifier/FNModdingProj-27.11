// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "FortAIFunctionLibrary.generated.h"

class AAIController;
class AActor;
class ABuildingActor;
class AFortAIPawn;
class UAthenaAISpawner;
class UFortAthenaAIRuntimeParameters;
class UObject;

UCLASS()
class UFortAIFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AI", meta=(WorldContext="WorldContextObject"))
	static UAthenaAISpawner* GetAISpawner(UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI")
	static UFortAthenaAIRuntimeParameters* GetOrCreateAIRuntimeParameters(const AAIController* AIController, const TSubclassOf<UFortAthenaAIRuntimeParameters> ParametersClass);

	UFUNCTION(BlueprintCallable, Category="AI", meta=(WorldContext="WorldContextObject"))
	static bool IsConcealedByPerceptionModifiers(const UObject* WorldContextObject, FVector ObserverLocation, FVector TargetLocation, float& OutConcealment);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI|Perception")
	static void MakeNoiseEvent(AActor* NoiseMaker, const float MaxRange, const FName NoiseTag = NAME_None);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI|Perception")
	static void MakeNoiseEventAtLocation(AActor* NoiseMaker, const float MaxRange, const FVector& NoiseLocation, const FName NoiseTag = NAME_None);

	UFUNCTION(BlueprintCallable, Category="AI")
	static void RequestNavUpdateForBuilding(ABuildingActor* BuildingActor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI|Perception")
	static void SetHearingRange(AActor* AIAgent, float Range);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="AI")
	static bool TeleportAIPawn(AFortAIPawn* AIPawn, FVector DestLocation, FRotator DestRotation, bool bIgnoreCollision = false);

};

