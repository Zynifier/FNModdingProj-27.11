// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "BuildingTurretComponent.generated.h"

class AActor;
class UAbilitySystemComponent;
class UPrimitiveComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBuildingTurretTargetChanged, AActor*, NewTarget);

UCLASS(Abstract)
class UBuildingTurretComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="TurretComponent")
	virtual bool AttemptSetCurrentTarget(AActor* NewTarget);

	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="TurretComponent")
	bool IsValidTarget(AActor* InTarget) const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="TurretComponent")
	virtual void SetTargetingOverlapComponent(UPrimitiveComponent* NewTargetingOverlapComponent);

protected:
	UFUNCTION(BlueprintNativeEvent, Category="TurretComponent")
	AActor* ChooseBestTarget(UPARAM(ref) TArray<AActor*>& InOutPotentialTargets) const;

	UFUNCTION()
	virtual void OnFiringTimer();

	UFUNCTION()
	virtual void OnPerformTargetValidation();

	UFUNCTION()
	virtual void OnRep_CurrentTarget(AActor* OldTarget);

	UFUNCTION()
	virtual void OnTargetingBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	virtual void OnTargetingEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(BlueprintAssignable, Category="TurretComponent")
	FBuildingTurretTargetChanged OnTurretTargetChanged;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TurretComponent")
	FGameplayTag OnFireTagTrigger;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TurretComponent", meta=(ClampMin=".1", UIMin=".1"))
	float FiringInterval;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TurretComponent", meta=(EditCondition="bPerformPeriodicValidationOnCurrentTarget"))
	float CurrentTargetValidationInterval;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="TurretComponent")
	uint8 bPerformPeriodicValidationOnCurrentTarget : 1;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="TurretComponent", meta=(EditInline="true"))
	TObjectPtr<UPrimitiveComponent> TargetingOverlapComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UAbilitySystemComponent> OwnerASC;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_CurrentTarget, Category="TurretComponent")
	TObjectPtr<AActor> CurrentTarget;

};

