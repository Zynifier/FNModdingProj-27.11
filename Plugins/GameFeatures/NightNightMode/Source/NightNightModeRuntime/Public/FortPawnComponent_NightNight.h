// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortPawnOverrideComponent.h"
#include "FortPawnComponent_NightNight.generated.h"

class AActor;
class UFortCameraMode;
class UFortUICameraManagerComponent;

UCLASS(HideCategories=("Activation", "AssetUserData", "Collision", "ComponentReplication", "ComponentTick", "Cooking", "Replication", "Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class NIGHTNIGHTMODERUNTIME_API UFortPawnComponent_NightNight : public UFortPawnOverrideComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetAllowUIViewTarget(const bool bAllow);

protected:
	UPROPERTY(EditAnywhere, Category="FortPawnComponent_NightNight")
	bool bAutoPossess;

	UPROPERTY(EditAnywhere, Category="FortPawnComponent_NightNight")
	bool bAllowUIViewTarget;

	UPROPERTY(EditAnywhere, Category="FortPawnComponent_NightNight")
	TSubclassOf<UFortCameraMode> CameraModeOverrideClass;

private:
	UFUNCTION()
	void OnUIViewTargetChanged(UFortUICameraManagerComponent* InUICameraManagerComponent, AActor* OldUIViewTarget, AActor* NewUIViewTarget);

};

