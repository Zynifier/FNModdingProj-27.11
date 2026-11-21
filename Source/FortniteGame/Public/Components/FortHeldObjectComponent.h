// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Items/FortItemEntry.h"
#include "FortHeldObjectComponent.generated.h"

class AActor;
class AController;
class AFortDecoPreview;
class AFortPlayerPawn;
class AFortProjectileBase;
class AFortWaterBodyActor;
class AFortWeapon;
class UFortCameraMode;
class UFortHeldObjectComponent;
class UFortProjectileMovementComponent;
class UFortWaterInteractionComponent;
class UFortWeaponItemDefinition;
class UFortWorldItem;
class UMaterialInterface;
class UMeshComponent;
class UPrimitiveComponent;

UENUM()
enum class EHeldObjectState : uint8
{
	/** Object has no current relation to any pawn. It is just existing in the world, a subject to physics. */
	Unheld = 0,
	/** Object is held by a pawn */
	Held = 1,
	/** A pawn has thrown this object. */
	Thrown = 2,
	/** A pawn has placed this object in front of them using a ray trace to determine the exact location. */
	Placed = 3,
	/** A pawn has dropped this object. Dropped is similar to placed, but without a ray trace. */
	Dropped = 4,
	/** Object is held by a pawn that is in a vehicle */
	HeldInVehicle = 5,
};

USTRUCT(BlueprintType)
struct FHeldObjectMovementReplicatedData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	uint8 RepIncrement;

	UPROPERTY()
	FVector DetachLocation;

	UPROPERTY()
	FRotator DetachRotation;

	UPROPERTY()
	FVector MovementVelocity;

};

USTRUCT(BlueprintType)
struct FHeldObjectThrownData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Held Objects|Thrown Data")
	FScalableFloat MaxSpeed;

	UPROPERTY(EditAnywhere, Category="Held Objects|Thrown Data")
	FScalableFloat GravityScale;

};

USTRUCT()
struct FHoldingObjectData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="HoldingObjectData")
	TObjectPtr<AActor> ObjectHeld;

	UPROPERTY(EditAnywhere, Category="HoldingObjectData")
	EAttachmentRule AttachmentScaleRule;

	UPROPERTY(EditAnywhere, Category="HoldingObjectData")
	FVector AttachmentOffset;

	UPROPERTY(EditAnywhere, Category="HoldingObjectData")
	FName AttachmentSocketName;

	UPROPERTY(EditAnywhere, Category="HoldingObjectData")
	bool bWasSimulating;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("ComponentReplication", "Activation", "Cooking", "AssetUserData", "Collision", "Sockets", "Tags"), meta=(BlueprintSpawnableComponent))
class UFortHeldObjectComponent : public UActorComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHeldObjectAttached);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHeldObjectDestroy);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHeldObjectDropped);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHeldObjectEnteredWater);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHeldObjectGuideProjectileStarted);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHeldObjectGuideProjectileStopped);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHeldObjectMovedToVehicle, UFortHeldObjectComponent*, HeldObject);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHeldObjectOwningPawnChanged);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHeldObjectPickedUp);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHeldObjectPlaced);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHeldObjectThrown);
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnHeldObjectThrownLanded);

public:
	UFUNCTION(BlueprintCallable, Category="Held Objects|Interaction")
	bool CanInteract(const AFortPlayerPawn* RequestingPawn);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Held Objects|Behavior")
	void DropHeldObject();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Held Objects|Behavior")
	void DropObjectHeldInVehicle();

	UFUNCTION(BlueprintPure, Category="Held Objects")
	bool GetAllowObjectToBeHeldInVehicle() const;

	UFUNCTION(BlueprintPure, Category="Held Objects")
	bool GetBlocksVehicleDriverSeat() const;

	UFUNCTION(BlueprintPure, Category="Held Objects|Trajectory")
	float GetGravityScale() const;

	UFUNCTION(BlueprintPure, Category="Held Objects|Trajectory")
	float GetGravityZ() const;

	UFUNCTION(BlueprintPure, Category="Held Objects|Instigator")
	AFortPlayerPawn* GetInstigator() const;

	UFUNCTION(BlueprintPure, Category="Held Objects")
	FFortItemEntry GetItemEntry() const;

	UFUNCTION(BlueprintPure, Category="Held Objects|Trajectory")
	float GetMaxSpeed() const;

	UFUNCTION(BlueprintPure, Category="Held Objects|Mesh")
	UMeshComponent* GetMeshComponent() const;

	UFUNCTION(BlueprintPure, Category="Held Objects|Trajectory")
	float GetSweptTraceRadius() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Held Objects|Behavior")
	void HoldObjectInVehicle();

	UFUNCTION(BlueprintPure, Category="Held Objects")
	bool IsDropped() const;

	UFUNCTION(BlueprintPure, Category="Held Objects")
	bool IsHeld() const;

	UFUNCTION(BlueprintPure, Category="Held Objects")
	bool IsHeldInVehicle() const;

	UFUNCTION(BlueprintPure, Category="Held Objects")
	bool IsPlaced() const;

	UFUNCTION(BlueprintPure, Category="Held Objects")
	bool IsThrown() const;

	UFUNCTION(BlueprintPure, Category="Held Objects")
	bool IsUnheld() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Held Objects|Behavior")
	void OnThrowComplete();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Held Objects|Behavior")
	void PickupHeldObject(AFortPlayerPawn* PlayerPawn);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Held Objects|Behavior")
	void PlaceHeldObject();

	UFUNCTION()
	void RemoveHeldObjectFromVehicle();

	UFUNCTION(BlueprintCallable, Category="Held Objects|Mesh")
	void SetMeshComponent(UMeshComponent* InMeshComponent);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Held Objects|Behavior")
	void SetPreviousOwner(AFortPlayerPawn* PlayerPawn);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Held Objects|Behavior")
	void ThrowHeldObject(const FVector& DetachLocation, const FRotator& ThrowDirection);

	UPROPERTY(BlueprintAssignable)
	FOnHeldObjectPickedUp OnHeldObjectPickedUp;

	UPROPERTY(BlueprintAssignable)
	FOnHeldObjectPlaced OnHeldObjectPlaced;

	UPROPERTY(BlueprintAssignable)
	FOnHeldObjectDropped OnHeldObjectDropped;

	UPROPERTY(BlueprintAssignable)
	FOnHeldObjectGuideProjectileStarted OnHeldObjectGuideProjectileStarted;

	UPROPERTY(BlueprintAssignable)
	FOnHeldObjectGuideProjectileStopped OnHeldObjectGuideProjectileStopped;

	UPROPERTY(BlueprintAssignable)
	FOnHeldObjectEnteredWater OnHeldObjectEnteredWater;

	UPROPERTY(BlueprintAssignable)
	FOnHeldObjectMovedToVehicle OnHeldObjectMovedToVehicle;

	UPROPERTY(BlueprintAssignable)
	FOnHeldObjectThrown OnHeldObjectThrown;

	UPROPERTY(BlueprintAssignable)
	FOnHeldObjectThrownLanded OnHeldObjectThrownLanded;

	UPROPERTY(BlueprintAssignable)
	FOnHeldObjectDestroy OnHeldObjectDestroy;

	UPROPERTY(BlueprintAssignable)
	FOnHeldObjectAttached OnHeldObjectAttached;

	UPROPERTY(BlueprintAssignable)
	FOnHeldObjectOwningPawnChanged OnHeldObjectOwningPawnChanged;

protected:
	UFUNCTION()
	void GuideProjectileStopped(const FHitResult& ImpactResult);

	UFUNCTION()
	void HandleGuideProjectileDestroyed(AActor* DestroyedActor);

	UFUNCTION(BlueprintNativeEvent)
	bool OnCanInteract(const AFortPlayerPawn* RequestingPawn);

	UFUNCTION()
	void OnWeaponUnequipped();

	UFUNCTION()
	void ThrownObjectEnteredWater(AFortWaterBodyActor* WaterBody, UFortWaterInteractionComponent* WaterInteractionComponent, bool bIsFirstBody);

	UFUNCTION()
	void ThrownObjectStopped(const FHitResult& ImpactResult);

	UFUNCTION(BlueprintCallable, Category="Held Objects")
	void TurnOffCollisionSettings();

	UFUNCTION(BlueprintCallable, Category="Held Objects")
	void TurnOnCollisionSettings();

	UPROPERTY(EditDefaultsOnly, Category="Held Objects|Weapon")
	TSoftObjectPtr<UFortWeaponItemDefinition> EquippedWeaponItemDefinition;

	UPROPERTY(EditAnywhere, Category="Held Objects|Weapon")
	TSubclassOf<UFortCameraMode> CameraModeClass;

	UPROPERTY(EditDefaultsOnly, Category="Held Objects|Weapon")
	FHeldObjectThrownData HeldObjectThrownData;

	UPROPERTY(EditDefaultsOnly, Category="Held Objects|Attachment")
	FVector AttachmentOffset;

	UPROPERTY(EditDefaultsOnly, Category="Held Objects|Attachment")
	EAttachmentRule PlayerAttachmentScaleRule;

	UPROPERTY(EditDefaultsOnly, Category="Held Objects|Attachment")
	FName AttachmentSocketName;

	UPROPERTY(EditDefaultsOnly, Category="Held Objects|Vehicles")
	uint8 bAllowObjectToBeHeldInVehicle : 1;

	UPROPERTY(EditDefaultsOnly, Category="Held Objects|Vehicles")
	uint8 bBlocksVehicleDriverSeat : 1;

	UPROPERTY(EditDefaultsOnly, Category="Held Objects|Physics", meta=(InlineEditConditionToggle))
	uint8 bApplyAngularImpulseOnThrow : 1;

	UPROPERTY(EditDefaultsOnly, Category="Held Objects|Detach Behavior")
	uint8 bUsePlacementRotationClamp : 1;

	UPROPERTY(EditDefaultsOnly, Category="Held Objects|Physics", meta=(EditCondition="bApplyAngularImpulseOnThrow"))
	FVector2D ThrowAngularImpulseRange;

	UPROPERTY(EditDefaultsOnly, Category="Held Objects|Preview")
	TSoftObjectPtr<UMaterialInterface> PreviewMaterial;

	UPROPERTY(EditDefaultsOnly, Category="Held Objects|Preview")
	TSubclassOf<AFortDecoPreview> PlacementPreviewClass;

	UPROPERTY(EditDefaultsOnly, Category="Held Objects|Attachment")
	TSubclassOf<AFortProjectileBase> GuideProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category="Held Objects|Attachment")
	FVector GuideAttachLocationOffset;

	UPROPERTY(EditDefaultsOnly, Category="Held Objects|Attachment")
	FRotator GuideAttachRotationOffset;

private:
	UFUNCTION()
	void HandleOwnerDestroyed(AActor* DestroyedActor);

	UFUNCTION()
	void HandleOwnerDied(AActor* DamagedActor, float Damage, AController* InstigatedBy, AActor* DamageCauser, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector Momentum);

	UFUNCTION()
	void OnRep_bCollisionBlockedByPawns();

	UFUNCTION()
	void OnRep_OwningPawn(AFortPlayerPawn* LastOwningPawn);

	UFUNCTION()
	void OnRep_UsePreviewMaterial();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_UsePreviewMaterial)
	uint8 bUsePreviewMaterial : 1;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_bCollisionBlockedByPawns)
	uint8 bCollisionBlockedByPawns : 1;

	UPROPERTY(Transient)
	uint8 bDroppedFromWeaponSwap : 1;

	UPROPERTY(Transient, Replicated)
	EHeldObjectState HeldObjectState;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_OwningPawn, Category="FortHeldObjectComponent", meta=(AllowPrivateAccess="true"))
	TObjectPtr<AFortPlayerPawn> OwningPawn;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortHeldObjectComponent", meta=(AllowPrivateAccess="true"))
	FRotator ObjectPickupRotation;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortPlayerPawn> PreviousOwningPawn;

	UPROPERTY(Transient)
	FHeldObjectMovementReplicatedData HeldObjectMovementReplicatedData;

	UPROPERTY(Transient)
	TWeakObjectPtr<UFortWorldItem> GrantedWeaponItem;

	UPROPERTY(Transient)
	TWeakObjectPtr<AFortWeapon> GrantedWeapon;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortProjectileMovementComponent> ProjectileMovementComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UMeshComponent> ReferenceMeshComponent;

	UPROPERTY(Transient)
	TObjectPtr<AFortDecoPreview> PlacementPreviewActor;

	UPROPERTY(BlueprintReadOnly, Transient, Replicated, Category="FortHeldObjectComponent", meta=(AllowPrivateAccess="true"))
	TWeakObjectPtr<AFortProjectileBase> GuideProjectile;

};

UCLASS(MinimalAPI, NotBlueprintable, HideCategories=("ComponentReplication", "Activation", "Cooking", "AssetUserData", "Collision", "Sockets", "Tags"))
class UFortHoldingObjectComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRep_HoldingObjectData(const FHoldingObjectData& PreviousData);

	UPROPERTY(Transient, ReplicatedUsing=OnRep_HoldingObjectData)
	FHoldingObjectData HoldingObjectData;

};

