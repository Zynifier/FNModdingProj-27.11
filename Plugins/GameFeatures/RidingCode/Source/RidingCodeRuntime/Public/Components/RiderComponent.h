// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CollisionProfile.h"
#include "Engine/DataTable.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Engine/TimerHandle.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Camera/FortCameraMode_ThirdPerson.h"
#include "Components/FortPawnOverrideComponent.h"
#include "FortWeaponTargetingSourceOffsetModifierInterface.h"
#include "Movement/FortMovementComp_Character.h"
#include "RidingAnalytics.h"
#include "RiderComponent.generated.h"

class AActor;
class ACharacter;
class AController;
class AFortPawn;
class AFortPlayerController;
class AFortPlayerPawn;
class AFortWeapon;
class UFXSystemAsset;
class UFXSystemComponent;
class UFortCameraMode_Riding;
class UFortInputComponent;
class UFortInputMappingContext;
class UInputAction;
class UPrimitiveComponent;
class URidableComponent;
class URiderComponent;
class USceneComponent;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRider_RidableChanged, URiderComponent*, Rider, URidableComponent*, Ridable);

USTRUCT(BlueprintType)
struct FRiderDismountLaunchVelocity
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RiderDismountLaunchVelocity")
	FScalableFloat DismountVelocityMultiplier;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RiderDismountLaunchVelocity")
	FScalableFloat DismountVelocityBaseForwardVelocity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RiderDismountLaunchVelocity")
	FScalableFloat DismountVelocityBaseRightVelocity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RiderDismountLaunchVelocity")
	FScalableFloat DismountVelocityBaseUpVelocity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RiderDismountLaunchVelocity")
	bool bApplyDismountVelocityMultiplierToZVelocity;

};

UCLASS(Config=Game, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class RIDINGCODERUNTIME_API URiderComponent : public UFortPawnOverrideComponent, public IFortWeaponTargetingSourceOffsetModifierInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Riding")
	virtual bool IsRidingActor() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Riding")
	virtual bool StartRidingActor(AActor* TargetActor);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Riding")
	virtual bool StopRidingActor(bool bLaunchRider = true, bool bFindDismountLocation = true, bool bIsJumpExit = false);

	UPROPERTY(BlueprintAssignable)
	FOnRider_RidableChanged OnStartedRiding;

	UPROPERTY(BlueprintAssignable)
	FOnRider_RidableChanged OnStoppedRiding;

protected:
	UFUNCTION()
	void ClientHandleFinishedCharacterCustomization(AFortPlayerPawn* PlayerPawn);

	UFUNCTION(Client, Reliable)
	void ClientNotifyEmoteFailure(const FGameplayTagContainer ErrorTags);

	UFUNCTION()
	void HandleActorEndPlayWhileRiding(AActor* Actor, EEndPlayReason::Type EndPlayReason);

	UFUNCTION()
	void HandleDBNOWhileRiding();

	UFUNCTION()
	void HandleDeferredExitVelocity(const FVector ExitVelocity);

	UFUNCTION()
	void HandleGamepadRidingExitReleased();

	UFUNCTION()
	void HandleOnWeaponEquipped(AFortWeapon* NewWeapon, AFortWeapon* PrevWeapon);

	UFUNCTION()
	void HandlePawnDiedWhileRiding(AFortPawn* DeadPawn);

	UFUNCTION()
	void HandlePawnTeleported(AFortPawn* TeleportedPawn);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleRidableFound(const FHitResult& HitResult);

	UFUNCTION()
	void HandleRidableMovementModeChanged(ACharacter* InCharacter, EMovementMode PrevMovementMode, uint8 PreviousCustomMode);

	UFUNCTION()
	void HandleRiderDidDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* HitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void HandleRiderTakenDamage(AActor* DamageOnOwnerPawnDamageddActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void HandleRidingExitPressed();

	UFUNCTION()
	void HandleRidingExitReleased();

	UFUNCTION(BlueprintNativeEvent)
	void HandleStartedRiding(URidableComponent* Ridable);

	UFUNCTION(BlueprintNativeEvent)
	void HandleStoppedRiding(URidableComponent* Ridable);

	UFUNCTION()
	void OnMovementModeChanged(ACharacter* InCharacter, EMovementMode PrevMovementMode, uint8 PreviousCustomMode);

	UFUNCTION()
	void OnRep_ActiveRidable();

	UFUNCTION()
	void OnRep_IsSprintingReplay();

	UFUNCTION()
	void OnRep_RidableControlRuntimeUpdated();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerRidingExit();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Camera")
	TSubclassOf<UFortCameraMode_Riding> RidingCameraModeClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Camera")
	TSubclassOf<UFortCameraMode_Riding> RidingSprintCameraModeClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Camera")
	float RidingCameraModeBlendTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Camera")
	FInterpOffset TargetingAdditionalViewTargetSpaceViewOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Rider Prop", meta=(AssetBundles="Client"))
	TSubclassOf<USceneComponent> RiderPropClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Ridable Prop", meta=(AssetBundles="Client"))
	TSubclassOf<USceneComponent> RidablePropClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Rider Prop")
	FVector RiderPropAttachLocationOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Rider Prop")
	FRotator RiderPropAttachRotationOffset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Rider Prop")
	float RiderPropAttachScale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Rider Prop")
	FName RiderPropAttachSocket;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Rider Prop")
	bool bUseClientAttachGuideSocket;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Rider Prop", meta=(EditCondition="!bUseClientAttachGuideSocket"))
	FVector RiderPropAttachSoftBounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Rider Prop", meta=(ClampMax="1.000000", ClampMin="0.000000", EditCondition="!bUseClientAttachGuideSocket"))
	float RiderPropAttachSoftBoundsScalar;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Rider Prop", meta=(EditCondition="!bUseClientAttachGuideSocket"))
	FVector RiderPropAttachHardBounds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Rider Prop", meta=(EditCondition="!bUseClientAttachGuideSocket"))
	float RiderPropAttachSoftBoundsTargetingScalar;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Rider Prop", meta=(EditCondition="!bUseClientAttachGuideSocket"))
	float RiderPropAttachHardBoundsTargetingScalar;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Rider Prop", meta=(EditCondition="!bUseClientAttachGuideSocket"))
	float RiderPropAttachVerticalBufferTargetingScalar;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Input")
	float RidingExitHoldTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Input")
	FScalableFloat TimeBeforeReenteringRiding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Input")
	FGameplayTag RidingExitStartedEventTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Input")
	FGameplayTag RidingExitStoppedEventTag;

	UPROPERTY(EditDefaultsOnly, Category="Riding|Input")
	TObjectPtr<UFortInputMappingContext> RidingInputContext;

	UPROPERTY(EditDefaultsOnly, Category="Riding|Input")
	TObjectPtr<UInputAction> RidingExit;

	UPROPERTY(EditDefaultsOnly, Category="Riding|Input")
	TObjectPtr<UInputAction> GamepadRidingExit;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Connector Prop", meta=(AssetBundles="Client"))
	TObjectPtr<UFXSystemAsset> ConnectorFXAsset;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Connector Prop")
	FName ConnectorPropSourceMeshParameterName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Connector Prop")
	FName ConnectorPropTargetMeshParameterName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Config, Category="Riding|Client Smoothing")
	float SimulatedSmoothedRotationSpeed;

	UPROPERTY(EditDefaultsOnly, Config, Category="Riding|Emote")
	FGameplayTagContainer ExcludedEmoteTags;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_ActiveRidable, Export, Category="Riding", meta=(EditInline="true"))
	TObjectPtr<URidableComponent> ActiveRidable;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<URidableComponent> LastRidable;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="Riding", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> RiderProp;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="Riding", meta=(EditInline="true"))
	TObjectPtr<UFXSystemComponent> ConnectorProp;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Riding|Debug")
	FVector PropAttachSeparation;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Riding|Debug")
	FVector AdditionalAttachOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Riding|Debug")
	FVector SoftBoundsAttachmentOffset;

	UPROPERTY(BlueprintReadOnly, Transient, Category="Riding|Debug")
	FVector HardBoundsAttachmentOffset;

	UPROPERTY(EditDefaultsOnly, Category="Riding")
	FDataTableRowHandle PlaylistTagDenylistRowHandle;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortInputComponent> RiderInputComponent;

	UPROPERTY(Transient)
	FGameplayTagContainer PendingFailedEmoteErrorTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Launch")
	FRiderDismountLaunchVelocity ExitLaunchVelocity;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Riding|Launch")
	FRiderDismountLaunchVelocity JumpExitLaunchVelocity;

	UPROPERTY(Transient)
	FRidingAnalyticsData_Stopped ActiveAnaltyicsData;

	UPROPERTY(Transient)
	FVector RidableLocationLastFrame;

	UPROPERTY(Transient)
	FTimerHandle RestoreCollisionHandle;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_RidableControlRuntimeUpdated)
	FRidableControlRuntimeData RidableControlRuntimeData;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_IsSprintingReplay)
	uint8 bIsSprintingReplay : 1;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerController> ClampedController;

	UPROPERTY(BlueprintReadWrite, Category="Riding")
	bool bIsPetting;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RiderComponent")
	FScalableFloat RidingCapsuleHalfHeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RiderComponent")
	FScalableFloat RidingCapsuleRadius;

	UPROPERTY(EditDefaultsOnly, Category="RidableTrace")
	FCollisionProfileName CollisionProfileName;

	UPROPERTY(EditDefaultsOnly, Category="RidableTrace")
	FScalableFloat TraceRadius;

	UPROPERTY(EditDefaultsOnly, Category="RidableTrace")
	FScalableFloat TraceLength;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category="Riding|Input")
	bool bPreventExitRidingFromInput;

};

