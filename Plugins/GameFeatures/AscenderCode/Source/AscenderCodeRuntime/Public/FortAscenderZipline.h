// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SplineMeshComponent.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Athena/FortAthenaSplineZipline.h"
#include "FortAscenderZipline.generated.h"

class AActor;
class ABuildingActor;
class ABuildingSMActor;
class AFortPawn;
class AFortPlayerPawn;
class UCapsuleComponent;
class UFortLinkToActorComponent;
class UFortZiplineLinkComponent;
class UPrimitiveComponent;
class USplineMeshComponent;
class UStaticMesh;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAscenderSetupComplete);

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortAscenderZipline : public AFortAthenaSplineZipline
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ApplyStructureDamage(ABuildingSMActor* BuildingActor, AActor* DamageSource) const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="HandlePlayerStartedUsingHandle"))
	void BP_HandlePlayerStartedUsingHandle(AFortPlayerPawn* Player);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="HandlePlayerStoppedUsingHandle"))
	void BP_HandlePlayerStoppedUsingHandle(AFortPlayerPawn* Player);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="HandleStartedLoweringCable"))
	void BP_HandleStartedLoweringCable();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="HandleStartedLoweringHandle"))
	void BP_HandleStartedLoweringHandle();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="HandleStoppedLoweringCable"))
	void BP_HandleStoppedLoweringCable();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="HandleStoppedLoweringHandle"))
	void BP_HandleStoppedLoweringHandle();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="HandleUpdatedLoweringCable"))
	void BP_HandleUpdatedLoweringCable();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="HandleUpdatedLoweringHandle"))
	void BP_HandleUpdatedLoweringHandle();

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	UPrimitiveComponent* GetHandleComponent() const;

	UFUNCTION(BlueprintNativeEvent)
	UPrimitiveComponent* GetInteractComponentOverride(AFortPlayerPawn* InteractingPawn, UPrimitiveComponent* InteractComponent) const;

	UFUNCTION(BlueprintPure)
	AFortPlayerPawn* GetPawnUsingHandle() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintPure)
	UPrimitiveComponent* GetTopComponent() const;

	UPROPERTY(BlueprintAssignable)
	FOnAscenderSetupComplete OnAscenderSetupComplete;

protected:
	UFUNCTION()
	void HandleFloorActorDestroyed(AActor* Actor);

	UFUNCTION()
	void HandleFloorActorHealthChanged();

	UFUNCTION()
	void HandlePawnUsingHandleDied(AFortPawn* DeadPawn);

	UFUNCTION()
	void OnRep_InitialSplineEndLocation();

	UFUNCTION()
	void OnRep_PawnUsingHandle();

	UFUNCTION()
	void OnRep_TargetSplineEndLocation();

	UFUNCTION(BlueprintCallable, Category="Ascender")
	void SetupAscender(const bool bFromConstruction, const bool bFromReplication);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAscenderZipline")
	FName SplineTopAttachPointName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAscenderZipline")
	bool bAutoFindSplineEndLocation;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAscenderZipline")
	float SplineOffsetFromGround;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAscenderZipline")
	float CableOffsetFromSplineEnd;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAscenderZipline")
	float SplineLength;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAscenderZipline")
	TObjectPtr<UStaticMesh> SplineStaticMesh;

	UPROPERTY(BlueprintReadOnly, Category="FortAscenderZipline")
	TEnumAsByte<ESplineMeshAxis::Type> MeshForwardAxis;

	UPROPERTY(BlueprintReadOnly, Category="FortAscenderZipline")
	bool bHandleReturning;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAscenderZipline")
	float HandleReturnSpeed;

	UPROPERTY(BlueprintReadOnly, Category="FortAscenderZipline")
	bool bCableDropping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAscenderZipline")
	float CableDropSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAscenderZipline")
	float YawRotationOffsetWhileUsingHandle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAscenderZipline")
	float YawRotationOffsetWhileSlidingDown;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAscenderZipline")
	bool bUseComplexSplineCollision;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAscenderZipline")
	float SimpleSplineCollisionRadius;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAscenderZipline")
	float SimpleSplineCollisionHeightExtension;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAscenderZipline")
	FScalableFloat DescendMinDistanceFromBottom;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAscenderZipline")
	FScalableFloat AscendReachedEndHorizontalLaunchSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAscenderZipline")
	FScalableFloat AscendReachedEndVerticalLaunchSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAscenderZipline")
	FScalableFloat AscendJumpedOffHorizontalLaunchSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAscenderZipline")
	FScalableFloat AscendJumpedOffVerticalLaunchSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAscenderZipline")
	FScalableFloat DescendReachedEndHorizontalLaunchSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAscenderZipline")
	FScalableFloat DescendReachedEndVerticalLaunchSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAscenderZipline")
	FScalableFloat DescendJumpedOffHorizontalLaunchSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAscenderZipline")
	FScalableFloat DescendJumpedOffVerticalLaunchSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAscenderZipline")
	FScalableFloat HandleActorHitPlayerHorizontalLaunchSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAscenderZipline")
	FScalableFloat HandleActorHitPlayerVerticalLaunchSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAscenderZipline")
	FVector HandleDestroyBuildingsOverlapExtents;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAscenderZipline")
	FVector PlayerDestroyBuildingsOverlapExtents;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_InitialSplineEndLocation, Category="FortAscenderZipline")
	FVector InitialSplineEndLocation;

	UPROPERTY(BlueprintReadOnly, Category="FortAscenderZipline")
	FVector CurrentSplineEndLocation;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_TargetSplineEndLocation, Category="FortAscenderZipline")
	FVector TargetSplineEndLocation;

	UPROPERTY(BlueprintReadOnly, Category="FortAscenderZipline")
	FVector CurrentHandleLocation;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FortAscenderZipline")
	TWeakObjectPtr<UPrimitiveComponent> CurrentInteractComponent;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PawnUsingHandle)
	TWeakObjectPtr<AFortPlayerPawn> PawnUsingHandle;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAscenderZipline")
	TWeakObjectPtr<AFortPlayerPawn> PreviousPawnUsingHandle;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAscenderZipline", meta=(EditInline="true"))
	TObjectPtr<USplineMeshComponent> SplineMesh;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortAscenderZipline", meta=(EditInline="true"))
	TObjectPtr<UCapsuleComponent> SimpleSplineMeshCollision;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortAscenderZipline")
	TWeakObjectPtr<ABuildingActor> FloorActor;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AFortPlayerPawn>> RotationLockedPawns;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Export, Category="Actor Linking", meta=(EditInline="true"))
	TObjectPtr<UFortLinkToActorComponent> LinkToActorComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Transient, Export, Category="AI", meta=(EditInline="true"))
	TObjectPtr<UFortZiplineLinkComponent> ZiplineLinkComponent;

};

