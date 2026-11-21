// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "Building/StructuralSupport/BuildingStructuralSupportSystem.h"
#include "FortCreativeLinearMoverComponent.generated.h"

class AActor;
class ABuildingActor;
class AController;
class AFortMinigame;
class IFortSpatialGameplayInterface;
class UFortCreativeLinearMoverComponent;
class UFortNavModifierComponent;
class UPrimitiveComponent;
enum class EFortCreativeLinearMoverRotationDirection : uint8;
enum class EFortCreativeLinearMoverTranslationType : uint8;

UENUM(BlueprintType)
enum class EFortCreativeLinearMoverCollisionBehavior : uint8
{
	EFCLMCB_None = 0 UMETA(DisplayName="None"),
	EFCLMCB_Stop = 1 UMETA(DisplayName="Stop"),
	EFCLMCB_Reverse = 2 UMETA(DisplayName="Reverse"),
	EFCLMCB_Push = 3 UMETA(DisplayName="Push"),
};

UENUM(BlueprintType)
enum class EFortCreativeLinearMoverMode : uint8
{
	EFCLMM_Translation = 0 UMETA(DisplayName="Translation"),
	EFCLMM_Rotation = 1 UMETA(DisplayName="Rotation"),
};

UENUM(BlueprintType)
enum class EFortCreativeLinearMoverMovementCompleteBehavior : uint8
{
	EFCLMMS_None = 0 UMETA(DisplayName="None"),
	EFCLMMS_Repeat = 1 UMETA(DisplayName="Repeat"),
	EFCLMMS_PingPong = 2 UMETA(DisplayName="Ping Pong"),
	EFCLMMS_Reset = 3 UMETA(DisplayName="Reset"),
};

UENUM(BlueprintType)
enum class EFortCreativeLinearMoverRotationAxis : uint8
{
	EFCLMRA_Roll = 0 UMETA(DisplayName="Roll"),
	EFCLMRA_Pitch = 1 UMETA(DisplayName="Pitch"),
	EFCLMRA_Yaw = 2 UMETA(DisplayName="Yaw"),
};

UENUM(BlueprintType)
enum class EFortCreativeLinearMoverRotationDirection : uint8
{
	EFCLMRD_Clockwise = 0 UMETA(DisplayName="Clockwise"),
	EFCLMRD_CounterClockwise = 1 UMETA(DisplayName="CounterClockwise"),
};

UENUM(BlueprintType)
enum class EFortCreativeLinearMoverTranslationType : uint8
{
	EFCLMTT_None = 0 UMETA(DisplayName="None"),
	EFCLMTT_Forward = 1 UMETA(DisplayName="Forward"),
	EFCLMTT_Reverse = 2 UMETA(DisplayName="Reverse"),
};

USTRUCT(BlueprintType)
struct FFortCreativeLinearMoverRotationMovementData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortCreativeLinearMoverRotationMovementData")
	FRotator TargetRotation;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeLinearMoverRotationMovementData")
	FRotator InitialRotation;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeLinearMoverRotationMovementData")
	float StartTime;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeLinearMoverRotationMovementData")
	float EndTime;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeLinearMoverRotationMovementData")
	EFortCreativeLinearMoverRotationDirection RotationDirection;

	UPROPERTY(BlueprintReadOnly, NotReplicated, Category="FortCreativeLinearMoverRotationMovementData")
	bool bFinished;

};

USTRUCT(BlueprintType)
struct FFortCreativeLinearMoverTranslationMovementData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortCreativeLinearMoverTranslationMovementData")
	FVector TargetLocation;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeLinearMoverTranslationMovementData")
	FVector InitialLocation;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeLinearMoverTranslationMovementData")
	float StartTime;

	UPROPERTY(BlueprintReadOnly, Category="FortCreativeLinearMoverTranslationMovementData")
	float EndTime;

	UPROPERTY(BlueprintReadOnly, NotReplicated, Category="FortCreativeLinearMoverTranslationMovementData")
	bool bFinished;

};

UCLASS(MinimalAPI, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class UFortCreativeLinearMoverComponent : public UActorComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FOnCreativeLinearMoverFinishedSignature, UFortCreativeLinearMoverComponent, OnCreativeLinearMoverFinishedDelegate, UFortCreativeLinearMoverComponent*, CreativeLinearMoverComponent);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FOnCreativeLinearMoverInterruptedSignature, UFortCreativeLinearMoverComponent, OnCreativeLinearMoverInterruptedDelegate, UFortCreativeLinearMoverComponent*, CreativeLinearMoverComponent);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_ThreeParams(FOnCreativeLinearMoverRotationDirectionChangedSignature, UFortCreativeLinearMoverComponent, OnCreativeLinearMoverRotationDirectionChangedDelegate, UFortCreativeLinearMoverComponent*, CreativeLinearMoverComponent, EFortCreativeLinearMoverRotationDirection, RotationDirection, AController*, Instigator);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FOnCreativeLinearMoverStartedSignature, UFortCreativeLinearMoverComponent, OnCreativeLinearMoverStartedDelegate, UFortCreativeLinearMoverComponent*, CreativeLinearMoverComponent);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_ThreeParams(FOnCreativeLinearMoverTargetCollisionSignature, UFortCreativeLinearMoverComponent, OnCreativeLinearMoverTargetCollisionDelegate, UFortCreativeLinearMoverComponent*, CreativeLinearMoverComponent, AActor*, TargetActor, AActor*, OtherActor);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_ThreeParams(FOnCreativeLinearMoverTranslationTypeChangedSignature, UFortCreativeLinearMoverComponent, OnCreativeLinearMoverTranslationTypeChangedDelegate, UFortCreativeLinearMoverComponent*, CreativeLinearMoverComponent, EFortCreativeLinearMoverTranslationType, TranslationType, AController*, Instigator);

public:
	UFUNCTION(BlueprintCallable)
	void AddActorToIgnoreDuringMovement(AActor* Actor);

	UFUNCTION(BlueprintPure)
	ABuildingActor* GetNearestOverlappingBuildingActor() const;

	UFUNCTION(BlueprintCallable)
	void OnEnabledStateChanged(const bool bEnabled);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ResetActorsToIgnoreDuringMovement();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ResetRotation();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ResetTranslation();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Rotate(const bool bTeleport = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RotateTo(const FRotator& TargetRotation, const bool bTeleport = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetRotationDirection(EFortCreativeLinearMoverRotationDirection InRotationDirection, AController* Instigator = nullptr);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetTranslationType(EFortCreativeLinearMoverTranslationType InTranslationType, AController* Instigator = nullptr);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void StopRotation();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void StopTranslation();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Translate(const bool bTeleport = false);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void TranslateTo(const FVector& TargetLocation, const bool bTeleport = false);

	UPROPERTY(BlueprintAssignable)
	FOnCreativeLinearMoverStartedSignature OnCreativeLinearMoverStartedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeLinearMoverInterruptedSignature OnCreativeLinearMoverInterruptedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeLinearMoverFinishedSignature OnCreativeLinearMoverFinishedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeLinearMoverTargetCollisionSignature OnCreativeLinearMoverTargetCollisionDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeLinearMoverTranslationTypeChangedSignature OnCreativeLinearMoverTranslationTypeChangedDelegate;

	UPROPERTY(BlueprintAssignable)
	FOnCreativeLinearMoverRotationDirectionChangedSignature OnCreativeLinearMoverRotationDirectionChangedDelegate;

protected:
	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="FortCreativeLinearMoverComponent")
	float Distance;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="FortCreativeLinearMoverComponent")
	float Speed;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="FortCreativeLinearMoverComponent")
	float RotationAngle;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="FortCreativeLinearMoverComponent")
	float RotationDuration;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="FortCreativeLinearMoverComponent")
	EFortCreativeLinearMoverRotationDirection RotationDirection;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="FortCreativeLinearMoverComponent")
	EFortCreativeLinearMoverMovementCompleteBehavior TranslationCompleteBehavior;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="FortCreativeLinearMoverComponent")
	EFortCreativeLinearMoverMovementCompleteBehavior RotationCompleteBehavior;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="FortCreativeLinearMoverComponent")
	EFortCreativeLinearMoverRotationAxis RotationAxis;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="FortCreativeLinearMoverComponent")
	EFortCreativeLinearMoverTranslationType TranslationType;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="FortCreativeLinearMoverComponent")
	EFortCreativeLinearMoverMode MovementMode;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="FortCreativeLinearMoverComponent")
	TObjectPtr<ABuildingActor> PendingTarget;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_Target, Category="FortCreativeLinearMoverComponent")
	TWeakObjectPtr<ABuildingActor> Target;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="FortCreativeLinearMoverComponent")
	FBuildingSupportCellIndex PreviousTargetCellIndexForUpdates;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="FortCreativeLinearMoverComponent")
	FVector PreviousTargetPosition;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="FortCreativeLinearMoverComponent")
	TScriptInterface<IFortSpatialGameplayInterface> CurrentSpatialGameplayInterface;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_TranslationMovementData, Category="FortCreativeLinearMoverComponent")
	FFortCreativeLinearMoverTranslationMovementData TranslationMovementData;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_RotationMovementData, Category="FortCreativeLinearMoverComponent")
	FFortCreativeLinearMoverRotationMovementData RotationMovementData;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_ActorsToIgnoreDuringMovement, Category="FortCreativeLinearMoverComponent")
	TArray<TObjectPtr<AActor>> ActorsToIgnoreDuringMovement;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="FortCreativeLinearMoverComponent")
	bool bSweepOnTranslation;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="FortCreativeLinearMoverComponent")
	bool bPerformOverlapsOnTranslation;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="FortCreativeLinearMoverComponent")
	bool bAllDevicesTargetable;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="FortCreativeLinearMoverComponent")
	FVector OriginalActorLocation;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="FortCreativeLinearMoverComponent")
	FRotator OriginalActorRotation;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="FortCreativeLinearMoverComponent")
	EFortCreativeLinearMoverTranslationType OriginalTranslationType;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="FortCreativeLinearMoverComponent")
	EFortCreativeLinearMoverRotationDirection OriginalRotationDirection;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="FortCreativeLinearMoverComponent")
	bool bEnableMusicSequencerBehavior;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="FortCreativeLinearMoverComponent")
	bool bSkipTranslationCompleteBehavior;

	UPROPERTY(VisibleInstanceOnly, BlueprintReadWrite, Transient, Category="FortCreativeLinearMoverComponent")
	bool bSkipRotationCompleteBehavior;

	UPROPERTY(VisibleAnywhere, Transient, Export, Category="FortCreativeLinearMoverComponent", meta=(EditInline="true"))
	TObjectPtr<UFortNavModifierComponent> CachedNavModifierComponent;

private:
	UFUNCTION()
	void ComponentHit(const UPrimitiveComponent* HitComponent, const AActor* OtherActor, const UPrimitiveComponent* OtherComp, const FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION(BlueprintPure, BlueprintAuthorityOnly)
	bool IsMovementFinished() const;

	UFUNCTION(BlueprintCallable)
	void OnMinigamePlayModeChanged(AFortMinigame* Minigame, bool bIsInPlayMode);

	UFUNCTION()
	void OnRep_ActorsToIgnoreDuringMovement();

	UFUNCTION()
	void OnRep_RotationMovementData();

	UFUNCTION()
	void OnRep_Target(TWeakObjectPtr<ABuildingActor> OldTarget);

	UFUNCTION()
	void OnRep_TranslationMovementData();

};

