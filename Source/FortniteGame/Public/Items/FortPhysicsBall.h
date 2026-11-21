// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Building/BuildingGameplayActor.h"
#include "FortPhysicsBall.generated.h"

class UFortVehicleAudioVoice;
class UFortWaterInteractionComponent;
class USceneComponent;
class USphereComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AFortPhysicsBall : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(Server, Reliable, WithValidation, BlueprintCallable)
	void AuthTriggerTargetHit(FVector StartPos, FVector EndPos);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnHitTarget(FVector StartPos, FVector EndPos);

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="FortPhysicsBall")
	void UpdateDirectionAndRotation(float DeltaSeconds);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPhysicsBall")
	bool bDetachRootChildrenOnServer;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPhysicsBall")
	bool bUpdateRotationOnlyIfRendered;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="FortPhysicsBall")
	bool bRollingAudioFaded;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPhysicsBall")
	float UpdateRollingAudioRangeMeters;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<USphereComponent> SphereCollision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<USceneComponent> RotationPivot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<UFortWaterInteractionComponent> WaterInteractionComponent;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Export, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true", EditInline="true"))
	TObjectPtr<USceneComponent> RotatedComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortVehicleAudioVoice> RollingAudioComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true"))
	bool bEnableBackspinOnKick;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true"))
	bool bApplyingBackspin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true", ClampMin="0"))
	float BackspinRotationScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true"))
	bool bEnableLiftAndDrag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true"))
	bool bStopLiftWhenFalling;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Replicated, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true"))
	bool bApplyingLift;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true", ClampMin="0"))
	float LiftFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true", ClampMin="0"))
	float StopLiftHorizontalVelocityThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true", ClampMin="0"))
	float StopLiftVerticalVelocityThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true", ClampMin="0"))
	float StopLiftTimeDuration;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true", ClampMin="0"))
	float LiftDuration;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true", ClampMin="0"))
	float DragVelocityThreshold;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true", ClampMin="0"))
	float DragFactor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true", ClampMin="0"))
	float WaterMinRotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true", ClampMin="0"))
	float WaterRotationInterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPhysicsBall", meta=(AllowPrivateAccess="true", ClampMin="0"))
	float WaterAxisFlipSpeed;

};

