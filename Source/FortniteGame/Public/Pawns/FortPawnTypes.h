// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/NetSerialization.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "Sound/FortFeedbackManager.h"
#include "FortPawnTypes.generated.h"

class AActor;
class AFortPawn;
class AFortWeapon;
class IWindVolumeInterface;
class UAudioComponent;
class UPrimitiveComponent;
class USkeletalMesh;
class USkeletalMeshComponentBudgeted;
class UStaticMesh;
class UStaticMeshComponent;

UENUM(BlueprintType)
enum class EFortControlRecoveryBehavior : uint8
{
	// Control Resist recovers to full as soon as the pawn enters stagger/stun/KB state. Impact is suffered as usual while in that state, and additional stagger/stun/KB can occur if the control resist is depleted again.

	DefaultControl = 0,
	// Control Resist recovers to full as soon as the pawn enters stagger/stun/KB state AND the pawn is immune to further impact until it exits the state.

	LimitedControl = 1,
	// Control Resist does not recover during stagger/stun/KB, allowing further impacts to continually "juggle" the pawn.

	ChainControl = 2,
};

UENUM(BlueprintType)
enum class EFortPawnPushSize : uint8
{
	FFPS_Normal = 0,
	FPPS_Player = 1,
	FPPS_Large = 2,
	FPPS_SuperLarge = 3,
};

UENUM()
enum class EFortSynchedActionEndMovementMode : uint8
{
	/** Transition to PhysFalling after the synched action */
	PhysFalling = 0,
	/** Transition to PhysWalking after the synched action */
	PhysWalking = 1,
};

UENUM()
enum class EFortWeaponListRemovalBehavior : uint8
{
	/** Destroy the weapon actor immediately upon removal */
	DestroyImmediately = 0,
	/** Destroy the weapon actor in a deferred manner by setting its lifespan to the CVar variable WeaponListRemovalLifespan in FortPawn.cpp */
	DeferredLifespan = 1,
	/** Do not destroy the weapon actor at all, just remove it from the list. Responsibility on the caller to make sure the weapon doesn't leak */
	DoNotDestroy = 2,
};

UENUM()
enum class EWindVolumePriority : uint8
{
	Priority_1 = 1,
	Priority_2 = 2,
	Priority_3 = 3,
	Priority_4 = 4,
	Priority_5 = 5,
	Priority_6 = 6,
	Priority_7 = 7,
	Priority_8 = 8,
	Priority_9 = 9,
	Priority_10 = 10,
	Priority_Default = 11,
};

USTRUCT(BlueprintType)
struct FAssetAttachment
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attachment")
	FName SocketName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attachment")
	TObjectPtr<USkeletalMesh> SkeletalMeshAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attachment")
	TObjectPtr<UStaticMesh> StaticMeshAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attachment")
	bool bSkipOnDedicatedServers;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Attachment")
	bool bIsCurrentWeaponSubstitute;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponentBudgeted> SkelMeshComp;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UStaticMeshComponent> StaticMeshComp;

};

USTRUCT()
struct FAthenaBatchedDamageGameplayCues_NonShared
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AActor> HitActor;

	UPROPERTY()
	TObjectPtr<AActor> NonPlayerHitActor;

};

USTRUCT()
struct FAthenaBatchedDamageGameplayCues_Shared
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FVector_NetQuantize10 Location;

	UPROPERTY()
	FVector_NetQuantizeNormal Normal;

	UPROPERTY()
	float Magnitude;

	UPROPERTY()
	bool bWeaponActivate;

	UPROPERTY()
	bool bIsFatal;

	UPROPERTY()
	bool bIsCritical;

	UPROPERTY()
	bool bIsShield;

	UPROPERTY()
	bool bIsShieldDestroyed;

	UPROPERTY()
	bool bIsShieldApplied;

	UPROPERTY()
	bool bIsBallistic;

	UPROPERTY()
	bool bIsBeam;

	UPROPERTY(NotReplicated)
	FVector_NetQuantize10 NonPlayerLocation;

	UPROPERTY(NotReplicated)
	FVector_NetQuantizeNormal NonPlayerNormal;

	UPROPERTY(NotReplicated)
	float NonPlayerMagnitude;

	UPROPERTY()
	bool NonPlayerbIsFatal;

	UPROPERTY()
	bool NonPlayerbIsCritical;

	UPROPERTY(NotReplicated)
	bool bIsValid;

};

USTRUCT()
struct FCalloutEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Callouts")
	FGameplayTag CalloutTag;

	UPROPERTY(EditDefaultsOnly, Category="Callouts")
	FSlateBrush CalloutIcon;

};

USTRUCT()
struct FDamageDoneInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTagContainer TrackedDamageTagGrouping;

	UPROPERTY()
	float DamageAmount;

};

USTRUCT()
struct FDamageDoneSourceInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTagContainer TrackedSourceTags;

	UPROPERTY()
	float DamageAmount;

	UPROPERTY()
	int32 NumHits;

};

USTRUCT()
struct FDamageDoneTargetInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FGameplayTagContainer TrackedTargetTags;

	UPROPERTY()
	TArray<FDamageDoneSourceInfo> TrackedSourceData;

};

USTRUCT()
struct FDamagerInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AActor> DamageCauser;

	UPROPERTY()
	int32 DamageAmount;

	UPROPERTY()
	FGameplayTagContainer SourceTags;

};

USTRUCT()
struct FFortPawnVocalChord
{
	GENERATED_BODY()

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UAudioComponent> FeedbackAudioComponent;

	UPROPERTY()
	FFortSpokenLine ReplicatedSpokenLine;

	UPROPERTY(NotReplicated)
	FFortSpokenLine PendingSpokenLine;

	UPROPERTY(NotReplicated)
	FFortSpokenLine QueuedSpokenLine;

	UPROPERTY(NotReplicated)
	FFortSpokenLine CurrentSpokenLine;

};

USTRUCT()
struct FPawnDamageZones
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	bool bActive;

	UPROPERTY(EditAnywhere, Category="DamageZone")
	TArray<FName> Bones;

};

USTRUCT()
struct FRecordedGunshot
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AFortWeapon> Weapon;

	UPROPERTY()
	TObjectPtr<AFortPawn> InstigatingFortPawn;

	UPROPERTY()
	FVector WorldLocation;

	UPROPERTY()
	float Strength;

	UPROPERTY()
	float Time;

};

USTRUCT(BlueprintType)
struct FSavedPosition
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SavedPosition")
	FVector Position;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SavedPosition")
	FRotator Rotation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SavedPosition")
	FVector Velocity;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SavedPosition")
	float Time;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SavedPosition")
	TEnumAsByte<EMovementMode> MovementMode;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SavedPosition")
	uint8 CustomMovementMode;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SavedPosition")
	uint8 bTeleported : 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="SavedPosition")
	uint8 bTouchingGround : 1;

};

USTRUCT()
struct FSynchedActionWarpPointInfo_Replicated
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AActor> RefActor;

	UPROPERTY(Export)
	TWeakObjectPtr<UPrimitiveComponent> RefActorComponent;

	UPROPERTY()
	FName RefActorBoneName;

protected:
	UPROPERTY()
	FVector LocalPosition;

	UPROPERTY()
	FQuat LocalDirection;

	UPROPERTY()
	FVector CachedGlobalPosition;

	UPROPERTY()
	FQuat CachedGlobalDirection;

	UPROPERTY()
	EFortSynchedActionEndMovementMode EndMovementMode;

	UPROPERTY()
	bool bValid;

};

USTRUCT()
struct FVortexParams
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float GravityFloorGravityScalar;

	UPROPERTY()
	float GravityFloorTerminalVelocity;

	UPROPERTY()
	FTransform Transform;

	UPROPERTY()
	float BoundsWidth;

	UPROPERTY()
	float SpinVelocity;

	UPROPERTY()
	float SpinRadius;

	UPROPERTY()
	bool bCanDeployGlider;

};

USTRUCT()
struct FWindVolumeID
{
	GENERATED_BODY()

private:
	UPROPERTY()
	uint32 ID;

};

USTRUCT()
struct FWindVolumeData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FWindVolumeID ID;

	UPROPERTY()
	EWindVolumePriority Priority;

	UPROPERTY()
	TScriptInterface<IWindVolumeInterface> WindVolume;

};

UINTERFACE(MinimalAPI, meta=(CannotImplementInterfaceInBlueprint))
class UWindVolumeInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IWindVolumeInterface
{
	GENERATED_BODY()

};

