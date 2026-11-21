// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Chaos/ChaosEngineInterface.h"
#include "Engine/EngineTypes.h"
#include "Components/FortPawnComponent.h"
#include "FortSurfaceTrackingComponent.generated.h"

class AActor;
class ACharacter;
class AFortPawn;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnSurfaceTypeChanged, AActor*, SurfaceActor, TEnumAsByte<EPhysicalSurface>, CurrentSurfaceType, TEnumAsByte<EPhysicalSurface>, PrevSurfaceType);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("ComponentTick", "Collision", "Trigger", "PhysicsVolume"), ClassGroup=("Gameplay"), meta=(BlueprintSpawnableComponent))
class UFortSurfaceTrackingComponent : public UFortPawnComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	EPhysicalSurface GetCurrentSurfaceType() const;

	UFUNCTION(BlueprintCallable)
	void UpdateSurfaceType(bool bAlwaysNotify = false, bool bLookForGround = false);

	UPROPERTY(EditAnywhere, Category="FortSurfaceTrackingComponent")
	float MinimumCheckDistance;

	UPROPERTY(EditAnywhere, Category="FortSurfaceTrackingComponent")
	bool bUseMovementCompCurrentFloor;

	UPROPERTY(EditAnywhere, Category="FortSurfaceTrackingComponent")
	FName MultiSurfaceActorTag;

	UPROPERTY(EditAnywhere, Category="FortSurfaceTrackingComponent", meta=(EditCondition="!bUseMovementCompCurrentFloor"))
	float SkinWidth;

	UPROPERTY(EditDefaultsOnly, Category="FortSurfaceTrackingComponent", meta=(EditCondition="!bUseMovementCompCurrentFloor"))
	TEnumAsByte<ETraceTypeQuery> TraceTypeQuery;

	UPROPERTY(EditAnywhere, Category="FortSurfaceTrackingComponent")
	bool bDebug;

	UPROPERTY(BlueprintAssignable)
	FOnSurfaceTypeChanged OnSurfaceTypeChanged;

private:
	UFUNCTION()
	void HandleMovementModeChanged(ACharacter* Character, EMovementMode PrevMovementMode, uint8 PreviousCustomMode);

	UPROPERTY(Transient)
	TObjectPtr<AFortPawn> OwningPawn;

	UPROPERTY(Transient)
	TObjectPtr<AActor> CurrentSurfaceActor;

};

