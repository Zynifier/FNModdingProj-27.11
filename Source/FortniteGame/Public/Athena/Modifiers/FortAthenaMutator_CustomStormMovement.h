// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Player/FortCheatManager_Coupled.h"
#include "FortAthenaMutator_CustomStormMovement.generated.h"

class AFortAthenaMutator_CustomStormMovement;
class UCurveFloat;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCustomStormMovementReadyToBeginAnyRoute);

USTRUCT(BlueprintType)
struct FSafeZoneRoute
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SafeZoneRoute")
	FScalableFloat bIsEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SafeZoneRoute")
	FScalableFloat bUsePOIStartLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SafeZoneRoute")
	FScalableFloat bUsePOINameOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="SafeZoneRoute")
	FText POINameOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SafeZoneRoute")
	FScalableFloat StartRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SafeZoneRoute")
	FScalableFloat EndRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SafeZoneRoute")
	FGameplayTag StartPOITag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SafeZoneRoute")
	FGameplayTag EndPOITag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SafeZoneRoute", meta=(EditCondition="!bUsePOIStartLocation"))
	FVector StartLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SafeZoneRoute", meta=(EditCondition="!EndPOITag"))
	FVector EndLocation;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSafeZoneRouteChanged, AFortAthenaMutator_CustomStormMovement*, Mutator, const FSafeZoneRoute&, SafeZoneRoute);

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Tick", "Actor", "LOD", "Cooking", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_CustomStormMovement : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const FSafeZoneRoute& GetSafeZoneRoute(const FString& ContextString) const;

	UPROPERTY(BlueprintAssignable)
	FOnSafeZoneRouteChanged OnSafeZoneRouteChanged;

protected:
	UPROPERTY(EditDefaultsOnly, Replicated, Category="SafeZones")
	TArray<FSafeZoneRoute> SafeZoneRoutes;

	UPROPERTY(EditDefaultsOnly, Category="SafeZones")
	TObjectPtr<UCurveFloat> PhaseProgressCurve;

private:
	UFUNCTION()
	void OnRep_SafeZoneRouteIndex();

	UPROPERTY(ReplicatedUsing=OnRep_SafeZoneRouteIndex)
	int32 SafeZoneRouteIndex;

};

UCLASS()
class UFortCheatManager_CustomStormMovement : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void CustomStormMovementDebug(float TextScale = 1.000000f);

};

