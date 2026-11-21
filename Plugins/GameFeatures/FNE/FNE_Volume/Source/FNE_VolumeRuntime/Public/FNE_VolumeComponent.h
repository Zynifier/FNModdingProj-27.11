// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ChildActorComponent.h"
#include "Math/MathFwd.h"
#include "FNE_VolumeComponent.generated.h"

class AActor;
class AFNE_Volume;
class AGameplayVolume;
class APawn;
class APlayerState;
class UOverlapComponent;
class USpatialGameplayActorTrackerComponent;
class UStaticMesh;
enum class EFNEVolumeShapeTypeEnum : uint8;

UENUM(BlueprintType)
enum class EFNEVolumeShapeTypeEnum : uint8
{
	BoxVolume = 0 UMETA(DisplayName="Box"),
	CylinderVolume = 1 UMETA(DisplayName="Cylinder"),
	SphereVolume = 2 UMETA(DisplayName="Sphere"),
};

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE_OneParam(FOnActorOverlapEvent, AActor*, OtherActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorOverlap, AActor*, OtherActor);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerStateOverlap, APlayerState*, PlayerState);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Object", "LOD", "Physics", "Lighting", "TextureStreaming", "Activation", "Components|Activation", "Collision", "Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFNE_VolumeComponent : public UChildActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	bool BindToOnOtherActorBeginOverlap(const FOnActorOverlapEvent& InEvent);

	UFUNCTION(BlueprintCallable)
	bool BindToOnOtherActorEndOverlap(const FOnActorOverlapEvent& InEvent);

	UFUNCTION(BlueprintPure)
	TArray<APawn*> GetAllPlayerPawns() const;

	UFUNCTION(BlueprintPure)
	TArray<APlayerState*> GetAllPlayerStates() const;

	UFUNCTION(BlueprintPure)
	TArray<AActor*> GetAllTrackedActors() const;

	UFUNCTION(BlueprintPure)
	bool GetEnableOverlap() const;

	UFUNCTION(BlueprintPure)
	AFNE_Volume* GetSpawnedVolume() const;

	UFUNCTION(BlueprintCallable)
	UOverlapComponent* GetSpawnedVolumeBoundsComponent();

	UFUNCTION(BlueprintCallable)
	void SetEnableOverlap(const bool bEnable);

	UFUNCTION(BlueprintCallable)
	void SetRelativeScale3DForBoundsComponent(const FVector& Scale3D);

	UFUNCTION(BlueprintCallable)
	bool SetStaticMeshForBoundsComponent(UStaticMesh* NewMesh);

	UFUNCTION(BlueprintCallable)
	void UnBindFromOnOtherActorBeginOverlap(const FOnActorOverlapEvent& InEvent);

	UFUNCTION(BlueprintCallable)
	void UnBindFromOnOtherActorEndOverlap(const FOnActorOverlapEvent& InEvent);

	UFUNCTION(BlueprintCallable)
	void UpdateOverLapShape(EFNEVolumeShapeTypeEnum EShape, const bool bUseCustomShape = false, UStaticMesh* CustomShape = nullptr);

	UPROPERTY(BlueprintAssignable)
	FOnPlayerStateOverlap OnPlayerStateBeginOverlap;

	UPROPERTY(BlueprintAssignable)
	FOnPlayerStateOverlap OnPlayerStateEndOverlap;

	UPROPERTY(BlueprintAssignable)
	FOnActorOverlap OnOtherActorBeginOverlap;

	UPROPERTY(BlueprintAssignable)
	FOnActorOverlap OnOtherActorEndOverlap;

protected:
	UFUNCTION()
	void HandleNotifyPlayerStateBeginOverlap(APlayerState* TouchingPlayerState, AGameplayVolume* Volume);

	UFUNCTION()
	void HandleNotifyPlayerStateEndOverlap(APlayerState* TouchingPlayerState, AGameplayVolume* Volume);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FNE_VolumeComponent")
	bool bEnableOverlap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FNE_VolumeComponent")
	TMap<EFNEVolumeShapeTypeEnum, TObjectPtr<UStaticMesh>> FNEVolumeShapeMap;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	USpatialGameplayActorTrackerComponent* SpatialGameplayActorTracker;

private:
	UFUNCTION()
	void HandleNotifyActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void HandleNotifyActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);

};

