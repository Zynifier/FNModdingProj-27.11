// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortClientOnlyActor.h"
#include "FortLightningActor.generated.h"

class AActor;
class UMaterialInstanceDynamic;
class UStaticMeshComponent;

UCLASS(BlueprintType, Blueprintable)
class AFortLightningActor : public AFortClientOnlyActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Effects")
	void CleanupLightning();

	UFUNCTION(BlueprintCallable, Category="Effects")
	void GenerateBoltLocations(const FVector& StartLocation, const FVector& EndLocation, float MinLength, float MaxLength, float RandomVectorContribution, float MinSizeDecayRate, float MaxSizeDecayRate, float FalloffMultiplier);

	UFUNCTION(BlueprintCallable, Category="Effects")
	void InitializeLightning(AActor* InActorToNotify);

	UFUNCTION(BlueprintImplementableEvent, Category="Effects")
	void OnLightingCleanup();

	UFUNCTION(BlueprintImplementableEvent, Category="Effects")
	void OnLightingInitialized();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Lightning")
	int32 MaxBoltMeshes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Lightning")
	float MaxBoltWidth;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Lightning")
	FName BoltMaterialParamTopPct;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Lightning")
	FName BoltMaterialParamBottomPct;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLightningActor")
	TObjectPtr<AActor> ActorToNotify;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortLightningActor")
	TArray<FVector> BoltLocations;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="FortLightningActor", meta=(EditInline="true"))
	TArray<TObjectPtr<UStaticMeshComponent>> BoltMeshes;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FortLightningActor")
	TArray<TObjectPtr<UMaterialInstanceDynamic>> BoltMIDs;

};

