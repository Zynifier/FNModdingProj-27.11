// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "GameplayAbilitySpecHandle.h"
#include "GameplayTagContainer.h"
#include "FortPlayerCameraBase.generated.h"

class AActor;
class APostProcessVolume;
class UFortCameraMode;
class UFortCinematicCamera;
class UFortUICameraManagerComponent;
class UObject;

USTRUCT()
struct FActiveFortCamera
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortCameraMode> Camera;

	UPROPERTY()
	TObjectPtr<AActor> ViewTarget;

	UPROPERTY()
	float TransitionAlpha;

	UPROPERTY()
	float TransitionUpdateRate;

	UPROPERTY()
	float BlendWeight;

};

USTRUCT()
struct FCameraModeTaggedOverrideEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TSubclassOf<UFortCameraMode> Mode;

};

USTRUCT(BlueprintType)
struct FFortAbilityCameraOverrideSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TSubclassOf<UFortCameraMode> AbilitySpecifiedCameraClass;

	UPROPERTY(Transient)
	FGameplayAbilitySpecHandle CameraOverrideRequesterAbilitySpec;

};

USTRUCT()
struct FFortCameraInstanceEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TSubclassOf<UFortCameraMode> CameraClass;

	UPROPERTY()
	TWeakObjectPtr<UObject> Owner;

	UPROPERTY()
	TObjectPtr<UFortCameraMode> Camera;

};

USTRUCT()
struct FFortCameraModeOverride
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortCameraPrototype")
	TSubclassOf<UFortCameraMode> OriginalClass;

	UPROPERTY(EditAnywhere, Category="FortCameraPrototype")
	TSubclassOf<UFortCameraMode> ClassOverride;

};

USTRUCT()
struct FFortCameraPrototype
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortCameraPrototype")
	FName PrototypeName;

	UPROPERTY(EditAnywhere, Category="FortCameraPrototype")
	FString PrototypeDescription;

	UPROPERTY(EditAnywhere, Category="FortCameraPrototype")
	TArray<FFortCameraModeOverride> ModeOverrides;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Transform|Actor", "Rendering", "Activation", "Replication", "INPUT", "Actor", "HLOD"))
class AFortPlayerCameraBase : public APlayerCameraManager
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Camera")
	void AddCameraModeOverride(const TSubclassOf<UFortCameraMode>& CameraModeClass, const FGameplayTag& Tag, int32 Priority, const UObject* InOwner = nullptr);

	UFUNCTION(BlueprintCallable, Category="Camera")
	void RemoveCameraModeOverride(const FGameplayTag& Tag, const UObject* InOwner = nullptr);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerCameraBase")
	TSubclassOf<UFortCameraMode> Base3PClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerCameraBase")
	TSubclassOf<UFortCameraMode> Targeting3PClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerCameraBase")
	TSubclassOf<UFortCameraMode> OverrideCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerCameraBase")
	TSubclassOf<UFortCinematicCamera> CinematicCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerCameraBase")
	TSubclassOf<UFortCameraMode> DBNOCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerCameraBase")
	TSubclassOf<UFortCameraMode> DBNOCarriedCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerCameraBase")
	TSubclassOf<UFortCameraMode> DeathCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerCameraBase")
	TSubclassOf<UFortCameraMode> RespawnedInAirCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerCameraBase")
	TSubclassOf<UFortCameraMode> SkydiveGlideCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerCameraBase")
	TSubclassOf<UFortCameraMode> SkydiveDiveCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerCameraBase")
	TSubclassOf<UFortCameraMode> SkydiveParachuteCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerCameraBase")
	TSubclassOf<UFortCameraMode> HoverboardCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerCameraBase")
	TSubclassOf<UFortCameraMode> WaterSprintBoostCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerCameraBase")
	TSubclassOf<UFortCameraMode> FocalPointCameraClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerCameraBase")
	TSubclassOf<UFortCameraMode> TetheredTargeting3PClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortPlayerCameraBase")
	TSubclassOf<UFortCameraMode> RCActorCameraClass;

	UPROPERTY(EditAnywhere, Category="FortPlayerCameraBase")
	TArray<FFortCameraPrototype> CameraPrototypes;

protected:
	UPROPERTY(Transient)
	TArray<FActiveFortCamera> CameraBlendStack;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortUICameraManagerComponent> UICamera;

	UPROPERTY(Transient)
	bool bLockCameraWhileInactiveForNextTransition;

private:
	UPROPERTY(Transient)
	TArray<FFortCameraInstanceEntry> CameraInstances;

	UPROPERTY(Transient)
	TObjectPtr<APostProcessVolume> ZoomPostProcessVolume;

	UPROPERTY(Transient)
	TArray<FCameraModeTaggedOverrideEntry> TaggedOverrideStack;

};

