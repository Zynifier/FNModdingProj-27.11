// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Components/RidableComponent.h"
#include "FortMovementEnums.h"
#include "Movement/FortMovementComp_Character.h"
#include "ControllableRidableComponent.generated.h"

class AActor;
class UPrimitiveComponent;
class URiderComponent;

UCLASS(HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class RIDINGCODERUNTIME_API UControllableRidableComponent : public URidableComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	bool CanBeControlled(URiderComponent* Rider) const;

	UFUNCTION(BlueprintPure)
	bool CanStartSprinting() const;

	UFUNCTION(BlueprintPure)
	const FText& GetAbilityDisplayText() const;

	UFUNCTION(BlueprintImplementableEvent)
	void HandleAbilityHeld();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleAbilityStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleAbilityStopped();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleCancelSprint(const bool bAbilityInputHeld, const bool bForceCancel);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleJumpHeld();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleJumpStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleJumpStopped();

	UFUNCTION(BlueprintPure)
	bool IsSprintToggleable() const;

protected:
	UFUNCTION(BlueprintCallable)
	void CancelBuildBar();

	UFUNCTION()
	void OnCapsuleBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnRep_IsBeingControlled();

	UFUNCTION(Server, Reliable, BlueprintCallable)
	void ServerDoJumpExit();

	UPROPERTY(EditDefaultsOnly, Config, Category="Riding|Control")
	bool bUseGravityJump;

	UPROPERTY(EditDefaultsOnly, Config, Category="Riding|Control", meta=(EditCondition="bUseGravityJump"))
	FGameplayTagQuery IgnoreGravityJumpTagQuery;

	UPROPERTY(EditDefaultsOnly, Config, Category="Riding|Control")
	bool bIsControllable;

	UPROPERTY(EditDefaultsOnly, Config, Category="Riding|Control")
	bool bHasAbility;

	UPROPERTY(EditDefaultsOnly, Config, Category="Riding|Control")
	FText AbilityDisplayText;

	UPROPERTY(EditDefaultsOnly, Config, Category="Riding|Control")
	bool bCanJump;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Config, Category="Riding|Control")
	bool bAlwaysMoveForward;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Config, Category="Riding|Control")
	float ForwardMoveSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Config, Category="Riding|Control")
	float BackwardMoveSpeedMultiplier;

	UPROPERTY(EditDefaultsOnly, Config, Category="Riding|Control")
	float SidewaysMoveRotationOffset;

	UPROPERTY(EditDefaultsOnly, Config, Category="ControllableRidableComponent")
	TEnumAsByte<EFortMovementUrgency::Type> MovementUrgency;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_IsBeingControlled, Category="ControllableRidableComponent")
	bool bIsBeingControlled;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding|Control")
	FRidableControlParams RidableControlParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding|Control")
	FScalableFloat JumpUpwardGravityScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Riding|Control")
	FScalableFloat JumpDownwardGravityScale;

};

