// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_Swinging.generated.h"

class AActor;

UCLASS(MinimalAPI, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_Swinging : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Swinging")
	void EndSwingingMovement();

	UFUNCTION(BlueprintPure, Category="Swinging")
	bool IsInSwingingMovement() const;

	UFUNCTION(BlueprintPure, Category="Swinging")
	bool IsSwingAttached() const;

	UFUNCTION(BlueprintPure, Category="Swinging")
	bool IsSwingingGrounded() const;

	UFUNCTION(BlueprintCallable, Category="Swinging")
	void JumpAndImpulse(const FVector& JumpImpulse);

	UFUNCTION(BlueprintCallable, Category="Swinging")
	void JumpPressed();

	UFUNCTION(BlueprintCallable, Category="Swinging")
	void LaunchEnterSwinging(const FVector& InVelocity);

	UFUNCTION(BlueprintCallable, Category="Swinging")
	void StartSwingingUnattached();

	UFUNCTION(BlueprintCallable, Category="Swinging")
	void SwingAttached(AActor* NewAttachedActor);

	UFUNCTION(BlueprintCallable, Category="Swinging")
	void SwingDetached();

private:
	UPROPERTY(Transient)
	bool bCanSwingJump;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> AttachedActor;

};

