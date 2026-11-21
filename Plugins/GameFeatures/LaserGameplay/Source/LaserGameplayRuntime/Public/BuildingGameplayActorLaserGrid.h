// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/HitResult.h"
#include "Engine/TimerHandle.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "Building/BuildingGameplayActor.h"
#include "BuildingGameplayActorLaserGrid.generated.h"

class AActor;
class ABuildingActor;
class ABuildingGameplayActorLaserGrid;
class AController;
class UHierarchicalInstancedStaticMeshComponent;
class ULaserCapsuleComponent;
class ULaserGridEditorComponent;
class UPrimitiveComponent;
class USoundBase;

UENUM(BlueprintType)
enum class ELaserConnectionState : uint8
{
	/** The laser connection is off.
		For outlets: there are no connections or all connections are set to Off. */
	Off = 0,
	/** The laser connection is transitioning on.
		For outlets: one or more connections are set to TransitionOn and there are no connections set to TransitionOff or On. */
	TransitionOn = 1,
	/** The laser connection is on.
		For outlets: a connection is set to on, or some (but not all) connections are set to TransitionOn, or some (but not all) connections are set to TransitionOff. */
	On = 2,
	/** The laser connection is transitioning off.
		For outlets: one or more connections are set to TransitionOff and there are no connections set to TransitionOn or On. */
	TransitionOff = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLaserGridOutletDestroyed, ABuildingGameplayActorLaserGrid*, LaserGrid);

USTRUCT(BlueprintType)
struct FLaserOutletConnection
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LaserOutletConnection")
	uint8 PrimaryOutletIndex;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="LaserOutletConnection")
	uint8 SecondaryOutletIndex;

};

USTRUCT(BlueprintType)
struct FLaserGridConnectionEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="LaserGridConnectionEntry")
	FLaserOutletConnection OutletConnection;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LaserGridConnectionEntry")
	ELaserConnectionState State;

	UPROPERTY(Transient, NotReplicated, Export, meta=(EditInline="true"))
	TObjectPtr<ULaserCapsuleComponent> LaserCapsuleComponent;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnLaserGridTriggered, ABuildingGameplayActorLaserGrid*, LaserGrid, const FLaserGridConnectionEntry&, LaserConnectionData, AActor*, TriggeringActor);

USTRUCT()
struct FLaserGridConnectionArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FLaserGridConnectionEntry> Entries;

};

USTRUCT(BlueprintType)
struct FLaserGridOutletEntry : public FFastArraySerializerItem
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="LaserGridOutletEntry")
	uint8 InstanceIndex;

	UPROPERTY(BlueprintReadOnly, Transient, Category="LaserGridOutletEntry")
	ELaserConnectionState State;

};

USTRUCT()
struct FLaserGridOutletArray : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<FLaserGridOutletEntry> Entries;

};

USTRUCT(BlueprintType)
struct FLaserGridPattern
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="LaserGridPattern")
	TArray<FLaserOutletConnection> OutletConnections;

	UPROPERTY(EditAnywhere, Category="LaserGridPattern", meta=(ClampMin="0.1", UIMin="0.1"))
	float Duration;

};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActorLaserGrid : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintPure=false, Category="Laser")
	void GetActiveLaserGridConnections(TArray<FLaserGridConnectionEntry>& OutActiveLaserGridConnections) const;

	UPROPERTY(BlueprintAssignable, Category="Laser")
	FOnLaserGridTriggered OnLaserGridTriggered;

	UPROPERTY(BlueprintAssignable, Category="Laser")
	FOnLaserGridOutletDestroyed OnLaserGridOutletDestroyed;

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="Laser")
	bool CanActorTriggerLaserGrid(const AActor* TriggeringActor) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Laser")
	void CosmeticDestroyOutletInstance(const FLaserGridOutletEntry& OutletEntry);

	UFUNCTION(BlueprintImplementableEvent, Category="Laser")
	void LaserGridStateUpdated(bool bLaserGridEnabled);

	UFUNCTION(BlueprintImplementableEvent, BlueprintAuthorityOnly, Category="Laser")
	void LaserGridTriggered(const FLaserGridConnectionEntry& LaserConnectionData, AActor* TriggeringActor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Laser")
	void SetLaserGridEnable(const bool bEnable);

	UPROPERTY(EditAnywhere, Category="Laser")
	TArray<FLaserGridPattern> LaserGridPatterns;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Laser")
	float LaserPatternChangeWarningTime;

	UPROPERTY(EditInstanceOnly, Category="Laser")
	TMap<int32, TObjectPtr<ABuildingActor>> LaserOutletToBuildingAttachmentMap;

	UPROPERTY(EditDefaultsOnly, Category="Laser")
	FGameplayTagContainer IgnoreActorTags;

	UPROPERTY(EditDefaultsOnly, Category="Laser")
	TSubclassOf<ULaserCapsuleComponent> LaserCapsuleComponentClass;

	UPROPERTY(EditDefaultsOnly, Category="Laser")
	FRotator LaserCapsuleCollisionRotationOffset;

	UPROPERTY(EditDefaultsOnly, Category="Laser")
	int32 LaserCustomDataIndexForRandomizedVisuals;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_LaserGridConnections)
	FLaserGridConnectionArray LaserGridConnections;

	UPROPERTY(Transient)
	TArray<FLaserGridConnectionEntry> LocalLaserGridConnections;

	UPROPERTY(EditDefaultsOnly, Category="Laser")
	FTransform LaserConnectionOffset;

	UPROPERTY(EditDefaultsOnly, Category="Laser")
	FVector LaserOutletConnectionOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Laser|Sound")
	USoundBase* SoundOutletTransitionOn;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Laser|Sound")
	USoundBase* SoundLaserTransitionPrimaryOutlet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Laser|Sound")
	USoundBase* SoundLaserTransitionSecondaryOutlet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Laser|Sound")
	USoundBase* SoundLaserTransition;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Laser|Material")
	int32 OutletMaterialCustomDataIndex_EmissiveEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Laser|Material")
	int32 OutletMaterialCustomDataIndex_DisableEmissivePulse;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Laser|Material")
	int32 OutletMaterialCustomDataIndex_AnimTimestamp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Laser|Material")
	int32 OutletMaterialCustomDataIndex_AnimTimestampDuration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Laser|Material")
	float MaterialCosineWavePeriod;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Laser|Material")
	FVector2D OutletMaterialTransitionOffTimestampOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Laser|Material")
	int32 LaserMaterialCustomDataIndex_PulseEnabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Laser|Material")
	int32 LaserMaterialCustomDataIndex_RandomFlickeringSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Laser|Material")
	int32 LaserMaterialCustomDataIndex_AnimTimestamp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Laser|Material")
	int32 LaserMaterialCustomDataIndex_PulseTimeOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Laser|Material")
	FVector2D LaserMaterialRandomFlickeringSpeed;

	UPROPERTY(Transient, Replicated)
	FLaserGridOutletArray LaserGridOutlets;

private:
	UFUNCTION()
	void HandleAttachedBuildingActorDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* HitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void HandleLaserCollisionOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void HandlePatternTimerComplete_PostTransition();

	UFUNCTION()
	void HandlePatternTimerComplete_PreTransition();

	UFUNCTION()
	void OnRep_bEnabled();

	UFUNCTION()
	void OnRep_LaserGridConnections();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="Laser", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	UHierarchicalInstancedStaticMeshComponent* HISMComponentOutlet;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="Laser", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	UHierarchicalInstancedStaticMeshComponent* HISMComponentLaser;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="Laser", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	ULaserGridEditorComponent* LaserGridEditorComponent;
#endif

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bEnabled)
	bool bEnabled;

	UPROPERTY(Transient)
	int32 LaserGridPatternIndex;

	UPROPERTY(Transient)
	FTimerHandle LaserPatternTimerHandle;

};

